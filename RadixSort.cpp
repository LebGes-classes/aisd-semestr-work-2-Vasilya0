#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortByDigit(vector<int>& array, int digit) {
    int n = array.size();
    int divisor = 1;
    for (int i = 0; i < digit; i++) {
        divisor *= 10;
    }
    vector<int> count(10, 0);
    vector<int> sortedArray(n);
    vector<int> positions(10, 0);

    for (int i = 0; i < n; i++) {
        count[(array[i] / divisor) % 10]++;
    }

    positions[0] = 0;
    for (int i = 1; i < 10; i++) {
        positions[i] = positions[i - 1] + count[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int x = (array[i] / divisor) % 10;
        sortedArray[positions[x]] = array[i];
        positions[x]++;
    }

    for (int i = 0; i < n; i++) {
        array[i] = sortedArray[i];
    }
}

void radixSort(vector<int>& array) {
    int max_num = 0;
    int n = array.size();
    for (int i = 0; i < n; i++) {
        max_num = max(array[i], max_num);
    }

    int digit = 0;
    while (max_num != 0) {
        max_num /= 10;
        digit++;
    }

    for (int i = 0; i < digit; i++) {
        sortByDigit(array, i);
    }
}

int main() {
    vector<int> array = { 12, 34, 90, 23, 22 };
    radixSort(array);
    for (int num : array) {
        cout << num << endl;
    }
    return 0;
}