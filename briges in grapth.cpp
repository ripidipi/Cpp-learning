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