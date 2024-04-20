#include <bits/stdc++.h>
using namespace std;

void merge(string &s, int left, int mid, int right){
    string firstHalf;
    string secondHalf;

    for (int i = 0; i<mid-left+1; i++)
        firstHalf+=s[left+i];
    for (int i = 0; i<right-mid; i++)
        secondHalf+=s[mid+i+1];
    
    int j=0, k=0, i=left;

    while(j<mid-left+1 && k<right-mid){
        if (firstHalf[j] <= secondHalf[k])
            s[i++] = firstHalf[j++];
        else
            s[i++] = secondHalf[k++];
    }
    while(j < mid-left+1) s[i++] = firstHalf[j++];
    while(k < right-mid) s[i++] = secondHalf[k++];

}

void mergeSort(string &s, int begin, int end){
    if (begin>=end) return;

    int mid = (begin+end) >> 1;
    mergeSort(s, begin, mid);
    mergeSort(s, mid+1, end);
    merge(s,begin,mid,end);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s, input;
    int k;
    
    cin >> input;
    cin >> k;

    int n = input.length();
    
    for (int i = 0; i < k; i++){
        s = "";
        for (int j = i; j < n; j+=k) s += input[j];
        mergeSort(s, 0, s.length()-1);
        int x = 0;
        for (int j = i; j < n; j+=k) input[j] = s[x++];
    }

    cout << input << endl;

    return 0;
}