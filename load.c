#include"lms.h"
void load(struct st **ptr)
{
	struct st temp; 
	FILE *fp=fopen("lmsbook.txt","r");
	if(fp==NULL){
		return;
	}
	/*while(fscanf(fp,"%d %s %s %d",&temp.bid,temp.aname,temp.bname,&temp.quantity)==4)*/
	while(fscanf(fp,"%d|%[^|]|%[^|]|%d\n",&temp.bid,temp.bname,temp.aname,&temp.quantity) == 4)
	{
		struct st *new;
		new=(struct st *)malloc(sizeof(struct st));
		*new=temp;
		new->next=0;
		if(*ptr==0)
			*ptr=new;
		else
		{
			struct st *last = *ptr;
			while(last->next!=0)
				last=last->next;
			last->next=new;
		}
	}
	fclose(fp);
}
