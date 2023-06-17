#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[10][2][47][47];

bool isPrime(int n) {
	if (n < 2) return 0;
	if (n < 4) return 1;
	if (n%2 == 0 || n%3 == 0) return 0;
	for (int i = 5; i*i <= n; i += 6)
		if (n%i == 0 || n%(i+2) == 0)
			return 0;
	return 1;
}

int calc(string num, int id, bool smaller, int sum, int s) {
	if (id == -1) return isPrime(sum-s);
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

// Link submit: https://www.spoj.com/problems/LUCIFER/
