#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define SEAT_MAX 12
#define FLIGHT_COUNT 4

struct ticket{
    char seat_num[3];
    bool is_ordered;
    bool is_confirmed; // Added confirmation status
    char order_fname[20];
    char order_lname[20];
};

struct flight {
    int flight_id;
    struct ticket tickets[SEAT_MAX];
};

void init_flights(struct flight *flights) {
    int flight_ids[FLIGHT_COUNT] = {102, 311, 444, 519};
    for (int f = 0; f < FLIGHT_COUNT; f++) {
        flights[f].flight_id = flight_ids[f];
        for (int i = 0; i < SEAT_MAX; i++) {
            sprintf(flights[f].tickets[i].seat_num, "%d", i + 1);
            flights[f].tickets[i].is_ordered = false;
            flights[f].tickets[i].is_confirmed = false;
            strcpy(flights[f].tickets[i].order_fname, "");
            strcpy(flights[f].tickets[i].order_lname, "");
        }
    }
}
void show_top_menu(void) {
    puts("------------------------------------------------");
    puts("Giant Airlines Flight Reservation System");
    puts("Choose a flight to manage (or q to quit):");
    puts("0) Flight 102");
    puts("1) Flight 311");
    puts("2) Flight 444");
    puts("3) Flight 519");
    puts("q) Quit program");
    puts("------------------------------------------------");
}

void show_menu(int flight_id){
    printf("\n--- Managing Flight %d ---\n", flight_id);
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Confirm a seat assignment"); // Added option
    puts("q) Return to top menu");
}
void confirm_seat(struct ticket * tickets) {
    char seat_num[3];
    printf("Please enter the seat number to confirm: ");
    scanf("%s", seat_num);
    while (getchar() != '\n') continue;

    for (int i = 0; i < SEAT_MAX; i++) {
        if (strcmp(tickets[i].seat_num, seat_num) == 0) {
            if (tickets[i].is_ordered) {
                tickets[i].is_confirmed = true;
                printf("Seat %s for %s %s is now CONFIRMED.\n", 
                       seat_num, tickets[i].order_fname, tickets[i].order_lname);
            } else {
                printf("Seat %s is empty. Cannot confirm.\n", seat_num);
            }
            return;
        }
    }
    printf("Invalid seat number.\n");
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
            tickets[i].is_confirmed = false;
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
            tickets[i].is_confirmed = false; // Default to unconfirmed upon assignment
            strcpy(tickets[i].order_fname, fname);
            strcpy(tickets[i].order_lname, lname);
            printf("Seat %s is assigned to %s %s (Status: Unconfirmed).\n", seat_num, fname, lname);
            break;
        }
    }
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
            printf("Seat %s: %s %s [Status: %s]\n", 
                   temp[i].seat_num, temp[i].order_fname, temp[i].order_lname,
                   temp[i].is_confirmed ? "Confirmed" : "Unconfirmed");
    }
}
char get_choice(void){
    char ch;
    ch = getchar();
    while (strchr("abcdefq", ch) == NULL) { // Updated valid choices
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
    struct flight flights[FLIGHT_COUNT];
    init_flights(flights);

    while (1) {
        show_top_menu();
        char top_choice = getchar();
        while (getchar() != '\n') continue; // consume newline

        if (top_choice == 'q') {
            puts("Bye!");
            break;
        }

        int flight_idx = -1;
        if (top_choice >= '0' && top_choice <= '3') {
            flight_idx = top_choice - '0';
        } else {
            puts("Invalid selection. Please try again.");
            continue;
        }

        struct ticket *current_tickets = flights[flight_idx].tickets;
        int current_flight_id = flights[flight_idx].flight_id;

        show_menu(current_flight_id);
        char ch = get_choice();
        while (ch != 'q') {
            switch (ch) {
            case 'a':
                show_empty_seats(current_tickets);
                break;
            case 'b':
                show_empty_seat_list(current_tickets);
                break;
            case 'c':
                show_seat_ordered_list(current_tickets);
                break;
            case 'd':
                assign_seat(current_tickets);
                break;
            case 'e':
                delete_assignment(current_tickets);
                break;
            case 'f':
                confirm_seat(current_tickets);
                break;
            default:
                break;
            }
            show_menu(current_flight_id);
            ch = get_choice();
        }
    }
    return 0;
}