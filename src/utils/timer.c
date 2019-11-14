#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.h"

volatile uint32_t milliseconds = 0;

ISR(TIMER0_OVF_vect)
{
    milliseconds++;
}

void timer0_init(void)
{
    TCCR0A = 0;
    TCCR0B = (1 << CS01) | (1 << CS00);
    TCNT0 = 0;
    TIMSK0 = (1 << TOIE0); //enable overflow interrupt
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
    return (milliseconds - timer->start > timer->timeout);
}

void timer_stop(TTimer * timer)
{
    timer->isActive = false;
}

void timer_restart(TTimer * timer)
{
    timer->start = milliseconds;
}