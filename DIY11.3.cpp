#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> freq;
    string word;

    cout << "Enter words (Ctrl+D to stop):" << endl;

    while (cin >> word)
        freq[word]++;

    string mostFrequent;
    int maxCount = 0;

    cout << "\nWord Frequencies:\n";

    for (auto p : freq) {
        cout << p.first << " : " << p.second << endl;

        if (p.second > maxCount) {
            maxCount = p.second;
            mostFrequent = p.first;
        }
    }

    if (!freq.empty())
        cout << "\nMost frequent word: " << mostFrequent;

    return 0;
}