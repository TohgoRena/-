def levenshtein_distance(S, T):
    # Sの長さ
    m = len(S)
    # Tの長さ
    n = len(T)

    # 動的計画法の表を初期化する
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # 初期化: 空文字列からの編集距離
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j

    # 動的計画法の表を更新する
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # 文字が一致する場合はコストは0
            if S[i - 1] == T[j - 1]:
                cost = 0
            else:
                cost = 1
            # 動的計画法の再帰的な更新式
            dp[i][j] = min(dp[i - 1][j] + 1,  # 挿入
                           dp[i][j - 1] + 1,  # 削除
                           dp[i - 1][j - 1] + cost)  # 置換または一致

    # 最終的な編集距離を返す
    return dp[m][n]

# テスト用の文字列
S = "東郷平八郎"
T = "東郷レナ"

# レーベンシュタイン距離を求める
distance = levenshtein_distance(S, T)
print("レーベンシュタイン距離:", distance)