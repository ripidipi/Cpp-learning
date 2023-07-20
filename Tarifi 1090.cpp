//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <fstream>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//ll Mod = 1e9 + 7;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, k1;
//    cin >> n >> k1;
//    int k = min(k1, n);
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    sort(a.begin(), a.end());
//    vector<vector<int>> dp(n, vector<int>(k));
//    vector<vector<int>> p(n, vector<int>(k, -1));
//    for (int i = 0; i < n; ++i) {
//        dp[i][0] = (n - i) * a[i];
//        for (int j = 1; j < k; ++j) {
//            for (int q = 0; q < i; ++q) {
//                if (dp[q][j - 1] + (a[i]-a[q]) * (n - i) > dp[i][j]) {
//                    dp[i][j] = dp[q][j - 1] + (a[i]-a[q]) * (n - i);
//                    p[i][j] = q;
//                }
//            }
//        }
//    }
//    int curi = 0, curj = k - 1;
//    for (int i = 0; i < n; ++i) {
//        if (dp[i][k - 1] > dp[curi][k - 1]) {
//            curi = i;
//        }
//    }
//    vector<int> ans;
//    while (curj >= 0) {
//        ans.push_back(a[curi]);
//        curi = p[curi][curj];
//        curj--;
//    }
//    reverse(ans.begin(), ans.end());
//    for (int i = 0; i < k1 - k; ++i) {
//        ans.push_back(a.back() + i + 1);
//    }
//    for (int i : ans) {
//        cout << i << ' ';
//    }
//    return 0;
//}
