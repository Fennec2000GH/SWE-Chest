
// https://vjudge.net/contest/396465#problem/B
// 09/28/2020.

// Trial 1
// Time Complexity: O (n log n)
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    unsigned S, C, K;
    cin >> S >> C >> K;

    vector<unsigned> colors;  // Color of each sock
    unsigned temp;
    for (unsigned sock = 1; sock <= S; sock++) {
        cin >> temp;
        colors.push_back(temp);
    }

    // edge case - only 1 sock
    if (S == 1) {
        cout << 1 << endl;
        return 0;
    }

    // edge case - capacity is only 1, therefore # machines = # socks
    if (C == 1) {
        cout << S << endl;
        return 0;
    }

    sort(colors.begin(), colors.end());

    // delete
//    cout << "sorted sock colors:" << endl;
//    copy(colors.cbegin(), colors.cend(), ostream_iterator<unsigned>(cout, ", "));
//    cout << endl;

    // baseColor - minimum color for specific machine
    unsigned baseColor = colors.front(), currentColor;

    // current number of socks in specific machine, and number of machines needed so far
    unsigned currentMachineFill = 0, machineCount = 0;
    for(unsigned index = 0; index < S; index++) {
        currentColor = colors[index];
        if (currentMachineFill == 0) { baseColor = currentColor; }

        // delete
//        cout << "---------------------------------------------------------------------------------------------" << endl;
//        cout << "index: " << index << endl;
//        cout << "base color: " << baseColor << endl;
//        cout << "current color: " << currentColor << endl;

        if (currentColor - baseColor <= K) { currentMachineFill++; }
        else { // needs to start new machine
            machineCount++;
            currentMachineFill = 1;
            baseColor = currentColor;
        }
        if (currentMachineFill == C) {
            machineCount++;
            currentMachineFill = 0;
        }

        // delete
//        cout << "base color after operations: " << baseColor << endl;
//        cout << "current machine fill: " << currentMachineFill << endl;
//        cout << "machine count:" << machineCount << endl;
    }

    // checking for residuals
    if (currentMachineFill > 0) {
        // delete
//        cout << "Residuals: " << currentMachineFill << endl;
        machineCount++;
    }

    // delete
//    cout << "---------------------------------------------------------------------------------------------" << endl;

    // Output
    cout << machineCount;

    return 0;
}
