#include"lms.h"
void save(struct st *ptr)
{
    struct st *temp = ptr;
    FILE *fp = fopen("lmsbook.txt","w");
    while(temp != NULL)
    {
	    fprintf(fp,"%d|%s|%s|%d\n",temp->bid,temp->bname,temp->aname,temp->quantity);
            temp = temp->next;
    }
    fclose(fp);
    FILE *fs = fopen("book_report.txt","w");
    if(fs == NULL)
    {
        printf("Unable to create report file\n");
        return;
    }
    int max_book = strlen("BOOK NAME");
    int max_author = strlen("AUTHOR NAME");
    struct st *temp1 = ptr;
    while(temp1)
    {
        if(strlen(temp1->bname) > max_book)
            max_book = strlen(temp1->bname);
        if(strlen(temp1->aname) > max_author)
            max_author = strlen(temp1->aname);
        temp1 = temp1->next;
    }
    fprintf(fs,"\n+---------------+");
    for(int i=0;i<max_book+2;i++) 
	    fprintf(fs,"-");
    fprintf(fs,"+");
    for(int i=0;i<max_author+2;i++)
	    fprintf(fs,"-");
    fprintf(fs,"+---------------+\n");
    fprintf(fs,"| %-13s | %-*s | %-*s | %-13s |\n","BOOK ID",max_book,"BOOK NAME",max_author,"AUTHOR NAME","QUANTITY");
    fprintf(fs,"+---------------+");
    for(int i=0;i<max_book+2;i++) 
	    fprintf(fs,"-");
    fprintf(fs,"+");
    for(int i=0;i<max_author+2;i++) 
	    fprintf(fs,"-");
    fprintf(fs,"+---------------+\n");
    while(ptr)
    {
        fprintf(fs,"| %-13d | %-*s | %-*s | %-13d |\n",ptr->bid,max_book,ptr->bname,max_author,ptr->aname,ptr->quantity);
        ptr = ptr->next;
    }
    fprintf(fs,"+---------------+");
    for(int i=0;i<max_book+2;i++) 
	    fprintf(fs,"-");
    fprintf(fs,"+");
    for(int i=0;i<max_author+2;i++) 
	    fprintf(fs,"-");
    fprintf(fs,"+---------------+\n");
    fclose(fs);
}
