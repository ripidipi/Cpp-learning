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
//vector<vector<pair<int, int>>> gr_b;
//vector<bool> used_b;
//vector<int> ts;
//
//void topsort(int v) {
//    used_b[v] = true;
//    for (int u: gr_b[v]) {
//        if(!used_b[u]) {
//            topsort(u);
//        }
//    }
//    ts.push_back(v);
//}
//
//vector<int> comp;
//vector<int> comps;
//vector<vector<int>> gr;
//
//
//ll timer = 0;
//vector<ll> tin,fup;
//set<ll> pc;
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
//
//void init(int n) {
//    used_b.resize(n, false);
//    gr_b.resize(n);
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
//        int a, b, c;
//        cin >> a >> b >> c;
//        a--;
//        b--;
//        c--;
//        gr_b[a].push_back({b, i});
//        gr_b[a].push_back({c, i});
//        gr_b[b].push_back({a, i});
//        gr_b[b].push_back({c, i});
//        gr_b[c].push_back({a, i});
//        gr_b[c].push_back({b, i});
//    }
//    for (int i = 0; i < n; ++i) {
//        if(!used_b[i])
//            topsort(i);
//    }
//
//    cout << pc.size() << '\n';
//    for (int i : pc) {
//        cout << i << '\n';
//    }
//}
