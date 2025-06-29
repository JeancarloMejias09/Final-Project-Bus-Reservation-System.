#include <stdio.h>
#include "routes.h"

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
    printf("\nAvailable Schedules:\n");
    
    if(route_id == 1 || route_id == 4) {
        // San José-Heredia or Heredia-San José
        printf("Monday-Saturday: 5:00 am to 10:00 pm (every 8 minutes)\n");
        printf("Sunday: 5:00 am to 10:00 pm (every 10 minutes)\n");
    } 
    else if(route_id == 3 || route_id == 6) {
        // San José-Alajuela or Alajuela-San José
        printf("Monday-Friday: 3:00 am to 10:00 pm (every 10 minutes)\n");
        printf("Saturday-Sunday: 4:00 am to 10:00 pm (every 12 minutes)\n");
    } 
    else if(route_id == 2) {
        // San José-Cartago
        printf("Monday-Friday: 4:00 am to 11:00 pm (every 12-17 minutes)\n");
        printf("Saturday-Sunday: 5:00 am to 11:00 pm (every 15 minutes)\n");
    }
    else if(route_id == 5) {
        // Cartago-San José
        printf("Monday-Friday: 4:30 am to 11:00 pm (every 20 minutes)\n");
        printf("Saturday-Sunday: 5:00 am to 11:00 pm (every 15 minutes)\n");
    }
    
    printf("\nPress Enter to confirm your selection...");
    getchar();  // Clear input buffer
    getchar();  // Wait for Enter
    
    return route_id;
}

float get_price(int route_id) {  // Removed schedule_id parameter
    // Pricing based on your specifications
    switch(route_id) {
        case 1: // San José-Heredia
        case 4: // Heredia-San José
            return 800.00f;  // Colones
        case 2: // San José-Cartago
        case 5: // Cartago-San José
            return 675.00f;
        case 3: // San José-Alajuela
        case 6: // Alajuela-San José
            return 735.00f;
        default:
            return 0.00f;  // Should never happen with proper input validation
    }
}
