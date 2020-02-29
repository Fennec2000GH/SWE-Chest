
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::merge
/* default (1)
 * template <class InputIterator1, class InputIterator2, class OutputIterator>
 * OutputIterator merge (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);
*/
 /* custom (2)
  * template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
  * OutputIterator merge (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp);
 */

 enum Animal { RABBIT, SNAKE, SPIDER, CHICKEN, DUCK, TURTLE};
 const vector<string> enumString = {"RABBIT", "SNAKE", "SPIDER", "CHICKEN", "DUCK", "TURTLE"};

int main() {
    //vectors to merge together
    cout << "BEFORE MERGING... " << endl;
    vector<Animal> first = { RABBIT, RABBIT, TURTLE, DUCK, DUCK, SNAKE};
    sort(first.begin(), first.end());
    cout << "first: { ";
    for_each(first.cbegin(), first.cend(), [](Animal a){ cout << enumString[a] << ", "; });
    cout << "} " << endl;

    vector<Animal> second = { CHICKEN, CHICKEN, CHICKEN, SPIDER };
    sort(second.begin(), second.end());
    cout << "second: { ";
    for_each(second.cbegin(), second.cend(), [](Animal a){ cout << enumString[a] << ", "; });
    cout << "} " << endl;
    cout << "--------------------------------------------------------------------------------------" << endl << endl;

    //merging two (2) vectors into one and storing into v
    cout << "AFTER MERGING... " << endl;
    vector<Animal> v(first.size() + second.size());
    merge(first.begin(), first.end(), second.begin(), second.end(), v.begin());
    cout << "v: { ";
    for_each(v.cbegin(), v.cend(), [](Animal a){ cout << enumString[a] << ", "; });
    cout << "} " << endl;
    cout << "--------------------------------------------------------------------------------------" << endl << endl;

    cout << "Note that the original two (2) vectors used in the merging remain unchanged. " << endl;
    cout << "size of first: " << first.size() << endl;
    cout << "size of second: " << second.size() << endl;
    cout << "first: { ";
    for_each(first.cbegin(), first.cend(), [](Animal a){ cout << enumString[a] << ", "; });
    cout << "} " << endl;
    cout << "second: { ";
    for_each(second.cbegin(), second.cend(), [](Animal a){ cout << enumString[a] << ", "; });
    cout << "} " << endl;
    cout << "--------------------------------------------------------------------------------------" << endl << endl;

    return 0;
}

