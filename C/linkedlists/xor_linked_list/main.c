#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xordll.h"
int main()
{
	int  a = 1,b = 2,c = 3, d = 4, e =5;
	XORList * list = xorlist_create();

	xorlist_push_back(list, &a);
	xorlist_push_back(list, &b);
	xorlist_push_back(list, &c);
	xorlist_push_back(list, &d);
	xorlist_push_back(list, &e);

	printf("%p %p %p %p %p\n",&a,&b,&c,&d,&e);

	XORListIterator itr = xorlist_iterator_reverse(list);

	for( ;
		!xorlist_iterator_at_end(&itr);
		xorlist_iterator_next(&itr)) {

		printf("Current : %p\n",xorlist_iterator_curr(&itr));
	}

	for(xorlist_iterator_prev(&itr);
		!xorlist_iterator_at_begin(&itr);
		xorlist_iterator_prev(&itr)) {

		printf("Current : %p\n",xorlist_iterator_curr(&itr));
	}

	xorlist_destroy(list);

	return 0;
}