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
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<vector<int>> dp(n, vector<int>(10));
//    dp[0] = vector<int>(10, 1);
//    dp[0][0] = 0;
//    for (int i = 1; i < n; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            if (j > 0) {
//                dp[i][j] += dp[i - 1][j - 1];
//            }
//            dp[i][j] += dp[i - 1][j];
//            if (j<9) {
//                dp[i][j] += dp[i -1][j + 1];
//            }
//        }
//    }
//    cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0) << '\n';
//    return 0;
//}


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
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> dp(n, vector<int>(k));
//    dp[0] = vector<int>(k, 1);
//    for (int i = 1; i < n; ++i) {
//        if (i % 2 == 0) {
//            dp[i][0] = 0;
//            for (int j = 1; j < k; ++j) {
//                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
//            }
//        } else {
//            dp[i][k - 1] = 0;
//            for (int j = k - 2; j > -1; --j) {
//                dp[i][j] = dp[i][j + 1] + dp[i - 1][j  + 1];
//            }
//        }
//    }
//    for (auto &i: dp) {
//        for (auto &j: i) {
//            cout << j << '\t';
//        }
//        cout << '\n';
//    }
//    cout << accumulate(dp[n-1].begin(), dp[n-1].end(), 0) << '\n';
//    return 0;
//}


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
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<vector<int>> dp(n, vector<int>(10));
//    dp[0] = vector<int>(10, 1);
//    dp[0][0] = 0;
//    for (int i = 1; i < n; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            if (j > 0) {
//                dp[i][j] += dp[i - 1][j - 1];
//            }
//            dp[i][j] += dp[i - 1][j];
//            if (j<9) {
//                dp[i][j] += dp[i -1][j + 1];
//            }
//        }
//    }
//    cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0) << '\n';
//    return 0;
//}

