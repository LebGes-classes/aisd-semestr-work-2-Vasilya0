#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<int>& arr, int bucketSize) {

    int min = arr[0];
    int max = arr[0];
    for (int num : arr) {
        if (num < min) {
            min = num;
        }
        else if (num > max) {
            max = num;
        }
    }

    int bucketCount = (max - min) / bucketSize + 1;
    std::vector<std::vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int bucketIndex = (num - min) / bucketSize;
        buckets[bucketIndex].push_back(num);
    }

    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    int index = 0;
    for (const auto& bucket : buckets) {
        for (int num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    std::vector<int> arr = { 34, 3456, 87, 64, 8, 987, 77, 1, 57, 9, 8 };
    int bucketSize = 5;

    bucketSort(arr, bucketSize);

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}