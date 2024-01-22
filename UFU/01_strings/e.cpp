#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;
    char last = s[0];
    int streak = 1;
    for (int i = 1; i < (int)s.length(); i++){
        if (s[i] == last) streak++;
        else{
            if (streak > 2) {
                cout << last << streak;
            }
            else{
                while(streak--) cout << last;
            }
            streak = 1;
        }

        last = s[i];
    }
    if (streak > 2) {
        cout << last << streak;
    }
    else{
        while(streak--) cout << last;
    }
    cout << endl;

    return 0;
}