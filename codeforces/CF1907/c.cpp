#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t, n;
    string s;
    stack<char> seq;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        cout << s << ' ';
        

        for (int i = 0; i < n; i++){
            if (seq.empty()) seq.push(s[i]);
            else{
                if (s[i] != seq.top()) seq.pop();
                else seq.push(s[i]);
            }
            
        }
        cout << seq.size() << '\n';
        while(!seq.empty()) {
            cout << seq.top();
            seq.pop();
        }
        cout << '\n';
    }

    return 0;
}