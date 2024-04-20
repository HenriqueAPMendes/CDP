#include <bits/stdc++.h>
using namespace std;

const int MAX = 212345;
#define ll long long

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int x; 
    cin >> x;

    if (x == 0 || x%100) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}
