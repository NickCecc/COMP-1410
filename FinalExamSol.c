// Ordered Doubly-LinkedList
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_struct {
    char data[15];
    struct Node_struct* next;
    struct Node_struct* previous;
} Node;

// Two global pointers to keep the start and end of the list.
Node* start = NULL;
Node* end = NULL;

// Selection menu (This function has already been developed)
void menu(void);

/*************
 * Develop this function at the bottom of this program
 * Print the list.
 */
void printList();

/*************
 * Develop this function at the bottom of this program
 * Check if the list is empty.
 */
int isEmpty();

/*************
 * Develop this function at the bottom of this program
 * Set the node's data, using a string value.
 */
void setData(Node* node, char* value);

/*************
 * Develop this function at the bottom of this program
 * Insert a new node into the list in its correct location.
 */
void insert(Node* newPtr);

/*************
 * Develop this function at the bottom of this program
 * It recieves a string to delete the very first node equal to it, if found.
 * If found, it returns the string value of the deleted node, Otherwise, returns "" (empty string).
 */
char* delete(char* value);

/*************
 * Develop this function at the bottom of this program
 * Print the list in the reverse order (from the end of the list to the beginning of the list).
 */
void printListReverse();

/*************
 * Read some words from an input file and insert them to the list.
 */
void readData();

/*************
 * Write the list into an output file.
 */
void writeData();

/*************
 * Develop this function at the bottom of this program
 * Safely make a linked list empty.
 */
void emptyList();

// main function
int main(void) {
    Node* newPtr = NULL;
    char item[15];

    // Creating the starting/ending node.
    start = (Node*)malloc(sizeof(Node));
    setData(start, "#");
    end = start;
    puts("An empty ordered Doubly-LinkedList created.");
    puts("********************************************");

    menu();
    printf("%s", "? ");
    unsigned int choice; // user's choice
    scanf("%u", &choice);
    fflush(stdin);

    while (choice != 8) {
        switch (choice) {
            case 1:
                /*************                      (6 marks)
                  * Complete this part:
                  * 1- Prompt the user to input a character.
                 * 2- Read the user's input.
                  * 3- Insert the input character into the list.
                  * 4- Print the linkedlist.
                  */
                printf("%s", "Enter a name (Maximum 14 characters): ");
                fgets(item, 15, stdin);
                if (item[strlen(item) - 1] == '\n')
                    item[strlen(item) - 1] = '\0';
                newPtr = (Node*)malloc(sizeof(Node)); // create node
                setData(newPtr, item);
                insert(newPtr); // insert item in list
                printList();
                break;
            case 2:
                /*************                      (6 marks)
                   * Complete this part:
                   * 1- If the list is empty, print out a proper message and skip this case.
                   *    Otherwise, prompt the user to input a string.
                  * 2- Read the user's input.
                   * 3- Delete the node that has the input string from the list,
                 *    and Print the linkedlist. If not found, show a proper message.
                   */
                if (!isEmpty()) {
                    printf("%s", "Enter character to be deleted: ");
                    fgets(item, 15, stdin);
                    if (item[strlen(item) - 1] == '\n')
                        item[strlen(item) - 1] = '\0';

                    char* found = delete(item);
                    if (strcmp(found, "") != 0) {
                        printf("%s deleted.\n", item);
                        printList();
                    }
                    else
                        printf("%s not found.\n\n", item);
                }
                else
                    puts("List is empty.\n");
                break;
            case 3:
                /*************                      (2 marks)
                    * Complete this part:
                    * 1- If the list is empty, print out a proper message,
                    *    Otherwise, print the linkedlist from the BEGINNING of the list.
                    */
                if (!isEmpty())
                    printList();
                else
                    puts("List is empty.\n");
                break;
            case 4:
                /*************                      (2 marks)
                 * Complete this part:
                 * 1- If the list is empty, print out a proper message,
                 *    Otherwise, print the linkedlist from the END of the list.
                 */
                if (!isEmpty())
                    printListReverse();
                else
                    puts("List is empty.\n");
                break;
            case 5:
                /*************                      (2 marks)
                 * Complete this part:
                 * Call the proper fnnction to read from an input file.
                 */
                readData();
                break;
            case 6:
                /*************                      (2 marks)
                 * Complete this part:
                 * Call the proper fnnction to write the list into a file.
                 */
                if (!isEmpty())
                    writeData();
                else
                    puts("List is empty.\n");
                break;
                // Handling invalid choice
            case 7:
                /*************                      (2 marks)
                 * Complete this part:
                 * Call the proper fnnction to empty the list.
                 */
                if (!isEmpty())
                    emptyList();
                puts("List is empty.\n");
                break;
            default:
                puts("Invalid choice.\n");
                break;
        } // end switch

        menu();
        printf("%s", "? ");
        scanf("%u", &choice);
        fflush(stdin);
    }
    puts("End of run.");
}

