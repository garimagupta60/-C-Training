#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef enum {
    VIP = 1,
    SENIOR_CITIZEN,
    GENERAL
} PassengerType;
 
typedef struct Passenger {
    int id;
    PassengerType passenger;
    char name[50];
    struct Passenger* next;
} Passenger;
 
Passenger* front = NULL;
Passenger* rear = NULL;
 
PassengerType getenum(char* string) {
    if (strcmp(string, "VIP") == 0) return VIP;
    if (strcmp(string, "SENIOR_CITIZEN") == 0) return SENIOR_CITIZEN;
    return GENERAL;
}
 
char* getstring(PassengerType passenger) {
    switch (passenger) {
        case VIP: return "VIP";
        case SENIOR_CITIZEN: return "SENIOR_CITIZEN";
        case GENERAL: return "GENERAL";
        default: return "UNKNOWN";
    }
}
 
Passenger* createpassenger(int id, PassengerType passenger, char* name) {
    Passenger* newpassenger = (Passenger*)malloc(sizeof(Passenger));
    newpassenger->id = id;
    newpassenger->passenger = passenger;
    strcpy(newpassenger->name, name);
    newpassenger->next = NULL;
    return newpassenger;
}
 
void enqueue(int id, PassengerType passenger, char* name) {
    Passenger* new_passenger = createpassenger(id, passenger, name);
    if (front == NULL) {
        front = rear = new_passenger;
    } else {
        Passenger* current = front;
        Passenger* prev = NULL;
       
        while (current != NULL && current->passenger <= passenger) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            new_passenger->next = front;
            front = new_passenger;
        } else {
            prev->next = new_passenger;
            new_passenger->next = current;
            if (current == NULL) rear = new_passenger;
        }
    }
}
 
void dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty");
        return;
    }
    Passenger* temp = front;
    front = front->next;
    printf("Serving Passenger: ID %d, Name: %s, Type: %s\n", temp->id, temp->name, getstring(temp->passenger));
    free(temp);
}
 
void displayQueue() {
    if (front == NULL) {
        printf("\nQueue is empty");
        return;
    }
    printf("Waiting Passengers:\n");
    Passenger* temp = front;
    while (temp != NULL) {
        printf("ID %d, Name: %s, Type: %s\n", temp->id, temp->name, getstring(temp->passenger));
        temp = temp->next;
    }
}

int isnumber(char input){
    if(input>='0' && input<='9')return 1;
    return 0;
}

int ischaracter(char input){
    return ((input>='a' && input<='z') || (input>='A' && input<='Z')|| (input == ' ' || input=='_'));
}
void parseinput(char *inputstring){
    int index = 0;
    int operationnumber = 0;
    int id=0;
    char* passengercategories = (char*)malloc(sizeof(char)*51);
    char* name = (char*)malloc(sizeof(char)*51);
    int passengerindex = 0;
    int nameindex= 0;
    while(isnumber(inputstring[index])){
        operationnumber = operationnumber*10 + (inputstring[index]-'0');
        index++;
    }
    while(inputstring[index] == ',' || inputstring[index] == ' ')index++;
    while(isnumber(inputstring[index])){
        id = id*10 + (inputstring[index]-'0');
        index++;
    }
    while(inputstring[index] == ',' || inputstring[index] == ' ')index++;
    while(ischaracter(inputstring[index])){
        passengercategories[passengerindex++] = inputstring[index++];
    }
    passengercategories[passengerindex] = '\0';
    while(inputstring[index] == ',' || inputstring[index] == ' ' || inputstring[index] == '"')index++;
    while(ischaracter(inputstring[index])){
        name[nameindex++] = inputstring[index++];
    }
    name[nameindex] = '\0';
    while(inputstring[index] == '"' || inputstring[index] == ';' || inputstring[index] == '\0')index++;
    if(operationnumber == 1){
        enqueue(id, getenum(passengercategories), name);
    }
    else if (operationnumber == 2) {
        dequeue();
    } else if (operationnumber == 3) {
        displayQueue();
    } else {
        printf("\nInvalid choice was entered");
    }
}
 
int main() {
    int numberofoperations, choice, id;
    char passenger[20], name[50];
    scanf("%d", &numberofoperations);
    getchar();
    char inputstring[1000];
    for (int i = 0; i < numberofoperations; i++) {
        scanf("%[^\n]%*c",inputstring);
        parseinput(inputstring);
    }
    return 0;
}
 
 