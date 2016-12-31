#include "function_headers.h"


struct node{
	int row;
	int col;
	int data;
	struct node *next;
};


struct node *compresslist(struct node *head, int row)
{
	printf("HI %d %d %d \n", head->row, head->col, head->data);
	struct node *temp = head;
	while (temp->next != NULL)
	{
		if (temp->row == temp->next->row)
		{
			if (temp->col + temp->data == temp->next->col)
			{
				temp->data = temp->data + temp->next->data;
				temp->next = temp->next->next;
			}
			else
				temp = temp->next;
		}
		else if (temp->row < temp->next->row){
			return head;
		}

	}

	return head;
}
