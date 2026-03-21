#include <stdio.h>
#include <stdlib.h>

// Tree Node Definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder traversal (for checking)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Driver code (VS Code testing)
int main() {
    struct TreeNode* root = NULL;

    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertIntoBST(root, val);
    }

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}