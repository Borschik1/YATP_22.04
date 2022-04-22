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
    vector<int> vec(n);
    vector<int> len(n, 0);
    for (int i = 0; i < n; ++i)
        fin >> vec[i];
    int maxi = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (vec[j] < vec[i]) {
                if (len[j] > len[i]) {
                    len[i] = len[j];
                }
            }
        }
        len[i]++;
        maxi = max(maxi, len[i]);
    }
    fout << maxi;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}