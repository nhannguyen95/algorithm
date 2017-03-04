#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int b[10000000 + 5];

int main() {

    ios::sync_with_stdio(0);
    int T; cin >> T; cin.ignore(1);
    while(T--) {
        string s; getline(cin, s);
        string r(s);
        reverse(r.begin(), r.end());
        s = s + s;
        
        // KMP preprocessor on r
        int i = 0, j = -1; b[0] = -1;
        while(i < r.size()) {
            while(j >= 0 && r[i] != r[j]) j = b[j];
            i++; j++;
            b[i] = j;
        }
        
        // search for r on s (s + s actually)
        vector<int> v;
        i = 0, j = 0;
        while(i < s.size()) {
            while(j >= 0 && s[i] != r[j]) j = b[j];
            i++; j++;
            
            if (j == r.size()) {
                if (i-j < s.size()/2) v.push_back(i-j);
                j = b[j];
            }
        }
        
        // cases
//        for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
//        cout << '\n';
//        continue;
        if (v.size() == 0) cout << "simple\n";
        else {
            
            if (v.size() == 1 && v[0] == 0) cout << "palindrome\n";
            else cout << "alindrome\n";
        }
    }
    
    return 0;
}
