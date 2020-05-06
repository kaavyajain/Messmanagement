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
int order()
{
    int a,i,sum=0;
    int t;
    printf("Enter number of dishes to be ordered: \n");
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        printf("Enter code of the dish:\n");
        scanf("%d",&t);
        
        }
        else
            printf("Order not found\n");




    }
    return 0;
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
		{	case 1:
            		break;
                        case 2:order();

			case 3:	card_details(head,n);
               		 break;
			case 4: return;
			default :printf("\a");
		}
		mess_menu(n);
}
