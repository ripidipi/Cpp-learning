/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<int> fact;
    cin >> n;
    int n_ = n;
    for (int i = 2; i * i <= n_; ++i) {
        while (n%i==0) {
            fact.push_back(i);
            n/=i;
        }
    }
    if (n > 1) {
        fact.push_back(n);
    }
    for (int i: fact)
        cout << i << ' ';
    return 0;
}
 */