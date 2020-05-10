#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"student.h"
#include"admin.h"
#include"mess.h"


void card_details(int val)
{
    system("cls");
    system("color e");
    stud *head;
    fromfile_stud(&head);
     printf("\n\n\tCARD DETAILS :\n");
    while(head)
    {
        if(head->data.card==val)
        {
            printf("\n\n\tCARD NO.  :\t%d",head->data.card);
            printf("\n\n\tNAME  :\t%s",head->data.name);
            printf("\n\n\tCARD BALANCE  : Rs.%d\n\n\t",head->data.bal);
            break;
        }
        head=head->next;
    }
    system("pause");
}

void health_print(health_data Loc)
{
    printf("\n\n\t***HEALTH TIP : STAY HEALTHY, BURN CALORIES***");
    printf("\n\n\tGIVEN BELOW ARE VARIOUS PATHS ACROSS THE CAMPUS");
    printf("\n\tEACH INDICATES THE AMOUNT OF CALORIES YOU CAN BURN BY CHOOSING IT");
    printf( "\n\n\tPATH 1 : %s\n", Loc.t);
    printf( "\n\tPATH 2 : %s\n", Loc.ur);
    printf( "\n\tPATH 3 : %s\n", Loc.rt);
    printf( "\n\tLocations cal_count : %d\n", Loc.cal_count);
    printf("\n\n\t***PICK AN OPTIMAL PATH TO STAY FIT***\n\n\t");
}

void health()
{
    health_data LOCATION;
    strcpy( LOCATION.t, "A-BLOCK-------44cal------->D-BLOCK");
    strcpy( LOCATION.ur, "GIRLS HOSTEL---145CAL-->LIBRARY---250cal-->Mess");
    strcpy( LOCATION.rt, "B-Block--------300cal------>sports complex");
    LOCATION.cal_count = 594;
    health_print( LOCATION );
    system("Pause");
}


int order()
{
    system("cls");
    system("color e");
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
                printf("\n\t\tPRICE  : Rs.%d",headd->info.price);
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

void payment_student(int n,int bill)
{
    stud *head,*t;
    int flag=0;
    printf("\n\n\tYour Total Amount is Rs.%d",bill);
    fromfile_stud(&head);
    t=head;
    while(t)
    {
        if(t->data.card==n)
        {
            flag=1;
            t->data.bal=t->data.bal-bill;
            break;
        }
        t=t->next;
    }
    if(flag==0)
    {
        printf("\n\n\t\aCARD NOT FOUND\n\n\t");
        system("pause");
        return;
    }
    if(t->data.bal<0)
    {
        printf("\n\n\t\aINSUFFICIENT BALANCE, RECHARGE SOON!!");
        printf("\n\n\tPlease pay remaining Rs.%d by cash.\n",-t->data.bal);
        t->data.bal=0;
    }
    for(int i=0;i<16;i++)
    {
        usleep(10000);
        usleep(10000);
    }
    printf("\n\n\tTRANSACTION SUCCESSFUL ... THANK YOU SO MUCH\n\n\t");
    remove("details.dat");
    save_stud(head);
    system("pause");
}

void payment_guest(int bill)
{
    printf("\n\n\tYour Total Amount is Rs.%d",bill);

    printf("\n\n\tPlease pay Rs.%d by cash",bill);
    printf("\n\n\tYou can also PAYTM us at XXXXXXXXXX");

    for(int i=0;i<16;i++)
    {
        usleep(10000);
        usleep(10000);
    }
    printf("\n\n\tTRANSACTION SUCCESSFUL ... THANK YOU SO MUCH\n\n\t");
    system("pause");
}

int delivery(int n)
{
	printf("\n\n\tAN EXTRA RS. 50 WILL BE ADDED TO THE TOTAL AMOUNT");
	int l;
	printf("\n\n\tLIST OF LOCATIONS AVAILABLE : ");
	printf("\n\n\t1. Towers (includes Faculty Housing)");
	printf("\n\t2. Girls Hostel");
	printf("\n\t3. Boys Hostel");
	printf("\n\t4. Canopies");
	printf("\n\t5. Indoor Sports Complex (ISC)");
	printf("\n\n\tCHOOSE A LOCATION : ");
	scanf("%d",&l);

	return n+50;
}

void recharge_card(int n)
{
    stud *head,*t;
    int amt;
    system("cls");
    system("color e");
    printf("\n\n\tCARD RECHARGE\n");
    printf("\n\n\tEnter the amount you want to add : ");
    scanf("%d",&amt);
    printf("\n\n\t-Please pay Rs.%d by cash",amt);
    printf("\n\n\t-You can also PAYTM us at XXXXXXXXXX");
    fromfile_stud(&head);
    t=head;
    while(t)
    {
        if(t->data.card==n)
        {
            t->data.bal=t->data.bal+amt;
            break;
        }
        t=t->next;
    }
    for(int i=0;i<16;i++)
    {
        usleep(10000);
        usleep(10000);
    }
    printf("\n\n\tTRANSACTION SUCCESSFUL ... CARD RECHARGED\n\n\t");
    remove("details.dat");
    save_stud(head);
    system("pause");
}
void mess_menu(int n)
{
	system("cls");
	system("color a");
	int ch,c,bill;

		printf("\n\n\t1. MENU");
		printf("\n\n\t2. ORDER");
		printf("\n\n\t3. RECHARGE CARD");
		printf("\n\n\t4. CARD DETAILS");
		printf("\n\n\t5. BACK");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1: menu();
                break;
           case 2:  printf("\n\n\t\t1.DELIVERY");
                    printf("\n\n\t\t2.EAT IN");
                    printf("\n\n\tPlease Select Your Option : ");
                    scanf("%d",&c);
                    bill=order();
                    usleep(10000);
                    usleep(10000);
                    if(c==1)
                        bill=delivery(bill);

                    payment_student(n,bill);
                    health();
                break;
            case 3:	recharge_card(n);
                break;
			case 4:	card_details(n);
                break;
			case 5: return;
			default :printf("\a");
		}
		mess_menu(n);
}
