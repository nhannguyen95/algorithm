#include <iostream>
#include <string>
using namespace std;

string s;
int b[int(1e7) + 1];

int main() {
    
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0); // must use !
    cin >> s;
    int i = 0, j = -1; b[0] = -1;
    int n = int(s.size());
    int len = 0, pos = 1;
    while(i < n) {
        while(j >= 0 && s[i]!=s[j]) j=b[j];
        i++;j++;
        b[i]=j;
        
        if (i < n) {
            if (s[i] == s[j]) { // the length now is j + 1
                if (2*(j+1) >= i+1) j = (i+1)/2-1;
                if (j+1 > len) { len = j+1; pos = i-j+1; }
            }
        }
    }
    
    cout << len << ' ' << pos;
    
    return 0;
}
