#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[16][136];

void calc() {
	for (int i = 1; i <= 9; ++i) f[1][i] = f[1][i-1]+i;
	for (int i = 2; i <= 15; ++i)
		for (int j = 0; j <= 9; ++j)
			for (int k = j; k <= 15*9; ++k)
				f[i][k] += f[i-1][k-j];
}

signed main() {
	calc();
	int t; cin >> t;
	while (t--) {
		int L;
		string r; cin >> L >> r;
		string l = to_string(L-1);
		int sL = 0, sR = 0, res = 0;
		for (int i = 0; i < l.length(); ++i) sL += l[i]-'0';
		for (int i = 0; i < r.length(); ++i) sR += r[i]-'0';
		cout << f[r.length()][sR] << " " << f[l.length()][sL] << '\n';
			
	}
	return 0;
}

/*
	Link submit: https://www.spoj.com/problems/PR003004/
*/
