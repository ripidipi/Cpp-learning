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
//#include <fstream>
//typedef long double ld;
//typedef long long ll;
//#define all(a) a.begin(), a.end()
//#define null nullptr
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9 + 9;
//const int SIZE = 1e6 + 6;
//const int MOD = 1e9 + 7;
//const int BASE = 256;
//typedef long long ll;
//
//inline ostream& operator << (ostream& out, vector<int>& a) {
//    for (auto i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(null);
//    cout.tie(null);
//    int n;
//    cin >> n;
//    stack<ll> s;
//    vector<ll> arr(n), summ(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//    }
//    ll c = 0, j;
//    for (int i = 0; i < n; i++) {
//        while(!s.empty() && arr[s.top()] >= arr[i]) {
//            s.pop();
//        }
//        j = (s.empty() ? -1 : s.top());
//        summ[i] = ((j >= 0 ? summ[j] : 0) + (i - j) * arr[i]);
//        s.push(i);
//    }
//    for (ll i: summ) {
//        c+=i;
//    }
//    cout << c << '\n';
//
//
//
//    return 0;
//}
