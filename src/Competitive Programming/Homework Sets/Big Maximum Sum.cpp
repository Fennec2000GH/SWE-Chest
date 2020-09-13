
// https://vjudge.net/contest/391584#problem/E
// 09/10/2020

// algorithm functions
/*
// gets left index, right index, and sum after applying kadane's algorithm
tuple<int, int, long long> kadane(const vector<int> &v) {
    // edge case
    if(v.empty()) { return make_tuple<int, int, long long>(-1, -1, LLONG_MIN); }
    if(v.size() == 1) { return make_tuple<int, int, long long>(0, 0, v.front()); }

    long long localSum = 0, globalSum = v.front();
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
    return tuple<int, int, long long>(globalLeftIndex, globalRightIndex, globalSum);
}

// maximum contiguous subarray sum starting at index 0
tuple<int, int, long long> maxPrefixSum(const vector<int> &v) {
    // edge cases
    if (v.empty()) { return tuple<int, int, long long>(-1, -1, LLONG_MIN); }
    if (v.size() == 1) { return tuple<int, int, long long>(0, 0, v.front()); }

    long long localSum = 0, globalSum = v.front();
    int rightIndex = 0;
    for(int i = 0; i < v.size(); i++) {
        localSum += v[i];
        if (localSum > globalSum) {
            globalSum = localSum;
            rightIndex = i;
        }
    }
    return tuple<int, int, long long>(0, rightIndex, globalSum);
}

// minimum contiguous subarray sum starting at index 0
tuple<int, int, long long> minPrefixSum(const vector<int> &v) {
    // edge cases
    if (v.empty()) { return tuple<int, int, long long>(-1, -1, LLONG_MIN); }
    if (v.size() == 1) { return tuple<int, int, long long>(0, 0, v.front()); }

    long long localSum = 0, globalSum = v.front();
    int rightIndex = 0;
    for(int i = 0; i < v.size(); i++) {
        localSum += v[i];
        if (localSum < globalSum) {
            globalSum = localSum;
            rightIndex = i;
        }
    }
    return tuple<int, int, long long>(0, rightIndex, globalSum);
}
*/

// Trial 1: Untested and scrapped
/*
#include <algorithm>
#include <iostream>
#include<vector>
#include <tuple>
#include <numeric>
using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    // temporary variables for re-use
    int temp;
    vector<short> tempVector;
    tuple<int, int, long long> tempTuple;

    vector <vector<short>> records(n + 1);  // keeps record of each distinct small array
    vector<int> sums(n + 1);  // keeps sum of eall elements per each distinct small array
    short l;  // length of each small array
    for (int i = 1; i <= n; i++) {
        cin >> l;
        for (short j = 0; j < l; j++) {
            cin >> temp;
            records[i].push_back(temp);
        }
        sums[i] = accumulate(records[i].cbegin(), records[i].cend(), 0);
    }

    //delete
    cout << "sums: ";
    for (const int &i : sums) { cout << i << ", "; }
    cout << endl;
//    for (const vector<short> &v : records) {
//        for (const short &el : v) { cout << el << ", "; }
//        cout << endl;
//    }

    vector<int> bigArray(m);  // NOTE: 1-based indexes, so sum of first small array has index 0, second sum has index 1, ...
    vector<short> smallArrayIndexes(m);  // 1-based indexes of small arrays used in same order during initialization og big array
    for (int i = 0; i < m; i++) {
        cin >> temp;

        //delete
//        cout << "temp: " << temp << ", ";
//        cout << "sums[temp]: " << sums[temp] << endl;
        bigArray[i] = sums[temp];
        smallArrayIndexes[i] = temp;
    }

    // edge case for 1 single small array used in big array (m = 1)
    if (m == 1) {
        cout << "Only 1 small array used (m=1)..." << endl << endl;
        tempVector = records[smallArrayIndexes.front()];
        tempTuple = kadane(vector<int>(tempVector.cbegin(), tempVector.cend()));
        cout << get<2>(tempTuple);
        return 0;
    }

    auto tBig = kadane(bigArray);
    int tBigLeftIndex = get<0>(tBig), tBigRightIndex = get<1>(tBig);
    long long maxSum = get<2>(tBig);  // maximum contiguous subarray sum of bigArray

    // delete
    cout << "bigArray: ";
    for (const int &i : bigArray) { cout << i << ", "; }
    cout << endl << endl;
    cout << "bigArray kadane info: " << tBigLeftIndex << ", " << tBigRightIndex << ", " << maxSum << endl << endl;

    // Still need to check for positive net sums for left and right bordering small arrays
    int edgeSum = 0;
    int leftEdgePositive

    // ridding of possible maximum contiguous negative sum on first element in bigArray kadane
    tempVector = records[smallArrayIndexes[tBigLeftIndex]];

    // delete
    cout << "Left tBig small array: ";
    for(const short &s : tempVector) { cout << s << ", "; }
    cout << endl << endl;

    tempTuple = minPrefixSum(vector<int>(tempVector.cbegin(), tempVector.cend()));
    temp = get<2>(tempTuple);
    cout << "Left tBig minPrefixSum info: " << get<0>(tempTuple) << ", " << get<1>(tempTuple) << ", " << get<2>(tempTuple) << endl << endl;
    if(temp < 0) { edgeSum = temp; }

    // Salvage any positive contiguous sum from reversed left edge small array
    if (tBigLeftIndex >= 1) {
        cout << "Analyzing left edge..." << endl;
        tempVector = records[smallArrayIndexes[tBigLeftIndex - 1]];
        vector<int> leftEdge(tempVector.cbegin(), tempVector.cend());

        //delete
        cout << "leftEdge: ";
        for(const int &i : leftEdge) { cout << i << ", "; }
        cout << endl << endl;

        reverse(leftEdge.begin(), leftEdge.end());

        //delete
        cout << "leftEdge REVERSED: ";
        for(const int &i : leftEdge) { cout << i << ", "; }
        cout << endl << endl;

        auto tLeft = maxPrefixSum(leftEdge);
        temp = get<2>(tLeft);

        cout << "tLeft max prefix sum done!" << endl << endl;
        cout << "tLeft max prefix info: ";
        cout << get<0>(tLeft) << ", " << get<1>(tLeft) << ", " << get<2>(tLeft) << endl << endl;

        if(temp > 0 && temp > abs(edgeSum)) { edgeSum = temp; }
    }

    // updating maxSum from left edge
    cout << "Left edge sum: " << edgeSum << endl;
    maxSum += abs(edgeSum);
    cout << "maxSum after adding left edge sum: " << maxSum << endl << endl;
    edgeSum = 0;

    // ridding of possible maximum contiguous negative sum on last element in bigArray kadane
    tempVector = records[smallArrayIndexes[tBigRightIndex]];  // corresponds to right small array index in tBig

    // delete
    cout << "Right tBig small array: ";
    for(const short &s : tempVector) { cout << s << ", "; }
    cout << endl;

    reverse(tempVector.begin(), tempVector.end());

    // delete
    cout << "Right tBig small array REVERSED: ";
    for(const short &s : tempVector) { cout << s << ", "; }
    cout << endl << endl;

    tempTuple = minPrefixSum(vector<int>(tempVector.cbegin(), tempVector.cend()));
    temp = get<2>(tempTuple);
    cout << "Right tBig minPrefixSum info: " << get<0>(tempTuple) << ", " << get<1>(tempTuple) << ", " << get<2>(tempTuple) << endl << endl;
    if(temp < 0) { edgeSum = temp; }

    // Salvage any positive contiguous sum from right edge small array
    if(tBigRightIndex <= m - 2) {
        cout << "Analyzing right edge..." << endl;
        tempVector = records[smallArrayIndexes[tBigRightIndex + 1]];
        vector<int> rightEdge(tempVector.cbegin(), tempVector.cend());

        //delete
        cout << "rightEdge: ";
        for(const int &i : rightEdge) { cout << i << ", "; }
        cout << endl << endl;

        auto tRight = maxPrefixSum(rightEdge);
        temp = get<2>(tRight);

        cout << "tRight max prefix sum done!" << endl << endl;
        cout << "tRight max prefix info: ";
        cout << get<0>(tRight) << ", " << get<1>(tRight) << ", " << get<2>(tRight) << endl << endl;

        if(temp > 0 && temp > abs(edgeSum)) { edgeSum = temp; }
    }

    maxSum += abs(edgeSum);
    cout << "Left edge sum: " << edgeSum << endl;
    cout << "maxSum after adding right edge sum: " << maxSum << endl << endl;
    tempVector.clear();

    cout << maxSum;
    return 0;
}
 */

