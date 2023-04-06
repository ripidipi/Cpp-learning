//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//typedef long double ld;
//typedef long long ll;
//

// could you rewrite and improve code under: 
#include <iostream>
#include <vector>

using namespace std;

int modulo(int a, int b) {
    return (a % b + b) % b;
}

int lower_bound(vector<int>& a, int x) {
    int left = -1;
    int right = a.size();
    while (right - left > 1) {
        int mid = (right + left) / 2;
        (a[mid] < x ? left : right) = mid;
    }
    return right;
}

int median(vector<int>& a, vector<int>& b, int n) {
    int left_val = min(a[0], b[0]);
    int right_val = max(a[n-1], b[n-1]) + 1;
    while (right_val - left_val > 1) {
        int mid = (left_val + right_val) / 2;
        if (lower_bound(a, mid) + lower_bound(b, mid) < n) {
            left_val = mid;
        } else {
            right_val = mid;
        }
    }
    return right_val;
}

vector<int> generate_sequence(int x1, int d1, int a, int c, int m, int sequence_length) {
    vector<int> sequence(sequence_length); 
    vector<int> deltas(sequence_length);
    sequence[0] = x1; deltas[0] = d1;
    for (int i = 1; i < sequence_length; i++) {
        deltas[i] = modulo((a * deltas[i-1] + c), m);
    }
    for (int i = 1; i < sequence_length; i++) {
        sequence[i] = sequence[i - 1] + deltas[i - 1];
    }
    return sequence;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, sequence_length; 
    cin >> n >> sequence_length;
    vector<vector<int>> sequences(n);
    for (int i = 0; i < n; i++) {
        int x1, d1, a, c, m; 
        cin >> x1 >> d1 >> a >> c >> m;
        sequences[i] = generate_sequence(x1, d1, a, c, m, sequence_length);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << median(sequences[i], sequences[j], sequence_length) - 1 << "\n";
        }
    }
    return 0;
}
