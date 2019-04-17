#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int index) {
    int largestIndex = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < arr.size() && arr[left] > arr[largestIndex]) largestIndex = left;
    if (right < arr.size() && arr[right] > arr[largestIndex]) largestIndex = right;
    
    if (largestIndex != index) {
        swap(arr[index], arr[largestIndex]);
        heapify(arr, largestIndex);
    }
}

void buildHeap(vector<int>& arr) {
    int size = (int)arr.size();
    for (int i = size/2 - 1; i >= 0; i--) heapify(arr, i);
}

//int main() {
//    vector<int> a = {1, 3, 5, 7, 9};
//    buildHeap(a);
//    
//    for (auto& it : a) cout << it << " "; cout << endl;
//}
