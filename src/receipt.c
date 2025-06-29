#include <stdio.h>
#include <time.h>
#include "receipt.h"
#include "routes.h"  // To use get_price()

void generate_receipt(int route_id) {
    time_t now;
    time(&now);
    
    // Clear screen and print header
    printf("\n=== BUS TICKET RECEIPT ===\n");
    printf("Date: %s", ctime(&now));
    printf("Transaction ID: %ld\n", now);
    
    // Determine route name
    char* route_name;
    switch(route_id) {
        case 1: route_name = "San José - Heredia"; break;
        case 2: route_name = "San José - Cartago"; break;
        case 3: route_name = "San José - Alajuela"; break;
        case 4: route_name = "Heredia - San José"; break;
        case 5: route_name = "Cartago - San José"; break;
        case 6: route_name = "Alajuela - San José"; break;
        default: route_name = "Unknown Route";
    }
    
    // Get price from routes module
    float price = get_price(route_id);
    
    // Print ticket details
    printf("\nRoute: %s\n", route_name);
    printf("Price: ₡%.2f\n", price);
    
    // Print schedule information
    printf("\nDeparture Times Available:\n");
    if(route_id == 1 || route_id == 4) {
        printf("- Monday-Saturday: Every 8 minutes (5:00 am - 10:00 pm)\n");
        printf("- Sunday: Every 10 minutes (5:00 am - 10:00 pm)\n");
    } 
    else if(route_id == 3 || route_id == 6) {
        printf("- Weekdays: Every 10 minutes (3:00 am - 10:00 pm)\n");
        printf("- Weekends: Every 12 minutes (4:00 am - 10:00 pm)\n");
    } 
    else if(route_id == 2) {
        printf("- Weekdays: Every 12-17 minutes (4:00 am - 11:00 pm)\n");
        printf("- Weekends: Every 15 minutes (5:00 am - 11:00 pm)\n");
    }
    else if(route_id == 5) {
        printf("- Weekdays: Every 20 minutes (4:30 am - 11:00 pm)\n");
        printf("- Weekends: Every 15 minutes (5:00 am - 11:00 pm)\n");
    }
    
    // Generate QR code placeholder
    printf("\nScan this QR code at the station:\n");
    printf("+---------------------+\n");
    printf("|  * * *    * * *     |\n");
    printf("|  *     *      *     |\n");
    printf("|  *   ROUTE %2d   * |\n", route_id);
    printf("|  *     *      *     |\n");
    printf("|  * * *    * * *     |\n");
    printf("+---------------------+\n");
    
    printf("\nThank you for choosing our service!\n");
}
