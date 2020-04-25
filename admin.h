typedef struct data_d{
    char d_name[20];
    int code,price;
}data_d;

typedef struct dish{
    data_d info;
    struct dish *next;
}dish;



void menu(dish *);
void add(dish **);
void admin_menu();
//void all_stud();


