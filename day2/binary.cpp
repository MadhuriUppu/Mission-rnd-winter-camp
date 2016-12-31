#include<stdlib.h>
#include<stdio.h>

int check(int *row_mask, int len, int skip, int *index){
	int count = 0;
	for (int i = 0; i < len; i++){
		if (row_mask[skip*i] == 1){
			count++;
			*index = i;
		}
	}
	return count;
}

int func(int a, int b){
	if (a == 1 && b == 1)
		return 1;
	else if (a == 0)
		return 0;
	else
		return b;
}


void get_row_and_col(int *array, int rows, int cols, int *row, int *col){

	int index = 0;
	int *row_mask = (int*)malloc(cols * sizeof (int));
	for (int i = 0; i < cols; i++)
		row_mask[i] = 1;
	int *col_mask = (int*)malloc(rows * sizeof (int));
	for (int i = 0; i < rows; i++)
		col_mask[i] = 1;
	for (int i = 0; i < rows; i++){
		int j;
		for (j = 0; j < cols; j++){
			if (check(array, cols, rows, &index) != 0)
				row_mask[j] = func(row_mask[j], array[i*cols + j]);
			else
				continue;
			if (check(row_mask, cols, 1, &index) == 1){
				*row = index;
				break;
			}
		}
		if (j != cols)
			break;
	}
	for (int i = 0; i < rows; i++){
		int j;
		for (j = 0; j < cols; j++){
			if (check(array, rows, cols, &index) != 0)
				col_mask[j] = func(col_mask[j], array[j*rows + i]);
			else
				continue;
			if (check(col_mask, cols, 1, &index) == 1){
				*col = index;
				break;
			}
		}
		if (j != cols)
			break;
	}

}