#include<stdio.h>

void sort(int *input, int len){
	int i, count = 0;
	for (i = 0; i < len; i++){
		if (input[i] == 0)
			count++;
	}
	for (i = 0; i < count; i++){
		input[i] = 0;
	}
	for (i = count; i < len; i++){
		input[i] = 1;
	}

	for (i = 0; i < len; i++){
		printf("%d ", input[i]);
	}
	

}