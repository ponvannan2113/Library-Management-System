#include "lms.h"
void remove_book(struct st **ptr)
{
	char op, confirm;
	char bname[100];
	char buf[20];
	int bid;
	struct st *temp, *prev;
	printf("\n");
	printf("\t\t+----------------------------+\n");
	printf("\t\t|        REMOVE BOOK         |\n");
	printf("\t\t+----------------------------+\n");
	printf("\t\t|     A. BY BOOK ID          |\n");
	printf("\t\t|     B. BY BOOK NAME        |\n");
	printf("\t\t|     C. BACK TO MENU        |\n");
	printf("\t\t+----------------------------+\n");
	printf("CHOOSE THE OPTION : ");
	scanf(" %c",&op);
	switch(op|32)
	{
		case 'a':
			printf("Enter Book ID : ");
			scanf("%d",&bid);
			sprintf(buf,"%d",bid);
			// Display matching book 
			print_books(*ptr,1,buf);
			printf("\nDELETE THIS BOOK (Y/N) : ");
			scanf(" %c",&confirm);
			if((confirm|32)!='y')
			{
				printf("\nDELETE OPERATION CANCELLED\n");
				return;
			}
			temp=*ptr;
			prev=NULL;
			while(temp)
			{
				if(temp->bid==bid)
				{
					if(temp==*ptr)
						*ptr=temp->next;
					else
						prev->next=temp->next;
					free(temp);
					printf("\nBOOK DELETED SUCCESSFULLY\n");
					return;
				}
				prev=temp;
				temp=temp->next;
			}
			printf("\nBOOK ID NOT FOUND\n");
			break;
		case 'b':
			printf("Enter Book Name : ");
			scanf(" %[^\n]",bname);
			// Display all matching books 
			print_books(*ptr,2,bname);
			printf("\nENTER THE BOOK ID TO DELETE : ");
			scanf("%d",&bid);
			temp=*ptr;
			prev=NULL;
			while(temp)
			{
				if(temp->bid==bid)
				{
					printf("\nDELETE THIS BOOK (Y/N) : ");
					scanf(" %c",&confirm);
					if((confirm|32)=='y')
					{
						if(temp==*ptr)
							*ptr=temp->next;
						else
							prev->next=temp->next;
						free(temp);
						printf("\nBOOK DELETED SUCCESSFULLY\n");
					}
					else
					{
						printf("\nDELETE OPERATION CANCELLED\n");
					}
					return;
				}
				prev=temp;
				temp=temp->next;
			}
			printf("\nBOOK ID NOT FOUND\n");
			break;
		case 'c':
			return;
		default:
			printf("\nINVALID OPTION\n");
	}
}
