#include <bits/stdc++.h>
using namespace std;

map<char,int> used;

void addChar(char c){
    if (used.count(c)) used[c]++;
    else used[c]=1;
}

bool valid(string s){
    int n = s.length();
    bool odd = n%2;

    used.clear();

    for (int i = 0; i < n; i++)
        addChar(s[i]);
    
    int maxOdd = odd ? 1 : 0;
    int currentOdd = 0;
    for (auto &c : used)
        if(c.second % 2) currentOdd++;
    
    return (currentOdd == maxOdd);
}

void generatePalindrome(string s){
    string ans = "";
    char mid = '#';

    for (auto &v : used) {
        if (v.second % 2) mid = v.first;
        for(int i = 0; i < v.second/2; i++) ans+=v.first;
        v.second /= 2;
    }
    if (mid != '#') ans += mid;

    for (map<char,int>::reverse_iterator it = used.rbegin(); it != used.rend(); it++){
        for (int i = 0; i < it->second; i++) ans+=it->first;
    }

    cout << ans << endl;

}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    if (!valid(s)) cout << "NO SOLUTION\n";
    else generatePalindrome(s);
}