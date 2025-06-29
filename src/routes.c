#include <stdio.h>
#include <string.h>
#include "routes.h"

typedef struct {
    int id;
    char day[20];
    char time_range[30];
    char frequency[30];
} Schedule;

int show_schedules(int route_id) {
    Schedule schedules[7]; // 7 days of week
    int count = 0;
    
    // Populate schedules based on route
    if(route_id == 1 || route_id == 4) { // SJ-Heredia or Heredia-SJ
        strcpy(schedules[count].day, "Monday");
        strcpy(schedules[count].time_range, "5:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 8 minutes");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Tuesday");
        strcpy(schedules[count].time_range, "5:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 8 minutes");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Wednesday");
        strcpy(schedules[count].time_range, "5:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 8 minutes");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Thursday");
        strcpy(schedules[count].time_range, "5:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 8 minutes");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Friday");
        strcpy(schedules[count].time_range, "5:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 8 minutes");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Saturday");
        strcpy(schedules[count].time_range, "5:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 10 minutes");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Sunday");
        strcpy(schedules[count].time_range, "5:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 10 minutes");
        schedules[count].id = count+1;
        count++;
    }
    else if(route_id == 3 || route_id == 6) { // SJ-Alajuela or Alajuela-SJ
        // Weekdays (Mon-Fri)
        for(int i = 0; i < 5; i++) {
            const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
            strcpy(schedules[count].day, days[i]);
            strcpy(schedules[count].time_range, "3:00 am - 10:00 pm");
            strcpy(schedules[count].frequency, "Every 10 minutes");
            schedules[count].id = count+1;
            count++;
        }
        
        // Saturday
        strcpy(schedules[count].day, "Saturday");
        strcpy(schedules[count].time_range, "4:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 12 minutes");
        schedules[count].id = count+1;
        count++;
        
        // Sunday
        strcpy(schedules[count].day, "Sunday");
        strcpy(schedules[count].time_range, "4:00 am - 10:00 pm");
        strcpy(schedules[count].frequency, "Every 12 minutes");
        schedules[count].id = count+1;
        count++;
    }
    else if(route_id == 2 || route_id == 5) { // SJ-Cartago or Cartago-SJ
        // Weekdays (Mon-Fri)
        for(int i = 0; i < 5; i++) {
            const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
            strcpy(schedules[count].day, days[i]);
            
            if(route_id == 2) { // SJ-Cartago
                strcpy(schedules[count].time_range, "4:00 am - 11:00 pm");
                strcpy(schedules[count].frequency, "Every 12-17 minutes");
            } else { // Cartago-SJ
                strcpy(schedules[count].time_range, "4:30 am - 11:00 pm");
                strcpy(schedules[count].frequency, "Every 20 minutes");
            }
            
            schedules[count].id = count+1;
            count++;
        }
        
        // Weekend (same for both directions)
        strcpy(schedules[count].day, "Saturday");
        strcpy(schedules[count].time_range, "5:00 am - 11:00 pm");
        strcpy(schedules[count].frequency, "Every 15 minutes");
        schedules[count].id = count+1;
        count++;
        
        strcpy(schedules[count].day, "Sunday");
        strcpy(schedules[count].time_range, "5:00 am - 11:00 pm");
        strcpy(schedules[count].frequency, "Every 15 minutes");
        schedules[count].id = count+1;
        count++;
    }

    // Display available schedules
    printf("\nAvailable Schedules:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s. %s (%s)\n", 
               schedules[i].id, 
               schedules[i].day, 
               schedules[i].time_range, 
               schedules[i].frequency);
    }

    // Let user select a schedule
    int choice;
    printf("\nSelect a schedule (1-%d): ", count);
    scanf("%d", &choice);
    
    return choice;
}

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

float get_price(int route_id) {
    switch(route_id) {
        case 1: case 4: return 800.00f;
        case 2: case 5: return 675.00f;
        case 3: case 6: return 735.00f;
        default: return 0.00f;
    }
}

int get_ticket_count() {
    int tickets;
    printf("\nEnter number of tickets (1-10): ");
    scanf("%d", &tickets);
    return (tickets < 1) ? 1 : (tickets > 10) ? 10 : tickets;
}
