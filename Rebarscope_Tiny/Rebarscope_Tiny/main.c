/*
 * Rebarscope_Tiny.c
 *
 * Created: 3/7/2018 3:36:49 PM
 * Author : Mike Hoag
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h.>

#define CD1 PORTA7
#define CD2 PORTB2
#define W1  PORTA0
#define W2  PORTA1
#define W3  PORTA2
#define W4  PORTA3
#define W5  PORTB0
#define W6  PORTB1
#define BIT(x) ( 1<< (x) )
#define SETBIT(p, b) (p) |= BIT(b)
#define CLRBIT(p, b) (p) &= ~BIT(b)

#define CD1_TIME 116 //80 - 160 uS
#define CD2_TIME 103.5 //80 - 160 uS
#define W1_TIME  70.5  //60 - 100 uS
#define W2_TIME  55.5  //60 - 100 uS
#define W3_TIME  62.5  //60 - 100 uS
#define W4_TIME  63.5  //60 - 100 uS
#define W5_TIME  31.5  //20 - 50 uS
#define W6_TIME  10.0	 //half DT1
#define DT1		 24.5  //15 - 25 uS
#define DT2		 47.5  //15 - 25 uS
#define DT3		 26.0  // for large coil
#define DT4		 43.0 //
//#define W6_TiME  1   //place holder

int main(void)
{
	DDRB |= 0x0F; //set ports to outputs
	DDRA |= 0xFF;

	/* Replace with your application code */
	while (1)
	{
		SETBIT( PORTB, W6 );
		_delay_us( W6_TIME );
		SETBIT( PORTA, CD1 );
		_delay_us( CD1_TIME );
		CLRBIT( PORTA, CD1 );
		_delay_us( W6_TIME );
		CLRBIT( PORTB, W6 );

		_delay_us( DT1 );

		SETBIT( PORTA, W1 );
		_delay_us( W1_TIME );
		CLRBIT( PORTA, W1 );

		_delay_us( DT2 );

		SETBIT( PORTA, W2 );
		_delay_us( W2_TIME );
		CLRBIT( PORTA, W2 );

		SETBIT( PORTB, W5 );
		_delay_us( W5_TIME );
		CLRBIT( PORTB, W5 );

		SETBIT( PORTB, W6 );
		_delay_us( W6_TIME );
		SETBIT( PORTB, CD2 );
		_delay_us( CD2_TIME );
		CLRBIT( PORTB, CD2 );
		_delay_us( W6_TIME );
		CLRBIT( PORTB, W6 );

		_delay_us( DT1 );

		SETBIT( PORTA, W3 );
		_delay_us( W3_TIME );
		CLRBIT( PORTA, W3 );

		_delay_us( DT4 );

		SETBIT( PORTA, W4 );
		_delay_us( W4_TIME );
		CLRBIT( PORTA, W4 );

		SETBIT( PORTB, W5 );
		_delay_us( W5_TIME );
		CLRBIT( PORTB, W5 );
	}
	return 0;
}

