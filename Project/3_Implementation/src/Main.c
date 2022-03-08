/**
 * @brief Sainimitha Mullapudi
 * 
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "lcd.h"

#define DHT11_PIN 5

/* Variables */
uint8_t data;
float A0value;
float A1value;
float averageValue;
char A0string[20];
char A1string[20];
char averageString[20];
uint8_t c=0,I_RH,D_RH,I_Temp,D_Temp,CheckSum;
char humString[10];
char tempString[10];
char humString2[10];
char tempString2[10];
char checkString[10];

/* Functions */
int ADC_read (unsigned char channel);
void USART_init (uint16_t baud);
void USART_send (uint8_t data);
uint8_t USART_receive (void);
void USART_message (char *data);
void ADC_init (void);
int ADC_read (unsigned char channel);
void Request();
void Response();
uint8_t Receive_data();

void USART_init (uint16_t baud)
{
	uint16_t baudPrescaler;						
	baudPrescaler = (F_CPU/(16UL*baud))-1;		/* Baud prescaler calculation */
	UBRRH = (uint8_t)(baudPrescaler>>8);		/* Writing 4 MSB baud rate bits in UBRRH register */
	UBRRL = (uint8_t)baudPrescaler;			/* Writing 8 LSB baud rate bits in UBRRL register */
	UCSRA &= ~(1<<U2X);				/* Synchronous operation */
	UCSRB = (1<<RXEN)|(1<<TXEN);			/* Enables the USART Receiver and Transmitter */
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);	/* Enables writing the UCSRC register, sets the number of data bits 
							in a frame the Receiver and Transmitter use. */
}
void USART_send (uint8_t data)
{
	while (!(UCSRA &(1<<UDRE)));			/* Wait for empty transmit buffer */ 
	UDR=data;					/* Put data into buffer, sends the data */
}

uint8_t USART_receive (void)
{
	while (!(UCSRA&(1<<RXC)));			/* Wait for data to be received */
	return UDR;
}

void USART_message (char *data)
{
	while ( *data != '\0')
	USART_send(*data++);
}

void ADC_init (void)
{
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);/* ADC enable,  ADC starts on rising edge, 
																				prescaler select (128) */
	SFIOR = 0x00;
}

int ADC_read (unsigned char channel)
{
	int ADC_value;
	unsigned char temp;
	ADMUX = (1 << REFS0)|channel;			/* AVCC as referent voltage, ADC channel select */
	_delay_ms(1);
	temp = ADCL;							
	ADC_value = ADCH;				/* Storing data in ADCH i ADCL data registers */
	ADC_value = (ADC_value << 8)|temp;			
	return ADC_value;
}

void Request()						/* Microcontroller sends start pulse */
{
	DDRB |= (1<<DHT11_PIN);
	PORTB &= ~(1<<DHT11_PIN);			/* Set pin LOW */
	_delay_ms(20);					
	PORTB |= (1<<DHT11_PIN);			/* Set pin HIGH */
}

void Response()		 /* Response from DHT11 */
{				
	DDRB &= ~(1<<DHT11_PIN);
	while(PINB & (1<<DHT11_PIN))
	while((PINB & (1<<DHT11_PIN))==0)
	while(PINB & (1<<DHT11_PIN));
}

uint8_t Receive_data()					/* Receive data */
{
	for (int q=0; q<8; q++)
	{
		while((PINB & (1<<DHT11_PIN)) == 0);	/* Receive bit check (0 or 1) */
		_delay_us(30);
		if(PINB & (1<<DHT11_PIN))		/* If high pulse is greater than 30 ms */
		c = (c<<1)|(0x01);			/* then it's logic HIGH */
		else					/* otherwise, it's logic LOW */
		c = (c<<1);
		while(PINB & (1<<DHT11_PIN));
	}
	return c;
}

