#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"

volatile uint32_t milliseconds = 0;

ISR(TIMER0_OVF_vect)
{
    cli();
    milliseconds++;
    sei();
}

ISR(TIMER1_OVF_vect)
{

}

void timer0_init(void)
{
    TCCR0A = 0;
    TCCR0B = (1 << CS01) | (1 << CS00);
    TCNT0 = 0;
    TIMSK0 = (1 << TOIE0); //enable overflow interrupt
}

void timer1_init(void)
{
    TCCR1A = 0;
    TCCR1B = (1 << CS12) | (1 << CS10); //1024
    TCCR1C = 0;
    TCNT1 = 0;
    TIMSK1 = (1 << TOIE1); //enable overflow interrupt
}

void timer_start(TTimer * timer, uint32_t timeout)
{
    timer->isActive = true;
    timer->start = milliseconds;
    timer->timeout = timeout;
}

bool timer_check(TTimer * timer)
{
    if(!timer->isActive)
        return false;
    return ((milliseconds - timer->start) > timer->timeout);
}

void timer_stop(TTimer * timer)
{
    timer->isActive = false;
}

void timer_restart(TTimer * timer)
{
    timer->start = milliseconds;
}

