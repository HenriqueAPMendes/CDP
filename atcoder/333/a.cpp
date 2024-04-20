#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    char c = '0'+n;
    string s;

    for (int i = 0; i < n; i++)
        s+=c;
    

    cout << s << endl;

    return 0;
}