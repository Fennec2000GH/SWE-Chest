
// https://vjudge.net/contest/396471#problem/D
// 09/29/2020


// Trial 2
/*
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct vertex {
    unsigned x, y;  // x and y coordinates
    int tree;  // identifies dijoint set of vertices (tree) current vertex belongs to during Kruskal's algorithm
    vertex(unsigned _x = 0, unsigned _y = 0, int _tree = -1) : x(_x), y(_y), tree(_tree) { }
};

struct edge {
    unsigned endpoint1, endpoint2;  // Indexes of endpoint vertices from vertexSet defined in main
    double distance;  // Euclidean distance between the 2 endpoints
    edge(unsigned _endpoint1 = 0, unsigned _endpoint2 = 0, double _distance = 0.0) :
    endpoint1(_endpoint1), endpoint2(_endpoint2), distance(_distance) { }
};

struct CompareEdge {
    bool operator()(const edge& e1, const edge& e2) const {
        return e1.distance < e2.distance;
    }
};

// Computes Euclidean distance between 2 vertices
double getDistance(const vertex& v1, const vertex& v2) {
    return sqrt(pow(double(v1.x) - double(v2.x), 2.0) + pow(double(v1.y) - double(v2.y), 2.0));
}

int main() {
    unsigned N, S, P, x, y;
    double D, dist;  // temporarily holds distance between 2 endpoints
    vertex tempVertex;
    edge tempEdge;
    cin >> N;

    // delete
//    cout << "N: " << N << endl;

    vector<vertex> vertexSet;  // Each node / vertex is represented by unsigned index
    set<edge, CompareEdge> sortedEdgeSet;  // Edges sorted by euclidean distance between endpoints
    vector<edge> MST;  // Set of edges sorted from smallest to largest euclidean distance from minimum spanning tree (Kruskal's Algorithm)
    unordered_map<unsigned, unordered_set<unsigned>> trees;  // Used to hold disjoint trees before V - 1 edges are combined into one tree
    unordered_set<unsigned> satelliteUsed;  // Stores 0-based indexes of vertices having a satellite ability to communicate from vertexSet

    for (unsigned test_case = 1; test_case <= N; test_case++) {
        // delete
//cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cin >> S >> P;

        // delete
//        cout << "S: " << S << endl;
//        cout << "P: " << P << endl;
//cout << "-----------------------------------------------------------------------------------------------------" << endl;

        // Entering information for each outpost
        for (unsigned index = 1; index <= P; index++) {
            cin >> x >> y;
            tempVertex = vertex(x, y, -1);

            // delete
//            cout << "New vertex inputted..." << endl;
//            cout << "x: " << x << ", y: " << y << endl;

            for (unsigned vertexIndex = 0; vertexIndex < vertexSet.size(); vertexIndex++) {
                // Compute euclidean distance between each existing vertex and new vertex
                dist = getDistance(vertexSet[vertexIndex], tempVertex);
                tempEdge = edge(vertexIndex, vertexSet.size(), dist);
                sortedEdgeSet.insert(tempEdge);

                // delete
//                cout << "Distance between vertices (" << vertexIndex << ": (" << vertexSet[vertexIndex].x << ", "
//                << vertexSet[vertexIndex].y << ")) and (" << vertexSet.size() << ": (" << x << ", " << y << ")) "
//                << "is " << dist << endl;
            }
            vertexSet.push_back(tempVertex);
        }

        // delete
//        cout << endl << "vertexSet size: " << vertexSet.size() << endl;
//        cout << "vertexSet: " << endl;
//        for(auto& v : vertexSet) { cout << "\t(" << v.x<< ", " << v.y << ")," << endl; }
//        cout << endl;

        // edge case - S is only 1 less than P, so find the edge with lowest edge weight
        if(S == P - 1) {
            // delete
//            cout << "Edge case for S == P - 1..." << endl;

            D = sortedEdgeSet.cbegin() -> distance;
            cout << D << endl;

            // Clean up for next trial
            vertexSet.clear();
            sortedEdgeSet.clear();
            continue;
        }

        // delete
//        cout << endl << "sortedEdgeSet size: " << sortedEdgeSet.size() << endl;

        // delete
//        cout << endl << "Using Kruskal's algorithm..." << endl;

        // Kruskal's algorithm
        unsigned endpointIndex1, endpointIndex2, treeIndex = 0;
        vertex v1, v2;
        for (auto it = sortedEdgeSet.cbegin(); it != sortedEdgeSet.cend() && MST.size() < vertexSet.size() - 1; it++) {
            endpointIndex1 = it -> endpoint1;
            endpointIndex2 = it -> endpoint2;
            v1 = vertexSet[endpointIndex1];
            v2 = vertexSet[endpointIndex2];

            // delete
//            cout << "Next smallest edge ";
//            cout << "(" << endpointIndex1 << ": (" << v1.x << ", " << v1.y << "), "
//            << endpointIndex2 << ": (" << v2.x << ", " << v2.y << "), "
//            << "dist: " << it -> distance << ") ";

            // Decide whether to admit next smallest edge into MST or not
            if(v1.tree == -1 && v2.tree == -1) {
                // Neither endpoint is mstt of any disjoint set / tree yet
                // delete
//                cout << "has neither endpoint as mstt of a disjoint set / tree yet..." << endl;

                v1.tree = v1.tree = treeIndex;
                trees[treeIndex].insert(endpointIndex1);
                trees[treeIndex].insert(endpointIndex2);
                treeIndex++;
            } else if(v1.tree == v2.tree) {
                // Check for cycles; skip and continue if next smallest edge will form a cycle
                // delete
//                cout << "will form a cycle, so skipping that one..." << endl;

                continue;
            } else if(v1.tree != -1) {
                // First endpoint already belongs to a disjoint set / tree, but not second endpoint
//                cout << "only has first endpoint belonging to a disjoint set / tree, but not second..." << endl;

                v2.tree = v1.tree;
                trees[v1.tree].insert(endpointIndex2);
            } else if(v2.tree != -1) {
                // Second endpoint already belongs to a disjoint set / tree, but not first endpoint
//                cout << "only has second endpoint belonging to a disjoint set / tree, but not first..." << endl;

                v1.tree = v2.tree;
                trees[v2.tree].insert(endpointIndex1);
            } else {
                // Both endpoints belong to different disjoint sets / trees
//                cout << "has both endpoints in different disjoint sets / trees..." << endl;
//                cout << "Merging larger tree into smaller tree..." << endl;

                if(trees[v1.tree].size() < trees[v2.tree].size()) {
                    // first tree is smaller
                    trees[v2.tree].insert(trees[v1.tree].begin(), trees[v1.tree].end());
                    trees.erase(v1.tree);
                } else {
                    // second tree is smaller
                    trees[v1.tree].insert(trees[v2.tree].begin(), trees[v2.tree].end());
                    trees.erase(v2.tree);
                }
            }

            MST.push_back(*it);

            // delete
//            cout << "Added edge (" << endpointIndex1 << ": "
//            << "(" << v1.x << ", " << v1.y << "), "
//            << endpointIndex2 << ": "
//            << "(" << v2.x << ", " << v2.y << "), "
//            << "dist: " << it -> distance << ") to MST..." << endl;
        }


        // delete
//        cout << endl << "Assigning satellites to top edge weights in MST..." << endl;

        // Getting rid as many top edge weights as possible given S amount of satellites available
        for (unsigned index = MST.size() - 1; index >= 0; index--) {
            tempEdge = MST[index];
            endpointIndex1 = tempEdge.endpoint1;
            endpointIndex2 = tempEdge.endpoint2;

            // Both vertices for next largest edge weight in MST need satellites
            if (satelliteUsed.find(endpointIndex1) == satelliteUsed.end()
                && satelliteUsed.find(endpointIndex2) == satelliteUsed.end()) {
                // Not enough satellites left for both endpoints; current edge weight is D
                if(S < 2) {
                    // delete
//                    cout << "Not enough satellites left for both endpoints..." << endl;

                    D = MST[index].distance;
                    break;
                }

                S -= 2;
                satelliteUsed.insert(endpointIndex1);
                satelliteUsed.insert(endpointIndex2);

                // delete
//                cout << "Added 2 satellites to vertices (" << endpointIndex1 << ": (" << v1.x
//                << ", " << v1.y << ")) and " << endpointIndex2 << ": ("
//                << v2.x << ", " << v2.y << ")" << endl;
            } else {
                // Only one of the endpoints lacks satellite
                S--;
                unsigned vertexIndex = satelliteUsed.find(endpointIndex1) == satelliteUsed.end() ? endpointIndex1 : endpointIndex2;
                satelliteUsed.insert(vertexIndex);

                // delete
//                cout << "Added 1 satellite to vertex (" << vertexIndex << ": (" << vertexSet[vertexIndex].x << ", "
//                << vertexSet[vertexIndex].y << "))" << endl;
            }

            // Current index indicates last edge in MST to receive any satellites; next largest edge weight is D
            if(S == 0) {
                // delete
//                cout << "S ran out of satellites to perfectly zero (0)..." << endl;

                D = MST[index - 1].distance;
                break;
            }
        }

        unsigned indexD = MST.size() - S;  // index of maximum D from MST given S satellites available
        D = MST[indexD].distance;

        // Printing output
        // delete
//        cout << "D: ";

        cout << fixed << showpoint << setprecision(2) << D << endl;

        // Clean up for next trial
        MST.clear();
        vertexSet.clear();
        sortedEdgeSet.clear();
        satelliteUsed.clear();
    }

    return 0;
}
*/

