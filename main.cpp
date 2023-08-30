#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <cmath>
#include <random>
#include <unordered_map>
#define all(a) a.begin(), a.end()

using namespace std;

const double eps = 1e-7;
const int INF = 1e9;
const int MAXSIZE = 1e5 + 5;
typedef long double ld;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 2; i > -1; --i) {
        if(a[i] < a[i + 1]) {
            for (int j = n - 1; j > -1; --j) {
                  if(a[j] > a[i]) {
                      swap(a[i], a[j]);
                      break;
                  }
            }
            reverse(a.begin() + i + 1, a.end());
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}





