#include <stdio.h>
#include <stdbool.h>

#define N 5
#define TARGET_SUM 10

int main() {
    int numbers[N] = {1, 2, 3, 4, 5};
    bool dp[TARGET_SUM + 1] = {false};

    // 部分和0は常にtrue（何も選ばなければよいため）
    dp[0] = true;

    // 動的プログラミングによる部分和の計算
    for (int i = 0; i < N; i++) {
        for (int j = TARGET_SUM; j >= numbers[i]; j--) {
            if (dp[j - numbers[i]]) {
                dp[j] = true;
            }
        }
    }

    // 結果の出力
    if (dp[TARGET_SUM]) {
        printf("部分和 %d を作ることができます。\n", TARGET_SUM);
    } else {
        printf("部分和 %d を作ることができません。\n", TARGET_SUM);
    }

    return 0;
}