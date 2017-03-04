#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int b[10000000 + 5];

int main() {
    
    ios::sync_with_stdio(0);
    int T; cin >> T; cin.ignore(1);
    while(T--) {
        string s; getline(cin, s);
        string r(s); reverse(r.begin(), r.end());
        
        // do KMP preprocessor on S
        int i = 0, j = -1; b[0] = -1;
        while(i < s.size()) {
            while(j >= 0 && s[i] != s[j]) j = b[j];
            i++; j++;
            b[i] = j;
        }
        
        // search S on R
        i = j = 0;
        int id = -1;
        while(i < r.size()) {
            while(j >= 0 && r[i] != s[j]) j = b[j];
            if (j >= 0 && r[i] == s[j]) id = max(id, j);
            i++; j++;
            if (j == s.size()) j = b[j];
        }
        
        // result
        if (id != -1) {
            for(int i = id; i >= 0; i--) cout << s[i];
            cout << '\n';
        } else cout << "???";
    }
    
    return 0;
}
