#include<stdio.h>
struct node;
struct matrix_node;
void sort(int *, int);
void get_row_and_col(int *array, int rows, int cols, int *row, int *col);
node* insert(node* list, int element);
struct node* mergesll(node* head1, node* head2);
node* num_to_ll_wrapper(int);
int largestsll(node*, node*);
node* matrixtoll(unsigned int *array, int rows, int cols);
node* compressll(unsigned int *array, int rows, int cols);
matrix_node* insert_matrix(matrix_node *head, int row, int col, int data);
void m_display(matrix_node *head);