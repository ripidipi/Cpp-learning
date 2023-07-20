//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//const ll MOD = pow((ll)10, 9) + 7;
//
//ll psp(int n, int k) {
//    vector<vector<ll>> dp(n + 1, vector<ll>(k+1));
//    dp[0][0] = 1;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= k; ++j) {
//            if (j > 0) {
//                dp[i][j] += dp[i-1][j-1];
//            }
//            if (j < k) {
//                dp[i][j] +=dp[i - 1][j + 1];
//            }
//            dp[i][j] %= MOD;
//        }
//    }
//    return dp[n][0];
//}
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, k;
//    cin >> n >> k;
//    ll ans = psp(2 * n, k) - psp(2 * n, k-1);
//    cout << (ans < 0 ? ans + MOD : ans) << '\n';
//    return 0;
//}
