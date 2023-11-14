#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isVowel(char c){
    return  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';

}

void eh_facil(string s){
    int n = s.length();

    int currentC = 0;
    for (int i = 0; i < n; i++){
        currentC = 0;
        for(int j = i; j < n; j++){
            if (!isVowel(s[j])) currentC++;
            else currentC = 0;
            
            if (currentC >= 3) { cout << s << " nao eh facil\n"; return; }
        }
    }

    cout << s << " eh facil\n";
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        eh_facil(s);
    }

    return 0;
}