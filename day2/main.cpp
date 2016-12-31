#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
struct node{
	unsigned int data;
	struct node* next;
};

node* insert(node *head, int element){
	
	node *cur = head;
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = element;
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



void display(node *head){
	node* cur = head;
	while (cur != NULL){

		printf("%d ", cur->data);
		cur = cur->next;

	}
	printf("\n");
}



int main(){
	

	//FOR MERGING SLL
	node* head1 = NULL;
	node* head2 = NULL;
	
	int array[] = {1, 3, 5, 7, 9, 10, 14};
	int array2[] = {1, 2, 4, 6};

	for (int i = 0; i < 5; i++){
		head1 = insert(head1, array[i]);
	}
	for (int i = 0; i < 6; i++){
		head2 = insert(head2, array2[i]);
	}

	mergesll(head1, head2);
	//display(head1);


	//FOR NUMBER TO SLL
	node *list = num_to_ll_wrapper(99999);
	//display(list);


	//FOR LARGEST SLL
	node *list2 = num_to_ll_wrapper(12456);
	int result = largestsll(list, list2);
	//printf("%d\n", result);

	//FOR MATRIX TO LL
	unsigned int matrix[4][4] = {
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 1 }

	};
	node* list3 = compressll(*matrix, 4, 4);
	//display(list3);


	//

	matrix_node *list_m1 = NULL;
	matrix_node *list_m2 = NULL;
	int matrix1[4][4] = {
		{ 0, 1, 0, 1 },
		{ 0, 0, 1, 1 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 }

	};
	int matrix2[4][4] = {
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 1 }

	};

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (matrix1[i][j] == 1)
			list_m1 = insert_matrix(list_m1, i, j, matrix1[i][j]);
		}
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (matrix2[i][j] == 1)
				list_m2 = insert_matrix(list_m2, i, j, matrix2[i][j]);
		}
	}
	m_display(list_m1);
	printf("\n");
	m_display(list_m2);
	printf("\n");
	m_display(list_m1);
	getchar();
	return 0;
}