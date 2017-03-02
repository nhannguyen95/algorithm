#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string s;
int b[1000000 + 5];

bool ok(int len) {
    if (s.size() == 1 && len == 1) return true;
    int i = 0, j = 0;
    vector<int> pos;
    while(i < s.size()) {
        while(j >= 0 && s[i] != s[j]) j = b[j];
        i++; j++;
        
        if (j == len) {
            pos.push_back(i-j);
            j = b[j];
        }
    }
    if (s.size() / len == pos.size()) {
        for(int i = 1; i < pos.size(); i++) {
            if (pos[i] - pos[i-1] != len) return false;
        }
        return true;
    }
    return false;
}

int main() {
    
    while(getline(cin, s), !(s.size()==1&&s[0]=='.')) {
        if (s.size() == 0) cout << 0;
        else {
            int i = 0, j = -1; b[0] = -1;
            while(i < s.size()) {
                while(j >= 0 && s[i] != s[j]) j = b[j];
                i++; j++;
                b[i] = j;
            }
            
            int res = s.size();
            for(int len = 1; len <= s.size()/2; len++) {
                if (s.size()%len==0 && ok(len)) {
                    res = len;
                    break;
                }
            }
            
            cout << (s.size() / res);
        }
        cout << '\n';
    }
    
    return 0;
}
