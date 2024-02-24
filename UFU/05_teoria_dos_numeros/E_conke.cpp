#include <bits/stdc++.h>
using namespace std;

void solve(long long A, long long B, long long mod){
    cout<<A<<" + "<<B<<" mod "<<mod<<" = "<<(A+B)%mod<<endl;
    cout<<A<<" - "<<B<<" mod "<<mod<<" = "<<(A-B)%mod<<endl;
    cout<<A<<" * "<<B<<" mod "<<mod<<" = "<<(A*B)%mod<<endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    while(true){
        long long A, B, mod; cin>>A>>B>>mod;
        if(!A && !B && !mod){break;}
        solve(A, B, mod);
    }

    return 0;
}