#include "mbed.h"
#include "mbed_events.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
InterruptIn btn(SW2);

EventQueue queue_low;
EventQueue queue_high;

void print_high()
{
  printf("1\r\n");
}

void print_low ()
{
  printf("2\r\n");
}

/*
void btn_fall_irq() {
  led1 = !led1;

  // defer the printf call to the low priority thread
  printfQueue.call(&print_toggle_led);
}
*/

int main() 
{
  Thread low(osPriorityLow);
  Thread high(osPriorityHigh);

  queue_low.call(print_low);
  queue_high.call(print_high);
  
  low.start(callback(&queue_low, &EventQueue::dispatch_forever));
  high.start(callback(&queue_high, &EventQueue::dispatch_forever));

  


  
}