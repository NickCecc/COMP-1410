#include <stdio.h>

typedef struct node{
    int value;
    struct node* next; // going to point to next address
};

void printList(struct node *head){
    struct node *temp = head;
    for(int i = 0; i < 3; i++){
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}


#include <string.h>


typedef struct Data_struct {
    int ID;
    char type[8];
} Data;


int main(void) {
    const int NUM_DATA = 2;
    Data idData[NUM_DATA];
    int i;

    idData[0].ID = 0;
    strcpy(idData[0].type, "Public");
    idData[1].ID = 1;
    strcpy(idData[1].type, "Private");
    printf("Total data: %d", NUM_DATA);

    for (i = 0; i < NUM_DATA; ++i) {
        printf(" ID: %d", idData[i].ID);
        printf(" type %s", idData[i].type);
    }

    return 0;
}