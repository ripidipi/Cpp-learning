#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <cmath>


#define all(a) a.begin(), a.end()
using namespace std;


const double eps = 1e-7;
const int INF = 1e9;


typedef long double ld;
typedef long long ll;

vector<vector<pair<int, int>>> gr;
vector<int> parent;
vector<int> sizee;


int find_set(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}


void make_set(int v) {
    parent[v] = v;
    sizee[v] = 1;
}


void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizee[a] < sizee[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    parent.resize(n, -1);
    sizee.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < gr[i].size(); ++j) {
            if (find_set(gr[i][j]) == gr[i][j] && gr[i][j] > i) {
              unite_sets(gr[i][j], i);
              cout << i + 1 << ' ' << gr[i][j] + 1 << '\n';
            }
        }
    }
    return 0;
}
