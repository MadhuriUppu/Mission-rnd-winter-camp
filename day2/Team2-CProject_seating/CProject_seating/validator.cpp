#include "function_headers.h"

struct node{
	int row;
	int col;
	int data;
	struct node *next;
};

node* validate_and_insert(struct node* root, int row, int col, int data, int total_cols, int *is_valid, node** row_begin_node){
	
	if (col + data > total_cols){
		*is_valid = 0;
		return root;
	}

	node* temp = root;
	node* prev = NULL;

	node* newnode = new node;
	newnode->col = col;
	newnode->row = row;
	newnode->data = data;
	newnode->next = NULL;

	if (root == NULL)
		return newnode;

	while (temp != NULL && temp->row <= row){ //loop until a node with greater row or NULL is reached
		if (temp->row == row && *row_begin_node == NULL){ //assigning starting of a row to row_begin_node
			if (col < temp->col)
				*row_begin_node = newnode;
			else
				*row_begin_node = temp;
		}
		if (temp->row >= row && temp->col > col){
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (prev == NULL){ //INSERT AT FIRST
		if (newnode->row == row && newnode->col + newnode->data > temp->col){
			*is_valid = 0;
			return root;
		}
		newnode->next = temp;
		return newnode;
	}
	else if (temp == NULL){
		if (prev->row == row && prev->col + prev->data > col){
			*is_valid = 0;
			return root;
		}
		prev->next = newnode;
		newnode->next = NULL;
		return root;
	}
	
	else if (prev->row == row && prev->data + prev->col <= col){

		int dist=0;
		if (prev->next->row != row)
			dist = total_cols;
		else
			dist = prev->next->col;
		if (prev->data + prev->col + data <= dist){
			newnode->next = prev->next;
			prev->next = newnode;
			return root;
		}
		else{
			*is_valid = 0;
			return root;
		}
	}
	else if (prev->row != row){
		newnode->next = prev->next;
		prev->next = newnode;
		return root;
	}

	*is_valid = 0;
	return root;
}

