//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//
//struct Edge {
//    int to;
//    int num;
//    bool isbriage;
//    Edge(){};
//    Edge(int to, int num) :to(to), num(num) {};
//};
//
//const int INF = 1e9 + 9;
//
//int n, m;
//vector<bool> used;
//vector<vector<int>> gr;
//vector<Edge> edges;
//vector<int> dp, d;
//vector<int> ans;
//
//void dfs(int v, int depth = 0, int p = -1) {
//    used[v] = true;
//    d[v] = depth;
//    for (int e: gr[v]) {
//        int u = edges[e].to;
//        int num = edges[e].num;
//        if(!used[u]) {
//            dfs(u, depth+1, num);
//            dp[v] = min(dp[v], dp[u]);
//        } else if (num != p) {
//            dp[v] = min(dp[v], dp[u]);
//        }
//    }
//    if(dp[v] >= d[v] && p != -1) {
//        ans.push_back(p + 1);
//        edges[2 * p].isbriage = true;
//        edges[2 * p + 1].isbriage = true;
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cin >> n >> m;
//    gr.resize(n);
//    edges.reserve(2 * n);
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        u--; v--;
//        gr[u].push_back(i);
//        edges.push_back(Edge(u, i));
//        edges.push_back(Edge(v, i));
//    }
//    used.reserve(n);
//    d.resize(n);
//    dp.resize(n);
//    for (int i = 0; i < n; ++i) {
//        if (!used[i]) {
//            dfs(i);
//        }
//    }
//    sort(ans.begin(), ans.end());
//    cout << ans.size() << '\n';
//    for (int a: ans) {
//        cout << a << ' ';
//    }
//    return 0;
//}
//
//
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <numeric>
////
////using namespace std;
////
////const int INF = 1e9 + 9;
////
////vector<bool> used;
////vector<vector<pair<int, int>>> gr;
////vector<int> d;
////vector<int> dp;
////vector<int> ans;
////
////void init(int n) {
////    used.resize(n, false);
////    gr.resize(n);
////    d.resize(n);
////    dp.resize(n);
////}
////
////void dfs(int v, int depth = 0, int p = -1) {
////    used[v] = true;
////    d[v] = depth;
////    dp[v] = depth;
////    for (auto e: gr[v]) {
////        if(e.second == p) {
////            continue;
////        } else if (!used[e.first]) {
////            dfs(e.first, depth+1, e.second);
////            dp[v] = min(dp[v], dp[e.first]);
////            if(dp[e.first] >= d[e.first]) {
////                ans.push_back(e.second);
////            }
////        } else if(used[e.first]) {
////            dp[v] = min(dp[v], d[e.first]);
////        }
////    }
////}
////
////
////int main() {
////    int n, m;
////    cin >> n >> m;
////    init(n);
////    for (int i = 0; i < m; ++i) {
////        int u, v;
////        cin >> u >> v;
////        u--, v--;
////        gr[u].push_back({v, i});
////        gr[v].push_back({u, i});
////    }
////    dfs(0);
////    cout << ans.size() << '\n';
////    for (int i: ans) {
////        cout << i + 1 << ' ';
////    }
////}