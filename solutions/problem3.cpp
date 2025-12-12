#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    ifstream file("../inputs/states.txt");
    if (!file.is_open()) {
        cout << "Error: Cannot open states.txt\n";
        return 1;
    }

    vector<int> nums;
    int x;
    while (file >> x) nums.push_back(x);
    file.close();

    int doneCount = 0;

    for (int n : nums) {
        if (isPrime(n)) {
            doneCount++;             
        } else if (n % 2 == 0) {
            doneCount++;            
        } else {
            
        }
    }

    cout << "Clue 3 = " << doneCount << endl;

    return 0;
}
