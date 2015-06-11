#define F_CPU 16000000UL
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 

int delay_time;
void BEEP(uint16_t time, uint16_t freq);
void BEEP2(int time);
void SILENCE(uint16_t time);
void BLINK();

void delay_ms(int xms)
{
    while(xms){
        _delay_ms(0.96);
        xms--;
    }
}

void delay_us(int xms)
{
    while (xms) {
        _delay_us(0.096);
        xms--;
    }
}

ISR(INT0_vect) 
{

    delay_time = 0;
   /* 
    BEEP(200, 100);
    SILENCE(200);
    BEEP(200, 500);
    BEEP(200, 100);
    BEEP(200, 150);
    SILENCE(200);
    BEEP(200, 500);
    BEEP(200, 250);
    BEEP(200, 100);
    SILENCE(200);
    BEEP(200, 500);
    BEEP(200, 100);
    SILENCE(200);
    BEEP(200, 500);

    BEEP(200, 500);
    BEEP(200, 100);
    SILENCE(200);
    BEEP(200, 500);

    BEEP(200, 800);
    BEEP(200, 1000);
    SILENCE(200);
    BEEP(200, 400);
    BEEP(200, 540);
    BEEP(200, 100);
    SILENCE(200);
    BEEP(200, 150);
    BEEP(200, 250);
    BEEP(200, 200);
    SILENCE(200);
    BEEP(200, 500);

    SILENCE(1000);
    
    BEEP(200, 500);
    BEEP(200, 1000);
    BEEP(200, 155);
    BEEP(200, 125);
    BEEP(200, 253);
    BEEP(200, 100);
    BEEP(200, 1000);
    BEEP(200, 500);


     SILENCE(1000);
    
    BEEP(200, 500);
    BEEP(200, 1000);
    BEEP(200, 100);
    BEEP(200, 125);
    BEEP(200, 253);
    BEEP(200, 100);
    BEEP(200, 1000);
    BEEP(200, 500);
*/
    uint16_t i =0;
    uint16_t freq = 0;
    uint16_t time = 0;
    for ( i =10 ; i<25000; i++) {
        //BEEP2(255);
        freq = rand() % 10000 +i;
        time = rand() % 10 + 30;
        if (freq > 100000) {
            freq = freq/100;
        }
        BEEP(time , freq);
        SILENCE( rand() % 100);
    }
    delay_time = rand() % 5000 + 10000;
   
}

void BLINK() 
{
    PORTD |= _BV(PD1);
    delay_us(delay_time);
    PORTD &= ~_BV(PD1);
    delay_us(delay_time);
}

void SILENCE(uint16_t time){
    uint16_t i = 0;
    for (i=0; i< time; i++) {
        delay_us(1000);
    }
}

void BEEP(uint16_t time, uint16_t freq)
{
    uint16_t i = 0;
    for (i = 0; i< time; i++) {
        PORTD |= _BV(PD7);
        delay_us(freq);
        PORTD &= ~_BV(PD7);
        delay_us(freq);
    }
}

void BEEP2(int time)
{
    int i =0;
    for (i = 0; i< time; i++) {
        PORTD |= _BV(PD7);
        delay_ms(2);
        PORTD &= ~_BV(PD7);
        delay_ms(2);
    }
}


int main(void) {
    MCUCR = (1<<ISC01) | (1<<ISC00); 
    GICR |= (1<<INT0);
    sei();
    delay_time = 500;
    DDRD = 0xfb;
    while (1) {
        //        BLINK(delay_time);
    }
    return 1;
}
