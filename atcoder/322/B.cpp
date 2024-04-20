#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M; 
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    bool prefix = T.substr(0, N) == S;
    bool sufix = T.substr(M-N, N) == S;

    if (prefix && sufix) cout << "0\n";
    else if (prefix) cout << "1\n";
    else if (sufix) cout << "2\n";
    else cout << "3\n";


    return 0;
}