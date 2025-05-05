using i64 = long long;

constexpr int MOD = 1E9 + 7;
constexpr int MAX_N = 1000;

class Solution {
 public:
  int numTilings(int n) {
    auto modPlus = [](i64 a, i64 b) -> int { return (a + b) % MOD; };
    std::array<int, MAX_N + 1> dp{};
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = modPlus(dp[i], 2LL * dp[i - 1] + dp[i - 3]);
    }
    return dp[n];
  }

  int numTilingsTwoState(int n) {
    auto modPlus = [](i64 a, i64 b) -> int { return (a + b) % MOD; };
    std::array<int, MAX_N + 1> dp{}, incomplete{};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = modPlus(dp[i], 1LL * dp[i - 1] + dp[i - 2]);
      dp[i] = modPlus(dp[i], 2LL * incomplete[i - 1]);

  
      incomplete[i] =
          modPlus(incomplete[i], 1LL * dp[i - 2] + incomplete[i - 1]);
    }
    return dp[n];
  }
};