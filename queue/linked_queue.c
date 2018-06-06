#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int data;
    struct __node *next;
} Node;

typedef struct __queue {
    int count;
    Node *front;
    Node *rear;
} Queue;

void push(Queue **q, int data);
int pop(Queue **q);
int isEmpty(Queue *q);
void traverse(Node *n);

void push(Queue **q, int data) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    if((*q)->front != NULL) {
        (*q)->rear->next = n;
        (*q)->rear = n;
    } else {
        (*q)->front = n;
        (*q)->rear = n;
    }
    (*q)->count++;
    traverse((*q)->front);
}

int pop(Queue **q) {
    if(isEmpty((*q))) {
        printf("Empty");
        return -1;
    }

    Node *front = (*q)->front;
    int data = front->data;
    if((*q)->front->next == NULL) {
        (*q)->front = NULL;
        (*q)->rear = NULL;
    } else {
        (*q)->front = (*q)->front->next;
    }
    free(front);
    (*q)->count--;
    traverse((*q)->front);
    return data;
}

void traverse(Node* item) {
    Node* cursor = item;
    while(cursor != NULL) {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int main() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
    push(&q,1);
    push(&q,2);
    push(&q,3);
    push(&q,4);
    pop(&q);
    pop(&q);
    push(&q, 5);
    pop(&q);
    pop(&q);
}