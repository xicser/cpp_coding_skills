#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[50];
    char birth[50];
} Person_t;


/*
5
John  2001/05/12
Tom   1814/09/06
Ann   2121/01/30
James 1814/09/05
Steve 1967/11/20

今天是 2014 年 9 月 6 日
       1814 年 9 月 6 日

*/
int getYear(char *str)
{
    return
    (str[0] - 48) * 1000 +
    (str[1] - 48) * 100 +
    (str[2] - 48) * 10 +
    (str[3] - 48) * 1;
}
int getMonth(char *str)
{
    return
    (str[5] - 48) * 10 +
    (str[6] - 48) * 1;
}
int getDay(char *str)
{
    return
    (str[8] - 48) * 10 +
    (str[9] - 48) * 1;
}

int compare(Person_t *p1, Person_t *p2)
{
    int year1 = getYear(p1->birth);
    int month1 = getMonth(p1->birth);
    int day1 = getDay(p1->birth);

    int year2 = getYear(p2->birth);
    int month2 = getMonth(p2->birth);
    int day2 = getDay(p2->birth);

    if (year1 < year2) return 1;
    else if (year1 > year2) return -1;
    else {
        if (month1 < month2) return 1;
        else if (month1 > month2) return -1;
        else {
            if (day1 < day2) return 1;
            else if (day1 > day2) return -1;
            else return 0;
        }
    }
}
int main()
{
    int valid_flag;
    int N;
    scanf("%d", &N);

    Person_t oldest, youngest, person;
    int valid = 0;

    strcpy(oldest.birth, "2014/09/07");
    strcpy(youngest.birth, "1814/09/05");

    for (int i = 0; i < N; i++) {
        scanf("%s%s", person.name, person.birth);
        int year = getYear(person.birth);
        int month = getMonth(person.birth);
        int day = getDay(person.birth);

        valid_flag = 0;
        if (1814 <= year && year <= 2014) {
            if (year == 2014) {

                if (month < 9) {
                    valid++;
                    valid_flag = 1;
                } else if (month == 9) {
                    if (day <= 6) {
                        valid++;
                        valid_flag = 1;
                    }
                }

            } else if (year == 1814) {

                if (month > 9) {
                    valid++;
                    valid_flag = 1;
                } else if (month == 9) {
                    if (day >= 6) {
                        valid++;
                        valid_flag = 1;
                    }
                }

            } else {
                valid++;
                valid_flag = 1;
            }
        }

        //在有效的里面寻找
        if (valid_flag) {
            if (compare(&oldest, &person) == -1) {
                oldest = person;
            }
            if (compare(&youngest, &person) == 1) {
                youngest = person;
            }
        }
    }

    if (valid) {
        printf("%d", valid);
        printf(" %s %s", oldest.name, youngest.name);
    } else printf("0");


    return 0;
}
