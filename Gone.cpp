#include <bits/stdc++.h>

using namespace std;

long long f[9][2][73];

bool isPrime(int n) {
	if (n < 2) return 0;
	if (n < 4) return 1;
	if (n%2 == 0 || n%3 == 0) return 0;
	for (int i = 5; i*i <= n; i += 6)
		if (n%i == 0 || n%(i+2) == 0)
			return 0;
	return 1;
}

long long calc(string num, int id, int smaller, int sum) {
	if (id == -1) return isPrime(sum);
	if (f[id][smaller][sum] != -1) return f[id][smaller][sum];
	long long res = 0;
	int limit = smaller ? 9 : num[id]-'0';
	for (int i = 0; i <= limit; ++i)
		res += calc(num, id-1, smaller || i < num[id]-'0', sum+i);
	f[id][smaller][sum] = res;
	return res;
}

string toString(int n) {
	string res;
	while (n) res += n%10+'0', n /= 10;
	return res;
}

long long solve(int n){
	memset(f, -1, sizeof(f));
	string tmp = toString(n);
	return calc(tmp, tmp.length()-1, 0, 0);
}

int main() {
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		cout << solve(r)-solve(l-1) << "\n";
	}
	return 0;
}

// Link submit: https://www.spoj.com/problems/GONE/
