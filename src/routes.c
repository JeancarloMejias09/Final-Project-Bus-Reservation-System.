#include <stdio.h>
#include <string.h>
#include "routes.h"

typedef struct {
    int id;
    char day[20];
    char time[10];
} Schedule;

int show_routes() {
    printf("\nAvailable Routes:\n");
    printf("1. San José - Heredia (₡800)\n");
    printf("2. San José - Cartago (₡675)\n");
    printf("3. San José - Alajuela (₡735)\n");
    printf("4. Heredia - San José (₡800)\n");
    printf("5. Cartago - San José (₡675)\n");
    printf("6. Alajuela - San José (₡735)\n");

    int choice;
    printf("\nSelect a route (1-6): ");
    scanf("%d", &choice);

    return choice;
}

int show_schedules(int route_id) {
    Schedule schedules[10];
    int count = 0;
    
    // Populate schedules based on route
    if(route_id == 1 || route_id == 4) {
        // San José-Heredia or Heredia-San José
        strcpy(schedules[count].day, "Monday-Friday");
        strcpy(schedules[count].time, "5:00 am");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Saturday");
        strcpy(schedules[count].time, "6:00 am");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Sunday");
        strcpy(schedules[count].time, "7:00 am");
        schedules[count].id = count+1;
        count++;
    }
    else if(route_id == 3 || route_id == 6) {
        // San José-Alajuela or Alajuela-San José
        strcpy(schedules[count].day, "Monday-Friday");
        strcpy(schedules[count].time, "6:00 am");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Saturday");
        strcpy(schedules[count].time, "7:00 am");
        schedules[count].id = count+1;
        count++;
    }
    else if(route_id == 2 || route_id == 5) {
        // San José-Cartago or Cartago-San José
        strcpy(schedules[count].day, "Monday-Friday");
        strcpy(schedules[count].time, "5:30 am");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Weekend");
        strcpy(schedules[count].time, "8:00 am");
        schedules[count].id = count+1;
        count++;
    }

    // Display available schedules
    printf("\nAvailable Schedules:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s at %s\n", schedules[i].id, schedules[i].day, schedules[i].time);
    }

    // Let user select a schedule
    int choice;
    printf("\nSelect a schedule (1-%d): ", count);
    scanf("%d", &choice);
    
    return choice; // Return selected schedule ID
}

float get_price(int route_id) {
    // Pricing
    switch(route_id) {
        case 1: // San José-Heredia
        case 4: // Heredia-San José
            return 800.00f;
        case 2: // San José-Cartago
        case 5: // Cartago-San José
            return 675.00f;
        case 3: // San José-Alajuela
        case 6: // Alajuela-San José
            return 735.00f;
        default:
            return 0.00f;
    }
}

int get_ticket_count() {
    int tickets;
    printf("\nEnter number of tickets (1-10): ");
    scanf("%d", &tickets);
    
    // Basic input validation
    if(tickets < 1) tickets = 1;
    if(tickets > 10) tickets = 10;
    
    return tickets;
}
