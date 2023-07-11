#include <iostream>
#include <vector>

class MergeSort {
public:
  void sort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
  }

private:
  void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
      int middle = left + (right - left) / 2;
      mergeSort(arr, left, middle);
      mergeSort(arr, middle + 1, right);
      merge(arr, left, middle, right);
    }
  }

  void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
      leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
      rightArr[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
      if (leftArr[i] <= rightArr[j]) {
        arr[k] = leftArr[i];
        i++;
      } else {
        arr[k] = rightArr[j];
        j++;
      }
      k++;
    }

    while (i < n1) {
      arr[k] = leftArr[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = rightArr[j];
      j++;
      k++;
    }
  }
};

int main() {
  std::vector<int> arr = {9, 5, 1, 8, 3, 6, 2, 7, 4};
  
  MergeSort sorter;
  sorter.sort(arr);

  std::cout << "Sorted array: ";
  for (int num : arr)
    std::cout << num << " ";
  std::cout << std::endl;

  return 0;
}
