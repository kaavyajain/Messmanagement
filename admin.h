typedef struct data_d{
    char d_name[20];
    int code,price;
}data_d;

typedef struct dish{
    data_d info;
    struct dish *next;
}dish;

void menu();
void fromfile_dish(dish **head);
void add(dish **);
void admin_menu();


