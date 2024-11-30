#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Patient {
    char name[20];
    int age;
    char diagnosis[100];
    struct Patient* next;
} Patient;

Patient* head = NULL;

Patient* createPatient(const char* name, int age, const char* diagnosis) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->diagnosis, diagnosis);
    newPatient->next = NULL;

    return newPatient;
}

void insertAtBeginning(const char* name, int age, const char* diagnosis) {
    Patient* newPatient = createPatient(name, age, diagnosis);
    newPatient->next = head;
    head = newPatient;
    printf("Patient %s added at the beginning.\n", name);
}

void insertAtEnd(char* name, int age, char* diagnosis) {
    Patient* newPatient = createPatient(name, age, diagnosis);

    if (head == NULL) {
        head = newPatient;
        printf("Patient %s added.\n", name);
        return;
    }

    Patient* current = head;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPatient;
    printf("Patient %s added.\n", name);

}

// 1c. Insert patient at a specific position
void insertAtPosition(const char* name, int age, const char* diagnosis, int position) {
    // Check for invalid position
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    // Special case: inserting at beginning
    if (position == 1) {
        insertAtBeginning(name, age, diagnosis);
        return;
    }

    Patient* newPatient = createPatient(name, age, diagnosis);
    Patient* current = head;

    // Traverse to the node before the insertion point
    for (int i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Position exceeds list length.\n");
            free(newPatient);
            return;
        }
        current = current->next;
    }

    // Insert the new patient
    newPatient->next = current->next;
    current->next = newPatient;
    printf("Patient %s added at position %d.\n", name, position);
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
