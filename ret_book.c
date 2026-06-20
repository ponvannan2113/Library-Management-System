#include"lms.h"
int calculate_fine(char *, char *);
void ret_book(struct st *ptr,struct iss *sptr)
{
	int rn,run;
	char rch,buf[20];
	time_t t; 
	struct tm *str;
	struct st *temp=ptr;
	struct iss *temp1=sptr;
	printf("\tENTER THE BOOK ID : \n");
	scanf("%d",&rn);
	printf("\tENTER THE USER ID : \n");
	scanf("%d",&run);
	sprintf(buf,"%d",rn);
	print_books(ptr,1,buf);
	printf(" CONFIRM THE BOOK (Y/N) : ");
	scanf(" %c",&rch);
	while(temp!=0)
	{
		if(temp->bid==rn)
		{
			//temp->quantity=(temp->quantity)+1;
			temp->quantity++;
			break;		
		}
		else
			temp=temp->next;
	}
	while(temp1!=0)
	{
		if(temp1->bid==rn && temp1->uid==run)
		{
			t = time(NULL);
			str = localtime(&t);
			strftime(temp1->ret_date,sizeof(temp1->ret_date),"%d-%m-%Y",str);
			temp1->fine = calculate_fine(temp1->due_date,temp1->ret_date);
			break;
		}
		temp1=temp1->next;
	}
}
int calculate_fine(char *due_date, char *ret_date)
{
	struct tm due = {0};
	struct tm ret = {0};
	sscanf(due_date,"%d-%d-%d",&due.tm_mday,&due.tm_mon,&due.tm_year);
	sscanf(ret_date,"%d-%d-%d",&ret.tm_mday,&ret.tm_mon,&ret.tm_year);
	due.tm_mon--;
	ret.tm_mon--;
	due.tm_year -= 1900;
	ret.tm_year -= 1900;
	time_t t_due = mktime(&due);
	time_t t_ret = mktime(&ret);
	int days = (t_ret - t_due) / (24 * 60 * 60);
	if(days <= 0)
		return 0;
	return days * 5;   // ₹5 fine per day
}
