#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Memo
""は中の文字のメモリを表す（&とかポインタとかと同じ）だから、*""とすると動く
''は文字リテラルを表す（ベタ書きの文字のこと）

*/


/*
使用する構造体の宣言
*/
typedef struct
{
    int year;
    char name[100];
    double height;
} Kozin; //構造体の宣言
/*
メソッドの宣言
*/
int yomikomi(Kozin *kozin); //現在のcsvを読み込む次追加する行を変換する
int dataSyutoku(int Gyousuu,Kozin *kozin);   //レコード作成処理
int Suzihantei(char h[36]);//処理判定メソッド　1 or -1
int dataTouroku(char Touroku[500]);//csvへの登録処理

/*
メイン処理（呼び出し）
*/
int main(void)
{
    Kozin kozin[100];
    char h[30];
    int Gyousuu, Syori; //この行には差し込める

    Gyousuu = yomikomi(kozin);
    printf("登録を行いますか？\n1:yes\n");
    fgets(h, sizeof(h), stdin);
    Syori = Suzihantei(h);
    switch (Syori)
    {
    case 1:
        dataSyutoku(Gyousuu,kozin);
        break;
    default:
        printf("処理を終了します");
        return -1;
        break;
    }
}

/*
読み込み処理
*/
int yomikomi(Kozin *kozin)
{
    FILE *file = fopen("data.csv", "rt");
    // 100人まで読み込める

    // FILEを開く処理
    if (!file)
    {
        perror("fopen");
        return 0;
    }
    //読み込み処理
    int i; //行数
    int year;
    char name[100];
    double height;
    for (i = 0; fscanf(file, " %d,%[^,],%lf\n", &year, name, &height) != EOF; i++)
    {
        kozin[i].year = year;
        strcpy(kozin[i].name, name);
        // nameはcharの配列のため、strcpyを使用する
        //第一引数コピー先、第二引数コピー元
        kozin[i].height = height;
        // printf("%d,%s,%.2f\n",kozin[i].year,kozin[i].name,kozin[i].height);
        // double型の桁数制限は%.桁数fで記載する。
    }
    fclose(file);
    return i;
}
/*
入力が数字であるかどうかの判定処理
*/
int Suzihantei(char h[36])
{
    int i = 0, j = 0;
    char *err = NULL;
    i = (int)(strtol(h, &err, 10)); // strtolはlongに変換するhは変換する文字、errは最初にエラーになった文字、10は進数
    if (*err != '\n')
    {
        return -1; //異常終了
    }
    return i;
}

/*
csvに登録するデータ作成処理
*/
int dataSyutoku(int Gyousuu,Kozin *kozin){
    int year,Syori;
    char yearc[20],namec[100],name[100],h[36],Touroku[200];
    double height;

    //データ入力
    printf("年齢を入力してください\n");
    fgets(yearc,sizeof(yearc),stdin);
    year = Suzihantei(yearc);
    printf("名前を入力してください\n");
    fgets(namec,sizeof(namec),stdin);
    //fgetsは最終に'\n'が入るため加工する。
    for (int i = 0;namec[i] != '\n';i++)//初期化の宣言を忘れない
    {
        name[i] = namec[i];
    }
    printf("身長を入力してください\n");
    scanf("%lf",&height);
    //メモリオーバーフローの可能性
    printf("下記のデータでよろしいですか。\n");
    sprintf(Touroku,"\n%d,%s,%.2f",year,name,height);//文字を変換するだけ
    printf("%s\n",Touroku);
    printf("1:yes\n");
    fflush(stdin);//バッファの削除（c++)
    fgets(h,sizeof(h),stdin);
    Syori = Suzihantei(h);
    switch (Syori)
    {
    case 1:
        dataTouroku(Touroku);
        return 0;
        break;
    default:
        printf("登録を行いませんでした。");
        return -1;
        break;
    }
}

int dataTouroku(char Touroku[500]){
    FILE *file;
    file = fopen("data.csv","a");
    fprintf(file,"%s",Touroku);
    fclose(file);
    return 0;
}


