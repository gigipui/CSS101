#include <stdio.h>
#include <stdlib.h>

int checkID(int *acc, int temp, int count);

int main() {
    int count = 3;           
    int capacity = 5;        
    int acc[capacity];  

    acc[0] = 1234;
    acc[1] = 5678;
    acc[2] = 9012;

    printf("Existing account IDs:\n");
    for (int i = 0; i < count; i++) {
        printf("%i\n", acc[i]);
    }

    printf("\nWelcome new user! Please create a new account.\n");

    int temp;
    while (1) { 
        printf("Please enter a four-digit ID: ");
        scanf("%i", &temp);

        
        if (checkID(acc, temp, count)) {
            printf("ID %i already exists, please try again.\n", temp);
        } else {
            acc[count] = temp;
            count++;
            printf("Account created successfully, your ID is %i.\n", temp);
            break;  
        }
    }

    printf("\nAll account IDs:\n");
    for (int i = 0; i < count; i++) {
        printf("%i\n", acc[i]);
    }

    return 0;
}

int checkID(int acc[], int temp, int count) {
    for (int i = 0; i < count; i++) {
        if (temp == acc[i]) {
            return 1;  
        }
    }
    return 0;  

} 
