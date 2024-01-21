// TODO: Modify the code so that the vector holds characters instead of integers -- a flexible string

#include <stdio.h>
#include <stdlib.h>

// TODO: Modify the code so that the vector holds characters instead of integers -- a flexible string

#ifndef VECTOR_H
#define VECTOR_H

#include "string.h"                          // for conversion

// struct and typedef declaration for Vector ADT
typedef struct vector_struct {
    char* elements;
    unsigned int size;
} vector;

// interface for accessing Vector ADT

// Initialize vector
void vector_create(vector* v, unsigned int vectorSize);

// Destroy vector
void vector_destroy(vector* v);

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize);

// Return pointer to element at specified index
int* vector_at(vector* v, unsigned int index);

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, char value);

// Insert new value at end of vector
void vector_push_back(vector* v, char value);

// Erase (remove) value at specified index
void vector_erase(vector* v, unsigned int index);

// Return number of elements within vector
int vector_size(vector* v);

// Convert an ordinary string to a vector
void vector_from_string(vector*, char* string);

// Print the vector as if it were a string
void vector_print(vector* v);

#endif


// Initialize vector with specified size
void vector_create(vector* v, unsigned int vectorSize) {
    int i;

    if (v == NULL) return;

    v->elements = (char*)malloc(vectorSize * sizeof(char));;
    v->size = vectorSize;
    for (i = 0; i < v->size; ++i) {
        v->elements[i] = 0;
    }
}

// Destroy vector
void vector_destroy(vector* v) {
    if (v == NULL) return;

    free(v->elements);
    v->elements = NULL;
    v->size = 0;
}

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize) {
    int oldSize;
    int i;

    if (v == NULL) return;

    oldSize = v->size;
    v->elements = (char*)realloc(v->elements, vectorSize * sizeof(char));
    v->size = vectorSize;
    for (i = oldSize; i < v->size; ++i) {
        v->elements[i] = 0;
    }
}

// Return pointer to element at specified index
int* vector_at(vector* v, unsigned int index) {
    if (v == NULL || index >= v->size) return NULL;

    return &(v->elements[index]);
}

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, char value) {
    int i;

    if (v == NULL || index > v->size) return;

    vector_resize(v, v->size + 1);
    for (i = v->size - 1; i > index; --i) {
        v->elements[i] = v->elements[i-1];
    }
    v->elements[index] = value;
}

// Insert new value at end of vector
void vector_push_back(vector* v, char value) {
    vector_insert(v, v->size, value);
}

// Erase (remove) value at specified index
void vector_erase(vector* v, unsigned int index) {
    int i;

    if (v == NULL || index >= v->size) return;

    for (i = index; i < v->size - 1; ++i) {
        v->elements[i] = v->elements[i+1];
    }
    vector_resize(v, v->size - 1);
}

// Return number of elements within vector
 int vector_size(vector* v) {
    if (v == NULL) return -1;

    return v->size;
}

// Convert an ordinary string to a vector
void vector_from_string(vector* v, char* string) {
    vector_create(v, strlen(string));

    /* Type your code here. */
    unsigned int len = strlen(string);
    vector_create(v, len);

    for(int i = 0; i < len; i++){
        v->elements[i] = string[i];
    }

}

// Print the elements of the vector (no final newline)
void vector_print(vector* v) {

    /* Type your code here. */

    for(int i = 0; i < v->size; i++){
        printf("%c", v->elements[i]);
    }
}


int main(void) {
    int a;
    int b;
    char char1;
    char char2;
    vector v;
    char string[50];

    // Read a string
    scanf("%s\n", string);

    // TODO: Create a vector from the input string
    vector_create(&v, strlen(string));
    vector_from_string(&v, string);





    vector_print(&v);
    printf("\n");

    // Read a character char1
    scanf("%c", &char1);

    // TODDO: Add char1 to the end of the string
    vector_push_back(&v, char1);

    vector_print(&v);
    printf("\n");

    // Read two indices a and b
    scanf("%d %d", &a, &b);

    // TODO: Remove the character at index a from the vector,
    // then remove the character at index b of the modified vector
    vector_erase(&v, a);
    vector_erase(&v, b);

    vector_print(&v);
    printf("\n");

    // Read two pairs of index and character
    scanf("%d %c %d %c", &a, &char1, &b, &char2);

    // TODO: Replace the character at index a with char1 and
    // the character at index b with char2
    vector_erase(&v, a);
    vector_insert(&v, a, char1);
    vector_erase(&v, b);


    vector_insert(&v, b, char2);
    vector_print(&v);
    printf("\n");

    // Read two pairs of index and character
    scanf("%d %c %d %c", &a, &char1, &b, &char2);

    // TODO: Insert character char1 before index a of the vector, then
    // insert character char2 before index b of the modified vector

    vector_insert(&v, a, char1);
    vector_insert(&v, b-1, char2);
    vector_print(&v);
    printf("\n");

    // TODO: Free the memory allocated to the vectort
    vector_destroy(&v);

    return 0;
}