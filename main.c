#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARDS 8
#define TRY_COUNT 10

int main(void) {
  srand((unsigned int)time(NULL));
  int cards[TOTAL_CARDS];
  int input[4];
  int answer[4];

  for (int i = 0; i < TOTAL_CARDS; i++) {
    cards[i] = i;
  }

  for (int i = TOTAL_CARDS - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }
  for (int i = 0; i < 4; i++) {
    answer[i] = cards[i];
  }

  // printf("結果: [%d, %d, %d, %d]\n", answer[0], answer[1], answer[2], answer[3]);

  int hitCount = 0;
  int blowCount = 0;

  for (int i = 0; i < TRY_COUNT; i++) {
    hitCount = 0;
    blowCount = 0;
    printf("%d回目：0〜%dの中から、好きな数字を4つコンマ区切りで入力してください。\n", i + 1, TOTAL_CARDS - 1);
    while (true) {
      int result =
          scanf(" %d,%d,%d,%d", &input[0], &input[1], &input[2], &input[3]);
      if (result == 4) {
        break;
      } else {
        printf("入力が正しくありません。\n");
        while (getchar() != '\n');
      }
    }
    for (int j = 0; j < 4; j++) {
      bool found = false;
      if (input[j] == answer[j]) {
        hitCount++;
      } else {
        for (int k = 0; k < 4; k++) {
          if (input[j] == answer[k]) {
            found = true;
            break;
          }
        }
        if (found) {
          blowCount++;
        }
      }
    }
    printf("結果: %d Hit, %d Blow\n", hitCount, blowCount);
    if (hitCount >= 4) {
      printf("ゲームクリア！");
      return 0;
    }
  }
  printf("答え: [%d, %d, %d, %d]\n", answer[0], answer[1], answer[2], answer[3]);
  printf("ゲームオーバー\nまた挑戦してね");
  return 0;
}