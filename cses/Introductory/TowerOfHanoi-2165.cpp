#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void hanoi(int n, int a, int b){

    if (n == 1){
        cout << a+1 << ' ' << b+1 << endl;
        return ;
    }

    int mid;
    if (0!=a && 0!=b) mid = 0;
    else if (1!=a && 1!=b) mid = 1;
    else mid = 2;
    hanoi(n-1,a, mid);
    cout << a+1 << ' ' << b+1 << endl;
    hanoi(n-1,mid,b);
}

void solve(int n){
    hanoi(n, 0, 2);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    cout << (1<<n)-1 << endl;
    
    solve(n);

    return 0;
}