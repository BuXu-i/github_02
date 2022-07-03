#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e7 + 10, mod = 1e9 + 7;

LL p[4], q[4];

int main() {
	int n;
	cin >> n;
	while(n--) {
		p[3] = 1;
		for(int i = 1; i <= n; i ++ ) {
			q[3] = (p[0] + p[1] + p[2] + p[3]) % mod;
			q[0] = p[3] % mod;
			q[1] = (p[0] + p[2]) % mod;
			q[2] = (p[0] + p[1]) % mod;
			for(int i = 0; i <= 3; i ++ )
				p[i] = q[i];
		}
		cout << p[3]<<" ";
	}

	return 0;
}
