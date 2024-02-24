#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
long long lcm(long long a, long long b){
    return (a*b)/gcd(a, b);
}

void solve(){
    long long n; cin>>n;
    long long ant, cur; cin>>ant;
    for(long long i=1; i<n; i++){
        cin>>cur;
        ant = lcm(ant, cur);
    }
    cout<<ant<<endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}