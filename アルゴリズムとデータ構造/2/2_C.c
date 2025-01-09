#include <stdio.h>
#include <stdbool.h>

// カードの構造体定義
typedef struct {
    char suit; // カードのスート（ハート、ダイヤなど）
    int value; // カードの値
} Card;

// バブルソートを用いてカードをソートする関数
void bubbleSort(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            if (C[j].value < C[j - 1].value) {
                // カードを交換
                Card temp = C[j];
                C[j] = C[j - 1];
                C[j - 1] = temp;
            }
        }
    }
}

// 選択ソートを用いてカードをソートする関数
void selectionSort(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (C[j].value < C[minj].value) {
                minj = j;
            }
        }
        // カードを交換
        Card temp = C[i];
        C[i] = C[minj];
        C[minj] = temp;
    }
}

// ソートが安定かどうかを確認する関数
bool isStable(Card original[], Card sorted[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (original[i].value == original[j].value) {
                // 元の配列での順序を確認
                int pos1 = -1, pos2 = -1;
                for (int k = 0; k < N; k++) {
                    if (sorted[k].suit == original[i].suit && sorted[k].value == original[i].value) {
                        pos1 = k;
                    }
                    if (sorted[k].suit == original[j].suit && sorted[k].value == original[j].value) {
                        pos2 = k;
                    }
                }
                if (pos1 > pos2) {
                    return false; // 順序が逆転している場合は安定ではない
                }
            }
        }
    }
    return true; // 全ての順序が保たれている場合は安定
}

// カードを出力する関数
void printCards(Card C[], int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%c%d", C[i].suit, C[i].value);
    }
    printf("\n");
}

int main() {
    int N;
    // カードの枚数を読み取る
    scanf("%d", &N);
    Card cards[N], bubbleSorted[N], selectionSorted[N];

    // カードを読み取る
    for (int i = 0; i < N; i++) {
        scanf(" %c%d", &cards[i].suit, &cards[i].value);
        bubbleSorted[i] = cards[i];
        selectionSorted[i] = cards[i];
    }

    // バブルソートと選択ソートを実行
    bubbleSort(bubbleSorted, N);
    selectionSort(selectionSorted, N);

    // ソート結果を出力
    printCards(bubbleSorted, N);
    printf("%s\n", isStable(cards, bubbleSorted, N) ? "Stable" : "Not stable");

    printCards(selectionSorted, N);
    printf("%s\n", isStable(cards, selectionSorted, N) ? "Stable" : "Not stable");

    return 0;
}