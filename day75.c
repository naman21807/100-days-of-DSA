#include <stdio.h>

#define MAX 1000

// Simple hashmap using arrays (since constraints are small in most problems)
int maxLen(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Hashmap simulation
    int hash[2 * MAX + 1];
    
    // Initialize with -2 (means not visited)
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -2;
    }

    // Offset to handle negative sums
    int offset = MAX;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum = 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        // If sum seen before
        if (hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            if (i - prevIndex > maxLen) {
                maxLen = i - prevIndex;
            }
        } else {
            // Store first occurrence
            hash[sum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n)); // Output: 5

    return 0;
}