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
 |                   9.insersion sort the list
 |                   
 |
 |
 |    Algorithm:  Data Structures (Linked List)
 |
 |        Links:  https://en.wikipedia.org/wiki/Linked_list
 |                
 |
 *===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

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

int getLength(node* head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

node* leftPad(node* head, int total) {
    int max = total-getLength(head);
    for(int i=0; i<max; i++) {
        head = prepend(head, 0);
    }
    return head;
}

