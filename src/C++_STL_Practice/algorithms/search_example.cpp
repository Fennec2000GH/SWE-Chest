#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::search
/** (1) equality
    template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);
**/
/** (2) predicate
    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
 **/

int main(){
    vector<int> v;
    for(int i = 0; i < 10; i++) { v.push_back(i); } // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    //find iterator to start of sub-vector {5, 6, 7, 8, 9}
    vector<int> test1(v.begin() + 5, v.end());
    vector<int>::iterator it1 = search(v.begin(), v.end(), test1.begin(), test1.end());
    copy(it1, it1 + test1.size(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    //search in reverse for sub-vector {4, 3, 2}
    vector<int> test2 = {4, 3, 2};
    vector<int>::reverse_iterator it2  = search(v.rbegin(), v.rend(), test2.begin(), test2.end());
    copy(it2, it2 + test2.size(), ostream_iterator<int>(cout, ", "));

    //use binary predicate (ex. product is even)
    vector<int> test3(4, 2); // {2, 2, 2, 2}
    vector<int>::iterator it3 = search(v.begin(), v.end(), test3.begin(), test3.end(), [](int a, int b){ return (a * b) % 2 == 0; });
    copy(it3, it3 + test3.size(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    //constant iterators being used
    vector<int> test4(test2); reverse(test4.begin(), test4.end()); // {2, 3, 4}
    vector<int>::const_iterator it4 = search(v.cbegin(), v.cend(), test4.cbegin(), test4.cend());
    copy(it4, it4 + test4.size(), ostream_iterator<int>(cout, ", "));

    return 0;
}
