
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#include"student.h"
#include"admin.h"

void load();

int main()
{	int ch;
    int i;
    load();
    usleep(10);
	do
	{	system("cls");
		//printf("\n\n\n\tBOOK-A-HOLIC... \n\n        MAIN MENU");
		for(i=0;i<9;i++)
            printf("\n");
		printf("\t\t\t\t\t\t1. GUEST");
		printf("\n\n\t\t\t\t\t\t2. STUDENT");
		printf("\n\n\t\t\t\t\t\t3. ADMIN");
		printf("\n\n\t\t\t\t\t\t4. EXIT");
		printf("\n\n\t\t\t\t\tPlease Select Your Option : ");
		scanf("%d",&ch);
		switch(ch)
		{	case 2:student_menu();
				 break;
			case 1:guest_menu();
				 break;
            case 3:admin_menu();
				 break;
			case 4:exit(0);
			default :printf("\a");
		}
	}while(ch!=4);
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
