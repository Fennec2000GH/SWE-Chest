
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include "/usr/local/Cellar/boost/1.72.0_1/include/boost/thread/locks.hpp"
using namespace std;

extern inline void printInt(int i) { cout << i << endl; }

TEST_CASE("First") {
    mutex m;

    vector<thread*> v;
    for(int i = 0; i < 10; i++) {
        thread *t = new thread(printInt, i);
        v.push_back(t);
    }

    for(auto &th : v) { th -> join(); }

}



