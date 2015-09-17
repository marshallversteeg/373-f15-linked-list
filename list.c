#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	int a = new_element->index;
	list_t * ptr = head;
	list_t* ptr_prev;
	int b = ptr->index;
	if(a <= b){
		new_element->next = head;
		head = new_element;
		return head;
	}
	while(a > b){
		if(ptr->next == NULL){
			ptr->next = new_element;
			new_element->next = NULL;
			return head;
		}
		ptr_prev = ptr;
		ptr = ptr->next;
		b = ptr->index;
	}
	ptr_prev->next = new_element;
	new_element->next = ptr;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* prev = NULL;
	list_t* ptr = head;
	list_t* nxt = ptr->next;
	while(nxt != NULL){
		ptr->next = prev;
		prev = ptr;
		ptr = nxt;
		nxt = ptr->next;
	}
	ptr->next = prev;
	head = ptr;
	return head;
}

