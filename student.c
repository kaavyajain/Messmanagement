#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#include"student.h"
#include"admin.h"

stud *head_s=NULL;

void save(stud *head)
{
    FILE *fp = fopen("details.dat","a");
    while (head)
    {
        fwrite( &head->data, sizeof(head->data), 1, fp );
        head = head->next;
    }
    fclose(fp);
}

void signup(stud **head_s)
{
		system("cls");
		int i,c;  char name[10];

		for(i=0;i<9;i++)
            printf("\n");
        data_s temp;
        stud *ptr;
        ptr=(stud*)malloc(1*sizeof(stud));
		printf("\t\t\t\t\t\t\tSIGN UP\n");

		printf("\n\n\t\t\t\t\t\tNAME : ");
		gets(name);
		gets(name);
		strcpy(temp.name,name);

		printf("\n\n\t\t\t\t\t\tCARD NO. : : ");
		scanf("%d",&c);
		temp.card=c;

		printf("\n\n\t\t\t\t\t\tPASSWORD : ");
		gets(name);
		gets(name);
		strcpy(temp.name,name);

		printf("\n\n\t\t\t\t\t\tINITIAL BAL. : ");
		scanf("%d",&c);
		temp.bal=c;
		printf("\n\n=====================================================SIGNED-IN :)=======================================================");

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
    save(*head_s);
	for(int i=0;i<6;i++)
        usleep(100000);
}


/*void login( )
{
        printf("\t\t\t\t\t\tLOGIN\n");
		printf("\n\n\t\t\t\t\tUSERNAME : ");
		gets(name);
		gets(name);
		printf("\n\n\t\t\t\t\tPASSWORD : ");
		gets(name);
		printf("\n\n=====================================================SIGNED-IN :)=======================================================");

}*/

void student_menu()
{
	system("cls");
	int i,ch;
	char pass[10];

		printf("\n\t1. LOGIN");
		printf("\n\n\t2. SIGN UP");
		printf("\n\n\t3. BACK");
		printf("\n\n\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	case 2:signup(&head_s);
				 break;
			case 1: system("cls");
            printf("\n\t1. LOGIN\n");
            printf("\n\n\tCARD NO. : ");
            scanf("%d",&i);
            printf("\n\n\tPASSWORD : ");
            gets(pass);
		   // login_menu(name,pass);
				 break;
			case 3: return;
			default :printf("\a");
		}
		student_menu();
}

void guest_menu()
{
	system("cls");
	int ch;
	dish *head=NULL;

        printf("\n\tGUEST\n");
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
            case 2:// order();
				 break;
			case 4: return;
			default :printf("\a");
		}
		guest_menu();
}


