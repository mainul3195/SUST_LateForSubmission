ll bigmod(ll a, ll b, ll n) {ll res = 1;
if (b == 0) return 1; a = a % n; if (a == 0)
return 0;while (b > 0) {if (b % 2)res = (res * a) % n;
b = b / 2; a = (a * a) % n;}return res;}
