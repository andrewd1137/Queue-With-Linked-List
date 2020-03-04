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
    head = NULL;
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

    tail->next = NULL;
    strcpy(tail->name, fName);

    if(head == NULL){
        head = tail;
    } else{
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = tail;
    }
}

void printCustomerNames(){
    struct customer *custPointer = head;

    if(custPointer == NULL){
        printf("The list is empty.\n\n");
    }
    else {
        printf("\nCustomer List:\n");
    }
    while (NULL != custPointer) {
            puts(custPointer->name);
            custPointer = custPointer->next;
    }
}