#include<stdio.h>
#include<process.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"student.h"
#include"admin.h"
#include"mess.h"
#include"donate.h"

void donate_menu()
{
    system("cls");
    system("color b");
    int ch,c;

		printf("\n\t\t~~~DONATE A MEAL WORTH Rs.50 AND CELEBRATE THE SPIRIT OF HUMANITY!~~~");
		printf("\n\n\t\t\t^^^SUPPORT OUR CAMPAIGN: HOPE, NOT HUNGER^^^");
		printf("\n\n\n\t1. GO AHEAD AND DONATE");
		printf("\n\n\t2. BACK");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1: no_of_meals();
                    break;
			case 2: return;
			default :printf("\a");
		}
}

void no_of_meals()
{
    int n,d,card;
    system("cls");
    printf("\n\tHOW MANY MEALS DO YOU WANT TO DONATE?");
    printf("\n\n\tENTER A WHOLE NUMBER : ");
    scanf("%d",&n);
    int p= 50*n;
    printf("\n\n\tARE YOU A GUEST OR A STUDENT?");
    printf("\n\n\n\t1. STUDENT");
    printf("\n\n\t2. GUEST");
    printf("\n\n\tPlease Select Your Option : ");
    scanf("%d",&d);
    printf("\n\tTOTAL AMOUNT: Rs.%d",p);
    switch(d)
    {
        case 1:printf("\n\n\tENTER YOUR CARD NO.: ");
               scanf("%d",&card);
               payment_student(card,p);
               break;
        case 2:payment_guest(p);
               break;
        default:printf("\a");
    }


}
