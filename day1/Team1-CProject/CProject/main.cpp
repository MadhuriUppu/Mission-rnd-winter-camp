//line 88 = add str to int loop


#include "FunctionHeaders.h"

int top = -1;//initial value is -1.
int top_int = -1;
int size = 1000;
int index = 0;

double postfix_eval_stack[1000]; //numbers in stack
char postfix_operator_stack[1000]; //used in converting to postfix
char output[1000]; 
double operands[1000]; //list of operands


int len = 0;


int isEmpty(){
	if (top == -1)
		return 1;
	else
		return 0;    
}

int isFull(){
	if (top == (size - 1))
		return 1;
	else
		return 0;
}


int main()
{
	char input[1000];
	printf("Enter exit to stop\n");
	while (1){
		printf("> ");
		gets_s(input);
		if (strcmp(input, "exit") == 0)
			break;
		if (test_and_convert_postfix(input, output, &len, postfix_operator_stack, &top, operands, &index) != 0)
			postfix_eval(output, postfix_eval_stack, &top_int, operands, &top);
		top = -1;
		top_int = -1;
		index = 0;
		len = 0;
	}
	printf("Press enter to quit\n");
	getchar();
	return 0;
}