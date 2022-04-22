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
    int n, k;
    fin >> n >> k;
    vector<string> pole;
    for (int i = 0; i < n; ++i) {
        string need2;
        fin >> need2;
        pole.push_back(need2);
    }
    vector<vector<int>> moves, need4;
    vector<int> need3;
    int ans = 0;
    need3.push_back(0);
    need3.push_back(0);
    moves.push_back(need3);
    for (int i = 1; i <= k; ++i) {
        need4.clear();
        for (int j = 0; j < moves.size(); ++j) {
            if (moves[j][0] - 1 >= 0) {
                if (pole[moves[j][0] - 1][moves[j][1]] == '0') {
                    need3.clear();
                    need3.push_back(moves[j][0] - 1);
                    need3.push_back(moves[j][1]);
                    need4.push_back(need3);
                }
            }
            if (moves[j][0] + 1 < n) {
                if (pole[moves[j][0] + 1][moves[j][1]] == '0') {
                    need3.clear();
                    need3.push_back(moves[j][0] + 1);
                    need3.push_back(moves[j][1]);
                    need4.push_back(need3);
                }
            }
            if (moves[j][1] - 1 >= 0) {
                if (pole[moves[j][0]][moves[j][1] - 1] == '0') {
                    need3.clear();
                    need3.push_back(moves[j][0]);
                    need3.push_back(moves[j][1] - 1);
                    need4.push_back(need3);
                }
            }
            if (moves[j][1] + 1 < n) {
                if (pole[moves[j][0]][moves[j][1] + 1] == '0') {
                    need3.clear();
                    need3.push_back(moves[j][0]);
                    need3.push_back(moves[j][1] + 1);
                    need4.push_back(need3);
                }
            }
        }
        moves.clear();
        moves = need4;
    }
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i][0] == n - 1 && moves[i][1] == n - 1) {
            ans++;
        }
    }
    fout << ans;
    fin.close();
    fout.close();
    system("pause");
    return 0;
}
