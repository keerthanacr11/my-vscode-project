#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Apple", 30},
        {"Banana", 10},
        {"Mango", 20},
        {"Orange", 15}
    };

    sort(v.begin(), v.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        });

    for (auto p : v)
        cout << p.first << " " << p.second << endl;

    return 0;
}