#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string findSubstring(string s, int k) {
    string ans = "Not found!";
    
    // define first string number of vowels
    int n_vowels = 0;
    for (int i = 0; i < k; i++)
        if (isVowel(s[i])) n_vowels++;
        
    int maxVowels = n_vowels;
    int max_index = 0;
    
    for (unsigned int i = 1; i < s.length() +1 - k; i++){
        //cout << "i = " << i << " | s[i-1] = " << s[i-1] << " | s[i+k-1] = " << s[i+k-1] << endl;
				if (isVowel(s[i-1])){
					n_vowels--;
					//cout << "vowel detected on: " << i << ": " << s[i-1] << endl;
				}

				if (isVowel(s[i+k-1])){
					//cout << "vowel detected on: " << i << ": " << s[i+k-1] << endl;
					n_vowels++;
				}
        if (n_vowels > maxVowels){
            //cout << "found greater\n";
            maxVowels = n_vowels;
            max_index = i;
        }
    }
    
    if (maxVowels > 0)
        ans = s.substr(max_index, k);
        
    return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string s;
	int k;

	cin >> s >> k;

	cout << findSubstring(s, k) << endl;
	return 0;
}
