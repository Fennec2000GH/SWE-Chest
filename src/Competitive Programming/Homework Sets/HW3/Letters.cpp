
// https://vjudge.net/contest/394524#problem/A
// 09/22/2020
// Trial 1: FAILED - Some numbers needed larger data types (unsigned long long), leading to overflow
// Trial 2: SUCCESS

#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    // Each element is {K: cumulative number of rooms til i^th dorm, V: {first: 1-based dorm number, second: number of rooms in dorm}}
    map<unsigned long long, pair<unsigned long long, unsigned long long>> cumulativeMap;

    unsigned n, m;
    cin >> n >> m;

    // delete
//    cout << "n: " << n << ", m: " << m << endl;

    unsigned long long a, cumsum = 0;
    for(unsigned dorm = 1; dorm <= n; dorm++) {
        cin >> a;
        cumsum += a;
        cumulativeMap[cumsum] = {dorm, a};

        // delete
//        cout << "Map element: {" << cumsum << ", {" << dorm << ", " << a << "}}" << endl;
    }

    // Given letter's cumulative room number
    // Dorm number for given letter
    // Total number of rooms from dorm 1 to current dorm inclusively
    // Number of rooms for current dorm only
    // Room number relative to current dorm only
    unsigned long long letterNumber, dormNumber, totalDormRooms, currentDormRooms, localRoomNumber;

    auto it = cumulativeMap.cbegin();
    for(unsigned letter = 1; letter <= m; letter++) {
        cin >> letterNumber;

        // delete
//        cout << "letterNumber: " << letterNumber << endl;

        it = cumulativeMap.lower_bound(letterNumber);
        dormNumber = (it -> second).first;
        totalDormRooms = it -> first;
        currentDormRooms = (it -> second).second;
        localRoomNumber = currentDormRooms - (totalDormRooms - letterNumber);

        // Printing output
        cout << dormNumber << " " << localRoomNumber << endl;
    }

    return 0;
}
