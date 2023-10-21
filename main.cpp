//#define _USE_MATH_DEFINES
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
#include <stack>
#include <fstream>
#include <queue>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
#define all(a) a.begin(), a.end()
#define null nullptr
#define Fin ios_base::sync_with_stdio(false); cin.tie(null); cout.precision(40);
using namespace std;

const double eps = 1e-7;
const int INF = 1e9 + 9;
const ull UINF = (ull)1e17 + 7;
const int SIZE = 1e5 + 6;
const int MOD = 1e9 + 7;
const int BASE = 256;


inline ostream& operator << (ostream& out, vector<uint>& a) {
    for (auto i: a) {
        out << i << ' ';
    }
    return out;
}

inline ostream& operator << (ostream& out, vector<int>& a) {
    for (auto i: a) {
        out << i << ' ';
    }
    return out;
}

inline ostream& operator << (ostream& out, vector<char>& a) {
    for (auto i: a) {
        if (i != '\000')
            out << i;
    }
    return out;
}

uint cur = 0;

uint nextRand24(uint a, uint b) {
    cur = cur * a + b;
    return cur >> 8;
}

uint nextRand32(uint A, uint B) {
    uint a = nextRand24(A, B), b = nextRand24(A, B);
    return ((a << 8) ^ b);
}

vector<uint> gen(uint n, uint a, uint b) {
    vector<uint> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = nextRand32(a, b);
    }
    return arr;
}

ull dist_calc(vector<uint>& arr, ull y) {
    ull c = 0;
    for (auto &i: arr)c += abs((ll)y - (ll)i);

    return c;
}

void solve() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    auto arr = gen(n, a, b);
    ull c = 0;
    for (auto &i: arr) c += i;
    c /= (int)(arr.size());
    cout << dist_calc(arr, c) << '\n';
}

int main() {
    Fin
    cout << nextRand32(239, 13);
    solve();
    return 0;
}

