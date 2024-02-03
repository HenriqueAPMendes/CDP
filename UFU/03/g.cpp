#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

struct vetor{
    int x, y;
    vetor(int _x, int _y) : x(_x), y(_y) {}
};

int dot(vetor v1, vetor v2){
    return (v1.x*v2.x + v1.y*v2.y);
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    while(n--){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vetor l1 = vetor(x1-x2, y1-y2);
        vetor l2 = vetor(x1-x3, y1-y3);
        vetor l3 = vetor(x3-x2, y3-y2);
        
        if (dot(l1, l2) == 0 or dot(l1,l3) == 0 or dot(l2, l3) == 0) cout << "sim\n";
        else cout << "nao\n";
    }


    return 0;
}