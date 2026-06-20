//--------Add a new book -------///
#include"lms.h"
void add_newbook(struct st **ptr)
{
	struct st *temp;
	temp=(struct st *)malloc(sizeof(struct st));
	printf("\nenter the book details\n");
	printf("\nenter the book name : ");
	scanf(" %[^\n]",temp->bname);
	printf("\nenter the name of author : ");
	scanf(" %[^\n]",temp->aname);
	printf("\nenter the quantity of the book : ");
	scanf("%d",&temp->quantity);
	temp->bid=++id;
	temp->next=0;
	if(*ptr==0)
		*ptr=temp;
	else
	{
		struct st *last=*ptr;
		while (last->next!=0)
			last=last->next;
		last->next=temp;
	}
}

