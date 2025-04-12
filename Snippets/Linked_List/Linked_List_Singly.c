#include <stdio.h>
#include <stdlib.h>

/*
* Example implementation of a singly linked list
*
* @author Szymon Zemojtel
* @version 1
*/

struct list_item {
    int number_data;
    struct list_item *next;
};

struct list_item list_header;

struct list_item *create_item(int value);
void insert_beginning(struct list_item **head, struct list_item *item_to_insert);
void insert_end(struct list_item **head, struct list_item *item_to_insert);
void free_list(struct list_item **head);
void swap_items_by_pointer(struct list_item **head, struct list_item *a, struct list_item *b);
struct list_item *get_item_by_value(struct list_item *head, int value);

void print_list(struct list_item *head);


int main(void) {
    struct list_item *head = NULL;

    puts("Linked list structure, before any data is added:");
    print_list(head);

    ////////////////////////////////////////////////////////
    // INSERTING ITEMS TO BEGINNING
    ////////////////////////////////////////////////////////

    // test data: insert 30, then 20, then 10
    puts("Inserting 40 to the beginning of the linked list:");
    insert_beginning(&head, create_item(40));
    print_list(head);

    puts("Inserting 50 to the beginning of the linked list:");
    insert_beginning(&head, create_item(50));
    print_list(head);

    puts("Inserting 60 to the beginning of the linked list:");
    insert_beginning(&head, create_item(60));
    print_list(head);

    // print the list
    puts("Insert beginning, data (40, 50, 60) in that order:");
    print_list(head);

    // Free memory
    puts("\nFreeing list:");
    free_list(&head);
    puts("\nFreed list:");
    print_list(head);


    ////////////////////////////////////////////////////////
    // INSERTING ITEMS TO END
    ////////////////////////////////////////////////////////

    // test data: insert 30, then 20, then 10
    puts("Inserting 30 to the end of the linked list:");
    insert_end(&head, create_item(30));
    print_list(head);

    puts("Inserting 20 to the end of the linked list:");
    insert_end(&head, create_item(20));
    print_list(head);

    puts("Inserting 10 to the end of the linked list:");
    insert_end(&head, create_item(10));
    print_list(head);

    // print the list
    puts("Insert end, data (30, 20, 10) in that order:");
    print_list(head);


    ////////////////////////////////////////////////////////
    // SWAPPING ITEMS
    ////////////////////////////////////////////////////////
    struct list_item *itemA = get_item_by_value(head, 10);
    struct list_item *itemB = get_item_by_value(head, 20);

    puts("\nSwapping items of value 10 and 20:");
    swap_items_by_pointer(&head, itemA, itemB);
    print_list(head);




    // Free memory
    puts("Freeing list:");
    free_list(&head);
    print_list(head);

    return 0;
}

// create a new item
struct list_item *create_item(int value) {

    // allocate
    struct list_item *new_item = malloc(sizeof(struct list_item));

    // throw error if memory allocation failed
    if(new_item == NULL) {
        puts("Memory allocation failed");
        exit(1);
    }

    // assign data to item
    new_item->number_data = value;

    // set the next item pointer to NULL
    new_item->next = NULL;

    return new_item;
}

// insert an item at the beginning of the linked list
void insert_beginning(struct list_item **head, struct list_item *item_to_insert) {

    // set the item to insert's next pointer to the current header
    item_to_insert->next = *head;

    // make our item to insert the new header
    *head = item_to_insert;
}


// insert an item to the end of the linked list
void insert_end(struct list_item **head, struct list_item *item_to_insert) {

    // if its an empty list (head points to null) then the item to insert should be the header item
    if(*head == NULL) {
        *head = item_to_insert;
        return;
    }

    // define the pointer for the current item and set it to the first item on the list
    struct list_item *curr = *head;

    // loop through all list items until the end is found
    while(curr->next != NULL) {
        curr = curr->next;
    }

    // set the last list items next pointer to the item we want to insert
    curr->next = item_to_insert;
}


// frees up the linked list, basically deletes it all to prevent memory leaks
void free_list(struct list_item **head) {
    // initlaize curr item to the first item on the linked list
    struct list_item *curr = *head;

    // loop until we've reached the end of the linked list
    while(curr != NULL) {
        // keep the curr item in temp, since we have to set curr to the next linked list item
        struct list_item *temp = curr;

        // set curr to the next linked list item
        curr = curr->next;

        // free up the temp linked list item from memory
        printf("Freeing %i\n", temp->number_data);
        free(temp);
    }

    // MUST set the header to point to null, otherwise we will have a long list of junk data
    *head = NULL;
}

// gets an item on the linked list by its value
struct list_item *get_item_by_value(struct list_item *head, int value) {

    // initlaize curr item to the first item on the linked list
    struct list_item *curr = head;

    // loop until end of list
    while(curr != NULL) {

        // check if the current item has the correct value
        if(curr->number_data == value) {
            // found!
            return curr;
        }

        // go to the next item
        curr = curr->next;
    }

    // not found
    return NULL;
}


// swaps 2 items on the list
void swap_items_by_pointer(struct list_item **head, struct list_item *a, struct list_item *b) {

    // cancel if invalid input
    if (a == NULL || b == NULL || a == b)
    {
        return;
    }

    // define the original linked lists pointers
    struct list_item *prevA = NULL;
    struct list_item *prevB = NULL;

    // initialize the looping pointer to the start of the list
    struct list_item *curr = *head;


    // loop through all items in list
    while(curr && curr->next) {
        if(curr->next == a) {
            prevA = curr;
        }
        if(curr->next == b) {
            prevB = curr;
        }

        // set curr pointer to the next item in the list
        curr = curr->next;
    }

    // if a or b is head, we just remove their old pointers
    if(*head == a) {
        prevA = NULL;
    }
    if(*head == b) {
        prevB = NULL;
    }

    // Update previous node's next
    if(prevA) {
     prevA->next = b;
    } else {
        *head = b;
    }

    if (prevB) {
        prevB->next = a;
    } else {
        *head = a;
    }

    // swap next pointers
    struct list_item *temp = a->next;
    a->next = b->next;
    b->next = temp;
}



// prints the list in visual format
void print_list(struct list_item *head) {
    printf("HEAD");
    while(head != NULL) {
        printf(" -> %d", head->number_data);
        head = head->next;
    }
    puts(" -> NULL\n");
}

