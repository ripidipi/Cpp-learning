#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const double eps = 0.0000000001;

//ll n, a, b, w, h;
//ll f(ll m){
//    return max(( w / (a + 2 * m)) * ( h / (b + 2 * m)),
//               ( w / (b + 2 * m)) * ( h / (a + 2 * m)));
//}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    double a;
//    cin >> a;
//    cout.precision(20);
//    double r = a, l = 0;
//    while (r-l > eps) {
//        double m = (l+r) / 2;
//        if (pow(m, 2) + pow(m, 0.5) < a)
//            l = m;
//        else
//            r = m;
//    }
//    cout << fixed << l << '\n';
//

//    int n = 12;
//    vector<int> a = {1, 3, 4, 5, 5, 5, 6, 8, 8, 10, 23, 43};
//    int y;
//    cin >> y;
//    //int r = n -1, l = -1;
//    int r = n, l = 0;
//    while (l != r-1) {
//        int m = (l + r) / 2;
//        if (a[m] <= y)
//            l = m;
//        else
//            r = m;
//    }
//    cout << l << '\n';
//    //cout << r << '\n';



//    cin >> n >> a >> b >> w >> h;
//    ll l = 0, r = min(w, h) / 2 + 1;
//    while (l != r-1) {
//        ll m = (l + r) / 2;
//        if (f(m) >= n)
//            l = m;
//        else
//            r = m;
//    }
//    cout << l << '\n';
//    return 0;
//}


//ll f(ll n, ll h, ll w) {
//    return (n/h)*(n/w);
//}

//int main () {
//    ll w, h, n;
//    cin >> w >> h >> n;
//    ll l = 0, r = (int)(::sqrt(n)+1) * max(w, h)+1;
//    while (l != r - 1) {
//        ll m = (l / 2) + (r / 2);
//        if (f(m, h, w) < n)
//            l = m;
//        else
//            r = m;
//    }
//    cout << r << '\n';
//    return 0;
//}