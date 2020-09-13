
// 09/04/2020
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
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
        if(localSum >= globalSum) {
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

int main() {
    int b;
    cin >> b;
    int s, temp;
    vector<string> output(10);
    for(int r = 1; r <= b; r++) {
        cin >> s; // number of stops on current route
        vector<int> v;
        for (int i = 1; i < s; i++) {
            cin >> temp;
            v.push_back(temp);
        }
        pair<int, int> p = kadaneIndexes(v); // 0-based indexes of max subarray
        if (p.first == p.second && v[p.first] < 0) {
//            cout << "Route " << r << " has no nice parts" << endl;
            output[r - 1] = "Route " + to_string(r) + " has no nice parts\n";

        } else {
//            cout << "The nicest part of route " << r << " is between stops " << p.first + 1 << " and " << p.second + 2
//                 << endl;
            output[r - 1] = "The nicest part of route " + to_string(r) + " is between stops " + to_string(p.first + 1) + " and " + to_string(p.second + 2) + "\n";
        }
    }
    copy(output.cbegin(), output.cend(), ostream_iterator<string>(cout));

    return 0;
}
