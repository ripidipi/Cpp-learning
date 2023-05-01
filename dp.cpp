//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    ll c, k;
//    cin >> n >> c >> k;
//    ll Mod = pow((ll)10, k);
//    string s;
//    cin >> s;
//    vector<ll> dp(n);
//    for (int i = 0; i < n; ++i) {
//        if (i < 10) {
//            string cur = s.substr(0, i + 1);
//            if (stoll(cur) <= c && (i == 0 || cur[0] != '0')) {
//                dp[i]++;
//            }
//        }
//        for (int j = i; j >=max(1, i - 10); --j) {
//            string cur = s.substr(j, i - j + 1);
//            if (stoll(cur) <= c && (i == j || cur[0] != '0')) {
//                dp[i] += dp[j - 1];
//                dp[i] %= Mod;
//            }
//        }
//    }
//    cout << dp[n - 1] << '\n';
//    return 0;
//}
