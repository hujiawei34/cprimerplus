#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define SEAT_MAX 12
struct ticket{
    char seat_num[3];
    bool is_ordered;
    char order_fname[20];
    char order_lname[20];
};
struct ticket * init_ticket(void){
    struct ticket * tickets = malloc(SEAT_MAX * sizeof(struct ticket));
    for (int i = 0; i < SEAT_MAX; i++) {
        sprintf(tickets[i].seat_num, "%d", i + 1);
        tickets[i].is_ordered = false;
        strcpy(tickets[i].order_fname, "");
        strcpy(tickets[i].order_lname, "");
    }
    return tickets;
}
void show_menu(void){
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of epmpty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("q) Quit");
}
void delete_assignment(struct ticket * tickets){
    char seat_num[3];
    printf("Please enter the seat number: ");
    scanf("%s", seat_num);
    while (getchar() != '\n')
        continue;
    for (int i = 0; i < SEAT_MAX; i++) {
        if (strcmp(tickets[i].seat_num, seat_num) == 0) {
            tickets[i].is_ordered = false;
            strcpy(tickets[i].order_fname, "");
            strcpy(tickets[i].order_lname, "");
            break;
        }
    }
    printf("Seat %s is deleted.\n", seat_num);
}
void assign_seat(struct ticket * tickets){
    char seat_num[3];
    char fname[20];
    char lname[20];
    printf("Please enter the seat number: ");
    scanf("%s", seat_num);
    while (getchar() != '\n')
        continue;
    printf("Please enter the customer's first name: ");
    scanf("%s", fname);
    while (getchar() != '\n')
        continue;
    printf("Please enter the customer's last name: ");
    scanf("%s", lname);
    while (getchar() != '\n')
        continue;
    for (int i = 0; i < SEAT_MAX; i++) {
        if (strcmp(tickets[i].seat_num, seat_num) == 0) {
            tickets[i].is_ordered = true;
            strcpy(tickets[i].order_fname, fname);
            strcpy(tickets[i].order_lname, lname);
            break;
        }
    }
    printf("Seat %s is assigned to %s %s.\n", seat_num, fname, lname);
}
void sort_ticket(struct ticket * tickets){
    for (int i = 0; i < SEAT_MAX; i++) {
        for (int j = 0; j < SEAT_MAX - 1; j++) {
            if (strcmp(tickets[j].order_fname, tickets[j + 1].order_fname) > 0) {
                struct ticket temp = tickets[j];
                tickets[j] = tickets[j + 1];
                tickets[j + 1] = temp;
            }
        }
    }
}

void show_seat_ordered_list(struct ticket * tickets){
    struct ticket temp[SEAT_MAX];
    memcpy(temp, tickets, SEAT_MAX * sizeof(struct ticket));
    sort_ticket(temp);
    printf("The seat list is:\n");
    for (int i = 0; i < SEAT_MAX; i++) {
        if (temp[i].is_ordered)
        printf("%s %s %s\n", temp[i].seat_num, temp[i].order_fname, temp[i].order_lname);
    }
}
char get_choice(void){
    char ch;
    ch = getchar();
    while (strchr("abcdeq", ch) == NULL) {
        printf("Please enter a letter from the menu.\n");
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;
    return ch;
}
void show_empty_seats(struct ticket * tickets){
    int empty_seats = 0;
    for (int i = 0; i < SEAT_MAX; i++) {
        if (!tickets[i].is_ordered)
            empty_seats++;
    }
    printf("There are %d empty seats.\n", empty_seats);
}
void show_empty_seat_list(struct ticket * tickets){
    printf("The empty seat list is:\n");
    for (int i = 0; i < SEAT_MAX; i++) {
        if (!tickets[i].is_ordered)
            printf("%s ", tickets[i].seat_num);
    }
    printf("\n");
}   
int main(int argc, char *argv[])
{
    struct ticket * tickets = init_ticket();
    show_menu();
    char ch = get_choice();
    while (ch != 'q') {
        switch (ch) {
        case 'a':
            show_empty_seats(tickets);
            break;
        case 'b':
            show_empty_seat_list(tickets);
            break;
        case 'c':
            show_seat_ordered_list(tickets);
            break;
        case 'd':
            assign_seat(tickets);
            break;
        case 'e':
            delete_assignment(tickets);
            break;
        default:
            break;
        }
        show_menu();
        ch = get_choice();
    } 
    return 0;
}