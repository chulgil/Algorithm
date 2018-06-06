#include <stdio.h>
#include <stdlib.h>
#include "sll.c"

typedef struct __storage {
    int carry;
    node* result;
} Storage;

node* sumLinks(node* l1, node* l2, int carry) {
    if(l1 == NULL && l2 == NULL && carry == 0) return NULL;
    node* result = NULL;
    int value = carry;

    if(l1 != NULL) {
        value += l1->data;
    }
    if(l2 != NULL) {
        value += l2->data;
    }
    result = prepend(result, value % 10);
    if(l1 != NULL || l2 != NULL) {
        node* next = sumLinks(
            l1==NULL ? NULL : l1->next,
            l2==NULL ? NULL : l2->next, 
            value>10 ? 1 : 0);
        result->next = next;
    }
    return result;
}

Storage* addSum(node* l1, node* l2) {
    if(l1 == NULL && l2 == NULL) {
        Storage* s = (Storage *)malloc(sizeof(Storage));
        s->carry = 0;
        s->result = NULL;
        return s;
    }
    
    Storage* s = addSum(l1->next, l2->next);
    int value = s->carry + l1->data + l2->data;
    s->carry = value / 10;
    node *p = prepend(s->result, value % 10);
    s->result = p;
    return s;
}

node* sumReverse(node* l1, node* l2) {
    l1 = leftPad(l1, getLength(l2));
    l2 = leftPad(l2, getLength(l1));
    callback disp = display;

    traverse(l1, disp);
    traverse(l2, disp);
    Storage* s = addSum(l1,l2);
    if(s->carry >= 1) {
        s->result = prepend(s->result, s->carry);
    }
    return s->result;
}

int main() {

    #define CNT(x) (sizeof(x) / sizeof((x)[0]))

    int data;
    int length;
    
    node* head1 = NULL;
    node* head2 = NULL;
    callback disp = display;
    
    int arrList1[] = {1,9,4};
    int arrList2[] = {3,4,6,5,9};
    
    // int arrList1[] = {7,2,1,9,4};
    // int arrList2[] = {3,4,6,5,9};
                
    for(int i=0; i<CNT(arrList1); i++) {
        head1 = append(head1, arrList1[i]);
    }
    for(int i=0; i<CNT(arrList2); i++) {
        head2 = append(head2, arrList2[i]);
    }
    node* r = sumReverse(head1, head2);
    traverse(r, disp);
}
