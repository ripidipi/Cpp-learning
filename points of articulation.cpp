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



//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include <set>
//
//using namespace std;
//
//const int INF = 1e9 + 9;
//typedef long long ll;
//
//ll timer = 0;
//vector<vector<ll>> gr;
//vector<ll> tin,fup;
//set<ll> pc;
//vector<bool> used;
//
//void dfs(ll v,ll p = -1){
//    used[v] = true;
//    tin[v] = fup[v] = timer++;
//    ll children = 0;
//    for(auto u : gr[v]){
//        if(u == p){
//            continue;
//        }
//        if(used[u]){
//            fup[v] = min(fup[v],tin[u]);
//        }
//        else{
//            dfs(u,v);
//            fup[v] = min(fup[v],fup[u]);
//            if(fup[u] >= tin[v] && p != -1){
//                pc.insert(v+1);
//            }
//            children++;
//        }
//    }
//    if(p == -1 && children > 1){
//        pc.insert(v+1);
//    }
//}
//void init(int n) {
//    used.resize(n, false);
//    gr.resize(n);
//    fup.resize(n);
//    tin.resize(n);
//}
//
//int main () {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    init(n);
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> v >> u;
//        v--;
//        u--;
//        gr[v].push_back(u);
//        gr[u].push_back(v);
//    }
//    for (int i = 0; i < n; ++i) {
//        if(!used[i])
//            dfs(i);
//    }
//    cout << pc.size() << '\n';
//    for (int i : pc) {
//        cout << i << '\n';
//    }
//}
