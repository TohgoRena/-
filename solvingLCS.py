def lcs_length(X, Y, m, n):
    # 基本ケース: どちらかの文字列が空の場合、LCSの長さは0
    if m == 0 or n == 0:
        return 0
    # 最後の文字が一致する場合、1つ前の文字列に対するLCSの長さに1を加える
    elif X[m - 1] == Y[n - 1]:
        return 1 + lcs_length(X, Y, m - 1, n - 1)
    # 最後の文字が一致しない場合、2つの文字列それぞれの最後の文字を除いた部分文字列に対するLCSの長さの最大値を返す
    else:
        return max(lcs_length(X, Y, m, n - 1), lcs_length(X, Y, m - 1, n))

# 文字列の定義
S = "東郷レナ"
T = "東郷平八郎"
# 文字列の長さ
m = len(S)
n = len(T)

# LCSの長さを計算
lcs_length = lcs_length(S, T, m, n)
print("最長共通部分列の長さ:", lcs_length)