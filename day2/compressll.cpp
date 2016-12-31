
#include "functions.h"
struct node{
	unsigned int data;
	struct node* next;

};

node* compressll(unsigned int *array, int rows, int cols){
	node *list = NULL;
	list = insert(list, rows);
	list = insert(list, cols);
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (array[i*cols + j] == 1)
				list = insert(list, i*cols + j);
		}
	}
	return list;

}