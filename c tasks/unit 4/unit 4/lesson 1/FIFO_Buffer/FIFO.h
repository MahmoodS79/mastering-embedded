/*
 * fifo.h
 *
 *  Created on: Sep 30, 2021
 *      Author: Sence79
 */

#ifndef FIFO_H_
#define FIFO_H_


#include <stdint.h>

#define element_type uint32_t



typedef struct{

	int count;
	int length;
	element_type* head; //the last element to enter
	element_type* tail; //the 1st element to enter
	element_type* base; //fixed to the base of the queue

}sfifo1_t,sfifo2_t;

typedef enum evalid_t{
	LIFO_NULL,is_full,is_empty,no_error

	}evalid_t;

extern evalid_t fifo_buffer_init(sfifo1_t*fifo ,int length,element_type*buffer);
extern evalid_t fifo_buffer_enqueue(sfifo1_t*fifo ,element_type item);
extern evalid_t fifo_buffer_dequeue(sfifo1_t*fifo ,element_type*item);
extern void fifo_print_all(sfifo1_t*fifo);

#endif /* fifo_H_ */
