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
const int LOG = 17;
typedef long double ld;
typedef long long ll;


int n, m;
vector<int> used;
vector<vector<int>> gr;
vector<int> pr;

bool kuhn(int v, int timer) {
    used[v] = timer;
    for(int u: gr[v]) {
        if (pr[u] == -1 || used[pr[u]] != timer && kuhn(pr[u], timer)) {
            pr[u] = v;
            return true;
        }
    }
//    for(int u : gr[v]) {
//        if(!used[pr[u]] && kuhn(pr[u])) {
//            pr[u] = v;
//            return true;
//        }
//    }
    return false;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    gr.resize(n);
    used.resize(n);
    pr.resize(n, -1);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v   ;
        gr[u - 1].push_back(v - 1);
    }
    used.assign(n, -1);
    for(int i = 0; i < n; ++i) {
        kuhn(i, i);
    }
    vector<int> prl(n, -1);
    for(int i = 0; i < n; ++i) {
        if (pr[i] != -1) {
            prl[pr[i]] = i;
        }
    }
    vector<vector<int>> paths;
    for (int i = 0; i < n; ++i) {
        if(pr[i] == -1) {
            int cur = i;
            paths.push_back(vector<int>());
            while (cur != -1) {
                paths.back().push_back(cur);
                cur = prl[cur];
            }
        }
    }
    cout << paths.size() << '\n';
    for (auto& p: paths) {
        for(int& i : p) {
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
}
