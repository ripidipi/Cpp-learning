//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//const int LOG = 17;
//typedef long double ld;
//typedef long long ll;
//
//
//int n1, n2, m;
//vector<int> used;
//vector<vector<int>> gr;
//vector<int> pr;
//
//bool kuhn(int v, int timer) {
//    used[v] = timer;
//    for(int u: gr[v]) {
//        if (pr[u] == -1 || used[pr[u]] != timer && kuhn(pr[u], timer)) {
//            pr[u] = v;
//            return true;
//        }
//    }
////    for(int u : gr[v]) {
////        if(!used[pr[u]] && kuhn(pr[u])) {
////            pr[u] = v;
////            return true;
////        }
////    }
//    return false;
//}
//
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    cin >> n1 >> n2 >> m;
//    gr.resize(n1);
//    used.resize(n1);
//    pr.resize(n2, -1);
//    for(int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        gr[u - 1].push_back(v - 1);
//    }
//    used.assign(n1, -1);
//    for(int i = 0; i < n1; ++i) {
//        kuhn(i, i);
//    }
//}







//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//const int LOG = 17;
//typedef long double ld;
//typedef long long ll;
//
//
//int n1, n2, m;
//vector<int> used;
//vector<vector<int>> gr;
//vector<int> pr;
//
//bool kuhn(int v, int timer) {
//    used[v] = timer;
//    for(int u: gr[v]) {
//        if (pr[u] == -1 || used[pr[u]] != timer && kuhn(pr[u], timer)) {
//            pr[u] = v;
//            return true;
//        }
//    }
////    for(int u : gr[v]) {
////        if(!used[pr[u]] && kuhn(pr[u])) {
////            pr[u] = v;
////            return true;
////        }
////    }
//    return false;
//}
//
//vector<vector<int>> gr1;
//vector<bool> used1;
//
//
//void dfs(int v) {
//    used[v] = true;
//    for(int u: gr1[v]) {
//        if(!used1[u]) {
//            dfs(u);
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    cin >> n1 >> n2 >> m;
//    gr.resize(n1);
//    used.resize(n1);
//    pr.resize(n2, -1);
//    for(int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        gr[u - 1].push_back(v - 1);
//    }
//    used.assign(n1, -1);
//    for(int i = 0; i < n1; ++i) {
//        kuhn(i, i);
//    }
//    gr1.resize(n1 + n2);
//    used1.resize(n1 + n2);
//    vector<bool> sat(n1);
//    for(int i = 0; i < n1; ++i) {
//        for(int u : gr[i]) {
//            if(pr[u] == i) {
//                gr1[u + n1].push_back(i);
//            } else {
//                gr1[i].push_back(u + n2);
//            }
//        }
//    }
//    for(int i = 0; i < n1; ++i) {
//        if (!sat[i]) {
//            dfs(i);
//        }
//    }
//    vector<int> lp, lm, rp, rm;
//    for (int i = 0; i < n1; ++i) {
//        if (used1[i]) {
//            lp.push_back(i);
//        } else {
//            lm.push_back(i);
//        }
//    }
//    for (int i = n1; i < n1 + n2; ++i) {
//        if (used1[i]) {
//            rp.push_back(i);
//        } else {
//            rm.push_back(i - n1);
//        }
//    }
//}













//#include <iostream>
//#include <vector>
//#include <chrono>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <map>
//#include <set>
//#include <cmath>
//#include <random>
//#include <unordered_map>
//#define all(a) a.begin(), a.end()
//
//using namespace std;
//
//const double eps = 1e-7;
//const int INF = 1e9;
//const int MAXSIZE = 1e5 + 5;
//const int LOG = 17;
//typedef long double ld;
//typedef long long ll;
//
//
//int n, m;
//vector<int> used;
//vector<vector<int>> gr;
//vector<int> pr;
//
//bool kuhn(int v, int timer) {
//    used[v] = timer;
//    for(int u: gr[v]) {
//        if (pr[u] == -1 || used[pr[u]] != timer && kuhn(pr[u], timer)) {
//            pr[u] = v;
//            return true;
//        }
//    }
////    for(int u : gr[v]) {
////        if(!used[pr[u]] && kuhn(pr[u])) {
////            pr[u] = v;
////            return true;
////        }
////    }
//    return false;
//}
//
//
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    cin >> n >> m;
//    gr.resize(n);
//    used.resize(n);
//    pr.resize(n, -1);
//    for(int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v   ;
//        gr[u - 1].push_back(v - 1);
//    }
//    used.assign(n, -1);
//    for(int i = 0; i < n; ++i) {
//        kuhn(i, i);
//    }
//    vector<int> prl(n, -1);
//    for(int i = 0; i < n; ++i) {
//        if (pr[i] != -1) {
//            prl[pr[i]] = i;
//        }
//    }
//    vector<vector<int>> paths;
//    for (int i = 0; i < n; ++i) {
//        if(pr[i] == -1) {
//            int cur = i;
//            paths.push_back(vector<int>());
//            while (cur != -1) {
//                paths.back().push_back(cur);
//                cur = prl[cur];
//            }
//        }
//    }
//    cout << paths.size() << '\n';
//    for (auto& p: paths) {
//        for(int& i : p) {
//            cout << i + 1 << ' ';
//        }
//        cout << '\n';
//    }
//}
