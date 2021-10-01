/*
 * fifo.c
 *
 *  Created on: Sep 30, 2021
 *      Author: Sence79
 */


#include "FIFO.h"
#include "stdio.h"

evalid_t fifo_buffer_init(sfifo1_t*fifo ,int length,element_type*buffer){
	if(buffer == NULL)
		return LIFO_NULL;

	fifo->base=buffer;
	fifo->head=buffer;
	fifo->tail=buffer;
	fifo->count=0;
	fifo->length=length;
	return no_error;
};

evalid_t fifo_buffer_enqueue(sfifo1_t*fifo ,element_type item){
	if(!fifo->head || !fifo->tail || !fifo->base)
		return LIFO_NULL;
	if(fifo->count==fifo->length){
		printf("___is_full____");
		return is_full;
	}
	*(fifo->head)=item;
	fifo->count++;

	if(fifo->head == fifo->base+fifo->length*sizeof(element_type))
		fifo->head=fifo->base;
	else
		fifo->head++;



	printf("___enqueued %d___\n",item);
	return no_error;

};

evalid_t fifo_buffer_dequeue(sfifo1_t*fifo ,element_type*item){
	if(!fifo->head || !fifo->tail || !fifo->base)
		return LIFO_NULL;
	if(fifo->count==0){
		return is_empty;
		printf("Empty_fifo");
	}

	*item=*fifo->tail;
	fifo->count--;

	if(fifo->tail == fifo->base+(fifo->length*sizeof(element_type)))
		fifo->tail=fifo->base;
	else
		fifo->tail++;

	printf("___dequeued___%d\n",*item);
	return no_error;

};

void fifo_print_all(sfifo1_t*fifo){

	element_type* temp=fifo->tail;
	if(fifo->count!=0){
		printf("all_fifo_elements:\n");
	for(int i=0;i< fifo->count ;i++){
		printf("%d\n",*temp);
		temp++;
	}
	}
	else
		printf("empty_fifo");



}
