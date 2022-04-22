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
    int n, x, y, now = 1;
    fin >> n >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    n--;
    while (n > now / x + now / y) {
        now++;
    }
    fout << x + now;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}