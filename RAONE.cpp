#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[9][2][37][37];

int calc(string num, int id, bool smaller, int sum, int s) {
	if (id == -1) return (sum-s == 1);
	if (f[id][smaller][sum][s] != -1) return f[id][smaller][sum][s];
	int res = 0;
	int limit = smaller ? 9 : num[id]-'0';
	if (id&1) 
		for (int i = 0; i <= limit; ++i)
			res = res+calc(num, id-1, smaller || i < num[id]-'0', sum+i, s);	
	else 
		for (int i = 0; i <= limit; ++i)
			res = res+calc(num, id-1, smaller || i < num[id]-'0', sum, s+i);
	f[id][smaller][sum][s] = res;
	return res;
}

int solve(int n) {
	string num = to_string(n);
	reverse(num.begin(), num.end());
	memset(f, -1, sizeof(f));
	return calc(num, num.length()-1, 0, 0, 0);
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		cout << solve(r)-solve(l-1) << '\n';
	}
	return 0;
}

// Link submit: https://www.spoj.com/problems/RAONE/
