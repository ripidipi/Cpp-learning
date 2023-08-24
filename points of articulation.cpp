//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//
//using namespace std;
//
//const int INF = 1e9 + 9;
//
//vector<bool> used;
//vector<vector<pair<int, int>>> gr;
//vector<int> d;
//vector<int> dp;
//vector<int> ans;
//
//void init(int n) {
//    used.resize(n, false);
//    gr.resize(n);
//    d.resize(n);
//    dp.resize(n);
//}
//
//void dots(int v, int depth, bool root = false) {
//    used[v] = true;
//    d[v] = depth;
//    dp[v] = depth;
//    int count_ch = 0;
//    int min_d = depth;
//    for (auto e: gr[v]) {
//        if (!used[e.first]) {
//            dots(e.first, e.second, depth + 1);
//            dp[v] = min(dp[v], dp[e.first]);
//            min_d = min(min_d, dp[e.first]);
//            ++count_ch;
//        } else if(used[e.first]) {
//            dp[v] = min(dp[v], d[e.first]);
//        }
//    }
//    if (root && count_ch > 1) {
//        ans.push_back(v);
//    }
//    if (!root && min_d < d[v]) {
//        ans.push_back(v);
//    }
//}
