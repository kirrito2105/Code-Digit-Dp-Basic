#include <bits/stdc++.h>
#define int long long

using namespace std;

int f[11][2][90][4000];

bool isPrime(int n) {
	if (n < 2) return 0;
	if (n < 4) return 1;
	if (n%2 == 0 || n%3 == 0) return 0;
	for (int i = 5; i*i <= n; i += 6)
		if (n%i == 0 || n%(i+2) == 0)
			return 0;
	return 1;
}

int calc(string num, int id, bool smaller, int sum, int mod, int k) {
	if (id == -1) return (isPrime(sum) && mod == 0);
	if (f[id][smaller][sum][mod] != -1) return f[id][smaller][sum][mod];
	int res = 0;
	int limit = smaller ? 9 : num[id]-'0';
	for (int i = 0; i <= limit; ++i)
		res += calc(num, id-1, smaller || i < num[id]-'0', sum+i, (mod*10+i)%k, k);
	f[id][smaller][sum][mod] = res;
	return res;
}

int solve(int n, int k) {
	string num = to_string(n);
	reverse(num.begin(), num.end());
	memset(f, -1, sizeof(f));
	return calc(num, num.length()-1, 0, 0, 0, k);
}

signed main() {
	int l, r, k; cin >> l >> r >> k;
	cout << solve(r, k)-solve(l-1, k); 
	return 0;
}

// Link submit: https://www.hackerearth.com/problem/algorithm/playing-with-digits-4e25844f/
