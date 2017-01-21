#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xordll.h"

// Quick References:
// N.B. This is linear form from left to right, not traversal
//
// PREVPREV = XOR(CURR,PREV->LINK)
// PREV = XOR(CURR->LINK,NULL)
// NEXT = XOR(CURR->LINK,PREV)
// NEXTNEXT = XOR(CURR,NEXT->LINK)

struct _xornode_ {
	void * e;
	struct _xornode_ * npx;
};

struct _xorlist_ {
	XORNode * head;
	XORNode * tail;
	int size;
};


XORNode * xorlist_xor(XORNode * x, XORNode * y) {
	return (XORNode*) ((unsigned long)x ^ (unsigned long)y);
}

XORList * xorlist_create(void) {
	return (XORList*)calloc(1,sizeof(XORList));
}

void xorlist_destroy(XORList * list) {
	if(list == NULL)
		return;

	XORNode * curr = list->head;
	XORNode * prev = NULL;
	XORNode * next;

	while (curr != NULL) {
		next = xorlist_xor(prev, curr->npx);
		prev = curr;
		free(curr);
		curr = next;
	}

	memset(list, 0, sizeof(XORList));
	free(list);
}

void * xorlist_push_back(XORList * list, void * e) {
	if(list == NULL)
		return NULL;

	XORNode * node = (XORNode*)malloc(sizeof(XORNode));
	node->e = e;
	node->npx = xorlist_xor(list->tail, NULL);

	if(list->tail != NULL) {
		XORNode * next = xorlist_xor(list->tail->npx, NULL);
		list->tail->npx = xorlist_xor(node, next);
	} else {
		list->head = node;
	}

	list->size++;
	return (void*)(list->tail = node);
}

void * xorlist_pop_back(XORList * list) {
	if(list == NULL || list->tail == NULL)
		return NULL;

	XORNode * old = list->tail;
	void * old_e = old->e;

	XORNode * prev = xorlist_xor(NULL, list->tail->npx);
	XORNode * prevprev = xorlist_xor(list->tail, prev->npx);

	list->tail = prev;
	list->tail->npx = prevprev;

	free(old);
	list->size--;
	return old_e;
}


bool xorlist_is_empty(XORList * list) {
	return (list ? list->tail == NULL : true);
}

int xorlist_size(XORList * list) {
	return (list ? list->size : -1);
}


XORListIterator xorlist_iterator_forward(XORList * list) {
	XORListIterator itr = {0,0,0};

	if(list == NULL || xorlist_is_empty(list))
		return itr;

	itr.curr = list->head;
	itr.next = xorlist_xor(itr.prev, itr.curr->npx);
	return itr;
}

XORListIterator xorlist_iterator_reverse(XORList * list) {
	XORListIterator itr = {0,0,0};

	if(list == NULL || xorlist_is_empty(list))
		return itr;

	itr.curr = list->tail;
	itr.next = xorlist_xor(itr.prev, itr.curr->npx);
	return itr;
}

bool xorlist_iterator_at_end(XORListIterator * itr) {
	return (itr ? !itr->next && !itr->curr : false);
}

bool xorlist_iterator_at_begin(XORListIterator * itr) {
	return (itr ? !itr->prev && !itr->curr: false);
}

bool xorlist_iterator_has_next(XORListIterator * itr) {
	return (itr ? itr->next : false);
}

bool xorlist_iterator_has_prev(XORListIterator * itr) {
	return (itr ? itr->prev : false);
}

bool xorlist_iterator_has_curr(XORListIterator * itr) {
	return (itr ? itr->curr : false);
}

void * xorlist_iterator_next(XORListIterator * itr) {
	if(!itr || (!itr->curr && !itr->next))
		return NULL;

	if(!itr->curr)
		itr->curr = itr->prev;

	itr->next = xorlist_xor(itr->prev, itr->curr->npx);
	itr->prev = itr->curr;
	itr->curr = itr->next;

	if(itr->curr)
		itr->next = xorlist_xor(itr->prev, itr->curr->npx);

	return (itr->curr ? itr->curr->e : NULL);
}

void * xorlist_iterator_prev(XORListIterator * itr) {
	if(!itr || (!itr->curr && !itr->prev))
		return NULL;

	if(!itr->curr)
		itr->curr = itr->prev;

	itr->prev = xorlist_xor(itr->next, itr->curr->npx);
	itr->next = itr->curr;
	itr->curr = itr->prev;

	if(itr->curr)
		itr->prev = xorlist_xor(itr->next, itr->curr->npx);

	return (itr->curr ? itr->curr->e : NULL);
}

void * xorlist_iterator_curr(XORListIterator * itr) {
	return (itr && itr->curr ?
			(itr->curr ? itr->curr->e : NULL) :
			NULL);
}