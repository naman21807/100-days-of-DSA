#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value, key;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    struct Node *prev = NULL, *curr = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input key
    scanf("%d", &key);

    // Delete first occurrence
    curr = head;
    while(curr != NULL) {
        if(curr->data == key) {
            // Case 1: deleting head
            if(prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            break; // only first occurrence
        }
        prev = curr;
        curr = curr->next;
    }

    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}