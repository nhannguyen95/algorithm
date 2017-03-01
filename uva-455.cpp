#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int t, b[100], n;
string s;

bool ok(int period) {
    if (n % period != 0) return false;
    if (n == 1 && period == 1) return true;
    int i = 0, j = 0;
    vector<int> pos;
    while(i < n) {
        while (j >= 0 && s[i] != s[j]) j = b[j];
        i++; j++;
        
        if (j == period) {
            pos.push_back(i-j+1);
            j = b[j];
        }
    }
    if (n / period == pos.size()) {
        for(int i = 1; i < pos.size(); i++) {
            if (pos[i] - pos[i-1] != period) return false;
        }
        return true;
    }
    return false;
}

int main() {
    
    cin >> t; cin.ignore(1);
    getline(cin, s);
    while(t--) {
        getline(cin, s);
        
        int i = 0, j = -1;
        b[0] = -1;
        n = int(s.size());
        while(i < n) {
            while(j >= 0 && s[i] != s[j]) j = b[j];
            i++; j++;
            b[i] = j;
        }
        
        int res = n;
        for(int period = 1; period <= n/2; period++)
            if (ok(period)) { res = period; break; }
        
        cout << res;
        if (t) {
            cout << "\n\n";
            getline(cin, s);
        }
    }
    cout << '\n';

    
    return 0;
}
