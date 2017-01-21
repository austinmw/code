// type anything, Ctrl+D to stop
/* Here is a program that initially reads the file into a linked list, and then allocates a vector of pointers of the right size. Each individual character does then appear as array[line][col] but in fact each row is only as long as it needs to be. It's C99 except for <err.h>. */
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strnode {
	char *s;
	struct strnode *next;
} strnode;

strnode *list_head;
strnode *list_last;

strnode *read1line(void) {
	char space[1024];
	if(fgets(space, sizeof space, stdin) == NULL)
		return NULL;
	strnode *node = malloc(sizeof(strnode));
	if(node && (node->s = malloc(strlen(space) + 1))) {
		strcpy(node->s, space);
		node->next = NULL;
		if (list_head == NULL)
			list_head = node;
		else
			list_last->next = node;
		list_last = node;
		return node;
	}
	err(1, NULL);
}

int main(int ac, char **av) {
	int n;
	strnode *s;

	for(n = 0; (s = read1line()) != NULL; ++n)
		continue;
	if(n > 0) {
		int i;
		strnode *b;
		char **a = malloc(n * sizeof(char *));
		printf("There were %d lines\n", n);
		for(b = list_head, i = 0; b; b = b->next, ++i)
			a[i] = b->s;
		printf("Near the middle is: %s", a[n / 2]);
	}
	return 0;
}
