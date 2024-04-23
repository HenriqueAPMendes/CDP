#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int nlines = 1 << n;
/*
    0000 0000 0000 0000 - 0
    0000 0000 0000 0001 - 1
    0000 0000 0000 0011 - 2
    0000 0000 0000 0010 - 3
    0000 0000 0000 0110 - 4
    0000 0000 0000 0111 - 5
    0000 0000 0000 0101 - 6
    0000 0000 0000 0100 - 7
    0000 0000 0000 1100
    0000 0000 0000 1101
    0000 0000 0000 1111
    0000 0000 0000 1110
    0000 0000 0000 1010
    0000 0000 0000 1011
    0000 0000 0000 1001
    0000 0000 0000 1000

*/

    string s = "";
    for (int i = 0; i < n; i++) s+='0';
    cout << s << endl;

    for (int i = 1; i < nlines; i++){
        // s[n-1] = (i%(1 << 2) >= (1 << 0) && i%(1 << 2) < ((1 << 2) - (1<<0))) ? '1' : '0';
        // s[n-2] = (i%(1 << 3) >= (1 << 1) && i%(1 << 3) < ((1 << 3) - (1<<1))) ? '1' : '0';
        for (int j = 1; j <= n; j++){
            int r = i%(1<<(j+1));
            
            int left = (1<<(j-1));
            int rightT = 1<<(j+1);
            int rightO = 1<<(j-1);
            int right = rightT - rightO - 1;
            
            // cout << left << ' ' << right << endl;

            if (r >= left && r <= right) s[n-j] = '1';
            else s[n-j] = '0';
        }
            // s[n-i] = (i%(1<<(i+1)) >= (1<<(i-1)) && i%(1<<(i+1) < ((1<<(i+1))-(1<<(i-1))))) ? '1' : '0';
        
        cout << s << endl;
    }

    return 0;
}
