#include <stdio.h>

#define Q 5

// 貪欲法によるナップサック問題の解法
void knapsack_greedy(int n, int capacity, int goods[][2])
{
    int solution[Q] = {0}; // 解の配列、初期値はすべて0
    int current_capacity = capacity;

    // 単位サイズあたりの価格の大きい順にソート
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((double)goods[j][1] / goods[j][0] < (double)goods[j + 1][1] / goods[j + 1][0])
            {
                int temp_size = goods[j][0];
                int temp_cost = goods[j][1];
                goods[j][0] = goods[j + 1][0];
                goods[j][1] = goods[j + 1][1];
                goods[j + 1][0] = temp_size;
                goods[j + 1][1] = temp_cost;
            }
        }
    }

    // 貪欲法による探索
    int k = 0;
    while (k < n && current_capacity > 0)
    {
        if (goods[k][0] <= current_capacity)
        {
            solution[k] = 1;
            current_capacity -= goods[k][0];
        }
        k++;
    }

    // 結果の出力
    printf("選択された品物:\n");
    for (int i = 0; i < n; i++)
    {
        if (solution[i] == 1)
        {
            printf("サイズ: %d, コスト: %d\n", goods[i][0], goods[i][1]);
        }
    }
}

int main()
{
    int goods[Q][2] = {{12, 4}, {2, 2}, {1, 2}, {1, 1}, {4, 10}}; // [Q][0]にサイズ、[Q][1]にコスト
    int capacity = 15; // ナップサックの容量

    printf("ナップサックの容量: %d\n", capacity);
    knapsack_greedy(Q, capacity, goods);

    return 0;
}
