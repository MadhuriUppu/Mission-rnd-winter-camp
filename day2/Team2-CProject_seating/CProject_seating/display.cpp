#include "function_headers.h"

struct node{
	int row;
	int col;
	int data;
	struct node *next;
};

void display_list(node *head){
	node* cur = head;
	printf("List:\n");
	while (cur != NULL){
		printf("(%d, %d, %d)-> ", cur->row, cur->col, cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


void display_seating(node* list, int rows, int cols){

	node *cur = list;
	node *prev = NULL;
	int cur_row = 0;
	int cols_covered = 0;
	printf("Seating:\n");
	while (cur!= NULL){
		cols_covered = 0;
		printf("\t");
		while (cur != NULL && cur->row == cur_row){
			if (prev == NULL)
				for (int i = 0; i < cur->col; i++, cols_covered++)
					printf("0 ");
			else{
				if (prev->row == cur_row)
					for (int i = prev->col + prev->data; i < cur->col; i++, cols_covered++)
						printf("0 ");
				else
					for (int i = 0; i < cur->col; i++, cols_covered++)
						printf("0 ");
			}
			for (int i = cur->col; i < cur->col + cur->data; i++, cols_covered++)
				printf("1 ");
			prev = cur;
			cur = cur->next;
		}
		for (int i = cols_covered; i < cols; i++){
			printf("0 ");
		}
		cur_row++;
		printf("\n");
	}
	for (int i = cur_row; i < rows; i++){
		printf("\t");
		for (int j = 0 ; j < cols; j++){
			printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}