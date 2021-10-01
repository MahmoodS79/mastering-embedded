/*
 * main.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Sence79
 */
#include <stdio.h>
#include <stdint.h>
#include "fifo.h"

element_type buffer [5];



int main(){
	sfifo1_t* _fifo;element_type temp;
	fifo_buffer_init(_fifo,5,buffer);

		for(element_type i=0;i<5;i++)
			fifo_buffer_enqueue(_fifo,i);

    fifo_print_all(_fifo);
    fifo_buffer_dequeue(_fifo,&temp);
    fifo_print_all(_fifo);


return 0;

}
