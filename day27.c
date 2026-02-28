#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append node at end
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse both together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data)   // comparing values as per given example
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int n, m, value;

    // First list input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }

    // Second list input
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        append(&head2, value);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}