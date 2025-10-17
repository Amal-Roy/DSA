#include <stdio.h>
int binarySearch(int arr[], int n, int target, int *iterations) {
    int low = 0, high = n - 1, mid;
    *iterations = 0;
    while (low <= high) {
        (*iterations)++;          
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;  
        else if (arr[mid] < target)
            low = mid + 1;  
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, target, i, iterations;
    printf("Enter size of sorted array: ");      
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &target);
    int index = binarySearch(arr, n, target, &iterations);
    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found\n", target);
    int space_bytes = sizeof(n) + sizeof(target) + sizeof(i) + sizeof(iterations) + sizeof(int)*3 + sizeof(arr);
    printf("Time Complexity (iterations): %d\n", iterations);
    printf("Space Complexity: %d bytes\n", space_bytes);
    return 0;
}
