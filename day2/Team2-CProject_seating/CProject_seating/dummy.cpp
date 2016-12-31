/*
#include<malloc.h>

struct node{
int row;
int col;
int data;
struct node *next;
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



*/