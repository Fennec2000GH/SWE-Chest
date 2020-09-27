
// https://vjudge.net/contest/394524#problem/E
// 09/25/2020.
// Trial 1

#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    unsigned N;
    cin >> N;

    // Holds x and y coordinate values
    vector<int> X, Y;
    int temp;
    for (unsigned pos = 0; pos < N; pos++) {
       cin >> temp;
       X.push_back(temp);
       cin >> temp;
       Y.push_back(temp);
    }

    // Sorting x and y coordinate values
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    // Generating differences between x-coordinate and 0-based of future lined up soldiers
    for (unsigned index = 0; index < N; index++) { X[index] -= index; }

    sort(X.begin(), X.end());  // Sorting differences of original x coordinate and transformed (0-based) x coordinate
    int medianOfX = X[int(N - 1) / 2], medianOfY = Y[int(N - 1) / 2];
    unsigned output = 0;
    for (unsigned index = 0; index < N; index++) { output += (abs(X[index] - medianOfX) + abs(Y[index] - medianOfY)); }
    cout << output << endl;

    return 0;
}
