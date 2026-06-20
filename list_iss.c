#include"lms.h"
void list_iss(struct iss *sptr)
{
    struct iss *temp = sptr;   // Reset traversal pointer
    if(temp != NULL)
    {
        printf("\n");
        printf("\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
        printf("\t|                                LIST OF ISSUED BOOKS FROM LIBRARY TO STUDENTS                                 |\n");
        printf("\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
        printf("\t| ISSUE ID |  BOOK ID   |   USER ID   |   USER NAME   | ISSUE  DATE |   DUE DATE  | RETURN DATE | FINE AMMOUNT |\n");
        printf("\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
        while(temp != NULL)
        {
            printf("\t| %-8d | %-10d | %-11d | %-13s | %-11s | %-11s | %-11s |       %-6d |\n",temp->isid,temp->bid,
                            temp->uid,temp->uname,temp->iss_date,temp->due_date,temp->ret_date,temp->fine);
            temp = temp->next;
        }
        printf("\t+----------+------------+-------------+---------------+-------------+-------------+-------------+--------------+\n");
    }
    else
    {
        printf("\t\tNO BOOKS ARE ISSUED\n");
    }
}

