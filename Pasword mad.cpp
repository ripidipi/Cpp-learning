/*
#include <iostream>
#include <random>
using namespace std;


class Pred {
    char leters[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                       'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                       'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5',
                       '6', '7', '8', '9', '0'};
    int len = 6;
    char passw[6];//{'X', 'R', '6', '2', 'M', 'E'};

    bool checequel(const char* x, const char* y){
        for(int i=0; i < 6; ++i) {
            if (x[i] == y[i]){}
            else {
                return false;
            }
        }
        for(int i=0; i < 6; ++i) {
            cout << x[i];
        }
        return true;
    }

//   void check(char* x, int l = 6){
//       char* temp = new char[l];
//       for (int i = 0; i < l; i++){
//           temp[i]= x[i];
//       }
//       x = temp;
//   }

    void generation(){
        for (int i = 0; i < len; ++i) {
            random_device rd;
            mt19937 mt(rd());
            uniform_int_distribution<> dist(0, 35);
            passw[i] = leters[dist(mt)];
        }
        cout << "PASWARD: " << passw <<'\n';
    }

    char* predictions(){
        for (char &i1: leters){
            for (char &i2: leters){
                for (char &i3: leters){
                    for (char &i4: leters){
                        for (char &i5: leters){
                            for (char &i6: leters){
                                char t[6];
                                t[0] = i1;
                                t[1] = i2;
                                t[2] = i3;
                                t[3] = i4;
                                t[4] = i5;
                                t[5] = i6;
                                //cout << t << endl;
                                if (checequel(t, passw)){
                                    return t;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

public:
    void start(int num){
        for(int i=0; i < num; ++i) {
            //generation();
            cout << "ANSWER : "<< predictions() << '\n';
        }
    }
};


int main() {;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Pred R;
    R.start(1);
}
*/