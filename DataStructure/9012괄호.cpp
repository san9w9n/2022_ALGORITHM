#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, len;
    string str;
    stack<char> S;
    string answer[2] = {"NO", "YES"};
    
    cin >> N;
    while (N--) {
        int idx = 1;
        cin >> str;
        len = str.length();
        for (int i=0; i<len; i++) {
            if (str[i] == '(') S.push('(');
            else {
                if (S.empty()) {
                    idx = 0;
                    break;
                }
                if (S.top() == '(') 
                    S.pop();
                else S.push(')');
            }
        }
        if (!S.empty()) idx = 0;
        cout << answer[idx] << "\n";
        S = {};
    }
    return 0;
}