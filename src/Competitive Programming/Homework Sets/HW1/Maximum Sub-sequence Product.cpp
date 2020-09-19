
// https://vjudge.net/contest/391584#problem/B
// 09/10/2020
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long maxProduct(const vector<int> &v) {
    // edge case
    if (v.empty()) { return 0; }
    if (v.size() == 1) { return v.front(); }

    long long globalMax = v.front(), localMax = v.front(), localMin = v.front();
    long long prevLocalMax, prevLocalMin;  // previous values for localMax and localMin before an iteration
    unsigned short index = 1;
    while(index < v.size()) {
        prevLocalMax = localMax;
        prevLocalMin = localMin;
        localMax = max(max(prevLocalMax * v[index], prevLocalMin * v[index]), (long long)v[index]);
        localMin = min(min(prevLocalMax * v[index], prevLocalMin * v[index]), (long long)v[index]);
        if(localMax > globalMax) { globalMax = localMax; }
        ++index;
    }

    return globalMax;
}

int main() {
    int element;
    vector<int> v;
    while(cin >> element){
        if (element == -999999) { cout << maxProduct(v) << endl; v.clear(); }
        else { v.push_back(element); }
    }

    return 0;
}
