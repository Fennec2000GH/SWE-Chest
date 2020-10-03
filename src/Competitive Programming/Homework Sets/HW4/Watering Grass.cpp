
// https://vjudge.net/contest/396471#problem/C
// 09/30/2020

/*
// Trial 1: RUNTIME ERROR
// Trial 2
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Lower and upper bounds for inscribed rectangle by circle
struct Span {
    double lower, upper;
    Span(double l = 0.0, double u = 0.0) : lower(l), upper(u) { }
};

// Struct used as overloaded comparator for Span
// Sorted by left x-coordinate and span length
struct CompareSpan {
    bool operator()(const Span& s1, const Span& s2) {
        if(s1.lower == s2.lower) { return s1.upper < s2.upper; }
        return s1.lower < s2.lower;
    }
};

int main() {
    unsigned n, l, w;
    double x, r;  // position and radius for each circle
    double halfSpan;  // Half the length of the rectangle inscribed inside a circle
    Span tempSpan;
    vector<Span> spans;  // holds representations of inscribed rectangles

    while (cin >> n >> l >> w) {
        // delete
//cout << "-----------------------------------------------------------------------------------------------------" << endl;
//        cout << "n: " << n << endl;
//        cout << "l: " << l << endl;
//        cout << "w: " << w << endl;
//cout << "-----------------------------------------------------------------------------------------------------" << endl;
        for (unsigned circleIndex = 0; circleIndex < n; circleIndex++) {
            cin >> x >> r;

            // delete
//            cout << "x: " << x << endl;
//            cout << "r: " << r << endl;
//cout << "-----------------------------------------------------------------------------------------------------" << endl;

            // contributes zero-length inscribed rectangle
            if(r <= w / 2.0) { continue; }

            halfSpan = sqrt(pow(r, 2.0) - pow(w / 2.0, 2.0));
            tempSpan.lower = x - halfSpan;
            if(tempSpan.lower < 0.0) { tempSpan.lower = 0.0; }  // No need to sprinkle water left of strip
            tempSpan.upper = x + halfSpan;
            if(tempSpan.upper > double(l)) { tempSpan.upper = double(l); }  // No need to sprinkle water right of strip
            spans.push_back(tempSpan);
        }

        // Sort spans be left x-coordinate
        sort(spans.begin(), spans.end(), CompareSpan());

        // delete
//        cout << "spans:" << endl;
//        for(auto& s : spans) { cout << "\t(" << s.lower << ", " << s.upper << ")," << endl; }

        // edge case - no cover for left end of strip
        if(spans.front().lower > 0.0) {
            // delete
//            cout << "Impossible to cover left end..." << endl;

            cout << -1 << endl;
            spans.clear();
            continue;
        }

        if(spans.back().upper < double(l)) {
            // delete
//            cout << "Impossible to cover right end..." << endl;

            cout << -1 << endl;
            spans.clear();
            continue;
        }

        // Reach signifies the farthest contiguous strip of grass from left end able to water so far
        double prevReach, currReach;
        unsigned numSprinkles = 1, index = 0;
        while(spans[index].lower == 0.0) { index++; }
        // index - 1 has longest span able to cover to left end of strip
        prevReach = currReach = spans[index - 1].upper;

        // delete
//        cout << "Largest cover starting at left end..." << endl;
//        cout << "\tindex: " << index - 1 << endl;
//        cout << "\tcurrReach: " << currReach << endl;

        for(; index < n; index++) {
            // Very next span to the right does not connect with current reach so far from the left end
            if(spans[index].lower > currReach) {
                // delete
//                cout << "Next span to the right (lower: " << spans[index].lower << ") does not connect with currReach ("
//                << currReach << ") anymore..." << endl;

                cout << -1 << endl;
                spans.clear();
                break;
            }

            // current reach can be extended without new inscribed rectangle going past previous reach
            if(spans[index].lower <= prevReach && spans[index].upper > currReach) {
                currReach = spans[index].upper;

                // delete
//                cout << "New currReach from extending without resetting prevReach: " << currReach << endl;
            }

            if(spans[index].lower > prevReach) {
                prevReach = currReach;
                numSprinkles++;

                // delete
//                cout << "prevReach is now currReach before this span..." << endl;
//                cout << "New numSprinkles: " << numSprinkles << endl;

                if(spans[index].upper > currReach) {
                    currReach = spans[index].upper;

                    // delete
//                    cout << "New currReach from extending after resetting prevReach: " << currReach << endl;
                }
            }

            if(currReach == double(l)) {
                // delete
//                cout << "Reached right end of strip..." << endl;
//                cout << "Incrementing numSprinkles to account for last inscribed rectangle cover..." << endl;

                numSprinkles++;
                cout << numSprinkles << endl;
                break;
            }
        }

        // Cleanup for trial
        spans.clear();
    }

    return 0;
}
*/

