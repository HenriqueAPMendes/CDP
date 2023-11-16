#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001
typedef long long ll;

vector<int> divisors(MAX, 0);

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 1; i < MAX; i++)
        for (int j = i; j < MAX; j+=i) // quase crivo de eratostenes
            divisors[j]++;
        
    int n, x;
    cin >> n;
    while (n--){
        cin >> x;
        cout << divisors[x] << '\n';
    }
}