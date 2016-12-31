//given two numbers in single linked list form..return the greatest
/*#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *createNode(struct node *head, int num){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = num;
	if (head == NULL){
		newNode->next = NULL;
		head = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
	return head;
}
struct node *createList(int num){
	int rem;
	struct node *head = NULL;
	while (num>0){
		rem = num % 10;
		head = createNode(head, rem);
		num = num / 10;
	}
	return head;
}
int compare(struct node *head1, struct node *head2){
	int flag = 0;
	while ((head1 != NULL) && (head2 != NULL)){
		if (head1->data < head2->data)
			flag = 2;
		else if (head2->data < head1->data)
			flag = 1;
		head1 = head1->next;
		head2 = head2->next;
	}
	if ((head1 != NULL) && (head2 == NULL))
		return 1;
	else if ((head1 == NULL) && (head2 != NULL))
		return 2;
	else
		return flag;
}
int main(){
	int num1, num2,len1=0,len2=0,flag;
	struct node *head1, *head2, *temp1,*temp2;
	printf("enter num1: ");
	scanf("%d", &num1);
	printf("\nenter num2: ");
	scanf("%d", &num2);
	head1 = createList(num1);
	head2 = createList(num2);
	flag = compare(head1, head2);
	if (flag == 1)
		printf("%d is greatest", num1);
	else if (flag == 2)
		printf("%d is greatest", num2);
	return 0;
}*/