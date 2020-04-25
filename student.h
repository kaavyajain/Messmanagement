typedef struct data_s{
    char name[10],pass[10];
    int card,bal;
}data_s;

typedef struct stud{
    data_s data;
    struct stud *next;
}stud;


void signup(stud **head_s);
//void login(stud **);
void guest_menu();
void student_menu();
