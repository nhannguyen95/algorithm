#include <iostream>
#include <cstring>
#include <cmath> // math.h C
#include <algorithm>
using namespace std;

const int oo = 1e9;

int f[1000000 + 5];

int main() {
    
    for(int i = 1; i <= 1000000; i++)
        f[i] = oo;
    f[0] = 0;
        
    int pr[4] = { 2, 3, 5, 7};
    for(int i = 1; i <= 1000000; i++) {
        for(int j = 0; j < 4; j++) {
            if (i - pr[j] != 1 && i - pr[j] >= 0)
                f[i] = min(f[i], f[i-pr[j]] + 1);
        }
    }
    
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        if (f[x] == oo || f[x] == 0) cout << -1 << '\n';
        else cout << f[x] << '\n';
    }
    
    
    return 0;
}
