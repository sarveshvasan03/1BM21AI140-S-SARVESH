#include <iostream>

class SelectionSort {
private:
    int* arr;
    int size;

public:
    SelectionSort(int* array, int arraySize) {
        arr = array;
        size = arraySize;
    }

    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;

            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort selectionSort(arr, size);
    std::cout << "Original array: ";
    selectionSort.display();

    selectionSort.sort();
    std::cout << "Sorted array: ";
    selectionSort.display();

    return 0;
}
