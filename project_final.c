#include <stdio.h>
#include <stdlib.h>
void mgm();
void rsv();
void addBus();
void viewBus();
void makeRsv();
void viewReord();
void searchRsv();
void editRsv();
void cancelRsv();
int passenger_count = 0;
int bus_count = 0;
struct Bus
{
    int bus_no;
    char driver_name[50];
    int driver_contact;
    char departure[50];
    char arrival[50];
    char pickup_time[10];
    char dropoff_time[20];
    int seat[16];
};

struct Reservation
{

    int reservation_ID;
    char passenger_name[50];
    int passenger_contact;
    int bus_number;
    int seat_number;
    int fare;
} passenger[150];
struct Bus buses[10];

int main()
{
    // buses = (struct Bus *)malloc(10 * sizeof(struct Bus));
    printf("Bus Management System\n");

    int choice;
    system("color 5");
    while (1)
    {
        system("cls");
        printf("1.Bus Management\n"
               "2.Bus Reservation\n"
               "3.Exit\n"
               "Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            mgm();
            break;
        case 2:
            rsv();
            break;
        case 3:
            printf("Thank You For Using.\n");
            // free(buses);
            return 0;
        default:
            printf("Invalid Input\n");
        }
    }
}

void mgm()
{

    // printf("1.Add New Bus\n"
    //        "2.View All Buses\n"
    //        "3.Back\n"
    //        "Enter your choice : ");

    int choice;
    int running = 1;
    while (running == 1)
    {

        system("cls");
        printf("1.Add New Bus\n"
               "2.View All Buses\n"
               "3.Back\n"
               "Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBus();
            break;
        case 2:
            viewBus();
            break;
        case 3:
            // printf("I am in management");
            running = 0;
            break;
        }
    }
}
void addBus()
{
    system("cls");
  
    printf("\nAdd Bus No :");
    scanf("%d", &buses[bus_count].bus_no);
    printf("\nDriver's Name :");
    scanf(" %[^\n]", buses[bus_count].driver_name);
    printf("\nDriver's Contact No :");
    scanf(" %d", &buses[bus_count].driver_contact);
    printf("\nDeparture :");
    scanf(" %[^\n]", buses[bus_count].departure);
    printf("\nArrival :");
    scanf(" %[^\n]", buses[bus_count].arrival);
    printf("\nPick up time :");
    scanf(" %[^\n]", buses[bus_count].pickup_time);
    printf("\nDrop-off time :");
    scanf(" %[^\n]", buses[bus_count].dropoff_time);

    bus_count++;
    printf("\nBus count %d\n", bus_count);
}
void viewBus()
{
    printf("\nBus count %d\n", bus_count);
    int i;
    int user_confirm;
    printf("Bus No. Driver\tContact No\tDeparture\tArrival\tPick-up time\tDrop-off time\n");
    for (i = 0; i < bus_count; i++)
    {
        printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\n",
               buses[i].bus_no, buses[i].driver_name, buses[i].driver_contact, buses[i].departure,
               buses[i].arrival, buses[i].pickup_time, buses[i].dropoff_time);
    }
    scanf(" %d", &user_confirm);
}

void rsv()
{

    int choice;
    system("cls");
    printf("1.Make Reservation\n"
           "2.View Passenger Records\n"
           "3.Search Reservation\n"
           "4.Edit Reservation\n"
           "5.Cancel Reservation\n"
           "6.Back\n"
           "Enter your choice :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        makeRsv();
        break;
    case 2:
        viewReord();
        break;
    case 3:
        searchRsv();
        break;
    case 4:
        editRsv();
        break;
    case 5:
        cancelRsv();
        break;
    case 6:
        break;
    default:
        printf("Invalid Input");
    }
}
void makeRsv()
{
    system("cls");
    printf("\nReservation ID :");
    scanf("%d", &passenger[passenger_count].reservation_ID);
    printf("Passenger's Name :");
    scanf(" %[^\n]", passenger[passenger_count].passenger_name);
    printf("Passenger's Contact No :");
    scanf("%d", &passenger[passenger_count].passenger_contact);
    printf("Bus Number :");
    scanf("%d", &passenger[passenger_count].bus_number);
    printf("Seat Number :");
    scanf("%d", &passenger[passenger_count].seat_number);
    printf("Fare :");
    scanf("%d", &passenger[passenger_count].fare);

    passenger_count++;
}
void viewReord()
{
    system("cls");
    int i;
    int user_confirm;
    printf("Reservation Id\tPassenger's Name\tContact No\tBus No\tSeat No\tFare\n");
    for (i = 0; i < passenger_count; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n",
               passenger[i].reservation_ID, passenger[i].passenger_name, passenger[i].passenger_contact,
               passenger[i].bus_number, passenger[i].seat_number, passenger[i].fare);
    }
    printf("\nInsert 1 to continue.\n");
    scanf(" %d", &user_confirm);
}
void searchRsv()
{
    int i;
    int search_ID;
    int found = 0;
    int user_confirm;
    system("cls");
    printf("\nPassenger ID : ");
    scanf("%d", &search_ID);
    for (i = 0; i < passenger_count; i++)
    {
        if (search_ID == passenger[i].reservation_ID)
        {
            printf("Reservation ID\tPassenger's Name\tContact No\tBus No\tSeat No\tFare\n");
            printf("%d\t%s\t%d\t%d\t%d\t%d\n",
                   passenger[i].reservation_ID, passenger[i].passenger_name, passenger[i].passenger_contact,
                   passenger[i].bus_number, passenger[i].seat_number, passenger[i].fare);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Reservation not found.");
    }
    printf("\nInsert 1 to continue.\n");
    scanf(" %d", &user_confirm);
}
void editRsv()
{
    system("cls");
    int edit_ID, f = 0, i;
    printf("\nEnter Reservation ID :");
    scanf("%d", &edit_ID);
    for (i = 0; i < passenger_count; i++)
    {
        if (edit_ID == passenger[i].reservation_ID)
        {
            printf("\nEdit Information");
            printf("\nPassenger's Name :");
            scanf(" %[^\n]", passenger[i].passenger_name);
            printf("Passenger's Contact No :");
            scanf("%d", &passenger[i].passenger_contact);
            printf("Bus Number :");
            scanf("%d", &passenger[i].bus_number);
            printf("Seat Number :");
            scanf("%d", &passenger[i].seat_number);
            printf("Fare :");
            scanf("%d", &passenger[i].fare);
            f++;
            break;
        }
    }
    if (f == 0)
        printf("Not Found");
}
void cancelRsv()
{
    system("cls");
    int cancel_ID, f = 0, i, j;
    printf("\nEnter Reservation ID :");
    scanf("%d", &cancel_ID);
    for (i = 0; i < passenger_count; i++)
    {
        if (cancel_ID == passenger[i].reservation_ID)
        {
            for (j = i; j < passenger_count - 1; j++)
                passenger[j] = passenger[j + 1];
            f++;
            passenger_count--;
            break;
        }
    }

    if (f == 0)
    {
        printf("Not Found");
    }
}
