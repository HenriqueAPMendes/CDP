#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q; 
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    cin >> Q;

    int type, xq, iq;
    for (int i = 0; i < Q; i++){
        cin >> type;
        if (type == 1){
            cin >> xq;
            for(int j = 0; j < N; j++)
                A[j] = xq;

        } else if (type == 2){
            cin >> iq >> xq;
            iq--;
            A[iq] += xq;
        } else { // type == 3
            cin >> iq;
            iq--;
            cout << A[iq] << endl;
        }
    }

    return 0;
}