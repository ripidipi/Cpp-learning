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
//            comps.push_back(vector<int>());\
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