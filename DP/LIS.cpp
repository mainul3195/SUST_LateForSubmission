vector<int>dp, lis;int track[n];dp.push_back(a[0]);track[0] = 1;
for (int i = 1; i < n; i++){if (a[i] > dp.back()) dp.push_back(a[i]), track[i] = dp.size();
else{int ind = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
dp[ind] = a[i];	track[i] = ind + 1;}}int len = dp.size();
for (int i = n - 1 ; i >= 0 ; i--){if (track[i] == len) lis.push_back(a[i]), len--;
}reverse(lis.begin(), lis.end());
