#include "mbed.h"


DigitalOut blue(LED3);
EventQueue queue_LED;

void blink()
{
    blue=!blue;
}

int main()
{
    //can use ticker.attach(.....) too
    //ticker.attach()
    queue_LED.call_every(500,blink);
    queue_LED.dispatch();
    return 0;
}