#include"lms.h"
void iss_save(struct iss *sptr)
{
    struct iss *temp = sptr;
    FILE *fp = fopen("issuedbooks.txt","w");
    while(temp != NULL)
    {
	    fprintf(fp,"%d|%d|%d|%s|%s|%s|%s|%d\n",temp->isid,temp->bid,temp->uid,
			    temp->uname,temp->iss_date,temp->due_date,temp->ret_date,temp->fine);
        temp = temp->next;
    }
    fclose(fp);
    fp = fopen("issued_report.txt","w");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }
    temp = sptr;
    if(temp != NULL)
    {
        fprintf(fp,"\n");
        fprintf(fp,"\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
        fprintf(fp,"\t|                                LIST OF ISSUED BOOKS FROM LIBRARY TO STUDENTS                                 |\n");
        fprintf(fp,"\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
        fprintf(fp,"\t| ISSUE ID |  BOOK ID   |   USER ID   |   USER NAME   | ISSUE  DATE |   DUE DATE  | RETURN DATE | FINE AMMOUNT |\n");
        fprintf(fp,"\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
        while(temp != NULL)
        {
            fprintf(fp,"\t| %-8d | %-10d | %-11d | %-13s | %-11s | %-11s | %-11s |       %-6d |\n",temp->isid,temp->bid,
			    temp->uid,temp->uname,temp->iss_date,temp->due_date,temp->ret_date,temp->fine);
            temp = temp->next;
        }
        fprintf(fp,"\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
    }
    else
    {
        fprintf(fp,"\t\tNO BOOKS ARE ISSUED\n");
    }
    fclose(fp);
    printf("ISSUED FILE SAVED SUCCESSFULLY\n"); 
}
