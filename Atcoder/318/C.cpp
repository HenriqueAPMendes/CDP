#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){

    int N, D, P;
    cin >> N >> D >> P;

    int x;
    vector<int> F;

    for (int i = 0; i < N; i++){
        cin >> x;
        F.push_back(x);
    }

    sort(F.begin(), F.end(), greater<int>());

    long long S = 0;
    for (int i = 0; i < N; i++){
        S += F[i];
    }

    long long s2=0;

    for (int i = 0; i < N; i+=D){
        s2 = 0;
        for (int j = i; j < i+D && j < N; j++){
            s2 += F[j];
        }


        if (s2 > P) {
            S -= (s2-P);
        }
        else break;
    }

    cout << S << endl;

    return 0;
}