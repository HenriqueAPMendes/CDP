#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct vec{
    ll x; ll y; ll z;
    vec(){x=y=z=0;}
    vec(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) {}
};

vec cross(vec v1, vec v2){
    vec ans;
    ans.x = v1.y*v2.z - v1.z*v2.y;
    ans.y = v1.z*v2.x - v1.x*v2.z;
    ans.z = v1.x*v2.y - v1.y*v2.x;
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t,x1,x2,x3,y1,y2,y3;
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vec v1(x2-x1,y2-y1,0);
        vec v2(x3-x2,y3-y2,0);
        vec cr = cross(v1,v2);
        if (cr.z > 0) cout << "LEFT\n";
        else if (cr.z < 0) cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }
    return 0;
}