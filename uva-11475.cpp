#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int b[100000 + 5];

int main() {
    
    while(cin >> s) {
        string r(s);
        reverse(r.begin(), r.end());
        
        // kmp pre-processor on R
        int i = 0, j = -1; b[0] = -1;
        while(i < r.size()) {
            while(j >= 0 && r[i] != r[j]) j = b[j];
            i++; j++;
            b[i] = j;
        }
        
        // kmp search for R on S
        i = 0; j = 0;
        while(i < s.size()) {
            while(j >= 0 && r[j] != s[i]) j = b[j];
            i++; j++;
            if (j == r.size()) {
                // j = b[j]; // no need
            }
        }
        cout << s;
        while(j < r.size()) cout << r[j++];
        cout << '\n';
    }
    
    return 0;
}
