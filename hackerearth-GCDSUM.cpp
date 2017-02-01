#include <iostream>
#include <cstring>
using namespace std;

typedef long long int ll;

const int MAXN = 1e6 + 5;
const int MAXV = 5e5;
const ll MOD = 1e9 + 7;

int N, Q;
ll a[MAXN], phi[MAXV + 5], p[MAXV + 5], BIT[MAXN];

ll inline mod(ll x) {
	return (x%MOD + MOD)%MOD;
}

void compute_phi() {
    for(int i = 1; i <= MAXV; i++) phi[i] = i;
    for(int i = 2; i <= MAXV; i++)
        if (phi[i] == i) { // prime number
            for(int j = i; j <= MAXV; j += i) {
                phi[j] -= phi[j] / i;
                phi[j] = mod(phi[j]);
            }
        }
}

void compute_pillai() {
    for(int i = 1; i <= MAXV; i++)
        for(int j = i; j <= MAXV; j += i) {
            p[j] += i * phi[j / i];
            p[j] = mod(p[j]);
        }
}

void update(int i, ll val) {
    for(; i <= N; i += i&-i) {
        BIT[i] += val;
        BIT[i] = mod(BIT[i]);
    }
}

ll query(int i) {
    ll sum = 0;
    for(; i > 0; i -= i&-i) {
        sum += BIT[i];
        sum = mod(sum);
    }
    return sum;
}

int main() {
    
    compute_phi();
    compute_pillai();
    memset(BIT, 0, sizeof(BIT));
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        update(i, p[a[i]]);
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        char c; int x, y;
        cin >> c >> x >> y;
        if (c == 'U') {
            update(x, mod(-p[a[x]] + p[y]));
            a[x] = y;
        } else if (c == 'C') {
            cout << mod(query(y) - query(x) + p[a[x]]) << '\n';
        }
    }
    
    return 0;
}
