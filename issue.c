#include "lms.h"
int get_next_issue_id(struct iss *ptr)
{
	int max = 942004;
	while(ptr)
	{
		if(ptr->isid > max)
			max = ptr->isid;
		ptr = ptr->next;
	}
	return max + 1;
}

void issue_book(struct st *lib, struct iss **issptr)
{
	struct st *btemp;
	struct iss *itemp;
	int bid;
	time_t t;
	struct tm *ptr;
	char ch;
	// Search and display books
	search_book(lib);
	printf("\nEnter Book ID to Issue : ");
	scanf("%d",&bid); 
	btemp = lib;
	while(btemp)
	{
		if(btemp->bid == bid)
			break;
		btemp = btemp->next;
	}
	if(btemp == NULL)
	{
		printf("\nBook ID Not Found\n");
		return;
	}
	printf("\nSelected Book\n");
	printf("Book ID   : %d\n",btemp->bid);
	printf("Book Name : %s\n",btemp->bname);
	printf("Author    : %s\n",btemp->aname);
	printf("Quantity  : %d\n",btemp->quantity);
	if(btemp->quantity <= 0)
	{
		printf("\nBook Not Available\n");
		return;
	}
	printf("\nConfirm Issue (Y/N) : ");
	scanf(" %c",&ch);
	if((ch|32) != 'y')
	{
		printf("\nIssue Cancelled\n");
		return;
	}
	itemp = (struct iss *)malloc(sizeof(struct iss));
	if(itemp == NULL)
	{
		printf("\nMemory Allocation Failed\n");
		return;
	}
	// Auto Generate Issue ID 
	itemp->isid = get_next_issue_id(*issptr);
	itemp->bid = btemp->bid;
	printf("Enter User ID : ");
	scanf("%d",&itemp->uid);
	printf("Enter User Name : ");
	scanf(" %[^\n]",itemp->uname);
	// Issue Date 
	t = time(NULL);
	ptr = localtime(&t);
	strftime(itemp->iss_date,sizeof(itemp->iss_date),"%d-%m-%Y",ptr);
	// Due Date = Issue Date + 1 Days 
	t += 1 * 24 * 60 * 60;
	ptr = localtime(&t);
	strftime(itemp->due_date,sizeof(itemp->due_date),"%d-%m-%Y",ptr);
	// Return Date Empty 
	strcpy(itemp->ret_date, "-");
	itemp->fine = 0;
	// Reduce Book Quantity 
	btemp->quantity--;
	// Insert at end of issue list 
	itemp->next = NULL;
	if(*issptr == NULL)
	{
		*issptr = itemp;
	}
	else
	{
		struct iss *temp = *issptr;
		while(temp->next)
			temp = temp->next;
		temp->next = itemp;
	}
	printf("\nBOOK ISSUED SUCCESSFULLY\n");
	printf("Issue ID           : %d\n",itemp->isid);
	printf("Book ID            : %d\n",itemp->bid);
	printf("User ID            : %d\n",itemp->uid);
	printf("User Name          : %s\n",itemp->uname);
	printf("Issue Date         : %s\n",itemp->iss_date);
	printf("Due Date           : %s\n",itemp->due_date);
	printf("Remaining Quantity : %d\n",btemp->quantity);
}
