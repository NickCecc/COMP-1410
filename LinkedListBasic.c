#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next; // going to point to next address
};
typedef struct node node_t;

node_t *create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;

}

void printList(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main(void) {
    node_t *head;
    node_t *temp;
    temp = create_new_node(1);
    head = temp;
    temp = create_new_node(2);
    temp->next = head;
    head = temp;
    printList(head);







    return 0;
}