#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> HASH, REV_HASH, POW;
vector<int> BASE = {1231, 1567}, MOD = {1000000000 + 7, 1000000000 + 9};
#define lim 1000006 string text, pattern;void init(){
POW = vector<vector<long long>>(2, vector<long long>(lim));
POW[0][0] = POW[1][0] = 1;for (int b = 0; b < 2; b++)
for (int j = 1; j < lim; j++)POW[b][j] = (POW[b][j - 1] * BASE[b]) % MOD[b];return;
}void initHash(string str){int len = str.size();HASH[0][0] = HASH[1][0] = 0;
for (int b = 0; b < 2; b++)for (int i = 1; i <= len; i++)
HASH[b][i] = (HASH[b][i - 1] * BASE[b] + (str[i - 1] - 'a' + 1)) % MOD[b];
REV_HASH[0][len + 1] = REV_HASH[1][len + 1] = 0;for (int b = 0; b < 2; b++)
for (int i = len; i; i--)REV_HASH[b][i] = (REV_HASH[b][i + 1] * BASE[b] + (str[i - 1] - 'a' + 1)) % MOD[b];
return;}long long getHash(int left, int right, int hsh){int len = (right - left + 1);
long long ret = (HASH[hsh][right] - HASH[hsh][left - 1] * POW[hsh][len]) % MOD[hsh];
if (ret < 0)ret += MOD[hsh];return ret;}
pair<long long, long long> getHash(int left, int right){long long hsh0 = getHash(left, right, 0);
long long hsh1 = getHash(left, right, 1);return {hsh0, hsh1};}
long long getRevHash(int left, int right, int hsh){int len = (right - left + 1);
long long ret = (REV_HASH[hsh][left] - REV_HASH[hsh][right + 1] * POW[hsh][len]) % MOD[hsh];
if (ret < 0)ret += MOD[hsh];return ret;}pair<long long, long long> getRevHash(int left, int right){
long long hsh0 = getRevHash(left, right, 0);long long hsh1 = getRevHash(left, right, 1);
return {hsh0, hsh1};}bool palindrome(int l, int r){return getHash(l, r) == getRevHash(l, r);}
void solve(){string s = "aaabbabbaaac";HASH = vector<vector<long long>>(2, vector<long long>(s.size() + 5));
REV_HASH = vector<vector<long long>>(2, vector<long long>(s.size() + 5));initHash(s);
cout << (palindrome(1, s.size()) ? "YES\n" : "NO\n");cout << (palindrome(1, s.size() - 1) ? "YES\n" : "NO\n");
return;}int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);init();solve();return 0;}
