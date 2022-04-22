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
    int n, maxi = -pow(30000, 3);
    fin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int need;
        fin >> need;
        vec.push_back(need);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int z = j + 1; z < n; ++z) {
                maxi = max(maxi, vec[i] * vec[j] * vec[z]);
            }
        }
    }
    fout << maxi;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}