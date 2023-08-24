//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//
//const ll Mod = 1e9 + 11, p = 179;
//const int SIZE = 1e5 + 5;
//
//ll powers[SIZE];
//
//vector<ll> get_hash(string& s) {
//    int n = s.size();
//    vector<ll> h(n + 1);
//    h[0] = 0;
//    for (int i = 0; i < n; ++i) {
//        h[i + 1] = (h[i] + powers[i] * s[i]) % Mod;
//    }
//    return h;
//}
//
//inline ll subHash(int l, int r, const vector<ll>& h) {
//    return (h[r + 1] - h[l]) * powers[h.size() - l - 1] % Mod;
//}
//
//int cmp(int l1, int r1, int l2, int r2, const vector<ll>& h, const string& s) {
//    // < -1 | = 0 | > 1
//    int len1 = r1 - l1 + 1;
//    int len2 = r2 - l2 + 1;
//    if (s[l1] != s[l2]) {
//        return (s[l1] < s[l2] ? -1 : 1);
//    }
//    int l = 1, r = min(len1, len2) + 1;
//    while (l != r - 1) {
//        int m = (l + r) / 2;
//        if (subHash(l1, l1 + m - 1, h) == subHash(l2, l2 + m - 1, h)) {
//            l = m;
//        } else {
//            r = m;
//        }
//        if (len1 == len2 && l == len1) {
//            return 0;
//        }
//        if (l == len1) {
//            return -1;
//        }
//        if (l == len2) {
//            return 1;
//        }
//    }
//    return (s[l1 + l] < s[l2 + l] ? -1 : 1);
//}
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    powers[0] = 1;
//    for (int i = 1; i < SIZE; ++i) {
//        powers[i] = (powers[i - 1] * p) % Mod;
//    }
//    string s, t;
//    cin >> s >> t;
//    int n = s.size();
//    int m = t.size();
//    vector<ll> hs = get_hash(s), ht1 = get_hash(t);
//    ll ht = ht1.back();
//    int ans = 0;
//    for (int i = 0; i + m < n; ++i) {
//        ll tmp = subHash(i, i + m, hs);
//        if (tmp == ht)
//            ans++;
//    }
//    cout << ans << '\n';
//    return 0;
//}