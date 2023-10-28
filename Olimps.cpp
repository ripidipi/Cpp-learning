////#define _USE_MATH_DEFINES
//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//#include <random>
//#include <unordered_map>
//#include <stack>
//#include <fstream>
//#include <queue>
//typedef long double ld;
//typedef long long ll;
//typedef unsigned int uint;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//#define Min(a) *min_element(all(a))
//#define Max(a) *max_element(all(a))
//#define Max_Ind(a) max_element(all(a)) - a.begin()
//#define Min_Ind(a) min_element(all(a)) - a.begin()
//#define Fin ios_base::sync_with_stdio(false); cin.tie(null); cout.precision(40);
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9 + 9;
//const int SIZE = 1e5 + 6;
//const int MOD = 1e9 + 7;
//const int BASE = 256;
//
//inline ostream& operator << (ostream& out, vector<int>& a) {
//    for (auto i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//inline istream& operator >> (istream& in, pair<int, int>& a) {
//    in >> a.first >> a.second;
//    return in;
//}
//
//inline ostream& operator << (ostream& out, vector<char>& a) {
//    for (auto i: a) {
//        if (i != '\000')
//            out << i;
//    }
//    return out;
//}
//
//
//
//
//int main() {
//    Fin
//    int Y;
//    cin >> Y;
//    int gol = -1;
//    if (Y == 23) {
//        gol = 1;
//    } else if(Y == 34) {
//        gol = 2;
//    } else {
//        gol = 3;
//    }
//    vector<vector<int>> gr(4);
//    int r, g, t;
//    cin >> r >> g >> t;
//    if (g >= t) {
//        gr[3].push_back(r);
//        gr[3].push_back(g);
//        gr[3].push_back(t);
//    }
//
//    for (int i = 0; i < 3; ++i) {
//        cin >> r >> g >> t;
//        if (g >= t) {
//            gr[i].push_back(r);
//            gr[i].push_back(g);
//            gr[i].push_back(t);
//        }
//    }
//    vector<int> c(4);
//    for (int i = 0; i < 4; ++i) {
//        c[i] = gr[i][0] + gr[i][1];
//    }
//    int first = 0, second = 0, time = 0, cur = 0;
//    while(true) {
//        if(cur == gol) {
//            first = time;
//            break;
//        }
//        int debaf = 0;
//        if ((time % c[cur + 1]) > gr[cur + 1][0]) {
//            debaf = (time % c[cur + 1]) - gr[cur + 1][0];
//        } else {
//            time += gr[cur + 1][0] - (time % c[cur + 1]);
//        }
//        if (gr[cur + 1][1] - debaf >= gr[cur + 1][2]) {
//            time += gr[cur + 1][2];
//            cur++;
//        } else if (gr[cur + 1][1] >= gr[cur + 1][2]) {
//            time += gr[cur + 1][0] + gr[cur + 1][2];
//            cur++;
//        } else {
//            first = INF;
//            break;
//        }
//    }
//    time = 0, cur = 4;
//    while(true) {
//        if(cur == gol) {
//            second = time;
//            break;
//        }
//        int debaf = 0;
//        if ((time % c[cur - 1]) > gr[cur - 1][0]) {
//            debaf = (time % c[cur - 1]) - gr[cur - 1][0];
//        } else {
//            time += gr[cur - 1][0] - (time % c[cur - 1]);
//        }
//        if (gr[cur - 1][1] - debaf >= gr[cur - 1][2]) {
//            time += gr[cur - 1][2];
//            cur--;
//        } else if (gr[cur - 1][1] >= gr[cur - 1][2]) {
//            time += gr[cur - 1][0] + gr[cur - 1][2];
//            cur--;
//        } else {
//            second = INF;
//            break;
//        }
//    }
//    cout << min(first, second) << '\n';
//    return 0;
//}
//
//
////34
////80 15 12
////120 20 14
////60 22 10
////90 18 14
