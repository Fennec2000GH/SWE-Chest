
// https://vjudge.net/contest/396471#problem/E
// 09/29/2020

// Trial 1: ACCEPTED
// Time Complexity: O (n log n)
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    unsigned n;
    cin >> n;

    vector<unsigned> canisters(n + 1);  // Holds volume of helium per canister, index is 1-based
    unsigned heliumVolume;
    for(unsigned index = 1; index <= n; index++) {
        cin >> heliumVolume;
        canisters[index] = heliumVolume;
    }

    sort(canisters.begin() + 1, canisters.end());

    // delete
//    cout << "Sorted canisters:" << endl;
//    copy(canisters.cbegin(), canisters.cend(), ostream_iterator<unsigned>(cout, ", "));
//    cout << endl;

    double minFraction = 1.0;
    for(unsigned index = n; index >= 1; index--) {
        if (canisters[index] > index) {
            cout << "impossible";
            return 0;
        }
        if (canisters[index] / double(index) < minFraction) { minFraction = canisters[index] / double(index); }
    }

    cout << minFraction;

    return 0;
}
