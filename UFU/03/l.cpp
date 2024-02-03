#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    double a1, b1, r1;
    scanf("%lf %lf %lf", &a1, &b1, &r1);
    double a2, b2, r2;
    scanf("%lf %lf %lf", &a2, &b2, &r2);

    // a1x + b1y = r1

    if (a1*b2 - b1*a2 == 0) printf("sistema indeterminado\n");
    else{
        double y = (r2 - (a2*r1/a1))/(b2-a2*b1/a1);
        double x = (r1-b1*y)/a1;
        printf("%.2f %.2f\n", x, y);
    }

    return 0;
}