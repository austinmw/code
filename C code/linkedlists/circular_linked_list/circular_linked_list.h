#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

typedef struct cll_node {
	int data;
	struct cll_node *next;
} CLL_Node;

CLL_Node * CLL_Create(int data);	
int CLL_Length(CLL_Node *head);
void CLL_Print(CLL_Node *head);





void CLL_Push_Front(CLL_Node **head, int data);
void CLL_Push_Back(CLL_Node **head, int data);
int CLL_Pop_Front(CLL_Node **head);
int CLL_Pop_Back(CLL_Node **head);









#endif // CIRCULAR_LINKED_LIST_H_