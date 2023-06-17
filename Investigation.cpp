#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[11][2][100][10001];

int calc(string num, int id, bool smaller, int sum, int s, int k) {
	if (id == -1) return (!sum && s%k == 0);
	if (f[id][smaller][sum][s%k] != -1) return f[id][smaller][sum][s%k];
	int res = 0;
	int limit = smaller ? 9 : num[id]-'0';
	for (int i = 0; i <= limit; ++i)
		res = res+calc(num, id-1, smaller || i < num[id]-'0', (sum+i)%k, s*10+i, k);
	f[id][smaller][sum][s%k] = res;
	return res;
}

int solve(int n, int k) {
	string num = to_string(n);
	reverse(num.begin(), num.end());
	memset(f, -1, sizeof(f));
	return calc(num, num.length()-1, 0, 0, 0, k);
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int l, r, k; cin >> l >> r >> k;
		cout << solve(r, k)-solve(l-1, k) << '\n';
	}
	return 0;
}

// Link submit: https://lightoj.com/problem/investigation || https://toph.co/p/m-beautiful-numbers
// Memory Limit Exceeded
