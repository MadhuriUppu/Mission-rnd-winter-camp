#include "functions.h"

struct node{
	int data;
	struct node* next;
};

node *mergesll(struct node *root1, struct node *root2)
{
	struct node *result = NULL;
	if (root1 == NULL)
	{
		return root2;
	}
	if (root2 == NULL)
	{
		return root1;
	}
	if (root1->num <= root2->num)
	{
		result = root1;
		result->next = merge_SLL(root1->next, root2);
	}
	else if (root2->num <= root1->num)
	{
		result = root2;
		result->next = merge_SLL(root1, root2->next);
	}
	return result;
}
