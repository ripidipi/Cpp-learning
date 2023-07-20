//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <numeric>
//#include <cmath>
//
//using namespace std;
//typedef long long ll;
//
//
//struct Mo {
//    unordered_map<int, int> cnt;
//    int summ;
//    Mo(){
//        summ = 0;
//    }
//    void add(int x) {
//        cnt[x]++;
//        if (cnt[x] == 3) {
//            summ += x;
//        }
//    }
//    void del(int x) {
//        cnt[x]--;
//        if (cnt[x] == 2) {
//            summ -= x;
//        }
//    }
//    int f ( ) {
//        return summ;
//    }
//};
//
//struct Query {
//    int l, r, num;
//    Query() {}
//    Query(int l, int r, int num): l(l), r(r), num(num) {}
//};
//
//int K;
//
//inline bool operator < (const Query& a, const Query& b) {
//    if (a.l / K != b.l / K) {
//        return a.l / K < b.l / K;
//    }
//    if ((a.l / K) % 2 == 0) {
//        return a.r < b.r;
//    } else {
//        return a.r > b.r;
//    };
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    K = ::sqrt(n);
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    int Q;
//    cin >> Q;
//    vector<Query> qr;
//    for (int i = 0; i < Q; ++i) {
//        int l, r;
//        cin >> l >> r;
//        qr.push_back(Query(l - 1, r - 1, i));
//    }
//    sort(qr.begin(), qr.end());
//    Mo m;
//    vector<int> ans(Q);
//    int l = 0, r = -1;
//    for (auto& q: qr) {
//        while (l > q.l) {
//            m.add(a[l - 1]);
//            l--;
//        }
//        while (r < q.r) {
//            m.add(a[r + 1]);
//            r++;
//        }
//        while (l < q.l) {
//            m.del(a[l]);
//            l++;
//        }
//        while (r > q.l) {
//            m.del(a[r]);
//            r--;
//        }
//        ans[q.num] = m.f();
//    }
//    return 0;
//}
