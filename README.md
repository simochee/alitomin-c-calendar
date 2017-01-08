# カレンダーを表示するプログラム

プログラムの全体は`calendar.c`を参照。

## 問題(1)

```c
int input_month(void) {
    // (1)
    // input_year()を参考に、月を入力して入力値を返却する
    // 入力された値を保持するための変数をint型で宣言
    int month;
    // ラベルを出力
    printf("月：");
    // 月の値を整数値で入力。入力値はmonthへ代入
    scanf("%d", &month);
    // monthの値を返却
    return month;
}
```

```c
void show_calendar(int y, int m) {
    // (2)
    // 例のプログラムを参考にカレンダーを出力する

    // 年・月と曜日を表示
    printf("***** %d年 %2d月 ******\n", y, m);
    printf(" 日 月 火 水 木 金 土\n");

    // 指定された月の１日の曜日を取得
    int w = get_week_of_day(y, m);
    // 指定された月の日数を取得
    int last = get_month_last_day(y, m);
    int i;
    // 月の初めの余白を出力
    for(i = 0; i < w; i++) {
        printf("   ");
    }
    // 指定された月の日数だけ繰り返す
    for(i = 1; i <= last; i++) {
        // 日付を表示
        printf(" %2d", i);
        // 土曜日だったら改行を出力
        if( (i + w) % 7 == 0) {
            printf("\n");
        }
    }
    // カレンダーの最後に改行を出力
    printf("\n");
}
```

```c
int get_month_last_day(int y, int m) {
    // (3)
    // 指定された月の日数を計算し返却する

    // 返却される日数を保持する変数をint型で宣言
    int last;
    // ２月だったら
    if(m == 2) {
        if( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            // 年が"4で割り切れ100で割り切れない"か"400で割り切れる"ならば閏年なので29を代入
            last = 29;
        } else {
            // 閏年ではないので28を代入
            last = 28;
        }
     } else if(m == 4 || m == 6 || m == 9 || m == 11) {
         // 4月、6月、9月、11月なら30を代入
         last = 30;
     } else {
         // 上記以外なら31を代入
         last = 31;
     }
     // lastの値を返却
     return last;
}
```

```c
int get_week_of_day(int y, int m) {
    // (4)
    // ツェラーの公式を利用して指定された月の１日目の曜日を取得する

    // ツェラーさん最強説
    if(m == 1 || m == 2) {
        y--;
        m += 12;
    }
    return (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + 1) % 7;
}
```

## 問題(2)

> 部品化することで容易にプログラムを書き換えることができるようになる。
> このプログラムを修正して指定した年の１年のカレンダーを表示されるようにするには、どこを編集すれば良いか。

年・月を指定するカレンダーの`main()`の中身は以下のとおり。

```c
int main(void) {
    int year, month;

    printf("*** カレンダー表示プログラム ***\n");
    printf(">> 表示する西暦年と月を入力してください\n");
    year = input_year();
    month = input_month();

    show_calendar(year, month);

    return 0;
}
```

ここで、`month = input_month()`で月を指定しているので、ここを繰り返し文に書き換えれば、年間カレンダーが出力される。

```c
// 変更後
int main(void) {
    int year, month;
    // 追加：for文で使うための変数
    int i;

    printf("*** カレンダー表示プログラム ***\n");
    printf(">> 表示する西暦年と月を入力してください\n");
    year = input_year();
    // 削除
    // month = input_month();

    // 追加：入力の代わりに1〜12を繰り返す
    for(i = 1; i <= 12; i++) {
        show_calendar(year, i);
    }

    return 0;
}
```