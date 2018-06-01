#include <stdio.h>
#include <stdlib.h>
#include "sll.c"


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


node* addSum(node* l1, node* l2) {
    if(l1 == NULL && l2 == NULL) {
        printf("\naddSUM: NULL");
        node* s = create(NULL, 0);
        return s;
    }
    node* s = addSum(l1->next, l2->next);
    int value = s->data + l1->data + l2->data;
    s->data = value / 10;
    s->next = append(s, value % 10);
    printf("\n%d", s->data);
    return s;
}

node* sumReverse(node* l1, node* l2) {
    l1 = leftPad(l1, getLength(l2));
    l2 = leftPad(l2, getLength(l1));
    node* result = addSum(l1,l2);
    return result->next;
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
                
    for(int i=0; i<CNT(arrList1); i++) {
        head1 = append(head1, arrList1[i]);
    }
    for(int i=0; i<CNT(arrList2); i++) {
        head2 = append(head2, arrList2[i]);
    }

    node* r = sumReverse(head1, head2);
    traverse(r, disp);
    
    // traverse(r, disp);
}
