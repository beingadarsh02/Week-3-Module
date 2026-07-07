/*An online marketplace tracks the daily sales made by different sellers. At the end of each week,
management wants to identify the best-performing sellers.
*/
#include <stdio.h>
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
       
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}       
int main() {
    int n,sum=0;
    printf("Enter the number of sellers: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sales figures of %d sellers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    printf("TOP 3 : %d %d %d", arr[0], arr[1], arr[2]);
    printf("\n");
    printf("Average: %d", sum/n);
    return 0;
}