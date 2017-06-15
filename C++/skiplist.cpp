#include <stdio.h>
#include <stdlib.h>

#define MAXLEVEL 16
typedef struct linkNode* node;

typedef struct linkNode{
	int value;
	node* forwards;     
}requires_name;

typedef struct Link{
	int level; // current hight of list
	int size;
	node head;

}list;

int randLevel();
void showList(const list*);
bool find(list*, int);

list* newList(){
	list* l;
	l = (list*)malloc(sizeof(list));
	l->head = (node)malloc(sizeof(struct linkNode));
	l->head->forwards = (node*)malloc(sizeof(struct linkNode)*MAXLEVEL);
	l->level = 1;
	l->size = 0;
	int i;
	for(i = 0; i < MAXLEVEL; i++){ 
		l->head->forwards[i] = NULL;
	}
	return l;
}
//insert element
bool insert(list* l, int value){
	int k = l->level;
	node p, q;
	p = l->head;
	node update[MAXLEVEL];
	while(k > 0){
		while((q = p->forwards[k - 1])!=NULL && q->value < value){
			p = q;
		}
		update[k - 1] = p;
		k--;
	}
	if(NULL != q && q != l->head->forwards[0] && q->value == value){
		printf("value: %d is exists in the SkipList!\n", value);
		return false;
	}
	int nk = randLevel();
	if(nk >= l->level){
		nk = l->level;
		l->level++;
		update[nk - 1] = l->head;
	}
	node newN = (node)malloc(sizeof(struct linkNode));

	newN->value = value;
	newN->forwards = (node*)malloc(sizeof(struct linkNode)*nk);
	while(nk > 0){
		newN->forwards[nk - 1] = update[nk - 1]->forwards[nk - 1];
		update[nk - 1]->forwards[nk - 1] = newN;
		nk--;
	}
	return true;
}
// delete a node by value
bool del(list* l, int value){
	/*if(!find(l, value)){
		printf("value : %d does not exists!\n", value);
		return;
	}*/
	int k = l->level;
	int m = k;
	node p, q;
	p = l->head;
	node update[MAXLEVEL];
	while(k > 0){
		while((q = p->forwards[k - 1]) != NULL && q->value < value)
			p = q;
		update[k - 1] = p;
		k--;
	}
	if(NULL != q && q->value == value){
		for(k = 1; k <= m && ((p = update[k - 1])->forwards[ k - 1] == q); k++){
			p->forwards[k - 1] = q->forwards[k - 1];
		}
		free(q);
		while(m > 1 && l->head->forwards[m - 1] == NULL){
			m--;
			l->level--;
		}
		if(m > 1){
			l->level++;
		}
		return true;
	}
	printf("value: %d does not exists!\n", value);
	return false;
}
bool find(list* l, int value){
	int k = l->level;
	node p, q;
	p = l->head;
	while(k > 0){
		q = p -> forwards[k - 1];
		if(q == NULL){
			k--;
			continue;
		}
		if(q -> value < value){
			p = q;
		}else if(q -> value == value){
			return true;
		}
		k--;
	}
	return false;
}
void showList(const list* l){
	int k = l->level;
	node p, q;
	p = l->head;
	while(k > 0){
		printf("%d    ", k);
		q = p;
		while((q = q->forwards[k - 1]) != NULL){
			printf("%d-->", q->value);
		}
		printf("\n");
		k--;
	}
}

int randLevel(){
	int k = 1 + rand()%MAXLEVEL;
	return k;
}

int main(){
	list* l;
	l = newList();
	insert(l, 2);
	insert(l, 42);
	insert(l, 52);
	insert(l, 12);
	insert(l, 92);
	insert(l, 22);
	insert(l, 32);
	insert(l, 72);
	showList(l);
	printf("%d\n", find(l, 67));
	printf("%d\n", find(l, 12));
	printf("%d\n", find(l, 1));
	printf("%d\n", find(l, 2));
	printf("%d\n", find(l, 1232));
	printf("%d\n", find(l, 92));
	del(l, 172);
	del(l, 2);
	del(l, 42);
	del(l, 52);
	del(l, 12);
	del(l, 92);
	del(l, 22);
	del(l, 92);
	showList(l);
}