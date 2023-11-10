#include <bits/stdc++.h>
using namespace std;
#define MAX 1123456

char buff[MAX];
set<string> dic;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int c;
    int i = 0;
    while(1){
        c = getchar();
        if (c >= 'a' && c <= 'z') buff[i++] = c;
        else if (c >= 'A' && c <= 'Z') buff[i++] = c - 'A' + 'a';
        else{
            buff[i] = 0; // end of word
            if (i > 0){
                string s(buff);
                dic.insert(s);
            }
            i = 0;
            if (c == EOF) break;
        }
    }

    for (auto st : dic) cout << st << endl;
    

    return 0;
}