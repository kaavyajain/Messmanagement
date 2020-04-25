#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#include"admin.h"

dish *head_d=NULL;

void save_dish(dish *head)
{
    FILE *fp = fopen("menu.dat","a");
    dish *temp=head;
    while(temp)
    {
        fwrite( &temp->info, sizeof(temp->info), 1, fp );
        temp = temp->next;
    }
    fclose(fp);
}

void fromfile_dish(dish **head)
{
    FILE *fp = fopen("menu.dat","r+");
    data_d temp;
    dish *ptr;
    *head=NULL;

    while (fread(&temp,sizeof(temp),1,fp))
    {
        ptr=(dish*)malloc(sizeof(dish));
        ptr->info=temp;
        if(*head==NULL)
        {
            ptr->next=*head;
            *head=ptr;
        }
        else
        {
            ptr->next=NULL;
            dish *tmp=*head;
            while((tmp->next)!=NULL)
            {
                tmp=tmp->next;
            }
                tmp->next=ptr;
        }
    }
    fclose(fp);
}



void add(dish **head_d)
{
		system("cls");
		int c;  char name[10];
        data_d temp;

        dish *ptr;
        ptr=(dish*)malloc(1*sizeof(dish));
		printf("\n\tADD DISH\n");

		printf("\n\n\tNAME : ");
		gets(name);
		gets(name);
		strcpy(temp.d_name,name);

		printf("\n\n\tDISH CODE : ");
		scanf("%d",&c);
		temp.code=c;

		printf("\n\n\tPRICE : ");
		scanf("%d",&c);
		temp.price=c;
		printf("\n\n=====================================================MENU UPDATED=======================================================");

        ptr->info=temp;
        if(*head_d==NULL)
        {
            ptr->next=NULL;
            *head_d=ptr;
        }
        else
        {
            ptr->next=NULL;
            dish *tmp=*head_d;
            while((tmp->next)!=NULL)
            {
                tmp=tmp->next;
            }
                tmp->next=ptr;
        }
    save_dish(*head_d);
	for(int i=0;i<6;i++)
        usleep(100000);
}

void menu(dish *head)
{
    system("cls");
    fromfile_dish(&head);
    printf("\n\tMENU\n\n");
    printf("=========================================================================================\n");
    printf("\tDISH CODE\t\tDISH NAME\t\tPRICE\n");
    printf("=========================================================================================\n");
    while(head)
    {
        printf("\n\t%d\t\t\t%s\t\tRs.%d",head->info.code,head->info.d_name,head->info.price);
        printf("\n------------------------------------------------------------------------------------");
        head=head->next;
    }

	for(int i=0;i<50;i++)
        usleep(100000);

}


void admin_menu()
{
	system("cls");
	int ch;
	dish *head=NULL;

        printf("\n\tADMIN\n");
		printf("\n\n\t1. ADD DISH");
		printf("\n\n\t2. CURRENT MENU");
		printf("\n\n\t3. ALL STUDENT DETAILS");
		printf("\n\n\t4. EXIT");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	case 3://signup(&head_s);
				 break;
			case 1: add(&head_d);
				 break;
            case 2:menu(head);
				 break;
			case 4: return;
			default: printf("\a");
		}
		admin_menu();
}


