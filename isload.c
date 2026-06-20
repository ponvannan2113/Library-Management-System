#include"lms.h"
void isload(struct iss **ptr)
{
	struct iss temp; 
	FILE *fp=fopen("issuedbooks.txt","r");
	if(fp==NULL){
		return;
	}
	//while(fscanf(fp,"%d %d %d %s %s %s %s %d",&temp.isid,&temp.bid,&temp.uid,temp.uname,temp.iss_date,temp.due_date,temp.ret_date)==7)
	 while(fscanf(fp,"%d|%d|%d|%[^|]|%[^|]|%[^|]|%[^|]|%d\n",&temp.isid,&temp.bid,&temp.uid,temp.uname,
				 temp.iss_date,temp.due_date,temp.ret_date,&temp.fine) == 8)
	{
		struct iss *new;
		new=(struct iss *)malloc(sizeof(struct iss));
		*new=temp;
		new->next=0;
		if(*ptr==0)
			*ptr=new;
		else
		{
			struct iss *last = *ptr;
			while(last->next!=0)
				last=last->next;
			last->next=new;
		}
	}
	fclose(fp);
}