// Trial 4
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const unsigned maximumNumTrials=500;
struct edge {
    unsigned endpoint1, endpoint2;  // Indexes of endpoint vertices from vertexSet defined in main
    double distance;  // Euclidean distance between the 2 endpoints
    edge(unsigned _endpoint1, unsigned _endpoint2, double _distance) :
    endpoint1(_endpoint1), endpoint2(_endpoint2), distance(_distance) { }
};

// Comparator for edge objects
struct CompareEdge {
    bool operator()(const edge& e1, const edge& e2) const {
        return e1.distance < e2.distance;
    }
};

int getEndpoint(int a, unsigned _mst[]) {
    if(a == _mst[a]) { return a; }
    _mst[a] = getEndpoint(_mst[a], _mst);
    return _mst[a];
}

void kruskalAlgorithm(const unsigned& _N, const unsigned& _S, vector<edge>& _edgeSet, unsigned _mst[]){
    // temporary holders for first and second endpoints
    unsigned x, y, count = 0;
    double D;  // Possible final answer
    sort(_edgeSet.begin(),_edgeSet.end(), CompareEdge());

    // delete
//    cout << "_edgeSet size: " << _edgeSet.size() << endl;
//        cout << "Sorted edge set:" << endl;
//    for(auto& e : _edgeSet) { cout << "\t(" << e.endpoint1 << ", " << e.endpoint2 << ", " << e.distance << ")," << endl; }

    for(unsigned index = 0; index < _N; index++) { _mst[index] = index; }
    for(unsigned index = 0; index < _edgeSet.size(); index++){
        edge& e = _edgeSet[index];
        x = getEndpoint(e.endpoint1, _mst);
        y = getEndpoint(e.endpoint2, _mst);
        if(x != y) {
            _mst[x] = y;
            count++;
            if(count == _N - _S) {
                // delete
//                cout << "count: " << count << endl;
//                cout << "Printing output D..." << endl;
                D = e.distance;
                cout << fixed << showpoint << setprecision(2) << D << endl;
                return;
            }
        }
    }
}


