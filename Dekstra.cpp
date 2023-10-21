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
//#include <stack>
//typedef long double ld;
//typedef long long ll;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int SIZE = 1e5 + 5;
//const int MOD = 1e9;
//typedef long long ll;
//
//vector<vector<pair<int, int>>> gr;
//
//void init(int n, int m) {
//    gr.resize(n + m);
//}
//
//ll solve(int srt, int w,  int n, int m) {
//    int start = srt;
//    vector<ll> d(n, -INF);
//    set<pair<int, int>> s;
//    d[start] = w;
//    s.insert({d[start], start});
//    while(!s.empty()) {
//        int v = s.begin()->second;
//        s.erase(s.begin());
//        for(auto& e: gr[v]) {
//            int u = e.first, w = e.second;
//            if (d[u] < d[v] - w && ((u % m) + u / m) % m >= ((v % m) + v / m) % m) {
//                s.erase({d[u], u});
//                d[u] = d[v] + w;
//                s.insert({d[u], u});
//            }
//        }
//    }
//    return *max_element(all(d));
//}
//
//int main () {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    int n, m, p;
//    cin >> n >> m >> p;
//    vector<int> a(n), b(m);
//    init(n, m);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < m; ++i) {
//        cin >> b[i];
//    }
//    for (int i = 0; i < p; ++i) {
//        int lu, rv;
//        cin >> lu >> rv;
//        lu--; rv--;
//        gr[lu].push_back({rv + n, b[rv]});
//        gr[rv + n].push_back({lu, a[lu]});
//    }
//    ll res1 = solve(0, a[0], n + m, n),
//    res2 = solve(n, b[0], n + m, n);
//    cout << max(res1, res2) << '\n';
//}
