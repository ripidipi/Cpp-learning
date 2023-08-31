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
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//const int LOG = 17;
//typedef long double ld;
//typedef long long ll;
//
//
//int n;
//vector<vector<int>> gr;
//
//vector<int> tin, tout;
//int timer = 0;
//
//int up[MAXSIZE][LOG];
//
//void dfs(int v, int p = 0) {
//    tin[v] = timer++;
//    up[v][0] = p;
//    for (int i = 1; i < LOG; ++i) {
//        up[v][i] = up[up[v][i - 1]][i - 1];
//    }
//    for (auto& u : gr[v]) {
//        if(u != p) {
//            dfs(u, v);
//        }
//    }
//    tout[v] = timer++;
//}
//
//inline bool is_par(int u, int v) {
//    return tin[u] <= tin[v] && tout[v] <= tout[u];
//}
//
//int lca(int u, int v) {
//    if(is_par(u, v)) {
//        return u;
//    }
//    if(is_par(v, u)) {
//        return v;
//    }
//    for (int i = LOG - 1; i > -1; --i) {
//        if(!is_par(up[u][i], v))
//            u = up[u][i];
//    }
//    return up[u][0];
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    cin >> n;
//    gr.resize(n);
//    for (int i = 0; i < n; ++i) {
//        int u, v;
//        cin >> u >> v;
//        u--;
//        v--;
//        gr[u].push_back(v);
//        gr[v].push_back(u);
//    }
//    tin.resize(n);
//    tout.resize(n);
//
//}


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
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//const int LOG = 17;
//typedef long double ld;
//typedef long long ll;
//
//
//int n;
//vector<vector<int>> gr(MAXSIZE);
//
//int d[MAXSIZE];
//int first[MAXSIZE];
//vector<int> euler;
//
//int spars[LOG + 1][MAXSIZE * 2];
//int logs[MAXSIZE * 2];
//
//
//void dfs(int v, int p = -1) {
//    if (p == -1) {
//        d[v] = 0;
//    } else {
//        d[v] = d[p] + 1;
//    }
//    first[v] = euler.size();
//    euler.push_back(v);
//    for(int u : gr[v]) {
//        if(u != p) {
//            dfs(u, v);
//            euler.push_back(v);
//        }
//    }
//}
//
//void build() {
//    logs[1] = 0;
//    for(int i = 2; i < 2 * MAXSIZE; ++i) {
//        logs[i] = logs[i / 2] + 1;
//    }
//    int l = 2 * n - 1;
//    for(int i = 0; i < l; ++i) {
//        spars[0][i] = euler[i];
//    }
//    for(int level = 1; (1 << level) <= l; ++level) {
//        for(int i = 0; i + (1 << level) <= l; ++i) {
//            spars[level][i] = min(spars[level - 1][i], spars[level - 1][i + (1 << (level - 1))]);
//        }
//    }
//}
//
//int lca(int u, int v) {
//    u = first[u];
//    v = first[v];
//    if (u > v) {
//        swap(u, v);
//    }
//    int level = logs[u - v + 1];
//    return min(spars[level][u], spars[level][v - (1 << level) + 1]);
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    cin >> n;
//    gr.resize(n);
//    for (int i = 0; i < n; ++i) {
//        int u, v;
//        cin >> u >> v;
//        u--;
//        v--;
//        gr[u].push_back(v);
//        gr[v].push_back(u);
//    }
//    dfs(0);
//}
