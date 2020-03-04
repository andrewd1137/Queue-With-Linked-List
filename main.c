//Andrew DeMarco
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myCustomerLink.h"

struct customer {
    char name[50];
    struct customer *next;
};

struct customer *head;

int main() {
    int menu = 0;
    head = NULL; //start off empty
    char firstName[50];

    while (menu != 3) {
        printf("\nPress 1 to add a Customer.\nPress 2 to print customers in line.\nPress 3 to exit program.\n\nEnter a menu key:");
        scanf("%i", &menu);

        if (menu == 1){
            printf("Enter the Customer's First Name: ");
            scanf("%s", firstName);
            addCustomerNames(firstName);
        }

        if (menu == 2){
            printCustomerNames();
        }
        if (menu == 3)break;
    }

    return 0;
}

void addCustomerNames(char fName[50]){
    struct customer *current;
    struct customer *tail = malloc(sizeof(struct customer));

    tail->next = NULL; //tail is the end of the list
    strcpy(tail->name, fName); //next element is going at the end of the list
    
    //this is the first element being added to the list
    if(head == NULL){
        head = tail; 
    } 
    else{
        //go through the list until you get to the tail and then add the item at the end
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = tail;
    }
}

void printCustomerNames(){
    struct customer *custPointer = head;
    //empty list
    if(custPointer == NULL){
        printf("The list is empty.\n\n");
    }
    else {
        //prints the customer list with every element 
        printf("\nCustomer List:\n");
    }
    while (NULL != custPointer) {
            puts(custPointer->name);
            custPointer = custPointer->next;
    }
}
