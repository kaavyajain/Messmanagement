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
        if (t==11){
            printf("Item Code#-11");
            sum+=180;
            printf("\nLunch/Dinner ordered ,Bill=Rs-%d",sum);
       }
        else if(t==14) {
            printf("Item Code#-14");
            sum+=140;
            printf("\nGrilled Chicken ordered ,Bill=Rs-%d",sum);
        }
        else if(t==15) {
            printf("Item Code#-15");
            sum+=130;
            printf("\nNoodles ordered ,Bill=Rs-%d",sum);
        }
        else if(t==16) {
            printf("Item Code#-16");
            sum+=240;
            printf("\nPasta ordered ,Bill=Rs-%d",sum);
        }
        else if(t==18) {
            printf("Item Code#-18");
            sum+=65;
            printf("\nCold Coffee ordered ,Bill=Rs-%d",sum);
        }
        else if(t==19) {
            printf("Item Code#-19");
            sum+=70;
            printf("\nCappuccino ordered ,Bill=Rs-%d",sum);
        }
        else if(t==20) {
            printf("Item Code#-14");
            sum+=30;
            printf("\nCoke ordered ,Bill=Rs-%d",sum);
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
		{	case 1: printf("\n.....MENU...........\n");
                                printf("Item Code#---- Description---Price()\n");
                                printf("[11]----Lunch/Dinner----------------------Rs-180\n");
                                printf("[14]----Grilled Chicken--------------------Rs-140\n");
                                printf("[15]----Noodles----------------------------Rs-130\n");
                                printf("[16]----Pasta-------------------------------Rs-240\n");
                                printf("[18]----Cold Coffee------------------------Rs-65\n");
                                printf("[19]----Cappuccino-------------------------Rs-70\n");
                                printf("[20]----Coke-------------------------------Rs-30\n\n");
            break;
                        case 2:order();

			case 3:	card_details(head,n);
               		 break;
			case 4: return;
			default :printf("\a");
		}
		mess_menu(n);
}
