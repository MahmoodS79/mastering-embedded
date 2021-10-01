#include <stdio.h>
#include "Uart.h"
#define UART0DR *((volatile unsigned int* const)(0x101f1000))

void Uart0DR_Recieving_String(unsigned char* string){

while (*string!='\0'){


UART0DR =(unsigned int)*string;

string++;

}
}