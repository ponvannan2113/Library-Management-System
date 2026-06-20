//------- Show all the list -----//
#include "lms.h"
void view_all(struct st *ptr)
{
	if(ptr == NULL)
	{
		printf("\nTHERE ARE NO BOOKS IN LIBRARY\n");
		return;
	}
	int max_book = strlen("BOOK NAME");
	int max_author = strlen("AUTHOR NAME");
	struct st *temp = ptr;
	// Find maximum lengths 
	while(temp)
	{
		int len_book = strlen(temp->bname);
		int len_author = strlen(temp->aname);
		if(len_book > max_book)
			max_book = len_book;
		if(len_author > max_author)
			max_author = len_author;
		temp = temp->next;
	}
	// Top Border 
	printf("\n+---------------+");
	for(int i=0;i<max_book+2;i++) printf("-");
	printf("+");
	for(int i=0;i<max_author+2;i++) printf("-");
	printf("+---------------+\n");
	// Header 
	printf("| %-13s | %-*s | %-*s | %-13s |\n","BOOK ID",max_book, "BOOK NAME",max_author, "AUTHOR NAME","QUANTITY");
	// Header Border
	printf("+---------------+");
	for(int i=0;i<max_book+2;i++) printf("-");
	printf("+");
	for(int i=0;i<max_author+2;i++) printf("-");
	printf("+---------------+\n");
	// Data 
	while(ptr)
	{
		printf("| %-13d | %-*s | %-*s |      %-8d |\n",ptr->bid,max_book, ptr->bname,max_author, ptr->aname,ptr->quantity);
		ptr = ptr->next;
	}
	// Bottom Border 
	printf("+---------------+");
	for(int i=0;i<max_book+2;i++) printf("-");
	printf("+");
	for(int i=0;i<max_author+2;i++) printf("-");
	printf("+---------------+\n");

}

