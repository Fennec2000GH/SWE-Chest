
// https://vjudge.net/contest/396471#problem/A
// 09/27/2020

/*
// Trial 1: FAILED on Test Case 4
#include <iostream>
#include <set>
#include <numeric>
using namespace std;

int main() {
    unsigned T;
    cin >> T;

    // Data
    unsigned n, x, temp;
    unsigned wealthyCount = 0;  // Number of wealthy people per trial after wealth distributing
    multiset<unsigned long long> wealth;
    auto it = wealth.begin();  // Useful iterator across wealth multiset

    // Accumulated sums for top y most wealthy people
    // topYCumSum - net wealth sum of the top y richest people
    // minReuqiredWealthY - x * y, the minimum net wealth required for top y people to be wealthy after equal distribution
    unsigned long long topYCumSum = 0, minRequiredWealthY = 0;

    for (unsigned trial = 1; trial <= T; trial++) {
        // Capturing nubmer of people and minimum wealth to be wealthy
        cin >> n >> x;

        for (unsigned i = 1; i <= n; i++) {
            cin >> temp;
            wealth.insert(temp);
        }
        it = wealth.lower_bound(x);

        // edge case - highest wealth does not even meet min wealthy criteria
        if (it == wealth.end()) {
            cout << 0 << endl;
            wealth.clear();
            continue;
        }

        wealthyCount = distance(it, wealth.end());
        topYCumSum = accumulate(it, wealth.end(), 0);
        minRequiredWealthY = x * wealthyCount;

        // Special exit when all people are already considered wealthy
        if (it == wealth.begin()) {
            cout << wealthyCount << endl;
            wealth.clear();
            continue;
        }

        do {
            advance(it, -1);
            topYCumSum += *it;
            minRequiredWealthY += x;
            if (minRequiredWealthY <= topYCumSum) { wealthyCount++; }
            else { break; }
        } while(it != wealth.begin());

        // Printing output
        cout << wealthyCount << endl;

        // Cleanup for each trial
        wealthyCount = 0;
        topYCumSum = 0;
        minRequiredWealthY = 0;
        wealth.clear();
    }

    return 0;
}
*/

// Trial 2: Accumulating individual person's wealth on the go if s/he is above the wealth criteria
#include <iostream>
#include <set>
using namespace std;

int main() {
    unsigned T;
    cin >> T;

    // Data
    unsigned n, x, temp;
    unsigned wealthyCount = 0;  // Number of wealthy people per trial after wealth distributing
    unsigned long long extraWealth = 0;  // Accumulating portion of money of wealthy people falling above criteria
    multiset<unsigned> poorWealth;  // Initially holds each person's wealth if that person is considered poor

    for(unsigned trial = 1; trial <= T; trial++) {
        cin >> n >> x;
        for(unsigned i = 1; i <= n; i++) {
            cin >> temp;  // Next person's wealth
            if(temp >= x) {
                wealthyCount++;
                extraWealth += temp - x;
            } else { poorWealth.insert(temp); }
        }

        // Iterating from richest person that is still considered poor down to the very poorest person
        for(auto it = poorWealth.crbegin(); it != poorWealth.crend(); it++) {
            temp = x - *it;
            if(temp <= extraWealth) {
                wealthyCount++;
                extraWealth -= temp;
                continue;
            }
            break;
        }

        // Printing output
        cout << wealthyCount << endl;

        // Cleanup for each trial
        wealthyCount = 0;
        extraWealth = 0;
        poorWealth.clear();
    }

    return 0;
}
