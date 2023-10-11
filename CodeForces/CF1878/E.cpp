#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> prefix_and(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            prefix_and[i] = a[i];
        }


        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            int l, k;
            cin >> l >> k;
            l--; // 0-based indexing

            // Calcula o Prefix Bitwise AND
        
            for (int i = l+1; i < n; i++) {
                prefix_and[i] = a[i] & prefix_and[i - 1];
                if (prefix_and[i] < k) {
                    cout << i-1 << " ";
                    break;    
                }
            }



            // binary search on answer
            while(left < right){
                if (prefix_and[mid] < k)
                    right = mid - 1;
                else
                    left = mid + 1;
            }


            if (a[mid] >= k) {
                cout << mid << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
