#include <stdio.h>
#include <stdlib.h>
#include "booking.h"

void make_payment(float amount) {
    printf("\n=== PAYMENT SUMMARY ===\n");
    printf("Total amount to pay: ₡%.2f\n", amount);
    printf("1. Credit Card\n2. Cash\n3. Cancel\n");
    
    int choice;
    printf("Select payment method: ");
    scanf("%d", &choice);
    
    if(choice == 3) {
        printf("Booking cancelled.\n");
        exit(0);
    }
    
    printf("Payment processed successfully!\n");
}
