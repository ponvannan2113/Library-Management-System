#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>
struct st
{
	int bid;
	char bname[100];
	char aname[100];
	int quantity;
	struct st *next;
};
struct iss
{
	int isid;
	int bid;
	int uid;
	char uname[50];
	char iss_date[20];
	char due_date[20];
	char ret_date[20];
	int fine;
	struct iss *next;
};
extern int id,sid;
void load(struct st **);
void isload(struct iss **);
void view_all(struct st *);
void add_newbook(struct st **);
void save(struct st *);
int exit_lib(struct st *,struct iss *);
void search_book(struct st *);
void remove_book(struct st **);
void print_books(struct st *, int, char*);
void issue_book(struct st *, struct iss **);
void iss_save(struct iss *);
void list_iss(struct iss *);
void ret_book(struct st *,struct iss *);
void update_book(struct st *);
