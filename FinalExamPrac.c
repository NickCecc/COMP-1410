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

                printf("Enter a name (Maximum 14 characters):\n");
                fgets(item, 15, stdin);
                newPtr = (Node*)malloc(sizeof(Node)); // create node
                setData(newPtr, item);
                insert(newPtr);
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
                   if(!isEmpty()){
                       printf("Enter a name (Maximum 14 characters):\n");
                       fgets(item, 15, stdin);
                       char *del = delete(item);
                       printList();
                       if(strcmp(del, "")){
                           printf("%s deleted", del);


                       } else{
                           printf("%s not found.\n\n", item);

                       }


                   }

                break;
            case 3:
                /*************                      (2 marks)
                    * Complete this part:
                    * 1- If the list is empty, print out a proper message,
                    *    Otherwise, print the linkedlist from the BEGINNING of the list.
                    */


                break;
            case 4:
                /*************                      (2 marks)
                 * Complete this part:
                 * 1- If the list is empty, print out a proper message,
                 *    Otherwise, print the linkedlist from the END of the list.
                 */

                break;
            case 5:
                /*************                      (2 marks)
                 * Complete this part:
                 * Call the proper fnnction to read from an input file.
                 */

                break;
            case 6:
                /*************                      (2 marks)
                 * Complete this part:
                 * Call the proper fnnction to write the list into a file.
                 */

                break;
                // Handling invalid choice
            case 7:
                /*************                      (2 marks)
                 * Complete this part:
                 * Call the proper fnnction to empty the list.
                 */

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


/*************                      (14 marks)
 * Develop function insert.
 */


/*************                      (14 marks)
 * Develop function delete.
 */
char* delete(char* value){

}



/*************                      (7 marks)
 * Develop function printListReverse.
 */




