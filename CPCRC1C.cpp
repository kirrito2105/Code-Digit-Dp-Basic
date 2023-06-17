#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[20][2][180];

int calc(string num, int id, bool smaller, int sum) {
	if (id == -1) return sum;
	if (f[id][smaller][sum] != -1) return f[id][smaller][sum];
	int res = 0;
	int limit = smaller ? 9 : num[id]-'0';
	for (int i = 0; i <= limit; ++i)
		res += calc(num, id-1, smaller || i < num[id]-'0', sum+i);
	f[id][smaller][sum] = res;
	return res;
}

int solve(int n) {
	string num = to_string(n);
	reverse(num.begin(), num.end());
	memset(f, -1, sizeof(f));
	return calc(num, num.length()-1, 0, 0);
}

signed main() {
	int l, r; cin >> l >> r;
	while (l != -1 && r != -1) {
		cout << solve(r)-solve(l-1) << '\n';
		cin >> l >> r;
	}
	return 0;
}

// Link submit: https://www.spoj.com/problems/CPCRC1C/
