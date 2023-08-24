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
//struct Edge {
//    int from, to, w;
//    Edge(){}
//    Edge(int from, int to, int w) :from(from), to(to), w(w) {}
//};
//
//vector<vector<int>> gr;
//vector<bool> used;
//
//void dfs(int v) {
//    used[v] = true;
//    for(auto u: gr[v]) {
//        if(!used[u]) {
//            dfs(u);
//        }
//    }
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    vector<Edge> edges;
//    used.resize(n);
//    gr.resize(n);
//    for (int i = 0; i < m; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        edges.push_back(Edge(u, v, w));
//        gr[u - 1].push_back(v - 1)
//    }
//    int start = 0;
//    vector<int> d(n, INF);
//    d[start] = 0;
//    vector<int> pr(n, -1);
//    for (int i = 0; i < n - 1; ++i) {
//        for (auto& e: edges) {
//            if (d[e.from] != INF && (d[e.to] > d[e.from] + e.w)) {
//                d[e.to] = d[e.from] + e.w;
//                pr[e.to] = e.from;
//            }
//        }
//    }
//    vector<int> old = d;
//    for (int i = 0; i < n - 1; ++i) {
//        for (auto& e: edges) {
//            if (d[e.from] != INF && (d[e.to] > d[e.from] + e.w)) {
//                d[e.to] = d[e.from] + e.w;
//                pr[e.to] = e.from;
//            }
//        }
//    }
//    if (old == d) {
//        cout << "We don't have path";
//        return 0;
//    }
//    for (int i = 0; i < n; ++i) {
//        if (old[i] != d[i]) {
//            dfs(i);
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        if (d[i] == INF) {
//            cout << "+inf\n";
//        } else if (used[i]) {
//            cout << "-inf\n";
//        } else {
//            cout << d[i] << '\n';
//        }
//    }
//    return 0;
//}