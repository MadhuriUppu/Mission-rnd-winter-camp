#include <stdlib.h>
#include <stdio.h>
struct node;
node* validate_and_insert(struct node* root, int row, int col, int data, int total_cols, int* is_valid, node**);
struct node *compresslist(struct node *head, int row);
void display_seating(node* list, int rows, int cols);
void display_list(node *head);