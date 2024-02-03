#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    double v;
    int age;
    scanf("%lf %lld", &v, &age);
    v*=100;
    int val = v;

    double ans = val;
    if (age <= 5) ans *= 0.5;
    else if (age < 18) ans *= 0.95;
    else if (age <= 59) ans *= 1.1;
    else ans *= 0.85;

    ans /= 100;

    cout << ans << endl;

    printf("%.2lf\n", ans);

    return 0;
}