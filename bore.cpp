//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//const int SIZE = 1e7 + 7;
//
//struct Node {
//    vector<int> kids;
//    int cnt;
//    Node() {
//        cnt = 0;
//        kids.assign(26, -1);
//    }
//};
//
//Node nodes[SIZE];
//int sz = 0;
//
//inline int get_new() {
//    nodes[sz] = Node();
//    return sz++;
//}
//
//void add(int v, string& s, int pos = 0) {
//
//}
//int main() {
//    int root = get_new();
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        // + - ?
//        char type;
//        string s;
//        cin >> type >> s;
//        if (type == '+') {
//            add(root, s);
//        } else if (type == '-') {
//
//        } else if (type == '?') {
//
//        }
//
//    }
//    return 0;
//}