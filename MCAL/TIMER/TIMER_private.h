#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TCCR0 	(*((volatile u8*)(0x53))) /*timer0 control register*/
#define TCNT0 	(*((volatile u8*)(0x52)))
#define OCR0    (*((volatile u8*)(0x5C))) /*output comare register 0*/
#define TIMSK   (*((volatile u8*)(0x59))) /*timer mask*/
#define TIFR    (*((volatile u8*)(0x58)))


#define TCCR0_CS00 0            /*prescaler bit 0*/
#define TCCR0_CS01 1            /*prescaler bit 1*/
#define TCCR0_CS02 2            /*prescaler bit 2*/
#define TCCR0_WGM01 3           /*waveform generation bit1*/
#define TCCR0_COM00 4           /*Compare output mode bit0*/
#define TCCR0_COM01 5           /*Compare output mode bit1*/
#define TCCR0_WGM00 6           /*waveform generation bit0*/
#define TCCR0_FOC0  7           /*Force output compare "test"*/

#define TIMSK_TOIE0 0 /*timer overflow interrupt enable*/
#define TIMSK_OCIE0 1  /*output compare 0 interrupt enable*/
#define TIMSK_TOIE1 2
#define TIMSK_OCIE1B 3
#define TIMSK_OCIE1A 4
#define TIMSK_TICIE1 5
#define TIMSK_TOIE2 6
#define TIMSK_OICE2 7


#define  TIFR_TOV0  0
#define  TIFR_OCF0  1
#define  TIFR_TOV1  2
#define  TIFR_OCF1B 3
#define  TIFR_OCF1A 4
#define  TIFR_ICF1  5
#define  TIFR_TOV2  6
#define  TIFR_OCF2  7


#endif 