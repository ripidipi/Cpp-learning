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
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//typedef long double ld;
//typedef long long ll;
//
//int n;
//int a[MAXSIZE];
//vector<int> t[4 * MAXSIZE];
//void build(int v, int l, int r) {
//    if (l == r - 1) {
//        t[v].push_back(a[l]);
//        return;
//    }
//    int m = (l + r) / 2;
//    build(2 * v + 1, l, m);
//    build(2 * v + 2, m, r);
//    t[v].resize(r - l);
//    merge(all(t[2 * v + 1]), all(t[2 * v + 2]),t[v].begin());
//}
//
//int ask(int v, int l, int r, int askl, int askr, int a, int b) {
//    if (l >= askr || r <= askl) {
//        return 0;
//    }
//    if (l >= askl && r <= askr) {
//        return upper_bound(all(t[v]),  b) - lower_bound(all(t[v]), a);
//    }
//    int m = (l + r) / 2;
//    ask(2 * v + 1, l, m, askl, askr, a, b);
//    ask(2 * v + 2, m, r, askl, askr, a, b);
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    return 0;
//}
//
//
//
//
//
