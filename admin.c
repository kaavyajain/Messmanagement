#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"admin.h"
#include"student.h"

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
		system("color e");
		int c;  char name[10];
		*head_d=NULL;
        data_d temp;

        dish *ptr;
        ptr=(dish*)malloc(1*sizeof(dish));
		printf("\n\n\tADD DISH\n");

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
		printf("\n\n\t\tMENU UPDATED ");

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

void menu()
{
    dish *head;
    system("cls");
    system("color e");
    system("color ");
    fromfile_dish(&head);
    printf("\n\n\t\t\tMENU\n\n");
    printf("=========================================================================================\n");
    printf("\tDISH CODE\t\tDISH NAME\t\tPRICE\n");
    printf("=========================================================================================\n");
    while(head)
    {
        printf("\n\t%-5d\t\t\t%-10s\t\tRs.%d",head->info.code,head->info.d_name,head->info.price);
        printf("\n-----------------------------------------------------------------------------------------");
        head=head->next;
    }

	printf("\n\n");
	system("pause");

}

void all_stud()
{
    system("cls");
    system("color e");
    stud *head;
    fromfile_stud(&head);
    printf("\n\n\t\t\tDETAILS\n\n");
    printf("============================================================================================\n");
    printf("\n\tCARD NO.\t\tNAME\t\t\tPASSWORD\t\tCARD BALANCE\n");
    printf("\n============================================================================================\n");
    while(head)
    {
        printf("\n\t%d\t\t\t%-10s\t\t%-10s\t\tRs.%d",head->data.card,head->data.name,head->data.pass,head->data.bal);
        printf("\n--------------------------------------------------------------------------------------------");
        head=head->next;
    }

	printf("\n\n");
	system("pause");
}

void remove_dish()
{
		system("cls");
        system("color e");
		int c;
		dish *head;
		fromfile_dish(&head);
        dish *temp, *prev;
        temp=head;
        printf("\n\n\tREMOVE DISH\n");
        printf("\n\n\tEnter the code of the Dish you wish to remove from menu : ");
		scanf("%d",&c);


        while (temp != NULL && temp->info.code != c)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("\a\n\tDISH NOT FOUND :(");
            printf("\n\tGOING BACK...");
            for(int i=0;i<16;i++)
                usleep(100000);
            return;
        }
        else
        {
            prev->next = temp->next;
            free(temp);
            remove("menu.dat");
            save_dish(head);
            printf("\n\n\tMENU UPDATED!!!!!");
            for(int i=0;i<20;i++)
                usleep(100000);
        }

}

void admin_menu()
{
	system("cls");
	system("color b");
	int ch;

        printf("\n\n\tADMIN\n");
		printf("\n\n\t1. ADD DISH");
		printf("\n\n\t2. REMOVE DISH");
		printf("\n\n\t3. CURRENT MENU");
		printf("\n\n\t4. ALL STUDENT DETAILS");
		printf("\n\n\t5. BACK");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	case 4:all_stud();
				 break;
			case 1: add(&head_d);
				 break;
            case 2: remove_dish();
				 break;
            case 3:menu();
				 break;
			case 5: return;
			default: printf("\a");
		}
		admin_menu();
}


