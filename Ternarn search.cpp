//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//typedef long double ld;
//
//const double eps = 1e-12;
//
//
//struct Point {
//    int x, y;
//    Point() {}
//    Point(int x, int y) :x(x), y(y) {};
//};
//
//Point a, b, c;
//
//double len(const Point& a, ld x, ld y) {
//    return hypot(a.x - x, a.y- y);
//}
//
//istream& operator >> (istream& in, Point& p) {
//    in >> p.x >> p.y;
//    return in;
//}
//
//ld dist(ld x, ld y) {
//    return len(a, x, y) + len(b, x, y) + len(c, x, y);
//}
//
//pair<ld, ld> fy(ld x){
//    ld l = -1000, r = 1000;
//    for (int it = 0; it < 100; ++it) {
//        ld m1 = l + (r - l) / 3;
//        ld m2 = m1 + (r - l) / 3;
//        if (dist(x, m1) < dist(x, m2) ){
//            r = m2;
//        }
//        else {
//            l = m1;
//        }
//    }
//    return {dist(x, l), l};
//}


//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//
//    cin >> a >> b >> c;
//    ld l = -1000, r = 1000;
//    for (int it = 0; it < 100; ++it) {
//        ld m1 = l + (r - l) / 3;
//        ld m2 = m1 + (r - l) / 3;
//        if (fy(m1).first < fy(m2).first ){
//            r = m2;
//        }
//        else {
//            l = m1;
//        }
//    }
//    auto res = fy(l);
//    cout << l << res.second << '\n';
//    return 0;
//}


//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int n, k;
//    cin >> n >> k;
//    vector<int> x(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> x[i];
//    }
//    ll ans = 0;
//    int f = 0;
//    for (int i = 0; i < n; ++i) {
//        while (f<n && x[f] - x[i]< k) {
//            f++;
//        }
//        ans += (ll)(n - f);
//    }
//    cout << ans << '\n';
//    return 0;
//}


//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    string s;
//    cin >> s;
//    int n = s.size();
//    int maxl = n, optl = -1, optr = -1;
//    int f = 0;
//    int alph = 4;
//    vector<int> cnt(alph);
//    int zeroes = alph;
//    for (int i = 0; i < n; ++i) {
//        while (f < n && zeroes > 0) {
//            cnt [s[f]-'a']++;
//            if (cnt[s[f]-'a'] == 1) {
//                zeroes--;
//            }
//            f++;
//        }
//        if (zeroes == 0) {
//            if (f - i < maxl) {
//                optl = i;
//                optr = f - 1;
//                maxl = f - i;
//            }
//        }
//        cnt[s[i] - 'a']--;
//        if(cnt[s[i] - 'a'] == 0){
//            zeroes++;
//        }
//    }
//    cout << optl + 1 << ' ' << optr + 1 << '\n';
//    return 0;
//}



