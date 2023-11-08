#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int binExp(int n){
    if (n == 0) return 1;
    if (n%2) return (2*binExp(n-1))%mod;
    int b = binExp(n/2)%mod;
    return (b*b)%mod;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    cout << binExp(n)%mod << endl;
    return 0;
}