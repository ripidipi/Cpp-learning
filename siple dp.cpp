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
//typedef long long ll;
//
//const int maxx = 1e9;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int n;
//    cin >> n;
//    vector<int> dp(n + 1, maxx);
//    vector<int> p(n+1, -1);
//    dp[1] = 0;
//    for (int i = 2; i <= n; ++i) {
//        dp[i] = dp[i-1] + 1;
//        p[i] = 1;
//        if (i % 2 == 0) {
//            if (dp[i / 2] + 1 < dp[i]) {
//                dp[i] = min(dp[i], dp[i / 2] + 1);
//                p[i] = 2;
//            }
//        }
//        if (i % 3 == 0) {
//            if (dp[i / 3] + 1 < dp[i]) {
//                dp[i] = min(dp[i], dp[i / 3] + 1);
//                p[i] = 3;
//            }
//        }
//    }
//    vector<int> ans;
//    int cur = n;
//    while (cur != 1) {
//        ans.push_back(cur);
//        if (p[cur] == 1) {
//            cur--;
//        }
//        else if (p[cur] == 2) {
//            cur /= 2;
//        }
//        else {
//            cur /= 3;
//        }
//    }
//    reverse(ans.begin(), ans.end());
//    for (int &i: ans) {
//        cout << i << ' ';
//    }
//    cout << '\n';
//    return 0;
//}
//
// числа длинны n не содержащие k подряд 1-иц
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> dp(n, vector<int>(k));
//    dp[0][0] = dp[0][1] = 1;
//    for (int i = 1; i < n; ++i) {
//        dp[i][0] = accumulate(dp[i-1].begin(), dp[i-1].end(), 0);
//        for (int j = 1; j < k; ++j) {
//            dp[i][j] = dp[i - 1][j - 1];
//        }
//    }
//    cout << dp[n - 1][0] + dp[n - 1][1] << '\n';
//    return 0;
//}

// гвоздики
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.precision(30);
//    int n;
//    cin >> n;
//    vector<int> x(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> x[i];
//    }
//    sort(x.begin(), x.end());
//    vector<int> dp(n);
//    dp[0] = 0;
//    dp[1] = x[1] - x[0];
//    dp[2] = x[2] - x[0];
//    for (int i = 3; i < n; ++i) {
//        dp[i] = min(dp[i - 1], dp[i - 2]) + x[i] - x[i - 1];
//    }
//    cout << dp[n - 1] << '\n';
//    return 0;
//}
