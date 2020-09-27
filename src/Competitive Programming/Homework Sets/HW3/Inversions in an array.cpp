
// https://vjudge.net/contest/394524#problem/D
// Created by qcaij on 9/22/2020.
// Trial 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned> mergeSort(vector<unsigned> v, unsigned& inversionCounter) {
    if(v.size() == 1) { return v; }
    unsigned mid = v.size() / 2;
    vector<unsigned> part1 = mergeSort(vector<unsigned>(v.cbegin(), v.cbegin() + mid), inversionCounter),
                    part2 = mergeSort(vector<unsigned>(v.cbegin() + mid, v.cend()), inversionCounter);
    vector<unsigned> sortedV(v.size());
    unsigned part1Index = 0, part2Index = 0;
    unsigned index = 0;
    for(; part1Index < part1.size() && part2Index < part2.size(); index++) {
        if(part1[part1Index] <= part2[part2Index]) {
            sortedV[index] = part1[part1Index];
            part1Index++;
        } else {
            // delete
//            cout << part1[part1Index] << " > " << part2[part2Index] << endl;
//            cout << part1.size() - part1Index << " added to inversionCounter" << endl;

            sortedV[index] = part2[part2Index];
            part2Index++;
            inversionCounter += (part1.size() - part1Index);
        }
    }

    // Copying any leftovers after one pre-merged vectors already exhausted all its elements when sorting
    bool part1ReachedEnd = part1Index == part1.size();
    if(part1ReachedEnd) {
        copy(part2.cbegin() + part2Index, part2.cend(), sortedV.begin() + index);
    } else {
        copy(part1.cbegin() + part1Index, part1.cend(), sortedV.begin() + index);
    }
    return sortedV;
}

int main() {
    vector<unsigned> v, sortedV;
    unsigned T, N, a;
    cin >> T;

    unsigned inversionCounter = 0;
    for(unsigned test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        for(unsigned i = 0; i < N; i++) {
            cin >> a;
            v.push_back(a);
        }
        sortedV = mergeSort(v, inversionCounter);
        for (auto &element : sortedV) { cout << element << " "; }
        cout << endl << inversionCounter << endl;

        // clean up
        v.clear();
        sortedV.clear();
        inversionCounter = 0;
    }

    return 0;
}

