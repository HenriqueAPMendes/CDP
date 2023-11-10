#include <bits/stdc++.h>
using namespace std;

map<char,int> used;
char buff[1123456];

void addChar(char c){
    if (used.count(c)) used[c]++;
    else used.insert(make_pair(c,1));
}

bool valid(string s){
    int n = s.length();
    bool odd = n%2;
    bool even = !odd;

    used.clear();

    for (int i = 0; i < n; i++)
        addChar(s[i]);
    
    int maxOdd = odd ? 1 : 0;
    int currentOdd = 0;
    for (map<char,int>::iterator it = used.begin(); it != used.end(); it++)
        if(it->second % 2) currentOdd++;
    
    return (currentOdd == maxOdd);
}

void generatePalindrome(string s){
    // two pointer
    int n = s.length();

    int p = 0;
    for (map<char,int>::iterator it = used.begin(); it != used.end(); it++){


    }
        
    
}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    if (!valid(s)) cout << "NO SOLUTION\n";
    else generatePalindrome(s);
}