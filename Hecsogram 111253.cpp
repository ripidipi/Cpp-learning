/*
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long hist[n]; // array to store the heights of the rectangles
    for (int i = 0; i < n; i++) {
        cin >> hist[i];
    }
    stack<int> st; // stack to store the indices of the rectangles
    long long max_area = 0;
    int i = 0;
    while (i < n) {
        if (st.empty() || hist[st.top()] <= hist[i]) {
            // if stack is empty or current rectangle is higher than the top of stack
            st.push(i);
            i++;
        } else {
            // if current rectangle is lower than the top of stack
            int tp = st.top(); // pop the top of stack and calculate area of rectangle
            st.pop();
            long long area = hist[tp] * (st.empty() ? i : i - st.top() - 1);
            if (area > max_area) {
                max_area = area;
            }
        }
    }


    while (!st.empty()) {
        // pop remaining rectangles from the stack and calculate area
        int tp = st.top();
        st.pop();
        long long area = hist[tp] * (st.empty() ? i : i - st.top() - 1);
        if (area > max_area) {
            max_area = area;
        }
    }

    cout << max_area << endl;
    return 0;
}
 */