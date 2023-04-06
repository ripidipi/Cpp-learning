//#include <bits/stdc++.h>
//#define int long long
//// include header files and define macro 'int' as long long
//#define fastio
//// define empty macro 'fastio'
//
//using namespace std;
//
//int mod(int a, int b){
//    return (a%b + b)%b;
//}
//// define function mod to get a positive integer result of a%b
//
//
//int lb(vector<int> &a, int x){
//    int L = -1;
//    int R = a.size();
//    while (R - L > 1) {
//        int M = (R + L) / 2; //set middle index M
//        (a[M] < x ? L : R) = M; //decide which half of the vector to search next
//    }
//    return R;
//}
//// define lower bound binary search to get the number of elements in vector 'a' that is smaller than 'x'
//
//
//int median(vector<int>& a, vector<int>& b, int n){
//    int l = min(a[0], b[0]), r = max(a[n-1], b[n-1]) + 1;
//    while (r - l  > 1){ // binary search range [l, r)
//        int x = (l + r) / 2; //set middle index x
//        if (lb(a, x) + lb(b, x) < n) l = x; //increase search range to [x, r)
//        else r = x; //decrease search range to [l, x)
//    }
//    return r;
//}
//// define median value function using binary search
//
//
//vector<int> gen(int x1, int d1, int a, int c, int m, int l){
//    vector<int> x(l); vector<int> d(l);
//    x[0] = x1; d[0] = d1;
//    // set initial values
//    for (int i = 1; i < l; i++) d[i] = mod((a * d[i-1] + c), m); // get differences using the given formula
//    for (int i = 1; i < l; i++) x[i] = x[i - 1] + d[i - 1]; // get the vector by getting the prefix sum of differences
//    return x; // return the generated vector
//}
//
//signed main(){
//    fastio; //enable fast i/o
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    // equivalent to setbuf(stdout, NULL) in c
//    int n, l; cin >> n >> l; //read n and l
//    vector<vector<int>> use(n); //create a vector of vectors
//    for (int i = 0; i < n; i++) {
//        int x1, d1, a, c, m; cin >> x1 >> d1 >> a >> c >> m; // read x1, d1, a, c and m
//        use[i] = gen(x1, d1, a, c, m, l); //generate a vector using above read values and store it at index i
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            cout << median(use[i], use[j], l) - 1 << "\n"; // get median of the pairwise element sum and print it to standard output
//        }
//    }
//    return 0;
//}
//// return when everything has been executed successfully.
