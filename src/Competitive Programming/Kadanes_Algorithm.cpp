
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

pair<int, int> kadaneIndexes(const vector<int> &v) {
    // edge case
    if(v.empty()) { return make_pair(-1, -1); }
    if(v.size() == 1) { return make_pair(0, 0); }

    int localSum = 0, globalSum = 0;
    int localLeftIndex = 0, localRightIndex = 0, globalLeftIndex = 0, globalRightIndex = 0;
    for(int i = 0; i < v.size(); i++) {
        localSum += v[i];
        localRightIndex = i;
        if(localSum > globalSum) {
            globalSum = localSum;
            globalLeftIndex = localLeftIndex;
            globalRightIndex = localRightIndex;
        } else if(localSum < 0) {
            localSum = 0;
            localLeftIndex = i + 1;
        }
    }
    return make_pair(globalLeftIndex, globalRightIndex);
}

pair<int, int> maxProductIndexes(const vector<int> &v) {
    // edge case
    if(v.empty()) { return make_pair(-1, -1); }
    if(v.size() == 1) { return make_pair(0, 0); }

    int localMaxProduct = v.front(), localMinProduct = v.front(), globalMaxProduct = v.front();
    int localMaxLeftIndex = 0, localMinLeftIndex = 0, localRightIndex,
    globalLeftIndex = 1, globalRightIndex = 1;
    int prevLMaxP, prevLMinP; //previous local max and min products to be used in for loop
    for (int i = 1; i < v.size(); i++) {
        localRightIndex = i;
        prevLMaxP = localMaxProduct;
        prevLMinP = localMinProduct;
        cout << "(" << localMaxLeftIndex << ", " << localMinLeftIndex << ", " << localRightIndex << ") " << endl;

        localMaxProduct = max(max(prevLMaxP * v[i], prevLMinP * v[i]), v[i]);
        localMinProduct = min(min(prevLMaxP * v[i], prevLMinP * v[i]), v[i]);

        // Setting new local max product indexes
        int prevLMLI = localMaxLeftIndex; // previous unedited left index for max product subarray
        if(localMaxProduct == prevLMinP * v[i]) { localMaxLeftIndex = localMinLeftIndex; }
        else if(localMaxProduct == v[i]) { localMaxLeftIndex = i; }

        // Setting new local min product indexes
        if(localMinProduct == prevLMaxP * v[i]) { localMinLeftIndex = prevLMLI; }
        else if(localMinProduct == v[i]) { localMinLeftIndex = i; }

        if(localMaxProduct > globalMaxProduct) {
            globalMaxProduct = localMaxProduct;
            globalLeftIndex = localMaxLeftIndex;
            globalRightIndex = localRightIndex;
        }
    }
    return make_pair(globalLeftIndex, globalRightIndex);
}

int main() {
    vector<int> v = {-2, -5, 3, 5, -6, 1};
    pair<int, int> k = kadaneIndexes(v);
    pair<int, int> m = maxProductIndexes(v);
    cout << "(" << k.first << ", " << k.second << ")" << endl;
    cout << "(" << m.first << ", " << m.second << ")" << endl;
    return 0;
}

