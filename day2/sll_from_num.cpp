//create a linked list from number
/*#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *createnode(struct node *head, int num){
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
struct node *createlist(int num){
	int rem;
	struct node *head = NULL;
	while (num>0){
		rem = num % 10;
		head = createnode(head,rem);
		num = num / 10;
	}
	return head;
}
int main(){
	int num1;
	struct node *head1;
	printf("enter num1: ");
	scanf("%d", &num1);
	head1 = createlist(num1);
	while (head1 != NULL){
		printf("%d ", head1->data);
		head1 = head1->next;
	}
}*/