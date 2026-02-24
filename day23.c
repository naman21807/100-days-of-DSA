#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* createNode(int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}
struct node* insertEnd(struct node *head, int val) {
    struct node *newnode = createNode(val);

    if(head == NULL)
        return newnode;

    struct node *p = head;
    while(p->next != NULL)
        p = p->next;

    p->next = newnode;
    return head;
}
struct node* merge(struct node *l1, struct node *l2) {
    struct node dummy;   
    struct node *tail = &dummy;
    dummy.next = NULL;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}
void printList(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, m, x;
    struct node *list1 = NULL, *list2 = NULL, *merged = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insertEnd(list1, x);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insertEnd(list2, x);
    }
    merged = merge(list1, list2);
    printList(merged);

    return 0;
}