#include <stdio.h>
#include <time.h>
#include "receipt.h"
#include "routes.h"  // To use get_price()

void generate_receipt(int route_id, int schedule_id, int tickets) {
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
    
    // Get price and calculate total
    float unit_price = get_price(route_id);
    float total_price = unit_price * tickets;
    
    // Print ticket details
    printf("\nRoute: %s\n", route_name);
    printf("Unit Price: ₡%.2f\n", unit_price);
    printf("Number of Tickets: %d\n", tickets);
    printf("Total Price: ₡%.2f\n", total_price);
    
    // Print specific schedule information
    printf("\nSelected Schedule:\n");
    switch(schedule_id) {
        case 1:
            printf("- Monday-Friday at 5:00 am\n");
            break;
        case 2:
            printf("- Saturday at 6:00 am\n");
            break;
        case 3:
            printf("- Sunday at 7:00 am\n");
            break;
        // Add more cases as needed
        default:
            printf("- Standard schedule\n");
    }
    
    // Generate QR code placeholder
    printf("\nScan this QR code at the station:\n");
    printf("+---------------------+\n");
    printf("|  * * *    * * *     |\n");
    printf("|  *     *      *     |\n");
    printf("|  * TICKET x%-2d  * |\n", tickets);  // Updated to show ticket count
    printf("|  *     *      *     |\n");
    printf("|  * * *    * * *     |\n");
    printf("+---------------------+\n");
    
    printf("\nThank you for choosing our service!\n");
}
