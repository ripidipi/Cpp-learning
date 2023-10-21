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
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int SIZE = 1e5 + 5;
//const int LOG = 17;
//const int MOD = 1e9 + 7;
//
//inline ostream& operator << (ostream& out, vector<int>& a) {
//    for (int i: a) {
//        out << i << ' ';
//    }
//    return out;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin >> n;
//    vector<ll> e(n), c(n), p(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> e[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        cin >> c[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        cin >> p[i];
//    }
//    vector<ll> prefe(n), prefp(n);
//    partial_sum(all(e), prefe.begin());
//    partial_sum(all(p), prefp.begin());
//    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
//    for (int i = 1; i <= n; ++i) {
//        dp[i][0] = 0;
//        for (int j = 1; j <= n; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if(prefp[i - 1] + j < prefe[i - 1]) {
//                dp[i][j] = max(dp[i][j],  dp[i - 1][j - 1] + c[i - 1]);
//            }
//        }
//    }
//    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
//    return 0;
//}