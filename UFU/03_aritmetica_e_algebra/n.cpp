#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    double x1, y1, x2, y2;
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    scanf("%lf", &x2);
    scanf("%lf", &y2);
    double dx = x2-x1;
    double dy = y2-y1;
    double dist = sqrt(dx*dx + dy*dy);
    printf("%.3lf\n", dist);
    return 0;
}