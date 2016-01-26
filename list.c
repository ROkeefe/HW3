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
	list_t* node = head;
	list_t* prev = NULL;
	if (new_element->index < head->index) {
		new_element->next = head;
		return new_element;
	}
	prev = node;
	node = node->next;
	while (node->next != NULL) {
		if (node->index > new_element->index) {
			prev->next = new_element;
			new_element->next = node;
			break;
		}
		prev = node;
		node = node->next;
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* prev = NULL;
	list_t* one = head;
	list_t* two;
	if (one != NULL)
		two = one->next;
	while (one != NULL) {
		two = one->next;
		one->next = prev;
		prev = one;
		one = two;
	}
	return prev;
}

