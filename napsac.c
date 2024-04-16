#include <stdio.h>

#define N 5
#define MAX_WEIGHT 15

// 品物の情報を格納する構造体
typedef struct {
    int cost;   // 価値
    int weight; // 重さ
} Item;

// DPテーブルの状態を出力する関数
void print_dp_table(int dp[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%2d ", dp[i]);
    }
    printf("\n");
}

int main() {
    // 各品物の価値と重さ
    Item items[N] = {{15, 11}, {4, 4}, {3, 2}, {2, 1}, {8, 5}};
    
    // dp[i] は重さiでの最大価値
    int dp[MAX_WEIGHT + 1] = {0};  // 全て0で初期化

    printf("動的計画チャート:\n");
    print_dp_table(dp, MAX_WEIGHT + 1);

    // 動的プログラミングでナップサック問題を解く
    for (int i = 0; i < N; i++) {
        for (int j = MAX_WEIGHT; j >= items[i].weight; j--) {
            if (dp[j - items[i].weight] + items[i].cost > dp[j]) {
                dp[j] = dp[j - items[i].weight] + items[i].cost;
            }
        }
        printf("次の要素を考慮 %d (値段 = %d, 重量 = %d):\n", i+1, items[i].cost, items[i].weight);
        print_dp_table(dp, MAX_WEIGHT + 1);
    }

    // 最大価値の出力
    printf("カバンに詰め込める品物の価値の最大合計は %d ＄です。\n", dp[MAX_WEIGHT]);

    return 0;
}
