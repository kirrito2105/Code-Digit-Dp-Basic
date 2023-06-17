#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[10001][2][10], mod = 1e9+7;

int calc(string num, int id, bool smaller, int sum) {
	if (id == -1) return (sum == 0);
	if (f[id][smaller][sum] != -1) return f[id][smaller][sum];
	int res = 0;
	int limit = smaller ? 9 : num[id]-'0';
	for (int i = 0; i <= limit; ++i)
		res = (res+calc(num, id-1, smaller || i < num[id]-'0', (sum+i*i)%3))%mod;
	f[id][smaller][sum] = res;
	return res;
}

signed main() {
	string num; cin >> num;
	int s = 0;
	for (int i = 0; i < num.length(); ++i) s = (s+(num[i]-'0')*(num[i]-'0'))%3;
	reverse(num.begin(), num.end());
	memset(f, -1, sizeof(f));
	cout << calc(num, num.size()-1, 0, 0)-(s == 0);
	return 0;
}

// Link submit: https://oj.lequydon.net/problem/sqamod
