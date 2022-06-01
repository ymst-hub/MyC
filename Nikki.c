#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define N 256 // 1行の最大文字数(バイト数)
//毎日の日記を作ってみる（GUIなし）
int kakikomi(void);
int yomikomi(void);

int main(void){
    char h[12];
    int i;
    printf("書き込みは1、読み込みは2を選択してください\n");
    fgets(h,sizeof(h),stdin);
    i = atoi(h);
    switch (i)
    {
    case 1:
        kakikomi();
        break;
    case 2:
        yomikomi();
        break;
    
    default:
        printf("数値を入力してください");
        break;
    }

}



int kakikomi(void){
    char mainmemo[N];
    int memonum,i,kaigyou;
    FILE *file;

    time_t timer; 
    struct tm *local;
    /* 年月日と時分秒保存用 */
    int year, month, day, hour, minute, second;
    timer = time(NULL);        /* 現在時刻を取得 */
    local = localtime(&timer);    /* 地方時に変換 */
     /* 年月日と時分秒をtm構造体の各パラメタから変数に代入 */
    year = local->tm_year + 1900;        /* 1900年からの年数が取得されるため */
    month = local->tm_mon + 1;        /* 0を1月としているため */
    day = local->tm_mday;
    hour = local->tm_hour;
    minute = local->tm_min;
    second = local->tm_sec;

    printf("今日のことを記載してください\n");
    fgets(mainmemo,sizeof(mainmemo),stdin);
    file = fopen("Nikki.txt","a");
    fprintf(file,"%d年%d月%d日,",year,month,day);
    fprintf(file,"%s",mainmemo);
    fclose(file);
    printf("書き込みが終了しました");
    return 0;
}

int yomikomi(void){
    char str[N];
    FILE *file;

    printf("ファイルを表示します\n");
    file = fopen("Nikki.txt","r");//あけたファイルを格納してない
    while(fgets(str, N, file) != NULL)
    {
        printf("%s", str);
    }
    fclose(file);
    return 0;

}