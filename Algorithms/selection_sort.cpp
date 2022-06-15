#include <bits/stdc++.h>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        (i != v.size() - 1) && (os << ", ");
    }
    os << "]\n";
    return os;
}

template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

void selectionSort(std::vector<int> &);

int main() {
    std::vector<int> nums = { 10, 6, 4, 5, 1, 2, 2, 11 };

    selectionSort(nums);
    
    print(nums);
    return 0;
}

void selectionSort(std::vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        
        int temp = arr[i];
    
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
