#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            bool shouldSwap;

            if (ascending) {
                shouldSwap = arr[j] > arr[j + 1];
            } else {
                shouldSwap = arr[j] < arr[j + 1];
            }

            if (shouldSwap) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        int selectedIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (ascending) {
                if (arr[j] < arr[selectedIndex]) {
                    selectedIndex = j;
                }
            } else {
                if (arr[j] > arr[selectedIndex]) {
                    selectedIndex = j;
                }
            }
        }

        int temp = arr[i];
        arr[i] = arr[selectedIndex];
        arr[selectedIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n, bool ascending) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        if (ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        arr[j + 1] = key;
    }
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];

        if (i < n - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

int main() {
    int n;
    int sortingChoice;
    int orderChoice;

    cout << "========================================\n";
    cout << "       ARRAYS AND SORTING IN C++\n";
    cout << "========================================\n\n";

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of elements must be greater than 0.\n";
        return 0;
    }

    int* arr = new int[n];

    cout << "\nEnter " << n << " integer values:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nChoose a sorting algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "Enter your choice: ";
    cin >> sortingChoice;

    if (sortingChoice < 1 || sortingChoice > 3) {
        cout << "Invalid sorting choice.\n";
        delete[] arr;
        return 0;
    }

    cout << "\nChoose the order:\n";
    cout << "1. Ascending (smallest to largest)\n";
    cout << "2. Descending (largest to smallest)\n";
    cout << "Enter your choice: ";
    cin >> orderChoice;

    if (orderChoice != 1 && orderChoice != 2) {
        cout << "Invalid order choice.\n";
        delete[] arr;
        return 0;
    }

    bool ascending = (orderChoice == 1);

    cout << "\nOriginal array: ";
    displayArray(arr, n);

    switch (sortingChoice) {
        case 1:
            bubbleSort(arr, n, ascending);
            cout << "Algorithm: Bubble Sort\n";
            break;

        case 2:
            selectionSort(arr, n, ascending);
            cout << "Algorithm: Selection Sort\n";
            break;

        case 3:
            insertionSort(arr, n, ascending);
            cout << "Algorithm: Insertion Sort\n";
            break;
    }

    cout << "Order: "
         << (ascending ? "Ascending" : "Descending") << endl;

    cout << "Sorted array: ";
    displayArray(arr, n);

    delete[] arr;

    cout << "\nProgram completed successfully.\n";

    return 0;
}
