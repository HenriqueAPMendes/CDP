#include <bits/stdc++.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    wstring s, maxS;
    while(wcin >> s)
        if (s.length() > maxS.length()) maxS = s;
    
    wcout << maxS << endl;

    return 0;
}