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
//    int n, W;
//    cin >> W >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    vector<bool> dp(W + 1);
//    vector<int> p (W + 1, -1);
//    dp[0] = true;
//    for (int i = 1; i <= W; ++i) {
//        for (int j : a) {
//            if (i >= j && dp[i - j]) {
//                dp[i] = true;
//                p[i] = j;
//                break;
//            }
//        }
//    }
//    int maxx = 0;
//    for (int i = W; i > -1; --i) {
//        if (dp[i]) {
//            maxx = i;
//            break;
//        }
//    }
//    vector<int> ans;
//    cout << maxx - 1  << '\n';
//}


//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, W;
//    cin >> n >> W;
//    vector<int> a(n);
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//    }
//    vector<vector<bool>> dp(n + 1, vector<bool>(W + 1));
//    dp[0][0] = true;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= W; ++j) {
//            if (dp[i - 1][j]) {
//                dp[i][j] = true;
//            }
//            if (j >= a[i] && dp[i - 1][j - a[i]]) {
//                dp[i][j] = true;
//            }
//        }
//    }
//    for (int i = W; i > -1; --i) {
//        if (dp[n][i]) {
//            cout << i << '\n';
//            break;
//        }
//    }
//    return 0;
//}



//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, W;
//    cin >> n >> W;
//    vector<int> a(n + 1);
//    vector<int> c(n + 1);
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//    }
//    for (int i = 1; i <= n; ++i) {
//        cin >> c[i];
//    }
//    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -INF));
//    dp[0][0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= W; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= a[i] && dp[i - 1][j - a[i]] != -INF) {
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + c[i]);
//            }
//        }
//    }
//    for (int i = W; i > -1; --i) {
//        if (dp[n][i]) {
//            cout << i << '\n';
//            break;
//        }
//    }
//    return 0;
//}


//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, W;
//    cin >> n >> W;
//    vector<int> a(n + 1);
//    vector<int> c(n + 1);
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i];
//    }
//    for (int i = 1; i <= n; ++i) {
//        cin >> c[i];
//    }
//    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -INF));
//    dp[0][0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= W; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= a[i] && dp[i - 1][j - a[i]] != -INF) {
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + c[i]);
//            }
//        }
//    }
//    for (int i = W; i > -1; --i) {
//        if (dp[n][i]) {
//            cout << i << '\n';
//            break;
//        }
//    }
//    return 0;
//}