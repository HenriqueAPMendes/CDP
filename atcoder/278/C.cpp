#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N, Q, T, A, B;
    cin >> N >> Q;

    set< pair<int,int> > follows;

    for (int i = 0; i < Q; i++){
        cin >> T >> A >> B;

        if (T == 1) follows.insert(make_pair(A, B));
        else if (T == 2) follows.erase(make_pair(A, B));
        else cout <<  (follows.count(make_pair(A,B)) && follows.count(make_pair(B,A)) ? "Yes" : "No") << endl;
    }

    return 0;
}
