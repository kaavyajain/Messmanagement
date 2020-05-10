typedef struct health_data {
    char  t[100];
    char  ur[100];
    char  rt[100];
    int   cal_count;
}health_data;

void mess_menu(int n);
int order();
void payment_guest(int );
void payment_student(int ,int );
void health();



