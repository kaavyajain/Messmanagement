#include<stdio.h>
#include<process.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#include"student.h"
#include"admin.h"


void card_details(stud *head,int val)
{
    system("cls");
    fromfile_stud(&head);
    while(head)
    {
        if(head->data.card==val)
        {
            printf("\n\n\tCARD NO.  :\t%d",head->data.card);
            printf("\n\n\tNAME  :\t%s",head->data.name);
            printf("\n\n\tCARD BALANCE  :\t%d\n\n",head->data.bal);
            break;
        }
        head=head->next;
    }
    system("pause");
}

void mess_menu(int n)
{
	system("cls");
	int ch;
	stud *head=NULL;

		printf("\n\t1. MENU");
		printf("\n\n\t2. ORDER");
		printf("\n\n\t3. CARD DETAILS");
		printf("\n\n\t4. BACK");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	//case 2:signup(&head_s);
			//	 break;
			/*case 1: system("cls");
            printf("\n\t1. LOGIN\n");
            printf("\n\n\tCARD NO. : ");
            scanf("%d",&i);
            printf("\n\n\tPASSWORD : ");
            gets(pass);
		   // login_menu(name,pass);
				 break;*/
			case 3:	card_details(head,n);
                break;
			case 4: return;
			default :printf("\a");
		}
		mess_menu(n);
}
