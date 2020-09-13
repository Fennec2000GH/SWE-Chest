
// https://vjudge.net/contest/391584#problem/C
// 09/10/2020

// Trial 1: Wrong Answer
//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <set>
//#include <vector>
//using namespace std;
//
//long maxSumBoundedK(const vector<int> &v, int k) {
//    // edge cases
//    if(v.empty()) { return -1; }
//    if(find(v.cbegin(), v.cend(), k) != v.cend()) { return k; }
//
//    set<long long> cumsum = {v.front()};
//
//    // maxSum is largest sum of contiguous array not exceeding K
//    // prefixSum is sum of first j elements since index 0
//    // localSum is best attempt at honing in sum of K given fixed right index of subarrray
//    long maxSum = v.front(), prefixSum = 0, localSum;
//    set<long long>::iterator it;
//    for(unsigned index = 0; index < v.size(); index++) {
//        cout << "-----------------------------------------" << endl;
//        cout << "v[" << index << "]: " << v[index] << endl;
//        prefixSum += v[index];
//        if(prefixSum == k) { return k; }
//        cout << "prefixSum: " << prefixSum << endl;
//        it = cumsum.lower_bound(prefixSum - k);
//        if(it != cumsum.end()) {
//            localSum = prefixSum - *it;
//            if(prefixSum < k) { localSum = max(localSum, prefixSum); }
//            cout << "localSum: " << localSum << endl << "gap: " << prefixSum - k << endl << "lower_bound: " << *it << endl;
//            maxSum = max(maxSum, localSum);
//            cout << "maxSum: " << maxSum << endl;
//        }
//        cumsum.insert(prefixSum);
//    }
//    return maxSum;
//}
//
//int main() {
//    vector<int> v;
//    int N, M, item;
//    cin >> N >> M;
//    for(int index = 0; index < N; index++) {
//        cin >> item;
//        v.push_back(item);
//    }
//    cout << maxSumBoundedK(v, M);
//
//    return 0;
//}

// Trial 2: Success
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

// natural numbers only
long long maxSumBoundedM(const vector<int> &v, int M) {
    // cumulative sums from index 0 to j, 0 <= j <= n-1, (denoted by prefixSum as variable)
    set<long long> cumsum;
    cumsum.insert(0);  // in case prefix - M is negative, then zero (0) is subtracted from prefixSum

    long long maxSum = INT64_MIN, prefixSum = 0;
    set<long long>::iterator it;
    for (int index = 0; index < v.size(); index++) {
        prefixSum += v[index];
        it = cumsum.lower_bound(prefixSum - M);
        if (it != cumsum.end()) { maxSum = max(maxSum, prefixSum - *it); }
        if (maxSum == M) { return (long long)M; }

        cumsum.insert(prefixSum);
    }
    return maxSum;
}

int main() {
    vector<int> v;
    unsigned N, M, temp;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back((int)temp);
    }
    cout << maxSumBoundedM(v, M);

    return 0;
}