// Trial 2:
#include <iostream>
//#include <chrono>
#include <vector>
#include <numeric>
#include <tuple>
#include <algorithm>
using namespace std;

// minimum contiguous subarray sum starting at index 0
tuple<int, int, long long> minPrefixSum(const vector<int> &v) {
    // edge cases
    if (v.empty()) { return tuple<int, int, long long>(-1, -1, LLONG_MIN); }
    if (v.size() == 1) { return tuple<int, int, long long>(0, 0, v.front()); }

    long long localSum = 0, globalSum = v.front();
    int rightIndex = 0;
    for(int i = 0; i < v.size(); i++) {
        localSum += v[i];
        if (localSum < globalSum) {
            globalSum = localSum;
            rightIndex = i;
        }
    }
    return tuple<int, int, long long>(0, rightIndex, globalSum);
}

int main(){
//    chrono::time_point start = chrono::high_resolution_clock::now();
    int n, m;
    cin >> n >> m;

    // temporary variables for re-use
    int temp;
    vector<short> dummy;
    vector<short>& v_ref = dummy;

    long long globalMax = LLONG_MIN, localMax = 0;
    vector <vector<short>> records(n + 1);  // keeps record of each distinct small array
    vector<int> sums(n + 1);  // keeps sum of all elements per each distinct small array
    short l;  // length of each small array
    for (int i = 1; i <= n; i++) {
        cin >> l;
        for (short j = 0; j < l; j++) {
            cin >> temp;
            records[i].push_back(temp);
        }
        sums[i] = accumulate(records[i].cbegin(), records[i].cend(), 0);
    }

    //delete
//    int counter = 0;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        v_ref = records[temp];

        if(sums[temp] < 0) {
            for (short j = 0; j < v_ref.size(); j++) {
                localMax += v_ref[j];
//            cout << counter << ": (" << v_ref[j] << ", " << localMax << ", ";
                if (localMax > globalMax) { globalMax = localMax; }
                if (localMax < 0) { localMax = 0; }

                //delete
//            ++counter;
//            cout << globalMax << "), ";
            }
        } else {
            localMax += sums[temp];
            if (localMax > globalMax) {
                globalMax = localMax;
                globalSmallArrayIndex = temp;
            }
        }
    }

//    cout << endl;
    cout << globalMax;

//    chrono::time_point end = chrono::high_resolution_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;

    return 0;
}

