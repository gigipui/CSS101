// Menu: option 1: Create New Task (Exist and New)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef enum Priority{
    HIGH = 1, MEDIUM, LOW
}Priority;

typedef enum Category{
    HOME, PERSONAL, HOBBY, SCHOOL
}Category;

typedef struct Task{
    char name[50];
    int category;
    int priority;
    char deadline[50];
    bool status;

}Task;

void saveTask(Task task);
 
int validateCategoryInput(const char* question);
int validatePriorityInput(const char* question);



int main(){

    Task task;

    // char name[50];
    // int category;
    // int priority;
    // char deadline[50];
    // bool status;

    // Task Name//

    printf("Please enter the task name: ");
    fgets(task.name, sizeof(task.name), stdin);
    task.name[strcspn(task.name, "\n")] = '\0';  // Remove the newline character


    //category//
   
    /*display category*/
    printf("====================\n");
    printf("Category: \n");
    printf("1 : HOME \n");
    printf("2 : PERSONAL \n");
    printf("3 : HOBBY \n");
    printf("4 : SCHOOL \n");
    printf("==================== \n");

    task.category = validateCategoryInput("Please enter the task category (1-4):");
    //priority

    /*display priority*/
    printf("==================== \n");
    printf("Priority: \n");
    printf("1 : HIGH \n");
    printf("2 : MEDIUM \n");
    printf("3 : LOW \n");
    printf("==================== \n");


    task.priority = validatePriorityInput("Please enter the task priority (1-3): ");

    //deadline
    printf("Please enter the task deadline (YYYY-MM-DD HH:MM:SS): ");
    while(getchar() != '\n');
    fgets(task.deadline, sizeof(task.deadline), stdin);
    task.deadline[strcspn(task.deadline, "\n")] = '\0'; // Remove the newline character


    //status
    task.status = false;
    // can be EDITED by existing user

    saveTask(task);

    printf("Task has been saved successfully! \n");

    return 0;

}

int validateCategoryInput(const char* question){
    
    int value;
    printf("%s", question);

    while(1){
        int status = scanf("%i",&value);

        if(status != 1 || value <= 0 || value > 4){
            printf("Invalid input. Please enter a valid NUMBER in between 1-4.\n");
            while(getchar() != '\n');
        }else {
            break;
        }

        

    }
    return value;
    
}

int validatePriorityInput(const char* question) {
    int value;
    printf("%s", question);

    while (1) {
        int status = scanf("%i", &value);

        if (status != 1 || value < 1 || value > 3) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    }
    return value;
}

void saveTask(Task task) {
    FILE *file = fopen("task.txt", "a");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }

    fprintf(file, "%s,%d,%d,%s,%d\n", task.name, task.category, task.priority, task.deadline, task.status);
    fclose(file);
}
