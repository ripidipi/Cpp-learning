#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;

const int INF = 1e9;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> gr(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }
    int start = 0;
    vector<int> d(n, INF);
    deque<int> q;
    d[start] = 0;
    q.push_back(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto &e: gr[v]) {
            int u = e.first, w = e.second;
            if (d[u] > d[v] + w) {
                if (w == 0) {
                    q.push_front(u);
                } else {
                    q.push_back(u);
                }
            }
        }
    }
    return 0;
}