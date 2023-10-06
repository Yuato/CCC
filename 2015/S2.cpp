#include <bits/stdc++.h>

int main() {
    int J, A, num, count = 0;
    char size_jersey, size;
    std::cin >> J >> A;
    std::vector<int> jersey(J, 0); // Initialize with all jerseys as 'S' (0).

    for (int i = 0; i < J; i++) {
        std::cin >> size;
        if (size == 'M') jersey[i] = 1; // 'M' is represented as 1.
        else if (size == 'L') jersey[i] = 2; // 'L' is represented as 2.
    }

    for (int i = 0; i < A; i++) {
        std::cin >> size_jersey >> num;
        num--; // Adjust index to 0-based index.

        if (num < J) {
            if (size_jersey == 'S' && jersey[num] < 3) {
                count++;
                jersey[num] = 3; // Mark as 'e'.
            } 
            
            else if (size_jersey == 'M' && jersey[num] < 3 && jersey[num]>0) {
                count++;
                jersey[num] = 3;
            } 
            
            else if (size_jersey == 'L' && jersey[num]==2) {
                count++;
                jersey[num] = 3;
            }
        }
    }

    std::cout << count;
    return 0;
}