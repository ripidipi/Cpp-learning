/*
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
using namespace std;

struct StackMin{
    const int INF = 1e9;
    stack<pair<int, int>> s ;
    void push(int x){
        s.push({x, min(x, minn())});
    }
    void pop(){
        s.pop();
    }
    int top(){
        s.top().first;
    }
    size_t size(){
        return s.size();
    }
    bool empty(){
        return s.empty();
    }
    int minn() {
        if (s.empty())
            return INF;
        return s.top().second;
    }
};

struct QueueMin{
    StackMin in, out;
    void move () {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
    void push(int x) {
        in.push(x);
    }
    void pop() {
        if (out.empty()) {
            move();
        }
        out.pop();
    }
    size_t size() {
        return in.size() + out.size();
    }
    bool empty() {
        return in.empty() && out.empty();
    }
    int minn () {
        return min(in.minn(), out.minn());
    }
};

struct CMP{
    bool operator () (const int& a, const int& b) const {
        return a % 10 < b % 10;
    }
};

struct  HASH {
    size_t operator ()(const int&a) const{
        return a ^ (a<<15);
    }
};

template <class T>
ostream& operator << (ostream& out, const vector <T>& a){
    for (const T& i: a){
        out << i << ' ';
    }
    return out;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//       vector<int> a = {1, 2, 4, 4, 5, 7, 23, 645, 345, 2};
//       a.reserve(20);
//       for (auto it = a.begin(); it != a.end(); ++it){
//           int x =  *it;
//           cout << x << '\n';
//       }
//       cout << a << '\n';
    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();
    cout << s.top() << '\n';
    s.size(); s.empty();
    while(!s.empty()){
        s.pop();
    }
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    set<int> q;
    q.insert(3);
    q.insert(-40);
    q.insert(8);
    q.insert(6);
    auto i = q.begin();
    while(i != q.end()) {
        cout << *i << '\n';
        i++;
    }
    set<int, CMP> s1;
    set<int, greater<>> s2;
    map<string, int> m;
    m["afternoon"] = 5;
    m["beforetoon"] = 1;
    unordered_set<int, HASH> s;
    return 1;
}
 */