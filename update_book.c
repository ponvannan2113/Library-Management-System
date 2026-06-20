#include "lms.h"
void update_book(struct st *ptr)
{
	struct st *temp = NULL;
	char uch;
	int bid, ch;
	char buf[20];
	char name[100];
	printf("\n");
	printf("\t\t+--------------------------+\n");
	printf("\t\t|    UPDATE BOOK DETAIL    |\n");
	printf("\t\t+--------------------------+\n");
	printf("\t\t|   A. BY BOOK ID          |\n");
	printf("\t\t|   B. BY BOOK NAME        |\n");
	printf("\t\t|   C. BACK TO MENU        |\n");
	printf("\t\t+--------------------------+\n");
	printf("CHOOSE THE OPTION : ");
	scanf(" %c",&uch);
	switch(uch|32)
	{
		case 'a':
			printf("Enter Book ID : ");
			scanf("%d",&bid);
			sprintf(buf,"%d",bid);
			print_books(ptr,1,buf);
			temp = ptr;
			while(temp)
			{
				if(temp->bid == bid)
					break;
				temp = temp->next;
			}
			break;
		case 'b':
			printf("Enter Book Name : ");
			scanf(" %[^\n]",name);
			print_books(ptr,2,name);
			temp = ptr;
			while(temp)
			{
				if(strcmp(temp->bname,name) == 0)
					break;
				temp = temp->next;
			}
			break;
		case 'c':
			return;
		default:
			printf("Invalid Option\n");
			return;
	}
	if(temp == NULL)
	{
		printf("Book Not Found\n");
		return;
	}
	printf("\n");
	printf("\t\t+--------------------------+\n");
	printf("\t\t|    UPDATE OPTIONS        |\n");
	printf("\t\t+--------------------------+\n");
	printf("\t\t|   1. BOOK NAME           |\n");
	printf("\t\t|   2. AUTHOR NAME         |\n");
	printf("\t\t|   3. QUANTITY            |\n");
	printf("\t\t|   4. UPDATE ALL          |\n");
	printf("\t\t+--------------------------+\n");
	printf("Enter Choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter New Book Name : ");
			scanf(" %[^\n]",temp->bname);
			break;
		case 2:
			printf("Enter New Author Name : ");
			scanf(" %[^\n]",temp->aname);
			break;
		case 3:
			printf("Enter New Quantity : ");
			scanf("%d",&temp->quantity);
			break;
		case 4:
			printf("Enter New Book Name : ");
			scanf(" %[^\n]",temp->bname);
			printf("Enter New Author Name : ");
			scanf(" %[^\n]",temp->aname);
			printf("Enter New Quantity : ");
			scanf("%d",&temp->quantity);
			break;
		default:
			printf("Invalid Choice\n");
			return;
	}
	printf("Book Updated Successfully\n");
}
