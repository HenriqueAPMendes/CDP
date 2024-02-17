#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    double i, l, n;
    scanf("%lf %lf %lf", &i, &l, &n);
    double ans = i + (n-1)*l;
    printf("%.1lf\n", ans);

    return 0;
}