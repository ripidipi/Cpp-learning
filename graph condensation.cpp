//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//
//const int INF = 1e9 + 9;
//
//int n, m;
//vector<vector<int>> gr, rgr;
//vector<bool> used;
//vector<int> ts;
//
//vector<int> comp; // для каждой вершины отметим номер компоненты
//vector<vector<int>> comps; // для каждой компоненты запишем все верщины в ней
//vector<vector<int>> cgr; // сконденсированый граф
//
//
//void dfs (int v) {
//    used[v] = true;
//    for (auto u: gr[v]) {
//        if(!used[u]) {
//            dfs(u);
//        }
//    }
//    ts.push_back(v);
//}
//
//void dfs2(int v, int cur_comp) {
//    used[v] = true;
//    comp[v] = cur_comp;
//    comps[cur_comp].push_back(v);
//    for (int u: rgr[v])  {
//        if (!used[u]) {
//            dfs2(u, cur_comp);
//        } else if (comp[u] != cur_comp) {
//            cgr[comp[u]].push_back(cur_comp);
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cin >> n >> m;
//    used.resize(n);
//    rgr.resize(n);
//    gr.resize(n);
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        gr[u - 1].push_back(v - 1);
//        rgr[v - 1].push_back(u - 1);
//    }
//    for (int i = 0; i < n; ++i) {
//        if (!used[i]) {
//            dfs(i);
//        }
//    }
//    reverse(ts.begin(), ts.end());
//    used.assign(n, false);
//    comp.resize(n);
//    int cur_comp = 0;
//    for (int v: ts) {
//        if (!used[v]) {
//            cgr.push_back(vector<int>());
//            comps.push_back(vector<int>());
//            dfs2(v, cur_comp++);
//        }
//    }
//    cout << cur_comp << '\n';
//    for (int i = 0; i < n; ++i) {
//        cout << comp[i] + 1 << ' ';
//    }
//    return 0;
//}









//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//
//const int INF = 1e9 + 9;
//
//int n, m;
//vector<vector<int>> gr, rgr;
//vector<bool> used;
//vector<int> ts;
//
//vector<int> comp; // для каждой вершины отметим номер компоненты
//vector<vector<int>> comps; // для каждой компоненты запишем все верщины в ней
//vector<vector<int>> cgr; // сконденсированый граф
//
//
//void dfs (int v) {
//    used[v] = true;
//    for (auto u: gr[v]) {
//        if(!used[u]) {
//            dfs(u);
//        }
//    }
//    ts.push_back(v);
//}
//
//void dfs2(int v, int cur_comp) {
//    used[v] = true;
//    comp[v] = cur_comp;
//    comps[cur_comp].push_back(v);
//    for (int u: rgr[v])  {
//        if (!used[u]) {
//            dfs2(u, cur_comp);
//        } else if (comp[u] != cur_comp) {
//            cgr[comp[u]].push_back(cur_comp);
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cin >> n >> m;
//    used.resize(n);
//    rgr.resize(n);
//    gr.resize(n);
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        gr[u - 1].push_back(v - 1);
//        rgr[v - 1].push_back(u - 1);
//    }
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        if (!used[i]) {
//            dfs(i);
//        }
//    }
//    reverse(ts.begin(), ts.end());
//    used.assign(n, false);
//    comp.resize(n);
//    int cur_comp = 0;
//    for (int v: ts) {
//        if (!used[v]) {
//            cgr.push_back(vector<int>());
//            comps.push_back(vector<int>());\
//            dfs2(v, cur_comp++);
//        }
//    }
//    cout << cur_comp << '\n';
//    for (int i = 0; i < n; ++i) {
//        cout << comp[i] + 1 << ' ';
//    }
//    vector<int> cnums(cur_comp, INF);
//    for (int i = 0; i < n; ++i) {
//        cnums[comp[i]] = min(cnums[comp[i]], nums[i]);
//    }
//    vector<int>dp(cur_comp, INF);
//    for (int i = cur_comp - 1; i > -1; --i) {
//        dp[i] = cnums[i];
//        for (int u: cgr[i]) {
//            dp[i] = min(dp[i], dp[u]);
//        }
//    }
//    vector<int> ans(n);
//    for (int i = 0; i < n; ++i) {
//        ans[i] = dp[comp[i]];
//    }
//    return 0;
//}














//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//typedef unsigned long long ull;
//
//const int INF = 1e9;
//const int mod = 1e9 + 7;
//
//struct Edge {
//    int to, num;
//    bool is_bridge;
//    Edge() {}
//    Edge(int to, int num) :to(to), num(num) {
//        is_bridge = false;
//    }
//};
//
//vector<Edge> edges;
//vector<vector<int>> gr;
//vector<int> dp, d;
//vector<bool> used;
//
//vector<int> comps;
//vector<vector<int>> comp;
//vector<vector<int>> cgr;
//
//void dfs(int v, int depth = 0, int p = -1) {
//    used[v] = 1;
//    d[v] = depth;
//    dp[v] = INF;
//    for (int i : gr[v]) {
//        int u = edges[i].to;
//        int num = edges[i].num;
//        if (!used[u]) {
//            dfs(u, depth + 1, num);
//            dp[v] = min(dp[v] , dp[u]);
//        }
//        else if (num != p) {
//            dp[v] = min(dp[v], d[u]);
//        }
//    }
//    if (p != -1 && dp[v] >= d[v]) {
//        edges[2 * p].is_bridge = 1;
//        edges[2 * p + 1].is_bridge = 1;
//    }
//}
//
//void dfs2(int v, int cur_comp) {
//    used[v] = 1;
//    comps[v] = cur_comp;
//    comp[cur_comp].emplace_back(v);
//    for (int e : gr[v]) {
//        int u = edges[e].to;
//        int num = edges[e].num;
//        if (!used[u] && !edges[2 * num].is_bridge) {
//            dfs2(u, cur_comp);
//        }
//        else if (used[u] && comps[v] != comps[u]) {
//            cgr[comps[u]].emplace_back(cur_comp);
//            cgr[cur_comp].emplace_back(comps[u]);
//        }
//    }
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    int n, m;
//    cin >> n >> m;
//
//    gr.resize(n);
//    used.resize(n);
//    d.resize(n);
//    dp.resize(n);
//    edges.reserve(2 * m);
//
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        --u, --v;
//        edges.emplace_back(Edge(v, i));
//        edges.emplace_back(Edge(u, i));
//        gr[u].emplace_back(2 * i);
//        gr[v].emplace_back(2 * i + 1);
//    }
//
//    for (int i = 0; i < n; ++i) {
//        if (!used[i]) {
//            dfs(i);
//        }
//    }
//
//    comps.resize(n, -1);
//    used.assign(n, 0);
//
//    int cur_comp = 0;
//    for (int i = 0; i < n; ++i) {
//        if (!used[i]) {
//            comp.push_back(vector<int>());
//            cgr.push_back(vector<int>());
//            dfs2(i, cur_comp++);
//        }
//    }
//    if (cgr.size() == 1) {
//        cout << 0 << '\n';
//        return 0;
//    }
//    used.assign(n, false);
//    int nodes = 0;
//    for (int i = 0; i < cgr.size(); ++i) {
//        if(cgr[i].size() == 1) {
//            nodes++;
//        }
//    }
//    cout << nodes / 2 + nodes % 2 << '\n';
//}