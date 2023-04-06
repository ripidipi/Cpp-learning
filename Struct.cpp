/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Man{
    int height, waight;
    string name;
    Man(){
        height = 170;
        waight = 75;
    }
    Man(const string& name){
        height = 190;
        waight = 42;
        this->name = name;
    }
};

struct Triple{
    int a, b, c;
    Triple(){}
    Triple(int a, int b, int c) :a(a), b(b), c(c) {}
    int mult() const {
        return a * b * c;
    }
    int summ(const Triple& x) const {
        return a + x.b + x.c;
    }
    void add(int x){
        a+=x;
    }
    Triple operator +(const Triple& other){
        return Triple(a + other.a, b + other.b, c + other.c);
    }
};

Triple operator -(const Triple& x, const Triple& y){
    return Triple(x.a - y.a, x.b - y.b, x.c - y.c);
}
bool operator <(const Triple& x, const Triple& y){
    return x.mult() < y.mult();
}

bool operator ==(const Triple& x, const Triple& y){
    return x.summ(y) == y.summ(x);
}

istream& operator >>(istream& in, Triple& x){
    in >> x.a >> x.b >> x.c;
    return in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Man Dan;
    Dan.height = 178;
    Dan.name = "Danicios";
    int x = Dan.height + 1;
    cin >> Dan.waight;
    vector<Man> group;
    Man* John;
    John->height = 190;
    John->name = "John";
}
*/