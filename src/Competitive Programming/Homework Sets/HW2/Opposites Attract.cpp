
// https://vjudge.net/contest/391624#problem/D
// 09/17/2020.
// Trial 1: Fail on extreme edge case
// Trial 2: Changed smaller data types to unsigned long long and passed

#include <iostream>
#include <array>
#include <iterator>
using namespace std;

int main() {
    array<unsigned long long, 10> negatives, positives;  // holds count of negative and positive clients, indexes are abs of client number
    negatives.fill(0);
    positives.fill(0);
    unsigned long long zeros = 0;  // holds count of clients equal to zero (0)
    short temp;  // temporary holder for each client

    // delete
//    cout << "negatives: ";
//    copy(negatives.cbegin(), negatives.cend(), ostream_iterator<unsigned>(cout, ", "));
//    cout << endl << "positives: ";
//    copy(positives.cbegin(), positives.cend(), ostream_iterator<unsigned>(cout, ", "));
//    cout << endl;

    unsigned n;
    cin >> n;
    for(unsigned i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 0) { zeros++; }
        else if (temp < 0) { negatives[abs(temp) - 1]++; }
        else { positives[temp - 1]++; }
    }

    // delete
//    cout << "negatives: ";
//    copy(negatives.cbegin(), negatives.cend(), ostream_iterator<unsigned>(cout, ", "));
//    cout << endl << "positives: ";
//    copy(positives.cbegin(), positives.cend(), ostream_iterator<unsigned>(cout, ", "));
//    cout << endl;

    unsigned long long output = 0;
    for(unsigned short i = 0; i < 10; i++) { output += negatives[i] * positives[i]; }

    // computing combination C(no. of zeros, 2)
    output += zeros * (zeros - 1) / 2;

    cout << output;

    return 0;
}

