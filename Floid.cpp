//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <deque>
//
//using namespace std;
//typedef long long ll;
//
//const int INF = 1e9;
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> gr(n, vector<int>(n));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cin >> gr[i][j];
//        }
//    }
//    for (int k = 0; k < n; ++k) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
//            }
//        }
//    }
//    return 0;
//}