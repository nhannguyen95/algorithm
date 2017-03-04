#include <iostream>
#include <cstring>
using namespace std;

string s;
int b[1000000 + 5];

int main() {
    
    int n; cin >> n; cin.ignore(1);
    while(n--) {
        int k, w; cin >> k >> w; cin.ignore(1);
        getline(cin, s);
        int res = k;
        for(int cw = 0; cw < w-1; cw++) {
            string t; getline(cin, t);
            
            // preprocessor KMP on t;
            int i = 0, j = -1; b[0] = -1;
            while(i < t.size()) {
                while(j >= 0 && t[i] != t[j]) j = b[j];
                i++; j++;
                b[i] = j;
            }
            
            // search for t on s
            i = 0, j = 0;
            while(i < s.size()) {
                while(j >= 0 && s[i] != t[j]) j = b[j];
                i++; j++;
                
                if (j == t.size()) {
                    if (i != s.size()) j = b[j];
                }
            }
            
            while(j < t.size()) { s = s + t[j++]; res++; }
        }
        cout << res << '\n';
    }
    
    return 0;
}
