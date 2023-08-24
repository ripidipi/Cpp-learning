//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//
//using namespace std;
//
//struct node {
//    array<int, 26> go;
//    bool terminl = false;
//    int suf = 0;
//    node(){
//        fill(go.begin(), go.end(), -1);
//    }
//
//};
//vector<node> vertex(1);
//
//int go_char(int v, int c) {
//    if (vertex[v].go[c] == -1) {
//        vertex[v].go[c] = vertex.size();
//        vertex.emplace_back();
//    }
//    return vertex[v].go[c];
//}
//
//void add_string (const string & s) {
//    int v = 0;
//    for (auto c: s){
//        v = go_char(v, c - 'a');
//    }
//    vertex[v].terminl= true;
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    queue<int> q;
//    vector<int> used(vertex.size());
//    q.push(0);
//    for (int & i: vertex[0].go) {
//        if(i == -1) {
//            i = 0;
//        }
//    }
//    while (!q.empty()) {
//        int v = q.front();
//        q.pop();
//        for (int i = 0; i < vertex[v].go.size(); ++i) {
//            int& to = vertex[v].go[i];
//            if(to == -1) {
//                to = vertex[vertex[v].suf].go[i];
//                if(v == 0)
//                    to = 0;
//            } else {
//                vertex[to].suf = vertex[vertex[v].suf].go[i];
//                q.push(to);
//            }
//        }
//    }
//
//    return 0;
//}
