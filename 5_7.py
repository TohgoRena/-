def knapsack(capacity, weights, values):
    n = len(weights)
    # 動的計画法の表を初期化
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][capacity]

# 問題設定
capacity = 7
weights = [2, 1, 6, 5]
values = [10, 7, 25, 24]

# ナップサック問題を解く
max_value = knapsack(capacity, weights, values)
print("ナップサックに収納できる最大価値:", max_value)
