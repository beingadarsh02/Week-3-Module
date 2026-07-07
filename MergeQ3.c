/*A multinational company has employee salary records stored in an array. Before
 generating annual reports,
the Human Resources department wants the salary records arranged in ascending or
order.*/
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("No employees to sort.\n");
        return 0;
    }

    int arr[n];
    printf("Enter the salaries of %d employees:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nLowest salary: %d\n", arr[0]);
    printf("Highest salary: %d\n", arr[n - 1]);
    printf("Difference : %d\n", arr[n - 1] - arr[0]);
    return 0;
}
