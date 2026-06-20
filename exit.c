#include"lms.h"
int exit_lib(struct st *ptr,struct iss *isptr)
{
	char ex;
	printf("\n");
	printf("\t\t+------------------------+\n");
	printf("\t\t|        EXIT MENU       |\n");
	printf("\t\t+------------------------+\n");
	printf("\t\t|  S/s : Save and exit   |\n");
	printf("\t\t|  E/e : Exit only       |\n");
	printf("\t\t+------------------------+\n");
	printf("ENTER THE OPTION : ");
	scanf(" %c",&ex);
	switch(ex|32)
	{
		case 's': save(ptr);
			  printf("FILE SAVED SUCCESSFULLY\n");
			  iss_save(isptr);
			  break;
		case 'e': return 0;
	}
}
