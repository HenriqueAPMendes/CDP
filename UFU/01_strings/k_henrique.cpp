#include <bits/stdc++.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    wstring s;
    int n_words = 0, n_char = 0;
    while(wcin >> s){
        n_words++;
        n_char += s.length();
    }
    wcout << n_words << endl;
    wcout << n_char << endl;

    return 0;
}