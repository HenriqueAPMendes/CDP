#include <bits/stdc++.h>
using namespace std;

// 3n+1 conjecture

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n;
    cin >> n;

    cout << n << " ";
    while(n != 1){
        if (n % 2){
            n *= 3;
            n++;
        }
        else{
            n /= 2;
        }
         cout << n << " ";
    }
    cout << endl;
    return 0;
}
