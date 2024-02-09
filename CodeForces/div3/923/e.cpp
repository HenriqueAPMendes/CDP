#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define vi vector<int>
#define MAX 212345
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;

    vector<vi> partitions(k);

    int npart = n/k; // qtd of numbers per partition
    if (n == 2 && k == 2) cout << "1 2" << endl;
    else if (n%k) {
        npart++;

        int part = n%k; // qtd of partitions with npart numbers

        for (int i = 0; i < n; i++){
            if (i+1 <= npart*(n%k)) // npart sized partitions
                partitions[i/npart].push_back(i+1);
            
            else{
                int remainder = i-(npart*(n%k)); // count after first npart sized partitions
                int index = part + (remainder/(npart-1)); // offset
                partitions[index].push_back(i+1);
            }
        }
    }
    else {
        for (int i = 0; i < n; i++)
            partitions[i/k].push_back(i+1);
    }

    for (int i = 0; i < k; i++) 
        if (i & 1) reverse(partitions[i].begin(), partitions[i].end());
    
    
    for (int i = 0; i < npart; i++) // number
        for (int j = 0; j < k; j++){ // partition
            if (i < partitions[j].size()) cout << partitions[j][i] << ' ';
    
        }
    cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}