//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main () {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    vector<int> div;
//    int n, k;
//    cin >> n >> k;
//        for (int i = 1; i * i <= n; ++i) {
//            if (n % i == 0) {
//                if (i * i < n)
//                    div.push_back(n / i);
//                div.push_back(i);
//            }
//        }
//    sort(div.begin(), div.end());
//    for (int i : div)
//        cout << i << ' ';
//    return 0;
//}
