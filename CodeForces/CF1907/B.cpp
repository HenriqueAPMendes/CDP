#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    string s;
    stack<int> low, high;
    
    while(t--){
        while(!low.empty()) low.pop();
        while(!high.empty()) high.pop();
        
        cin >> s;
        for (int i = 0; i < (int)s.length(); i++){
            if (s[i] != 'b' && s[i] >= 'a' && s[i] <= 'z') low.push(i);
            else if (s[i] != 'B' && s[i] >= 'A' && s[i] <= 'Z') high.push(i);
            else if (s[i] == 'b' && !low.empty()){
                s[low.top()] = '*';
                low.pop();
            }
            else if (s[i] == 'B' && !high.empty()){
                s[high.top()] = '*';
                high.pop();
            }
        }

        for (int i = 0; i < (int)s.length(); i++)
            if (s[i] != '*' && s[i] != 'b' && s[i] != 'B') cout << s[i];
        cout << '\n';
    }

    return 0;
}