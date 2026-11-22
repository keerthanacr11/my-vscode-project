#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    string line;

    int n = 1;

    if (!fin || !fout) {
        cout << "File error";
        return 0;
    }

    while (getline(fin, line)) {
        fout << n << ". " << line << endl;
        n++;
    }

    cout << "File copied successfully";

    fin.close();
    fout.close();

    return 0;
}