ll dp[20][1030][2][2];ll casio[20][1030][2][2];int cur;int v[20];
string s;int n;ll foo(int pos, int mask, int ok, bool other){
if (pos == -1){int tb = 0;int mxdig = -1;for (int i = 0 ; i <= 9 ; i++){
if (mask & (1 << i))tb++, mxdig = max(mxdig, i);}return tb == mxdig;}
ll &R = dp[pos][mask][ok][other];if(casio[pos][mask][ok][other]==cur)
return R;casio[pos][mask][ok][other] = cur;if(ok && ~R)return R;
int dgt = 9;if (!ok){dgt = v[pos];}R = 0;for (int i = 0 ; i <= dgt; i++){
int temp = mask;if (other)temp |= (1 << i);else{if (i){other = 1;temp |= (1 << i);}
}if (i < dgt || ok)R += foo(pos - 1, temp , true, other);else
R += foo(pos - 1, temp , false, other);}return R;}void pro(){
memset()ll x;cin >> x;for(int i=0 ; i<20 ; i++){v[i] = x%10;x/=10;}
cur++;ll ans = foo(18, 0, 0, 0);cout << ans << endl;}
