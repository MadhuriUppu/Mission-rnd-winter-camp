
//step 1 : Take INFIX expression INPUT from user.
//step 2 : Convert INFIX to POSTFIX.
//step 3 : Push POSTFIX EXPRESSION onto STACK.
//step 4 : Evaluate using algorithm and display steps 

#include <stdio.h>
#include <stdlib.h>

void push(char);
void push_int(int);

int pop_int();
char pop();
char peek();
void display();

int top = -1;//initial value is -1.
int top_int = -1;
int size = 30;

int eval[30];// integer stack
char element[30];//used for stack purpose only
char postfixExp[30];//array which stores post fix expression.

//char posfixEval[30][16];// 30 row ,Each considered a STRING with capacity of  holding 16 characters.
int precede(char);
int isEmpty();
int isFull();
int length(char a[]);
int len = 0;

void convert_postfix(char *str);
void postfix_eval(char c[]);

int main()
{
	char choice[30];
	char tmp;
	int i = 0;

	printf("\n Please enter INFIX EXPRESSION : ");
	printf("\n Caution : only Variables and binary operators are allowed.\n ");
	printf("\n \n INPUT : ");


	gets_s(choice);// %s - escape sequence for STRING.    
	//step - 1.
	//printf("\n infix : %s \n",choice);

	convert_postfix(choice);//step 2
	printf("\n Postfix Expression : %s \n \n", postfixExp);
	//printf("\n Postfix Expression : %s \n",postfixExp);
	//if postfixExp[] is assigned '#' then invalid INFIX EXPRESSION GIVEN 
	//else proceed to evaluation.

	postfix_eval(postfixExp);
	getchar();
	getchar();
	getchar();
	return 0;
}// end of main method.

void postfix_eval(char c[])
{
	top_int = -1;//Virtually emptying integer stack.
	int i, x, y, res = 0;

	for (i = 0; i<length(c); i++)//loading empty stack with postfix Expression.
	{
		if ((c[i] >= 'a'&&c[i] <= 'z') || (c[i] >= 'A'&&c[i] <= 'Z'))
		{
			printf("\n Enter value of %c  :", c[i]);
			scanf_s("%d", &x);
			push_int(x);
		}
		else
		{
			y = pop_int();
			x = pop_int();

			switch (c[i])
			{
			case '*': res = x*y;
				break;
			case '+':res = x + y;
				break;
			case '-':res = x - y;
				break;
			case '/':res = x / y;
				break;
			}

			push_int(res);


		}

	}

	printf("\n RESULT : %d \n", pop_int());

}


int precede(char c)// order  :  / > * > + > - , bodmas rule ,Unary operatora not allowed
{
	switch (c){

	case '(':
	case ')':
		return 0;
	case '%':
		return 1;
	case '+':
		return 2;
	case '-':
		return 3;
	case '>':
		return 4;
	case '<':
		return 5;
	case '*':
		return 6;
	case '/':
		return 7;


	}

}

void convert_postfix(char *a)
{
	int i, j = 0;
	char c;
	for (i = 0; i<length(a); i++)
	{

		if (true) //only bodmas operators allowed.
		{

			if (precede(a[i]) >= precede(element[top])) //Incoming operator has higher precedence. 
			{
				// printf("\n Higher precencedence occured  with %c \n",a[i]);
				push(a[i]);
			}
			else if ((precede(a[i]) < precede(element[top])) && (element[top] != '(' || element[top] != ')'))  //Incoming operator has Lower precedence.        
			{
				// printf("\n Lower precencedence occured  with %c \n",a[i]);
				postfixExp[len] = pop();
				len++;
				i--;// for testing against NEW top of stack.
			}
		}
		else if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{

			while (element[top] != '(' && top >= 0)
			{

				c = pop();

				postfixExp[len] = c;
				len++;

			}//Loop breaks when left paranthesis is encountered.
			pop();// popping left paranthesis.

		}
		else if ((a[i] >= 'a'&&a[i] <= 'z') || (a[i] >= 'A'&&a[i] <= 'Z'))
		{
			postfixExp[len] = a[i];
			len++;
		}
		else
		{
			printf("\n INVALID INFIX EXPRESSION");
			postfixExp[0] = '#';
			break;
		}


	}//end of for loop. 

	while (top >= 0 && element[top] != '(')
	{
		postfixExp[len] = pop();
		len++;
	}//Popping elements until left paranthesis is encountered.


}//end of method.

int length(char a[])
{
	int i = 0;
	for (i = 0; a[i] != '\0'; i++)// '\0' is NULL character
	{
		i++;
		if (a[i] == '\0')
		{
			return i;
		}
	}
}

void display()
{
	printf("\n INT stack from bottom to top : ");
	int i;

	for (i = 0; i <= top_int; i++)
	{
		printf(" %c \t", eval[i]);
	}

	printf("\n ");

}

char pop()// returns topmost element and also removes it from top.
{
	int c = 0;
	if (isEmpty())
	{
		// printf("INVALID  POP OPERATION :STACK IS EMPTY ");
		return('#');
	}
	else
	{
		c = top;
		top--;
		return (element[c]);
	}

}

int pop_int()// returns topmost element and also removes it from top of INTEGER STACK
{
	int c = 0;

	c = top_int;
	top_int--;

	return (eval[c]);

}

char peek()// returns topmost element and also removes it from top.
{

	if (isEmpty())
	{
		// printf("INVALID  POP OPERATION :STACK IS EMPTY ");
		return('#');
	}
	else
	{
		return (element[top]);
	}

}


void push(char c)
{
	if (isFull())
	{
		printf("INVALID PUSH OPERATION: STACK OVERFLOW \n");
	}
	else
	{
		top++;
		element[top] = c;
	}

}

void push_int(int c)
{

	top_int++;
	eval[top_int] = c;

}

int isEmpty()
{
	if (top == -1)
	{
		return 1;// true
	}
	else
	{
		return 0;    //false
	}


}

int isFull()
{
	if (top == (size - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


