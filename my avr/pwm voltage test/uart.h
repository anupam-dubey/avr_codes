/*
===================================================================
SET DESIRED BAUD RATE
===================================================================
*/

#define BAUDRATE 9600
/*
===================================================================
CALCULATE UBRR VALUE
===================================================================
*/
#define UBRRVAL ((F_CPU/(BAUDRATE*16UL))-1)

void USART_INIT(void)
{
/*
===================================================================
SET BAUD RATE
===================================================================
*/
	UBRRL=UBRRVAL;
	UBRRH=(UBRRVAL>>8);

/*===================================================================
SET DATAFRAME FORMAT : ASYNCHRONOUS MODE, NO PARITY, 1 START BIT, 8BIT
                       SIZE DATA	
===================================================================
*/
	UCSRC=(1<<URSEL)|(0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|(0<<USBS)|(1<<UCSZ1)|(1<<UCSZ0);
/*
===================================================================
ENABLE TRANSMITTER AND RECEIVER	
===================================================================
*/
	UCSRB=(1<<RXEN)|(1<<TXEN);
}

/*
===================================================================
FUNCTION TO WRITE CHARACTER
===================================================================
*/
void rswritechar(unsigned char c)
{
/*
===================================================================
WAIT FOR EMPTY TRANSMIT BUFFER
===================================================================
*/
	while(!(UCSRA&(1<<UDRE)));
	UDR=c; //SEND RECEIVED DATA BACK
	_delay_ms(1);
}

/*
===================================================================
FUNCTION TO READ CHARACTER
===================================================================
*/

unsigned char rsreadchar(void)
{
/*
===================================================================
WAIT UNTIL DATA IS AVAILABLE
===================================================================
*/
	while(!(UCSRA&(1<<RXC)))
	{	}
	return UDR;
}

/*
===================================================================
FUNCTION TO PRINT STRING
===================================================================
*/
void rsstr(char *s)
{
	while(*s)
	{
		rswritechar(*s);
		s++;
	
	}
}