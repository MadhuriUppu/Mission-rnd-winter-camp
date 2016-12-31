#include "function_headers.h"

struct node{
	int row;
	int col;
	int data;
	struct node *next;
};


void main(){
	int total_rows, total_cols, data=0, row=0, col=0;
	printf("Enter rows: ");
	//196 = vertical, 179 = horizontal
	scanf_s("%d", &total_rows);
	printf("Enter cols: ");
	scanf_s("%d", &total_cols);
	printf("Input format: row col data (Eg: 1 1 2)\n\n");
	node *list_m1 = NULL;
	node *row_begin_node = NULL;
	display_list(list_m1);
	
	while (1){
		row_begin_node = NULL;
		int valid = 1;
		fflush(stdin);
		printf("> ");
		scanf_s("%d %d %d", &row, &col, &data);
		if (row >= total_rows || col >= total_cols || data <= 0){
			printf("Enter valid input\n");
			continue;
		}
		if (row < 0 || col < 0)
			break;
		list_m1 = validate_and_insert(list_m1, row, col, data, total_cols, &valid, &row_begin_node);
		if(row_begin_node != NULL)
			row_begin_node = compresslist(row_begin_node, row);
		if (valid == 0){
			printf("Enter valid input\n");
			continue;
		}
		display_list(list_m1);
		display_seating(list_m1, total_rows, total_cols);
		
	}





}