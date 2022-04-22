#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;


int need(int m, int n) {
    int answer = 0;
    if (n < m) {
        return 1;
    }
    for (int i = 0; i < n - m + 1; ++i) {
        answer += need(m, n - m - i);
    }
    return answer;
}

int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    int n, m;
    fin >> m >> n;
    fout << 1 + need(m, n);
    fin.close();
    fout.close();
    system("pause");
    return 0;
}