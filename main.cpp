#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(10));
    dp[0] = vector<int>(10, 1);
    dp[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] += dp[i - 1][j];
            if (j<9) {
                dp[i][j] += dp[i -1][j + 1];
            }
        }
    }
    cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0) << '\n';
    return 0;
}