#include<stdio.h>
#include<process.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"student.h"
#include"admin.h"


void card_details(int val)
{
    system("cls");
    stud *head;
    fromfile_stud(&head);
     printf("\n\n\tCARD DETAILS :\n");
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
    int a,i,sum=0,d,flag;
    dish *headd=NULL;
    fromfile_dish(&headd);
    printf("\n\n\tORDER\n");
    printf("\n\n\tEnter number of dishes you want to order : ");
    scanf("%d",&a);
    for(i=1;i<=a;i++,flag=0)
    {
        printf("\n\n\tEnter code of dish %d : ",i);
        scanf("%d",&d);

        while(headd)
        {
            if(headd->info.code==d)
            {
                flag=1;
                printf("\n\t\tDISH  :\t%s",headd->info.d_name);
                printf("\n\t\tPRICE  :\t%d",headd->info.price);
//                printf("\n\n\tCARD BALANCE  :\t%d\n\n",head->data.bal);
                sum=sum+headd->info.price;
                break;
            }
            headd=headd->next;
        }
        if(flag==0)
        {
            printf("\a\n\tDISH NOT FOUND :(");
        }
    }
   return sum;
}

void mess_menu(int n)
{
	system("cls");
	int ch,c;

		printf("\n\t1. MENU");
		printf("\n\n\t2. ORDER");
		printf("\n\n\t3. CARD DETAILS");
		printf("\n\n\t4. BACK");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1: menu();
                break;
            case 2: printf("\n\n\t\t1.DELIVERY");
                    printf("\n\n\t\t2.EAT IN");
                    printf("\n\n\tPlease Select Your Option : ");
                    scanf("%d",&c);
                    order();
                    if(c==1)
                        //delivery();
                    else

                break;
			case 3:	card_details(n);
                break;
			case 4: return;
			default :printf("\a");
		}
		mess_menu(n);
}
