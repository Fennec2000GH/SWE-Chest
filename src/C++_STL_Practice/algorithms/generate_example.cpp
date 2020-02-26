#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <thread>
#include <vector>
using namespace std;

//std::generate
/* template <class ForwardIterator, class Generator>
 * void generate (ForwardIterator first, ForwardIterator last, Generator gen);
 */

//struct as function
struct random_string_struct{
    //operator overloading
    string operator()(){
        unsigned length = rand() % 10 + 1;
        char temp[length];
        for(int i = 0; i < length; i++) {
            int r1 = rand() % int(pow(i + 10, i + 10));
            this_thread::sleep_for(chrono::nanoseconds(100));
            int r2 = rand() % int(pow(i * 2, i * 12));
            srand(time(new time_t(pow(r1, r2 ))));
            temp[i] = (char)(97 + rand() % 26);
        }
        string s(temp, length);
        return s;
    }
} RandomString;

int main() {
    cout << RandomString() << endl;
    //main vector
    vector<string> v(10);
    generate(v.begin(), v.end(), RandomString);
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;

    return 0;
}