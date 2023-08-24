//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <numeric>
//
//using namespace std;
//typedef long long ll;
//
//const int INF = 1e9;
//
//vector<int> p;
//vector<int> d;
//
//void init (int n) {
//    p.resize(n);
//    d.resize(n);
//    iota(p.begin(), p.end(), 0);
//}
//
//int get_par(int v) {
//    if(v == p[v]) {
//        return v;
//    }
//    return p[v] = get_par(p[v]);
//}
//
//void unit (int u, int v) {
//    u = get_par(u);
//    v = get_par(v);
//    if(u != v) {
//        if(d[u] > d[v]) {
//            swap(u, v);
//        }
//        p[u] = v;
//        if (d[v] == d[u]) {
//            d[v] ++;
//        }
//    }
//}
//
//struct Edge {
//    int u, v, w, num;
//    Edge(){};
//    Edge(int from, int to, int w, int num) : u(from), v(to), w(w), num(num) {}
//};
//
//bool operator < (const Edge& a, const Edge& b) {
//    return a.w < b.w;
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    vector<Edge> edges;
//    init(n);
//    for (int i = 0; i < n; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        edges.push_back(Edge(u - 1, v - 1, w, i));
//    }
//    sort(edges.begin(), edges.end());
//    vector<int> ans;
//    int answ = 0;
//    for (auto& e: edges) {
//        if (get_par(e.u) != get_par(e.v)) { // если e.u и e.v не связаны то связать их
//            unit(e.u, e.v);
//            ans.push_back(e.num);
//            answ += e.w;
//        }
//    }
//    return 0;
//}






//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <numeric>
//
//using namespace std;
//typedef long long ll;
//
//const int INF = 1e9;
//
//vector<int> p;
//vector<int> d;
//
//void init (int n) {
//    p.resize(n);
//    d.resize(n);
//    iota(p.begin(), p.end(), 0);
//}
//
//int get_par(int v) {
//    if(v == p[v]) {
//        return v;
//    }
//    return p[v] = get_par(p[v]);
//}
//
//void unit (int u, int v) {
//    u = get_par(u);
//    v = get_par(v);
//    if(u != v) {
//        if(d[u] > d[v]) {
//            swap(u, v);
//        }
//        p[u] = v;
//        if (d[v] == d[u]) {
//            d[v] ++;
//        }
//    }
//}
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    init(n);
//    int comp = n;
//    for (int i = 0; i < m; ++i) {
//        char type;
//        cin >> type;
//        if(type == '+') {
//            int u, v;
//            cin >> u >> v;
//            u--; v--;
//            if(get_par(u) != get_par(v)) {
//                comp--;
//                unit(u, v);
//            }
//        } else {
//            cout << comp << '\n';
//        }
//    }
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <numeric>
//
//using namespace std;
//typedef long long ll;
//
//const int INF = 1e9;
//
//vector<int> p;
//vector<int> d;
//vector<int> w;
//
//
//void init (int n) {
//    p.resize(n);
//    d.resize(n);
//    w.resize(n);
//    iota(p.begin(), p.end(), 0);
//}
//
//int get_par(int v) {
//    if(v == p[v]) {
//        return v;
//    }
//    return p[v] = get_par(p[v]);
//}
//
//void unit (int u, int v, int W) {
//    u = get_par(u);
//    v = get_par(v);
//    if (u != v) {
//        if(d[u] > d[v]) {
//            swap(u, v);
//        }
//        p[u] = v;
//        if (d[v] == d[u]) {
//            d[v] ++;
//        }
//    }
//    w[v] += W;
//}
//
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    init(n);
//    int comp = n;
//    for (int i = 0; i < m; ++i) {
//        char type;
//        cin >> type;
//        if(type == '+') {
//            int u, v, W;
//            cin >> u >> v >> W;
//            u--; v--;
//            unit(u, v, W);
//        } else {
//            int v;
//            cin >> v;
//            cout << w[get_par(v)] << '\n';
//        }
//    }
//    return 0;
//}