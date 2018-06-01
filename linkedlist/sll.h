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
typedef struct __node {
    int data;
    struct __node *next;
} node;

typedef void (*callback)(node* n);

void traverse(node* item, callback f);
void display(node* n);

node* create(node* item, int data);

node* prepend(node* head, int data);
node* append(node* head, int data);

node* insertAfter(node* head, node* target, int data);
node* insertBefore(node* head, node* target, int data);

node* search(node* head, int data);

node* makedata(node* head, int total);

node* removeFront(node* head);
node* removeLast(node* head);
node* removeData(node* head, node* target);

node* insersionSort(node* head);

int getLength(node* head);
node* leftPad(node * head, int total);