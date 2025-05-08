for (int pos = 1; pos <= N; pos++) Opt[0][pos] = 0;
for (int groupNo = 1; groupNo <= K; groupNo++) Opt[groupNo][N + 1] = N;
for (int groupNo = 1; groupNo <= K; groupNo++){ for (int pos = N; pos >= 1; pos--){ for (int endOfLast = Opt[groupNo - 1][pos];endOfLast <= Opt[groupNo][pos + 1]; endOfLast++){
            int ret = dp[groupNo - 1][endOfLast] + Cost(endOfLast + 1, pos); if (dp[groupNo][pos] <= ret) continue; dp[groupNo][pos] = ret;Opt[groupNo][pos] = endOfLast;
        }
    }
}
