#include"lms.h"
void print_books(struct st *ptr, int mode, char name[])
{
    struct st *temp = ptr;
    int found = 0;

    int max_book = strlen("BOOK NAME");
    int max_author = strlen("AUTHOR NAME");

    /* Find maximum lengths */
    while(temp)
    {
        if((mode == 1 && temp->bid == atoi(name)) ||
           (mode == 2 && strcmp(temp->bname,name)==0) ||
           (mode == 3 && strcmp(temp->aname,name)==0))
        {
            found = 1;

            if(strlen(temp->bname) > max_book)
                max_book = strlen(temp->bname);

            if(strlen(temp->aname) > max_author)
                max_author = strlen(temp->aname);
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nBOOK NOT FOUND\n");
        return;
    }

    printf("\n+---------------+");
    for(int i=0;i<max_book+2;i++) printf("-");
    printf("+");
    for(int i=0;i<max_author+2;i++) printf("-");
    printf("+---------------+\n");

    printf("| %-13s | %-*s | %-*s | %-13s |\n",
           "BOOK ID",
           max_book,"BOOK NAME",
           max_author,"AUTHOR NAME",
           "QUANTITY");

    printf("+---------------+");
    for(int i=0;i<max_book+2;i++) printf("-");
    printf("+");
    for(int i=0;i<max_author+2;i++) printf("-");
    printf("+---------------+\n");

    temp = ptr;

    while(temp)
    {
        if((mode == 1 && temp->bid == atoi(name)) ||
           (mode == 2 && strcmp(temp->bname,name)==0) ||
           (mode == 3 && strcmp(temp->aname,name)==0))
        {
            printf("| %-13d | %-*s | %-*s | %-13d |\n",
                   temp->bid,
                   max_book,temp->bname,
                   max_author,temp->aname,
                   temp->quantity);
        }

        temp=temp->next;
    }

    printf("+---------------+");
    for(int i=0;i<max_book+2;i++) printf("-");
    printf("+");
    for(int i=0;i<max_author+2;i++) printf("-");
    printf("+---------------+\n");
}

