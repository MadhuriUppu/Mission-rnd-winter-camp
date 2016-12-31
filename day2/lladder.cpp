#include "functions.h"
#include<malloc.h>

struct matrix_node{
	int row;
	int col;
	int data;
	struct matrix_node *next;
};

void m_display(matrix_node *head){
	matrix_node* cur = head;
	while (cur != NULL){

		printf("(%d, %d, %d)-> ", cur->row, cur->col, cur->data);
		cur = cur->next;

	}
	printf("NULL\n");
}

matrix_node* insert_matrix(matrix_node *head, int row, int col, int data){

	matrix_node *cur = head;
	matrix_node *new_node = (matrix_node*)malloc(sizeof(matrix_node));
	new_node->data = data;
	new_node->row = row;
	new_node->col = col;
	new_node->next = NULL;
	if (head == NULL){
		return new_node;
	}
	while (cur->next != NULL){
		cur = cur->next;
	}
	cur->next = new_node;
	return head;
}

matrix_node* lladder(matrix_node* head1, matrix_node* head2){
	matrix_node *result = NULL;
	if (head1 == NULL)
	{
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	if (head1->row == head2->row)
	{
		if (head1->col == head2->col){ //both are same
			result = head1;
			result->next = lladder(head1->next, head2->next);
		}
		else if (head1->col < head2->col){
			result = head1;
			result->next = lladder(head1->next, head2);
		}
		else if (head1->col > head2->col){
			result = head2;
			result->next = lladder(head1, head2->next);
		}
	}
	else if (head1->row < head2->row){
		result = head1;
		result->next = lladder(head1->next, head2);
	}
	else if (head1->row > head2->row){
		result = head2;
		result->next = lladder(head1, head2->next);
	}
	return result;
	

}

