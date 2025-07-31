#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define Size 10

typedef struct Operation {
    char url[100];
    char timestamp[50];
} Operation;

typedef struct Stack {
    Operation data[MAX];
    int top;
} Stack;

typedef struct History {
    Operation data;
    struct History *next;
    struct History *prev;
} History;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Operation character) {
    if (!isFull(s)) {
        s->data[++s->top] = character;
    }
}

Operation pop(Stack *s) {
    Operation empty = {"", ""};
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return empty;
}

Operation peek(Stack *s) {
    Operation empty = {"", ""};
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return empty;
}

typedef struct Queue {
    Operation data[MAX];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = q->size = 0;
}

void enqueue(Queue *q, Operation character) {
    if (q->size == Size) {
        q->front = (q->front + 1) % Size;
        q->size--;
    }
    q->data[q->rear] = character;
    q->rear = (q->rear + 1) % Size;
    q->size++;
}

void showQueue(Queue q) {
    int num = q.size;
    int fro = q.front;
    while (num--) {
        printf("%s\n", q.data[fro].url);
        printf("%s\n", q.data[fro].timestamp);
        fro = (fro + 1) % Size;
    }
}

void addHistory(History **head, Operation character) {
    History *newHistory = (History *)malloc(sizeof(History));
    newHistory->data = character;
    newHistory->next = NULL;
    newHistory->prev = NULL;
    if (*head == NULL) {
        *head = newHistory;
    } else {
        History *nodeHead = *head;
        while (nodeHead->next != NULL) {
            nodeHead = nodeHead->next;
        }
        nodeHead->next = newHistory;
        newHistory->prev = nodeHead;
    }
}

void showHistory(History *head) {
    History *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->data.url);
        printf("%s\n", temp->data.timestamp);
        temp = temp->next;
    }
}

void clearHis(History **head) {
    History *node = *head;
    while (node != NULL) {
        History *temp = node->next;
        free(node);
        node = temp;
    }
    *head = NULL;
}

int main(void) {
    int choice;
    char text[100];
    Operation current = {"", ""};

    Stack back;
    Stack forword;
    History *history = NULL;

    initStack(&back);
    initStack(&forword);

    do {
        printf("1. Visit url\n");
        printf("2. Backward\n");
        printf("3. Forward\n");
        printf("4. Current\n");
        printf("5. History\n");
        printf("6. Clear History\n");
        printf("7. Exit\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Hay nhap dia chi url: ");
                scanf("%s", text);
                getchar();
                if (strlen(current.url) > 0) {
                    push(&back, current);
                }
                strcpy(current.url, text);
                initStack(&forword);
                addHistory(&history, current);
                printf("Da truy cap vao: %s\n", current.url);
                break;
            }
            case 2: {
                if (!isEmpty(&back)) {
                    push(&forword, current);
                    current = pop(&back);
                    printf("Da truy cap vao: %s\n", current.url);
                } else {
                    printf("Ko hop le\n");
                }
                break;
            }
            case 3: {
                if (!isEmpty(&forword)) {
                    push(&back, current);
                    current = pop(&forword);
                    printf("Da truy cap vao: %s\n", current.url);
                } else {
                    printf("Ko hop le\n");
                }
                break;
            }
            case 4: {
                if (strlen(current.url) > 0) {
                    printf(" trang hien tai: %s\n", current.url);
                } else {
                    printf("KO co trang nao\n");
                }
                break;
            }
            case 5: {
                showHistory(history);
                break;
            }
            case 6: {
                clearHis(&history);
                printf("Da xoa lich su thanh cong\n");
                break;
            }
            case 7: {
                printf("Thoat thanh cong\n");
                break;
            }
            default : {
                printf("Hay nhap lai\n");
            }
        }
    } while (choice != 7);

    return 0;
}
