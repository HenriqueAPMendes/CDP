#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    double f1,f2;
    cin >> f1 >> f2;
    
    double ans = ((100 + f1)*(1+f2/100)) - 100;
    printf("%.6f\n", ans);

    return 0;
}