//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    vector<int> logs(n + 1);
//    logs[1] = 0;
//    for (int i = 2; i <= n; ++i) {
//        logs[i] = logs[i / 2] + 1;
//    }
//    vector<vector<int>> sparse(logs[n] + 1, vector<int> (n));
//    for (int i = 0; i < n; ++i) {
//        sparse[0][i] = a[i];
//    }
//    for (int level = 1; (1 << level) <= n; ++level) {
//        for (int i = 0; i + (1 << level) <= n; ++i) {
//            sparse[level][i] = min(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
//        }
//    }
//    int l, r;
//    cin >> l >> r;
//    l--, r-- ;
//    int level = logs[r - l + 1];
//    cout << min(sparse[level][l], sparse[level][r - (1 << level) + 1]) << '\n';
//    for (auto i : sparse[level]) {
//        cout << i << ' ';
//    }
//    return 0;
//}
//
//
//



// востановление ответа работает не очень
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <numeric>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//
//vector<int> a;
//
//inline int minn(int i, int j) {
//    return (a[i] < a[j] ? i : j);
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    a.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    vector<int> logs(n + 1);
//    logs[1] = 0;
//    for (int i = 2; i <= n; ++i) {
//        logs[i] = logs[i / 2] + 1;
//    }
//    vector<vector<int>> sparse(logs[n] + 1, vector<int> (n));
//    for (int i = 0; i < n; ++i) {
//        sparse[0][i] = i;
//    }
//    for (int level = 1; (1 << level) <= n; ++level) {
//        for (int i = 0; i + (1 << level) <= n; ++i) {
//            sparse[level][i] = minn(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
//        }
//    }
//    int l, r;
//    cin >> l >> r;
//    l--, r-- ;
//    int level = logs[r - l + 1];
//    cout << minn(sparse[level][l], sparse[level][r - (1 << level) + 1]) << '\n';
//    for (auto i : sparse[level]) {
//        cout << i << ' ';
//    }
//    return 0;
//}