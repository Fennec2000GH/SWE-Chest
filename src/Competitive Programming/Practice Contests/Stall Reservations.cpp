
// https://vjudge.net/contest/396465#problem/A
// 09/28/2020.
// Trial 1: TIME LIMIT EXCEEDED,
// Many trials later ... queue replaces set to hold available stall numbers (push and pop both have constant time complexity)
// Time Complexity: O(n log n)

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <iterator>
using namespace std;

struct Cow {
    // inputNumber indicates when this Cow was received by stdin (first = 1, second = 2, ...)
    unsigned startTime, endTime, inputNumber, stallNumber;
    Cow(unsigned a, unsigned b, unsigned i) {
        startTime = a;
        endTime = b;
        inputNumber = i;
    }
};

struct CompareStartTime {
    bool operator()(const Cow& c1, const Cow& c2) {
        return c1.startTime > c2.startTime;
    }
};

struct CompareEndTime {
    bool operator()(const Cow& c1, const Cow& c2) {
        return c1.endTime > c2.endTime;
    }
};

int main() {
    unsigned N;
    cin >> N;

    // delete
//    cout << "N: " << N << endl;

    vector<unsigned> stallNumberPerCow(N);  // Keeps stall number used by each cow in the same order as inputted

    queue<unsigned> stallNumberRepo;
//    for(unsigned stall = 1; stall <= N; stall++) { stallNumberRepo.insert(stall); }  // Keeps available stalls to issue to cows

    // delete
//    cout << "Initial stallNumberRepo: " << endl;
//    copy(stallNumberRepo.cbegin(), stallNumberRepo.cend(), ostream_iterator<unsigned>(cout, ", "));
//    cout << endl;

    priority_queue<Cow, vector<Cow>, CompareStartTime> waitingQueue;  // Initially all cows wait here to be admitted to a stall; first come first serve basis
    priority_queue<Cow, vector<Cow>, CompareEndTime> milkingQueue;
    unsigned a, b;  // start and end of time interval for some cow
    unsigned maxNumStalls = 0;  // Keeps maximum number of stalls occupied so far

    // Filling up waitingQueue before milking begins
    unsigned minStartTime, maxEndTime;  // Time interval (inclusive) for main for-loop
    for(unsigned cowIndex = 1; cowIndex <= N; cowIndex++) {
        cin >> a >> b;
        Cow c(a, b, cowIndex);
        waitingQueue.push(c);

        if (a < minStartTime) { minStartTime = a; }
        if (b > maxEndTime) { maxEndTime = b; }

        // delete
//        cout << "a: " << a << ", b: " << b << endl;
//        cout << "Size of waitingQueue: " << waitingQueue.size() << endl;
    }

    // delete
//    cout << "Minimum start time: " << minStartTime << endl;
//    cout << "Maximum end time: " << maxEndTime << endl;

    unsigned nextStall = stallNumberRepo.front();  // Smallest number in all available stalls
    for(unsigned time = minStartTime; time <= maxEndTime; time++) {
//        cout << "-------------------------------------------------------------------------------------------------" << endl;
//        cout << "time: " << time << endl;
//        cout << "Cows done milking. Recycling stall numbers..." << endl;

        // Getting rid of any finished milked cows from stalls to free up space
        while (!milkingQueue.empty()) {
            if (milkingQueue.top().endTime != time - 1) { break; }

            // delete
//            cout << "Stall number recycled: " << milkingQueue.top().stallNumber << endl;
//            cout << "Cow done: (" << milkingQueue.top().startTime << ", " << milkingQueue.top().endTime << ", "
//            << milkingQueue.top().inputNumber << ")" << endl;

            stallNumberRepo.push(milkingQueue.top().stallNumber);  // Recycling stalls
            milkingQueue.pop();
        }

        // delete
//        cout << "New cows admitted to a stall..." << endl;

        // New arrivals to be issued stalls
        while (!waitingQueue.empty()) {
            if (waitingQueue.top().startTime != time) { break; }

            if (stallNumberRepo.empty()) { nextStall = milkingQueue.size() + 1; }
            else {
                nextStall = stallNumberRepo.front();
                stallNumberRepo.pop();
            }

            const_cast<Cow&>(waitingQueue.top()).stallNumber = nextStall;
            stallNumberPerCow[waitingQueue.top().inputNumber - 1] = nextStall;  // Stall number to be printed for this cow

            // delete
//            cout << "Next available stall number: " << *nextStall << endl;
//            cout << "Next cow to milk: (" << waitingQueue.top().startTime << ", " << waitingQueue.top().endTime << ", "
//            << waitingQueue.top().inputNumber << ")" << endl;

            // Swapping priority queues
            milkingQueue.push(waitingQueue.top());
            waitingQueue.pop();
        }

        // Check for potential higher number of stalls occupied
        if (milkingQueue.size() > maxNumStalls) {
            maxNumStalls = milkingQueue.size();

            // delete
//            cout << "New max number of stalls needed: " << maxNumStalls << endl;
        }

        if (waitingQueue.empty()) { break; }
    }

    // delete
//    cout << "Output:" << endl;
//    cout << "-------------------------------------------------------------------------------------------------" << endl;

    // Printing output
    // Max number of stalls needed
    cout << maxNumStalls << endl;
    copy(stallNumberPerCow.begin(), stallNumberPerCow.end(), ostream_iterator<unsigned>(cout, "\n"));

    return 0;
}

