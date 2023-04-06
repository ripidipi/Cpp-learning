/*
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
using namespace std;

istream& operator >> (istream& in, vector<int>& a){
    for(int& i: a){
        in >> i;
    }
    return in;
}

ostream& operator << (ostream& out, const vector<int>& a){
    for (int i: a){
        out << i << " ";
    }
    return out;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(30);
//    int z;
//    ::scanf("%d", &z);
//    ::printf("%d", z);
//    char arr[100];
//    ::scanf("%s", arr);
//    ::printf("%s\n", arr);
//    double g;
//    ::scanf("%3lf", &g);
//    ::printf("%lf", g);
//    int x;
//    while(cin >> x){
//        cout << x << '\n';
//    }
//    vector<int> a(3);
//    cin >> a;
//    cout << a;
//    return 0;
//    ::freopen("input.txt", "r", stdin);
//    ::freopen("output.txt", "w", stdout);
//    int x;
//    cin >> x;
//    cout << x+1 << '\n';
    ifstream in("input");
    int x;
    in >> x;
    ofstream out("output");
    out << x << '\n';
    in.close();
    out.close();
}
*/