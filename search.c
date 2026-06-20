#include "lms.h"
void search_book(struct st *ptr)
{
	char sch,chh;
	char name[100];
	int id;
	printf("\n");
	printf("\t\t+----------------------------+\n");
	printf("\t\t|        SEARCH BOOK         |\n");
	printf("\t\t+----------------------------+\n");
	printf("\t\t|     A. BY BOOK ID          |\n");
	printf("\t\t|     B. BY BOOK NAME        |\n");
	printf("\t\t|     C. BY AUTHOR NAME      |\n");
	printf("\t\t|     D. BACK TO MAIN MENU   |\n");
	printf("\t\t+----------------------------+\n");
	printf("CHOOSE THE OPTION : ");
	scanf(" %c",&sch);
	switch(sch|32)
	{
		case 'a':
			{
				char buf[20];
				printf("Enter Book ID : ");
				scanf("%d",&id);
				sprintf(buf,"%d",id);
				print_books(ptr,1,buf);
				break;
			}
		case 'b':
			printf("Enter Book Name : ");
			scanf(" %[^\n]",name);
			print_books(ptr,2,name);
			break;
		case 'c':
			printf("Enter Author Name : ");
			scanf(" %[^\n]",name);
			print_books(ptr,3,name);
			break;
		case 'd':
			return;
		default:
			printf("\nINVALID OPTION\n");
	}
}
