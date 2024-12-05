// Menu: option 1: Create New Task (Exist and New)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum Priority{
    HIGH = 1, MEDIUM, LOW
}Priority;

typedef enum Category{
    HOME = 1, PERSONAL, HOBBY, SCHOOL
}Category;

typedef struct Task{
    int ID;
    char name[50];
    int category;
    int priority;
    char deadline[50];
    bool status;

}Task;

//----MENU----//

void menu();

// 1 - Create Task //

void createTask();
void initialiseTaskCount();
void saveTask(Task task);
int validateCategoryInput(const char* question);
int validatePriorityInput(const char* question);

void displayReport();

// 2 - Edit Status //
// 3 - Remove Task //
// 4 - Display All Task //


int main() {
    initialiseTaskCount();
    menu(); 
    return 0;
}

int taskcount = 0;

void menu() {

    int choice;

    printf("\n========= Menu =========\n");
    printf("1. Create New Task \n");
    printf("2. Edit Status \n");
    printf("3. Remove Task \n");
    printf("4. Display All Task \n");
    printf("5. Exit \n");

    while (1) {
        
        printf("Please Enter 1-5 to continue: ");
        scanf("%d", &choice);

        if( choice < 1 || choice > 5 ){
        printf("Please enter a valid number between 1-5. \n");
        continue;
        }

        while(getchar() != '\n');

        switch (choice) {
            case 1:
                createTask(); 
                break;
            case 4:
                displayReport();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Coming soon...\n");
        }
    }
}

/*---Create Task---*/
void createTask(){

    Task task;
    
    task.ID = ++taskcount ;


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
    printf("Please enter the task deadline (YYYY-MM-DD): ");
    while(getchar() != '\n');
    fgets(task.deadline, sizeof(task.deadline), stdin);
    task.deadline[strcspn(task.deadline, "\n")] = '\0'; // Remove the newline character


    //status
    task.status = false;
    // can be EDITED by existing user

    saveTask(task);

    printf("Task has been saved successfully! \n");

}

void initialiseTaskCount(){
    FILE *file = fopen("task.txt","r");
    if(file == NULL) {
        taskcount = 0; // if file doesn't exist, taskcount remains 0
    }

    int id;
    char buffer[200];

    while(fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "%i", &id);
        if(id > taskcount) {
            taskcount = id; // renew latest ID
        }
    }

    fclose(file);
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

    fprintf(file, "%i,%s,%d,%d,%s,%d\n", task.ID, task.name, task.category, task.priority, task.deadline, task.status);
    fclose(file);
}


/*---Edit Status---*/
bool editStatus(){
    
}

/*---Display ALL---*/
void displayReport(){

    FILE *file = fopen("task.txt","r");

    if(file == NULL){
        printf("Error opening file!");
        exit(1);
    }

    char buffer[256];
    int ID;
    char name[50];
    int category;
    int priority;
    char deadline[20];
    bool status;

    printf("\nTask List:\n");
    printf("%-10s %-15s %-10s %-10s %-20s %-15s\n", "Task ID", "Task Name", "Category", "Priority", "Deadline", "Status");

    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%d,%[^,],%d,%d,%19[^,],%d", &ID, name, &category, &priority, deadline, &status);
        
        char* statusText;
        if(status == 0){
            statusText = "Not Completed";
        }else{
            statusText = "Completed";
        }

        printf("%-10d %-15s %-10d %-10d %-20s %-15s\n", ID, name, category, priority, deadline, statusText);        
    }

    fclose(file);
}
