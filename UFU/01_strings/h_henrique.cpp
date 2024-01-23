#include <bits/stdc++.h>
using namespace std;

bool isUpper(char c){
    return (c >= 'A' and c <= 'Z');
}

bool isLower(char c){
    return (c >= 'a' and c <= 'z');
}

bool isLetter(char c){
    return (isUpper(c) or isLower(c));
}

int main(){  
    setlocale(LC_ALL, "pt_BR.UTF-8");
    wstring s; getline(wcin, s);
    wcout << s << endl;
    int t; wcin >> t;
    t %= 26;

    for (int i = 0; i < (int)s.length(); i++){
        if (!isLetter(s[i])) continue;
        if (isUpper(s[i]) and s[i]+t > 'Z') s[i] = 'A' + (t - 'Z' + s[i] - 1);
        else if (isLower(s[i]) and s[i]+t > 'z') s[i] = 'a' + (t - 'z' + s[i] - 1);
        else s[i]+=t;
    }

    wcout << s << endl;

    return 0;
}