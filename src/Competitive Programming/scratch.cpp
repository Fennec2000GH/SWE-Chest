
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

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

int main() {
//    vector<short> s;
//    vector<int> i;
//    vector<float> f;
//    vector<double> d;
//    vector<char> c;
//    vector<string> str;

//    cout << s.max_size() << endl;
//    cout << i.max_size() << endl;
//    cout << f.max_size() << endl;
//    cout << d.max_size() << endl;
//    cout << c.max_size() << endl;
//    cout << str.max_size() << endl;

    vector<int> v = {4, 5, 0, -12, 8};
    auto t = minPrefixSum(v);
    cout << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << endl;

    return 0;
}