int main(void)
{	
	USART_init (9600);
	ADC_init();					/* ADC initialization */
	lcd_init(LCD_DISP_ON);				/* LCD initialization */
	_delay_ms(1000);						
	
	DDRB = 0xff;					/* Set PortB as output, except PB5 */
	PORTB = 0b00000001;				/* Set PortB as "0" */
	DDRA = 0x00;					/* Set PortA as input */

	lcd_gotoxy(0,0);				/* Set cursor to 1. row (row0) and 1. character */
	lcd_puts("Welcome");
	_delay_ms(1000);
	
	while (1)
	{
		A0value = ADC_read (0);			/* Reading analog value of humidity sensor from pin A0 */
		A0value = 100-((A0value/1023)*100);	/* Percent calculation */
		float A0copy = A0value;
		
		if (A0value < 50)			/* If humidity is lower than 50 % */
		{
			PORTB |= (1<<PB1);		/* turn LED on */
		}
		else
		{
			PORTB &=~ (1<<PB1);		/* otherwise, turn LED off */
		}

		sprintf(A0string, "Soil humidity (0): %d", (int) A0value);
		USART_message(A0string);
		USART_send(10);
		USART_send(13);
		

		A1value = ADC_read (1);			/* Reading analog value of humidity sensor from pin A1 */
		A1value = 100-((A1value/1023)*100);	/* Percent calculation */
		float A1copy = A1value;
		
		if (A1value < 50)			/* If humidity is lower than 50 % */
		{
			PORTB |= (1<<PB3);		/* turn LED on */
		}
		else
		{
			PORTB &=~ (1<<PB3);		/* otherwise, turn LED off */
		}
		
		sprintf(A1string, "Soil humidity (1): %d  \r\n", (int) A1value);
		USART_message(A1string);
		USART_send(10);
		USART_send(13);
		
		averageValue = (A0copy+A1copy)/2;
		sprintf(averageString, "%d ", (int) averageValue);
		
		if ((A0copy < 50) && (A1copy < 50))	/* If humidity is lower than 50 % */
		{
			lcd_gotoxy(0,0);					
			lcd_puts("Soil humidity:");
			lcd_gotoxy(0,1);
			lcd_puts(averageString);
			lcd_gotoxy(2,1);
			lcd_puts(" %          ");
			_delay_ms(200);
			
			PORTB |= (1<<PB4);		/* Turn on relay on pin PB4 which drives solenoid for water irrigation */
			_delay_ms(10000);		/* Wait for 10 seconds */
			PORTB &=~ (1<<PB4);		/* Set pin LOW */
			_delay_ms(5000);		/* Wait for 5 seconds */
		}
		else
		{
			PORTB &=~ (1<<PB4);		/* otherwise, set pin LOW */
		}
		
		_delay_ms(200);	
		Request();				/* Send start pulse */
		Response();				/* Receive response */
		I_RH = Receive_data();			/* Store first eight bits in I_RH */
		D_RH = Receive_data();			/* Store next eight bits in D_RH */
		I_Temp = Receive_data();		/* Store next eight bits in I_Temp */
		D_Temp = Receive_data();		/* Store next eight bits in D_Temp */
		CheckSum = Receive_data();		/* Store next eight bits in CheckSum */
		
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)	
		{
			lcd_gotoxy(0,0);
			USART_message("Error");
			USART_send(10);
			USART_send(13);
		}
		
		else
		{
			itoa(I_RH,humString,10);	/* Convert first 8 bits to string */
			USART_message("Air humidity: ");	
			USART_message(humString);	/* Send data via USART */
			USART_message(".");
			itoa(D_RH,humString2,10);	/* Convert next 8 bits to string */
			USART_message(humString2);	/* Send data via USART */
			USART_message("%");
			USART_send(10);
			USART_send(13);
			itoa(I_Temp,tempString,10);	/* Convert next 8 bits to string */
			USART_message("Temperature: ");
			USART_message(tempString);			
			USART_message(".");
			itoa(D_Temp,tempString2,10);	/* Convert next 8 bits to string */	
			USART_message(tempString2);			
			USART_message("C ");
			USART_send(10);
			USART_send(13);
			itoa(CheckSum,checkString,10);	/* Convert next 8 bits to string */	
			USART_message("Checksum: ");
			USART_message(checkString);			
			USART_message(" ");
			USART_send(10);
			USART_send(13);
		}
		
		/* Show humidity and temperature values on LCD screen */
		
		lcd_gotoxy(0,0);						
		lcd_puts("Soil humidity:");
		lcd_gotoxy(0,1);
		lcd_puts(averageString);
		lcd_gotoxy(2,1);
		lcd_puts(" %          ");
		_delay_ms(1500);
		
		if (I_Temp != 0)
		{
			lcd_clrscr();
			lcd_gotoxy(0,0);
			lcd_puts("Temperature:");
			lcd_gotoxy(0,1);
			lcd_puts(tempString);
			lcd_gotoxy(3,1);
			lcd_puts("C   ");
			_delay_ms(1000);
		}	
	}
	return 0;
}
