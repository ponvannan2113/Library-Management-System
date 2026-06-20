#include"lms.h"
int id=0;
int sid=0;
int main()
{
	struct st *hptr=0;
	struct iss *ishptr=0;
	int n;
	char ch,w;
	load(&hptr);
	isload(&ishptr);
	if(hptr!=0)
	{
	struct st *last=hptr;
	while(last->next!=0)
		last=last->next;
	id=last->bid;
	}
	else
		id=25012008;
	while(1){
	printf("\n\n");
	printf("\t\t+-------------------------------+\t\t\n");
	printf("\t\t|     Book Management Menu      |\t\t\n");
	printf("\t\t+-------------------------------+\t\t\n");
	printf("\t\t|    1. Add New Book            |\t\t\n");
	printf("\t\t|    2. Update Book Details     |\t\t\n");
	printf("\t\t|    3. Remove Book             |\t\t\n");
	printf("\t\t|    4. Search Book             |\t\t\n");
	printf("\t\t|    5. View All Books          |\t\t\n");
	printf("\t\t|    6. Issue Book              |\t\t\n");
	printf("\t\t|    7. Return Book             |\t\t\n");
	printf("\t\t|    8. List Issued Books       |\t\t\n");
	printf("\t\t|    9. Save                    |\t\t\n");
	printf("\t\t|   10. Exit                    |\t\t\n");
	printf("\t\t+-------------------------------+\t\t\n\n");
	printf("Choose the option in the menu : ");
	if(scanf("%d",&n) != 1)
	{
    	printf("Invalid input\n");
    	while(getchar() != '\n');
    	return 0;
	}
	switch(n)
	{
		case 1: add_newbook(&hptr);
			system("clear");
			break;
		case 2: update_book(hptr);
			while(getchar() != '\n'); 
                        getchar();                                 
			system("clear");
			break;
		case 3: remove_book(&hptr);                 
			while(getchar() != '\n'); 
                        getchar();                 
                        system("clear");
			break;
		case 4: search_book(hptr);
			while(getchar() != '\n'); 
                        getchar();                 
			system("clear");
			break; 
		case 5: printf("\nLIST OF AVAILABLE BOOKS IN THE LIBRARAY\n");
			view_all(hptr);
			while(getchar() != '\n'); 
                        getchar();                 
			system("clear");
			break; 
		case 6: issue_book(hptr,&ishptr);
			printf("\nDONT FORGET THAT DUE DATE\n");
			while(getchar() != '\n'); 
                        getchar();                 
			system("clear");
			break;
		case 7: ret_book(hptr,ishptr);
			while(getchar() != '\n'); 
                        getchar();                 
			system("clear");
			break;
		case 8: list_iss(ishptr);
			while(getchar() != '\n'); 
                        getchar();                 
			system("clear");
			break;
        	case 9: save(hptr);
			printf("\nALL BOOK DETAILS ARE SAVED IN THE FILE lmsbook.txt \n");
			iss_save(ishptr);
			while(getchar() != '\n'); 
                        getchar();                 
			system("clear");
			break;
	      case 10:  exit_lib(hptr,ishptr);
			return 0;
	}
	}
}

