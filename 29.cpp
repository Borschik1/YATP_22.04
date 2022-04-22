#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;



int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    int n;
    fin >> n;
    vector<int> platforms;
    vector<int> moves;
    for (int i = 0; i < n; ++i) {
        int need;
        fin >> need;
        platforms.push_back(need);
    }
    for (int i = 0; i < n; ++i) {
        moves.push_back(30000);
    }
    moves[0] = 0;
    for (int i = 1; i < n; ++i) {
        moves[i] = min(moves[i - 1] + abs(platforms[i] - platforms[i - 1]), moves[i]);
        if (i != n - 1) {
            moves[i + 1] = min(moves[i - 1] + 3 * abs(platforms[i + 1] - platforms[i - 1]), moves[i + 1]);
        }
    }
    fout << moves[n - 1];
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
