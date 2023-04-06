#include <iostream>
#include <vector>
using namespace std;
/*
int main(){
    int h1, m1, s1, h2, m2, s2, sec1, sec2, diff;
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    sec1 = (h1 * 3600) + (m1 * 60) + s1;
    sec2 = (h2 * 3600) + (m2 * 60) + s2;
    //diff = min(abs(sec2-sec1), 86400-sec1+sec2);
    //cout << diff << endl;
    vector<int>ans(10);
}
*/


/*
int main(){
    int h1, m1, s1, sec1;
    int h2, m2, s2, sec2;
    int h3, m3, s3, sec3;
    int transp_time;
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    scanf("%d:%d:%d", &h3, &m3, &s3);
    sec1 = (h1 * 3600) + (m1 * 60) + s1;
    sec2 = (h2 * 3600) + (m2 * 60) + s2;
    sec3 = (h3 * 3600) + (m3 * 60) + s3;
    transp_time = sec3-sec1;
    sec2 += int(transp_time/2);
    h2 = int (sec2/3600);
    m2 = int ((sec2%3600)/60);
    s2 = sec2%60;
    cout << h2 << ":" << m2 << ":" << s2;
}
*/
/*
int days[]{31, 28, 31, 30, 31,
           30, 31, 31, 30, 31, 30, 31};

int count_day(int m){
    int answer = 0;
    while (m>1){
        answer+=days[m-1];
        m--;
    }
    return answer;
}


int count_month(int d) {
    int i=0;
    while(d>days[i]){
        d-=days[i];
        i++;
    }
    return i+1;
}


int main(){
    int d, m, quant_day, quant_month;
    ::scanf("%d.%d", &d, &m);
    quant_day = count_day(m) + d;
    cout << quant_day << endl;
    quant_month = count_month(quant_day);
    cout << quant_day-count_day(quant_month) << "." << quant_month << endl;
}
 */
/*
int days[]{31, 28, 31, 30, 31,
           30, 31, 31, 30, 31, 30, 31};

int count_day(int m){
    int answer = 0;
    while (m>1){
        answer+=days[m-1];
        m--;
    }
    return answer;
}


int main(){
    int d, m, y, quant_day, quant_month, i=0, answer=0;
    ::scanf("%d.%d.%d", &d, &m, &y);
    while (i+1<y){
        if (i%400==0 || (i%4==0 && i%100!=0)){
            answer +=366;
        }
        else {
            answer +=365;
        }
        i++;
    }
    quant_day = count_day(m) + d;
    answer+=quant_day;
    cout << answer << endl;
}
*/

/*
int main(){
    int i;
    cin >> i;
    if (i%400==0 || (i%4==0 && i%100!=0)){
        cout << i+28 << endl;
    }
    else if((i+3)%400==0 || ((i+3)%4==0 && (i+3)%100!=0)){
        cout << i+6 << endl;
    }
    else {
        cout << i+11 << endl;
    }
}
*/