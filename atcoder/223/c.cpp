#include <bits/stdc++.h>
using namespace std;

const int MAX = 112345;
#define ll long long

vector<pair<double,double>> fuses(MAX,{0,0});

int main (){

    int n, a, b, totalLength = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a >> b;
        totalLength += a;
        fuses[i] = {a,b};
    }

    int left = 0, right = n-1;
    double leftPos = 0, rightPos = totalLength;
    double tl = 0, tr = 0, t;

    while (left < right){
        if (tl == 0) tl = fuses[left].first / fuses[left].second;
        if (tr == 0) tr = fuses[right].first / fuses[right].second;

        t = min(tl, tr);
        leftPos += fuses[left].second*t;
        rightPos -= fuses[right].second*t;

        if (tl < tr) {
            left++;
            tr-=tl;
            tl = 0;
        }
        else if (tl > tr){
            right--;
            tl-=tr;
            tr = 0;
        }
        else{
            left++;
            right--;
            tl = 0;
            tr = 0;
        }
    }

    if (left > right) printf("%.15f\n", leftPos);
    else printf("%.15f\n", (leftPos+rightPos)/2.0);

    return 0;
}
