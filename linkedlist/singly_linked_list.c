/*=============================================================================
 |   Assignment:  Singly Linked List
 |
 |       Author:  CG.Lee(vncodenavi@gmail.com)
 |     Language:  C 
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  A linked list is a way to store a collection of elements. 
 |                Like an array these can be character or integers. 
 |                Each element in a linked list is stored in the form of a node.
 |
 |                   1.prepend an element
 |                   2.append an element
 |                   3.search for an element
 |                   4.insert after an element
 |                   5.insert before an element
 |                   6.remove front node
 |                   7.remove back node
 |                   8.remove any node
 |                   9.sort the list
 |                   10.Reverse the linked list
 |
 |
 |    Algorithm:  Data Structures (Linked List)
 |
 |        Links:  https://en.wikipedia.org/wiki/Linked_list
 |                http://www.zentut.com/c-tutorial/c-linked-list/
 |
 *===========================================================================*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int data;
    struct __node *next;
} node;

typedef void (*callback)(node* n);


void traverse(node* item, callback f) {
    node* cursor = item;
    while(cursor != NULL) {
        f(cursor);
        cursor = cursor->next;
    }
}

/*
    display a node
*/
void display(node* n)
{
    if(n != NULL)
        printf("%d ", n->data);
}


node* create(node* item, int data) {
    node* new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL) {
        printf("Error : Creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = item;
    return new_node;
}

node* prepend(node* head, int data){
    return create(head, data);
}

node* append(node* head, int data) {
    if(head == NULL) return prepend(head,data);
    /* go to the end */
    node* cursor = head;
    while( cursor->next != NULL )
        cursor = cursor->next;
    /* create a new node */
    cursor->next = create(NULL, data);
    return head;
}

node* insertAfter(node* head, node* target, int data) {
    if(head == NULL) return prepend(head,data);
    target->next = create(target->next, data);
    return head;
}


node* insertBefore(node* head, node* target, int data) {
    if(head == NULL) return prepend(head,data);
    if(target->data == head->data) {
        head = create(target->next, data);
    }
    node* cursor = head;
    node* prev = NULL;
    while(cursor != NULL) {
        if(cursor->next->data == target->data) {
            prev = cursor;
            break;
        }
        cursor = cursor->next;
    }
    prev->next = create(prev->next, data);
    return head;
}


node* search(node* head, int data) {
    node* cursor = head;
    while( cursor != NULL) {
        if(cursor->data == data) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

node* makedata(node* head, int total) {
    if(head != NULL) return head;
    for(int i=1; i<=total; i++) {
        head = append(head, i);
    }
    return head;
}

node* removeFront(node* head) {
    if(head == NULL || head->next == NULL) return head;
    node* front = head;
    head = head->next;
    free(front);
    return head;
}

node* removeLast(node* head) {
    if(head == NULL || head->next == NULL) return head;
    node* cursor = head;
    while(cursor->next->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = NULL;
    free(cursor);
    return head;
}

node* removeData(node* head, node* target) {

    if(head->data == target->data) return removeFront(head);
    node* cursor = head;
    
    while(cursor != NULL && cursor->next != target) {
        cursor = cursor->next;
    }
    node* tmp = cursor->next;
    cursor->next = cursor->next->next;
    tmp->next = NULL;
    free(tmp);

    return head;
}

node* insersionSort(node* head) {
    
    if(head == NULL || head->next == NULL) return head;

    node* cursor = head;
    node* x;
    node* y;
    callback disp = display;
    int matched = 1;
    int i = 0;
    
    x = cursor->next;
    y = cursor->next->next;
    if(x->data < y->data) {
        x->next = y->next;
        y->next = x;
        head->next = y;
    }
    return head;
}

/*
    display the menu
*/
void menu()
{
    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.search for an element\n");
    printf("4.insert after an element\n");
    printf("5.insert before an element\n");
    printf("6.remove front node\n");
    printf("7.remove back node\n");
    printf("8.remove any node\n");
    printf("9.sort the list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n");
 
}

int main() {

    int command = 0;
    int data;
    int position;

    node* head = NULL;
    node* temp = NULL;
    callback disp = display;

    menu();
    while(1) {
        printf("\nEnter a command(0-10,-1 to quit):");
        scanf("%d", &command);

        if(command == -1) break;
        
        switch(command) {
            case 0:
                menu();
                break;
                
            case 1:
                printf("\nPlease enter a number to prepend:");
                scanf("%d", &data);
                head = prepend(head, data);
                traverse(head, disp);
                break;
            case 2:
                printf("\nPlease enter a number to append:");
                scanf("%d", &data);
                head = append(head, data);
                traverse(head, disp);
                break;            
            case 3:
                printf("\nPlease enter a number to search:");
                scanf("%d", &data);
                temp = search(head, data);
                if(temp!=NULL) display(temp);
                else printf("Element with value %d not found.\n",data);
                break;
            case 4:
                printf("\nPlease enter a number to insert after ex) (after)3 (data)4: ");
                scanf("%d %d", &position, &data);
                printf("\nInput Data: %d", data);
                
                temp = search(head, position);
                if(temp!=NULL) insertAfter(head, temp, data);
                else printf("\nElement with value %d not found.\n",position);
                traverse(head, disp);
                break; 
            case 5:
                printf("\nPlease enter a number to insert after ex) (after)3 (data)4: ");
                scanf("%d %d", &position, &data);
                printf("\nInput Data: %d", data);
                temp = search(head, position);
                if(temp!=NULL) insertBefore(head, temp, data);
                else printf("\nElement with value %d not found.\n",position);
                traverse(head, disp);
                break;
            case 6:
                head = removeFront(head);
                traverse(head, disp);
                break;
            case 7:
                head = removeLast(head);
                traverse(head, disp);
                break;
            case 8:
                printf("\nPlease enter a number to remove:");
                scanf("%d", &position);
                temp = search(head, position);
                if(temp!=NULL) removeData(head, temp);
                else printf("\nElement with value %d not found.\n",position);
                traverse(head, disp);
                break;
            case 9:
                head = insersionSort(head);
                traverse(head, disp);
                break;

            case 99:
                printf("\nPlease enter a number to make data:");
                scanf("%d", &data);
                head = makedata(head, data);
                traverse(head, disp);
                break;

            default : 
                traverse(head, disp);
                break;
        }

    }
    return 0;
}