// Display the menu options.
void menu(void) {
    puts("Enter your choice:\n"
         "   1 to insert an element into the list.\n"
         "   2 to delete an element from the list.\n"
         "   3 to print the list from the beginning.\n"
         "   4 to print the list from the end.\n"
         "   5 Read some words from input file and insert them to the list.\n"
         "   6 Write the list into the output file.\n"
         "   7 Empty the list.\n"
         "   8 to end.");
}

// Print the list
void printList() {
    Node* currentPtr = start->next;
    puts("The list is:");
    printf("%s", "NULL <--> ");
    // while not the end of the list
    while (currentPtr != NULL) {
        printf("%s <--> ", currentPtr->data);
        currentPtr = currentPtr->next;
    }
    puts("NULL\n");
}

// Return 1 if the list is empty, 0 otherwise
int isEmpty() {
    return start->next == NULL;
}

/*************                      (4 marks)
 * Develop function setData.
 */
void setData(Node* node, char* value) {
    strcpy(node->data, value); // place value in node
    node->next = NULL;      // node does not link to another node
    node->previous = NULL;      // node does not link to another node
}

/*************                      (14 marks)
 * Develop function insert.
 */
void insert(Node* newPtr) {
    Node* previousPtr = start;
    Node* currentPtr = start->next;

    // loop to find the correct location in the list
    while (currentPtr != NULL && strcmp(newPtr->data, currentPtr->data) > 0) {
        previousPtr = currentPtr;         // walk to ...
        currentPtr = currentPtr->next; // ... next node
    }
    newPtr->previous = previousPtr;
    previousPtr->next = newPtr;
    newPtr->next = currentPtr;
    if (currentPtr != NULL)             // We insert the new node between two existing nodes
        currentPtr->previous = newPtr;
    else                                // We append the new node to the end of the list, and update end pointer
        end = newPtr;
}

/*************                      (14 marks)
 * Develop function delete.
 */
char* delete(char* value) {
    Node* previousPtr = start;
    Node* currentPtr = start->next;

    // loop to find the correct location in the list
    while (currentPtr != NULL && strcmp(currentPtr->data, value) != 0) {
        previousPtr = currentPtr;         // walk to ...
        currentPtr = currentPtr->next; // ... next node
    }
    // delete node at currentPtr
    if (currentPtr != NULL) {
        Node* tempPtr = currentPtr;
        if (currentPtr->next != NULL)                       // We are going to delete a node in between the list
            currentPtr->next->previous = previousPtr;
        else                                                // We are going to delete the last node
            end = previousPtr;
        previousPtr->next = currentPtr->next;
        free(tempPtr);
        return value;
    }
    else
        return "";
}

/*************                      (7 marks)
 * Develop function printListReverse.
 */
void printListReverse() {
    Node* currentPtr = end;
    puts("The list in reverse order is:");
    printf("%s", "NULL <--> ");
    // while not the beginning of the list
    while (currentPtr != start) {
        printf("%s <--> ", currentPtr->data);
        currentPtr = currentPtr->previous;
    }
    puts("NULL\n");
}

void readData() {
    FILE* in;
    if ((in = fopen("input.txt", "r")) == NULL) {
        puts("input file could not be opened.");
        return;
    }
    char word[15];
    Node* newPtr = NULL;
    while (!feof(in)) {
        fscanf(in,"%14s\n", word);
        newPtr = (Node*)malloc(sizeof(Node));
        setData(newPtr, word);
        insert(newPtr);
    }
    fclose(in);
}

void writeData() {
    FILE* out;
    if ((out = fopen("output.txt", "w")) == NULL) {
        puts("Output file could not be opened.");
        return;
    }
    if (isEmpty())
        fprintf(out,"List is empty.\n");
    else {
        Node* current = start->next;
        while (current != NULL) {
            fprintf(out,"%s\n", current->data);
            current = current->next;
        }
    }
    puts("List stored to the output file.");
    fclose(out);
}

void emptyList() {
    while (start->next != NULL) {
        Node* temp = start;
        start = start->next;
        free(temp);
    }
    end = start;
}