//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <numeric>
//#include <map>
//
//using namespace std;
//typedef long long ll;
//
//int n, m;
//
//struct Queris {
//    char type;
//    int u, v;
//    Queris(){};
//    Queris(char type, int u = -1, int v = -1) :type(type), u(u), v(v)  {};
//    inline pair<int, int> mp() {
//        return make_pair(min(u, v), max(u, v));
//    }
//};
//
//struct Edge {
//    int u, v;
//    Edge(){};
//    Edge(int u_, int v_) {
//        u = min(u_, v_);
//        v = max(u_, v_);
//    };
//    Edge(const Queris& q) {
//        u = q.u;
//        v = q.v;
//    }
//};
//
//struct RollBack {
//    int arr, pos, val; // arr - 0(p) arr - 1(d)
//    RollBack(){};
//    RollBack(int arr, int pos, int val) :arr(arr), pos(pos), val(val) {};
//};
//
//struct DSU {
//    vector<int> d, p;
//    int cur_comps;
//
//    DSU() {};
//
//    DSU(int N) {
//        cur_comps = n;
//        p.resize(N);
//        iota(p.begin(), p.end(), 0);
//        d.resize(N);
//    }
//
//    int get_par(int v) {
//        if (v == p[v]) {
//            return v;
//        }
//        return get_par(p[v]);
//    }
//
//    void unit(int u, int v, vector<RollBack> &r) {
//        u = get_par(u);
//        v = get_par(v);
//        if (u != v) {
//            cur_comps--;
//            if (d[u] > d[v]) {
//                swap(u, v);
//            }
//            r.push_back(RollBack(0, u, p[u]));
//            p[u] = v;
//            if (d[u] == d[v]) {
//                r.push_back(RollBack(1, v, d[v]));
//                d[v]++;
//            }
//        }
//    }
//
//    void undo(vector<RollBack> &r, int r_c) {
//        cur_comps = r_c;
//        for (int i = r.size() - 1; i > -1; --i) {
//            auto cur_r = r[i];
//            if (cur_r.arr == 0) {
//                p[cur_r.pos] = cur_r.val;
//            } else {
//                d[cur_r.pos] == cur_r.val;
//            }
//        }
//    }
//
//    void make_unites(const vector<Edge>& ed, vector<RollBack>& r) {
//        for (auto& e: ed) {
//            unit(e.v, e.u, r);
//        }
//    }
//
//};
//
//vector<int> times;
//vector<vector<Edge>> t;
//vector<int> L, R;
//vector<vector<RollBack>> rolls;
//vector<int> rolls_c;
//
//
//void build(int v, int l, int r) {
//    L[v] = l;
//    R[v] = r;
//    if(l == r - 1) {
//        return;
//    }
//    int mid = (l + r) / 2;
//    build(2 * v + 1, l, mid);
//    build(2 * v + 2, mid, r);
//}
//
//
//
//
//void add_edge (int v, int l, int r, int askl, int askr, const Edge& e) {
//    if(l >= askr || r <= askl) {
//        return;
//    }
//    if (l >= askl && r <= askr) {
//        t[v].push_back(e);
//        return;
//    }
//    int mid = (l + r) / 2;
//    add_edge(2 * v + 1, l, mid, askl, askr, e);
//    add_edge(2 * v + 2, mid, r, askl, askr, e);
//}
//
//void dfs (vector<int>& ans) {
//    DSU d(n);
//    rolls.resize(4 * m);
//    rolls_c.resize(4 * m);
//    int cur_v = 0, cur_l = 0, cur_r = m;
//    for (int T: times) {
//        while (!(T >= cur_l && T < cur_r)) {
//            d.undo(rolls[cur_v], rolls_c[cur_v]);
//            cur_v = (cur_v - 1) / 2;
//            cur_l = L[cur_v];
//            cur_r = R[cur_r];
//        }
//        while (cur_l != cur_r - 1) {
//            int cur_m = (cur_l + cur_r);
//            if (T < cur_m) {
//                cur_v = cur_v * 2 + 1;
//                cur_l = L[cur_v];
//                cur_r = R[cur_v];
//                d.make_unites(t[cur_v], rolls[cur_v]);
//                rolls_c[cur_v] = d.cur_comps;
//            } else {
//                cur_v = cur_v * 2 + 2;
//                cur_l = L[cur_v];
//                cur_r = R[cur_v];
//            }
//            d.make_unites(t[cur_v], rolls[cur_v]);
//            rolls_c[cur_v] = d.cur_comps;
//        }
//        ans.push_back(d.cur_comps);
//    }
//
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cin >> n >> m;
//    vector<Queris> qr;
//    qr.resize(n);
//    for (int i = 0; i < m; ++i) {
//        char type;
//        cin >> type;
//        if (type == '?') {
//            times.push_back(i);
//            qr.push_back(Queris('?'));
//        } else {
//            int u, v;
//            cin >> u >> v;
//            u--; v--;
//            qr.push_back(Queris(type, u, v));
//        }
//    }
//    t.resize(4 * m);
//    R.resize(4 * m);
//    L.resize(4 * m);
//    build(0, 0, m);
//    map<pair<int, int>, int> pos;
//    for (int i = 0; i < n; ++i) {
//        if (qr[i].type == '+') {
//            auto cur = qr[i].mp();
//            pos[cur] = i;
//        } else if (qr[i].type == '-') {
//            add_edge(0, 0, m, pos[qr[i].mp()], i + 1, Edge(qr[i]));
//        }
//    }
//    for (auto& i : pos) {
//        add_edge(0,  0, m , i.second, m, Edge(i. first.first, i.first.second));
//    }
//    vector<int> ans;
//    dfs(ans);
//    for (int i : ans) {
//        cout << i << ' ';
//    }
//    return 0;
//}