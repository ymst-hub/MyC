#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 32

int hantei(char h[N]);
int sisoku(int sum, int k, int kigou);

int main(void)
{
    int j = 0, i, c, sum = 0, kigou = 0;
    char h[N],k[N],*err = NULL;
    
    while (1){//無限ループ
        printf("計算する文字を入力してください\n終了する場合文字を入力してください\n");
        fgets(h, sizeof(h), stdin);
        j = hantei(h);
        if(j == -1) break;
        printf("1:足し算、2:引き算、3:掛け算、4:割り算\n終了する場合文字またはその他の数字を入力してください\n");
        fgets(k, sizeof(k), stdin);//四則演算の記号の取得
        kigou = hantei(k);
        sum = sisoku(sum, j, kigou);
    } 
    printf("計算結果は%dです", sum);

    return 0;
}

int hantei(char h[N])
{
    int i = 0, j = 0;
    char *err = NULL;
    i = (int)(strtol(h, &err, 10)); // strtolはlongに変換するhは変換する文字、errは最初にエラーになった文字、10は進数
    if (*err == '\n')
    { // fgetsは末尾に\nが入る。
        printf("正常に読み込まれました\n");
    }
    else
    {
        printf("終了します\n");
        return -1; //異常終了
    }
    return i;
}

int sisoku(int sum, int k, int kigou)
{
    switch (kigou)
    {
    case 1:
        sum += k;

        break;
    case 2:
        sum -= k;
        break;
    case 3:
        sum *= k;
        break;
    case 4:
        sum /= k;
        break;

    default:
        printf("無効な値が入力されました。");
        break;
    }
    return sum;    
}
