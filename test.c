#include <stdio.h>
int main(void)
{
    // 自分の得意な言語で
    // Let's チャレンジ！！
    int a, af = 0;
    int b;
    int swit = 0;
    char arr[31], brr[31];
    for (int i = 0; i < 31; i++)
    {
        arr[i] = 'x';
        brr[i] = 'x';
    }
    char str[1000];
    /*
    A取得部分
    */
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d\n", &a);
    fflush(stdin);
    for (int i = 0; i < a; i++)
    {
        fgets(str, sizeof(str), stdin);
        fflush(stdin);
        sscanf(str, "%d\n", &af);

        arr[af] = 'o';
    }
    /*
    B取得部分
    */
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%d\n", &b);
    fflush(stdin);
    for (int i = 0; i < a; i++)
    {
        fgets(str, sizeof(str), stdin);
        fflush(stdin);
        sscanf(str, "%d\n", &af);
        brr[af] = 'o';
    }

    for (int i = 0; i < 31; i++)
    {
        if (arr[i] == brr[i])
        {
            if (swit % 2 == 0)
            {
                arr[i] = 'A';
                swit++;
            }
            else
            {
                arr[i] = 'B';
                swit++;
            }
        }
        else if (arr[i] == 'o')
        {
            arr[i] = 'A';
        }
        else if (brr[i] == 'o')
        {
            arr[i] = 'B';
        }
    printf("%c\n", arr[i]);


    }
return 0;
}