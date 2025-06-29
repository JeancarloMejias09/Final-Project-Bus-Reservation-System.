#include <stdio.h>
#include "auth.h"
#include "routes.h"
#include "booking.h"
#include "receipt.h"
#include "helpers.h"
#include <stdlib.h>  // for exit()
#include <unistd.h>  // for sleep()

void show_auth_menu() {
    int choice;
    do {
        clear_screen();
        print_header("WELCOME TO BUS RESERVATION SYSTEM");
        printf("\n1. Login\n");
        printf("2. Sign Up\n");
        printf("3. Exit\n");
        printf("\nSelect option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(user_login()) {
                    return; // Proceed to main system
                }
                break;
            case 2:
                if(user_signup()) {
                    printf("Please login with your new credentials.\n");
                    sleep(2); // Give time to read message
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
        sleep(1); // Pause before clearing screen
    } while(1);
}

int main() {
    show_auth_menu();
    
    clear_screen();
    print_header("COSTA RICA'S BUS RESERVATION SYSTEM");
    
    int route_id = show_routes();
    int schedule_id = show_schedules(route_id);  //Unused
    (void)schedule_id;  //Mark as unused to suppress warning
    float price = get_price(route_id);
    make_payment(price);
    generate_receipt(route_id);
    
    return 0;
}
