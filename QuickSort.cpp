#include <vector>
#include <iostream>

using namespace std;

void swapValues(int& a, int& b) {  // This is a function just for swapping vector elements easier
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& array, int low, int high) {  // Function for partitioning array, uses last element as pivot point
    int pivot = array[high]; // This chooses last element as pivot
    int i = low - 1; // Index of smaller element

    // This is for traversing through the elements in the array
    // Elements less than pivot move to the left
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++; // Increments index of smaller element
            swap(array[i], array[j]);
        }
    }

    // Place pivot correctly
    swap(array[i + 1], array[high]);
    return i + 1; // Returning pivot's index
}

void quickSort(vector<int>& array, int low, int high) {
    /*
    Sorts the array with the QuickSort algorithm.
    
    Args:
        array (vector<int>&): The vector we're sorting
        low (int): starting index of sub-array
        high(int): ending index of sub-array
    
    Returns:
        None: The array is also sorted in place
    
    Example:
        array = {2, 6, 5, 1, 3, 4}
        quicksort(array, 0, array.size() - 1)
        array
        {1, 2, 3, 4, 5, 6}
    */

    if (low < high) {
        // Finding pivot elements.
        // Elements smaller than pivot on left
        // Elements larger than pivot on right

        int pivotIndex = partition(array, low, high);

        // Then recursively sort elements before and after pivot
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> myArray = {2, 6, 5, 1, 3, 4};

    quickSort(myArray, 0, myArray.size() - 1);

    for (int number : myArray) {
        cout << number << " ";
    }

    cout << endl;

    return 0;
}