// Trial 3
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Lower and upper bounds for inscribed rectangle by circle
struct Span {
    double lower, upper;
    Span(double l = 0.0, double u = 0.0) : lower(l), upper(u) { }
};

// Struct used as overloaded comparator for Span
// Sorted by left x-coordinate and span length
struct CompareSpan {
    bool operator()(const Span& s1, const Span& s2) {
        return s1.lower < s2.lower;
    }
};


int main() {
    unsigned n, l, w;
    double x, r;  // position and radius for each circle
    double halfSpan;  // Half the length of the rectangle inscribed inside a circle
    Span tempSpan;
    vector<Span> spans(1);  // holds representations of inscribed rectangles

    while(cin >> n >> l >> w) {
        // delete
//cout << "-----------------------------------------------------------------------------------------------------" << endl;
//        cout << "n: " << n << endl;
//        cout << "l: " << l << endl;
//        cout << "w: " << w << endl;
//cout << "-----------------------------------------------------------------------------------------------------" << endl;

        for (unsigned circleIndex = 0; circleIndex < n; circleIndex++) {
            cin >> x >> r;

            // contributes zero-length inscribed rectangle
            if(r <= w / 2.0) { continue; }

            halfSpan = sqrt(pow(r, 2.0) - pow(w / 2.0, 2.0));
            tempSpan.lower = x - halfSpan;
            tempSpan.upper = x + halfSpan;
            spans.push_back(tempSpan);
        }

        // Sort spans based on x-coordinate of left side of inscribed rectangle
        auto start = spans.begin();
        advance(start, 1);
        sort(start, spans.end(), CompareSpan());

        // delete
//        cout << "spans:" << endl;
//        for(auto& s : spans) { cout << "\t(" << s.lower << ", " << s.upper << ")," << endl; }
/*
        // edge case - no cover for left end of strip
        if(spans.front().lower > 0.0) {
            // delete
//            cout << "Impossible to cover left end..." << endl;

            cout << -1 << endl;
            spans.clear();
            continue;
        }

        if(spans.back().upper < double(l)) {
            // delete
//            cout << "Impossible to cover right end..." << endl;

            cout << -1 << endl;
            spans.clear();
            continue;
        }
*/
        // needed variables
        unsigned index = 1, numSprinklers = 0;  // number of sprinklers so far
        double newReach, prevReach = 0, currReach = 0;

        while(currReach < l) {
            newReach = prevReach;
            unsigned fMarker = 0;

            for (; index < spans.size(); index++) {
                if (spans[index].lower > prevReach) { break; }
                if (spans[index].upper >= newReach) {
                    newReach = spans[index].upper;
                    fMarker = index;
                }
            }
            if (fMarker == 0) { break; }

            // New sprinkler needed
            numSprinklers++;
            currReach = prevReach = newReach;  // Resetting reach for new rightward cover extension next iteration
        }

        // Current coverage does not reach length of strip yet, so cannot water all grass
        if (currReach < l) { cout << -1 << endl; }

        // Successfully waters all grass
        else { cout << numSprinklers << endl; }

        // Recycling spans vector for next test case
        spans.resize(1);
    }

    return 0;
}
