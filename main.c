#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"student.h"
#include"admin.h"
#include"mess.h"

void load();
void donate_menu();

int main()
{

    int ch;
    load();
    usleep(10);
	do
	{	system("cls");
        system("color e");

        printf("\n\n\tCRAVEZIA\n");
		printf("\n\n\t1. GUEST");
		printf("\n\n\t2. STUDENT");
		printf("\n\n\t3. ADMIN");
		printf("\n\n\t4. DONATE(TO COVID-19 RELIEF FUND)");
		printf("\n\n\t5. EXIT");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	case 2:student_menu();
				 break;
			case 1:guest_menu();
				 break;
            case 3:admin_menu();
				 break;
            case 4:donate_menu();
				 break;
			case 5:exit(0);
			default :printf("\a");
		}
	}while(ch!=5);
}

void donate_menu()
{
    system("cls");
    system("color b");
    int n,d,card;

		printf("\n\t\t~~~DONATE A MEAL WORTH Rs.50 AND CELEBRATE THE SPIRIT OF HUMANITY!~~~");
		printf("\n\n\t\t\t^^^SUPPORT OUR CAMPAIGN: HOPE, NOT HUNGER^^^");


    printf("\n\tHOW MANY MEALS DO YOU WANT TO DONATE?");
    printf("\n\tEACH MEAL COSTS RS.50.");
    printf("\n\n\tEnter a whole number : ");
    scanf("%d",&n);
    int p= 50*n;
    printf("\n\n\tAre you a guest or a student");
    printf("\n\n\t1. STUDENT");
    printf("\n\n\t2. GUEST");
    printf("\n\n\tPlease Select Your Option(Enter 0 to exit) : ");
    scanf("%d",&d);
    switch(d)
    {
        case 0: return;
        case 1:printf("\n\n\tENTER YOUR CARD NO.: ");
               scanf("%d",&card);
               payment_student(card,p);
            break;
        case 2:payment_guest(p);
            break;
        default:printf("\a");
    }
}

void load()
{
    int i;
    for(i=0;i<8;i++)
        printf("\n");
    usleep(10000);
    printf("\t\t\t\t\t\t\tLOADING....");
    usleep(10000);
    for(i=0;i<7;i++)
        printf("\n");
    printf("\t\t");
    for(i=0;i<80;i++)
    {
        printf("|");
        usleep(10000);
        usleep(10000);
    }
}
