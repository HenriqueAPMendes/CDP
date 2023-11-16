#include <bits/stdc++.h>
using namespace std;

#define MAX 1e6+1
#define ll long long

int main (){
    cin.tie(0); cout.tie(0);

    ios_base::sync_with_stdio(0);

    int n, x;
    cin >> n;
    vector<int> v(MAX, 0), a(MAX, 0);
    
    while (n--){
        cin >> x;
        v[x]++; // conta quantas vezes cada valor apareceu
    }
    int ans = 0;
    for (int i = MAX; !ans && i > 0; i--)
        for (int j = i; !ans && j < MAX; j+=i){
            a[i] += v[j]; // se esse multiplo de i aparece, soma no vetor a
            if (a[i] > 1) ans = i;// o primeiro valor que aparece duas vezes é o maior GCD
        }

    cout << ans << '\n';

}