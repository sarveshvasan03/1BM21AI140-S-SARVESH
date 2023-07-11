#include <iostream>

class LinearSearch {
private:
    int *arr;
    int size;

public:
    LinearSearch(int *array, int arraySize) {
        arr = array;
        size = arraySize;
    }

    int search(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                return i;  // Return the index where the key is found
            }
        }
        return -1;  // Return -1 if the key is not found
    }
};

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int arraySize = sizeof(array) / sizeof(array[0]);

    LinearSearch linearSearch(array, arraySize);

    int key;
    std::cout << "Enter the key to search: ";
    std::cin >> key;

    int index = linearSearch.search(key);

    if (index != -1) {
        std::cout << "Key found at index: " << index << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    return 0;
}
