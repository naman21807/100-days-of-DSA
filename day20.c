#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;
    long long prefix = 0;

    // Using a simple array as frequency map (since constraints not given strictly)
    // Shift index to handle negative prefix sums
    int OFFSET = 100000;
    int SIZE = 200001;

    long long *freq = (long long*)calloc(SIZE, sizeof(long long));

    // prefix sum 0 occurs once initially
    freq[OFFSET] = 1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        // if prefix seen before, add its frequency
        if(prefix + OFFSET >= 0 && prefix + OFFSET < SIZE)
            count += freq[prefix + OFFSET];

        // increase frequency
        if(prefix + OFFSET >= 0 && prefix + OFFSET < SIZE)
            freq[prefix + OFFSET]++;
    }

    printf("%lld", count);

    free(arr);
    free(freq);
    return 0;
}