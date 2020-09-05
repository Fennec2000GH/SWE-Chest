
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string word;
    for(int test = 0; test < n; test++) {
        getline(cin, word);
        if (word.size() == 5) { cout << 3 << endl; }
        else {
            pair<int, int> oneOrTwo = make_pair(0, 0);  // similarity points for child's given word and "one" and "two"
            const string one = "one", two = "two";
            for (int i = 0; i < 3; i++) {
                if (word[i] == one[i]) { ++oneOrTwo.first; }
                else if (word[i] == two[i]) { ++oneOrTwo.second; }
            }
            if (oneOrTwo.first > oneOrTwo.second) { cout << 1 << endl; }
            else { cout << 2 << endl; }
        }
    }
}

