#include <bits/stdc++.h>
using namespace std;

bool myfunction(pair<int, int> cup1, pair<int, int> cup2) {
    return (cup1.second > cup2.second);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    int F, S;
    vector<pair<int, int> > cups;

    for (int i = 0; i < N; i++){
        cin >> F >> S;
        cups.push_back(make_pair(F, S));
    }

    sort(cups.begin(), cups.end(), myfunction);

    for (int i = 1; i < N; i++){
        if (cups[i].first == cups[0].first) cups[i].second /= 2;
    }

    sort(cups.begin(), cups.end(), myfunction);

    cout << cups[0].second + cups[1].second << endl;

    return 0;
}