int main(){
    // needed variables
    vector<edge> edgeSet;
    unsigned N, S;  // number of test cases, number of available satellites
    unsigned x[maximumNumTrials], y[maximumNumTrials];  // x and y coordinates
    unsigned mst[maximumNumTrials];  // minimum spamming tree

    double dist; // temporarily holds distance between 2 endpoints
    unsigned trials;
    cin >> trials;
    for(; trials > 0; trials--) {
        cin >> S >> N;

        // delete
//        cout << "S: " << S << endl;
//        cout << "N: " << N << endl;

        edgeSet.clear();
        int temp;
        for(unsigned index = 0; index < N; index++) {
            cin >> temp;
            x[index] = temp;
            cin >> temp;
            y[index] = temp;
        }
        for(unsigned index = 0; index < N; index++) {
            for(unsigned j = index + 1; j < N; j++) {
                dist = sqrt(pow(double(x[index]) - double(x[j]), 2.0) + pow(double(y[index]) - double(y[j]), 2.0));
                edgeSet.push_back(edge(index,j,dist));

                // delete
//                cout << "dist: " << dist << endl;
            }
        }
        // delete
//        cout << "Checkpoint 1 reached..." << endl;

        kruskalAlgorithm(N, S, edgeSet, mst);

        // Clean up for next trial
        edgeSet.clear();
    }
    return 0;
}

