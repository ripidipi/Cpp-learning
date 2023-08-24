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
//    vector<vector<pair<int, int>>> gr(n);
//    for (int i = 0; i < m; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        u--; v--;
//        gr[u].push_back({v, w});
//        gr[v].push_back({u, w});
//    }
//    int start = 0;
//    vector<int> d(n, INF);
//    set<pair<int, int>> s;
//    d[start] = 0;
//    s.insert({d[start], start});
//    while(!s.empty()) {
//        int v = s.begin()->second;
//        s.erase(s.begin());
//        for (auto& e: gr[v]) {
//            int u = e.first, w = e.second;
//            if(d[u] > d[v] + w) {
//                s.erase({d[u], u});
//                d[u] = d[v] + w;
//                s.insert({d[u], u});
//            }
//        }
//    }
//    return 0;
//}