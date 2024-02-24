#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long P) {
    long long result = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
            result %= P;
        }
        base *= base;
        base %= P;
        exp /= 2;
    }

    return result;
}

void solve(){
    int a, b, c; cin>>a>>b>>c;
    cout<<power(a, b, c)<<endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}