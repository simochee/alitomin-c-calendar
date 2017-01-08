#include <stdio.h>

int input_year(void);
int input_month(void);
void show_calendar(int, int);
int get_month_last_day(int, int);
int get_week_of_day(int, int);

int main(void) {
    int year, month;
    int i;

    printf("*** カレンダー表示プログラム ***\n");
    printf(">> 表示する西暦年と月を入力してください\n");
    year = input_year();
    // month = input_month();

    // show_calendar(year, month);

    for(i = 1; i <= 12; i++) {
        show_calendar(year, i);
    }

    return 0;
}

int input_year(void) {
    int year;
    printf("西暦年：");
    scanf("%d", &year);
    return year;
}

int input_month(void) {
    int month;
    printf("月：");
    scanf("%d", &month);
    return month;
}

void show_calendar(int y, int m) {
    // 年・月と曜日を表示
    printf("***** %d年 %2d月 ******\n", y, m);
    printf(" 日 月 火 水 木 金 土\n");

    // 月初めの余白を出力
    int w = get_week_of_day(y, m);
    int last = get_month_last_day(y, m);
    int i;
    for(i = 0; i < w; i++) {
        printf("   ");
    }
    for(i = 1; i <= last; i++) {
        printf(" %2d", i);
        if( (i + w) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// 指定された月の日数を取得
int get_month_last_day(int y, int m) {
    int last;
    if(m == 2) {
        if( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            last = 29;
        } else {
            last = 28;
        }
     } else if(m == 4 || m == 6 || m == 9 || m == 11) {
         last = 30;
     } else {
         last = 31;
     }
     return last;
}

// 指定された月の１日の曜日を取得
int get_week_of_day(int y, int m) {
    if(m == 1 || m == 2) {
        y--;
        m += 12;
    }
    return (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + 1) % 7;
}