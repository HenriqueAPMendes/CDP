#include<bits/stdc++.h>
using namespace std;

int combine(int cnt){
    return 1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, Xp, Xe, M, Yp, Ye, i;
    map<int,int> X, Y;
    cin >> N;

    // primos da fatoracao X
    for (i=0; i<N; i++){
        cin >> Xp;
        X.insert(make_pair(Xp, 0));
    }

    map<int, int>::iterator it = X.begin();

    // expoentes fatoracao X
    for (i=0; i<N; i++){
        cin >> Xe;
        it->second = Xe;
        it++;
    }

    cin >> M;
    
    // primos da fatoracao Y
    for (i=0; i<M; i++){
        cin >> Yp;
        Y.insert(make_pair(Yp, 0));
    }

    it = Y.begin();

    // expoentes fatoracao Y
    for (i=0; i<M; i++){
        cin >> Ye;
        it->second = Ye;
        it++;
    }


    // embaixo nao pode sobrar, pois mmc é multiplo de mdc

    map<int, int>::iterator itX = X.begin();
    map<int, int>::iterator itY = Y.begin();

    int cnt = 0;

    while(itX != X.end() && itY != Y.end()){
        
        if (itX->first == itY->first){
            if (itX->second - itY->second > 0) cnt++;
            else if (itX->second - itY->second > 0){
                cout << 0 << endl;
                exit(0);
            }
            itX++;
            itY++;
        }
        else if (itX->first > itY->first){
            cout << 0 << endl;
            exit(0);
        }
        else{ // x < y
            itX++;
            cnt++;
        }
    }

    while(itX != X.end()){
        itX++;
        cnt++;
    }

    if(itY != Y.end()){
        cout << 0 << endl;
        exit(0);
    }

    cout << pow(2, cnt) << endl;

    return 0;
}