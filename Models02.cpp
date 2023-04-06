/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int finish = pow(k, n);
    for (int mask = 0; mask < finish; mask++){
        int cur = mask;
        for (int i = 0; i < n; i++){
            cout << cur % k << ' ';
            cur /= k;
        }
        cout << endl;
    }
}
 */