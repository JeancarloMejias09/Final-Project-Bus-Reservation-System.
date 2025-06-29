#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.h"

#define MAX_USERS 100
#define CREDENTIALS_FILE "data/users.txt"

typedef struct {
    char username[50];
    char password[50];
} User;

int user_signup() {
    User new_user;
    User users[MAX_USERS];
    int user_count = 0;
    
    // Read existing users
    FILE *file = fopen(CREDENTIALS_FILE, "r");
    if (file) {
        while (fscanf(file, "%49s %49s", users[user_count].username, users[user_count].password) == 2) {
            user_count++;
            if (user_count >= MAX_USERS) break;
        }
        fclose(file);
    }

    // Get new user credentials
    printf("\n=== SIGN UP ===\n");
    printf("Enter username: ");
    scanf("%49s", new_user.username);
    
    // Check if username exists
    for (int i = 0; i < user_count; i++) {
        if (strcmp(new_user.username, users[i].username) == 0) {
            printf("Username already exists!\n");
            return 0;
        }
    }
    
    printf("Enter password: ");
    scanf("%49s", new_user.password);
    
    // Save to file
    file = fopen(CREDENTIALS_FILE, "a");
    if (!file) {
        printf("Error saving credentials!\n");
        return 0;
    }
    
    fprintf(file, "%s %s\n", new_user.username, new_user.password);
    fclose(file);
    
    printf("Registration successful!\n");
    return 1;
}

int user_login() {
    User user;
    User stored_user;
    int found = 0;
    
    printf("\n=== LOGIN ===\n");
    printf("Username: ");
    scanf("%49s", user.username);
    printf("Password: ");
    scanf("%49s", user.password);
    
    FILE *file = fopen(CREDENTIALS_FILE, "r");
    if (!file) {
        printf("No users registered yet!\n");
        return 0;
    }
    
    while (fscanf(file, "%49s %49s", stored_user.username, stored_user.password) == 2) {
        if (strcmp(user.username, stored_user.username) == 0 && 
            strcmp(user.password, stored_user.password) == 0) {
            found = 1;
            break;
        }
    }
    
    fclose(file);
    
    if (found) {
        printf("\nLogin successful!\n");
        return 1;
    } else {
        printf("\nInvalid username or password!\n");
        return 0;
    }
}
