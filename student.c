#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"student.h"
#include"admin.h"
#include"mess.h"

stud *head_s=NULL;

void save_stud(stud *head)
{
    FILE *fp = fopen("details.dat","a");
    stud *temp=head;
    while (temp)
    {
        fwrite( &(temp->data), sizeof(temp->data), 1, fp );
        temp = temp->next;
    }
    fclose(fp);
}

void fromfile_stud(stud **head)
{
    FILE *fp = fopen("details.dat","r+");
    data_s temp;
    stud *ptr;
    *head=NULL;

    while (fread(&temp,sizeof(temp),1,fp))
    {
        ptr=(stud*)malloc(sizeof(stud));
        ptr->data=temp;
        if(*head==NULL)
        {
            ptr->next=*head;
            *head=ptr;
        }
        else
        {
            ptr->next=NULL;
            stud *tmp=*head;
            while((tmp->next)!=NULL)
            {
                tmp=tmp->next;
            }
                tmp->next=ptr;
        }
    }
    fclose(fp);
}

void signup(stud **head_s)
{
		system("cls");
		system("color e");
		int c;  char name[10];
		*head_s=NULL;

        data_s temp;
        stud *ptr;
        ptr=(stud*)malloc(1*sizeof(stud));
		printf("\n\n\tSIGN UP\n");

		printf("\n\n\tNAME : ");
		gets(name);
		gets(name);
		strcpy(temp.name,name);

		printf("\n\n\tCARD NO. : ");
		scanf("%d",&c);
		temp.card=c;

		printf("\n\n\tPASSWORD : ");
		gets(name);
		gets(name);
		strcpy(temp.pass,name);

		printf("\n\n\tINITIAL BAL. : ");
		scanf("%d",&c);
		temp.bal=c;
		printf("\n\n\t\tSIGNED-IN :)");

        ptr->data=temp;
        if(*head_s==NULL)
        {
            ptr->next=*head_s;
            *head_s=ptr;
        }
        else
        {
            ptr->next=NULL;
            stud *tmp=*head_s;
            while((tmp->next)!=NULL)
            {
                tmp=tmp->next;
            }
                tmp->next=ptr;
        }
    save_stud(*head_s);
	for(int i=0;i<6;i++)
        usleep(100000);
}


void login(stud *head)
{
    system("cls");
    system("color e");
    int c,flag=0;
    char pass[10];
    fromfile_stud(&head);

        printf("\n\n\tLOGIN\n");
        printf("\n\n\tCARD NO. : ");
        scanf("%d",&c);
        printf("\n\n\tPASSWORD : ");
        gets(pass);
        gets(pass);
        while(head)
        {
            if(head->data.card==c)
            {
                if(strcmp(head->data.pass,pass)==0)
                {
                    mess_menu(c);
                    return;
                }
                else
                {
                    printf("\a\t\n:x WRONG PASSWORD !!!");
                    flag=1;
                    for(int i=0;i<16;i++)
                        usleep(100000);
                    login(head);
                    break;
                }
            }
            head=head->next;
        }
        if(flag==0)
        {
            printf("\a\t\n:x CARD DOESN'T EXIST !!!");
            for(int i=0;i<16;i++)
                usleep(100000);
            login(head);
        }

}

void student_menu()
{
	system("cls");
	system("color b");
	int ch;
	stud *head=NULL;

		printf("\n\n\tSTUDENT\n");
		printf("\n\n\t1. LOGIN");
		printf("\n\n\t2. SIGN UP");
		printf("\n\n\t3. BACK");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	case 2: signup(&head_s);
				 break;
			case 1: login(head);
				 break;
			case 3: return;
			default: printf("\a");
		}
		student_menu();
}

void guest_menu()
{
	system("cls");
	system("color b");
	int ch,bill;
	dish *head=NULL;

        printf("\n\n\tGUEST\n");
		printf("\n\n\t1. MENU");
		printf("\n\n\t2. ORDER");
		printf("\n\n\t3. GET CARD");
		printf("\n\n\t4. EXIT");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	case 3: signup(&head_s);
				 break;
			case 1: menu(head);
				 break;
            case 2: bill=order();
                    payment_guest(bill);
                    health();
				 break;
			case 4: return;
			default :printf("\a");
		}
		guest_menu();
}


