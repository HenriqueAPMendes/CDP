#include<bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T, cnt = 0, exp;
    cin >> T;

    ll n, value;
    for (int i = 0; i < T; i++){
        cin >> n;
        exp = 14;
        cnt = 0;
        while (n != 0){
            value = 2050*(ll)pow(10, exp);
            if (n >= value){
                n -= value;
                cnt++;
            }
            else {
                if (exp == 0) break;
                exp--;
            }
        }

        if (n != 0) cout << -1 << endl;
        else cout << cnt << endl;
    }
    


    return 0;
}