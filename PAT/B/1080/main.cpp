#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>


using namespace std;

typedef struct {
    char name[25];
    int Gprog;
    int Gmid;
    int Gfinal;
    int Gscore;
    char is_qualified; //是否合格
    char mid_exist;
    char final_exist;
} Student_t;

int cmp(const void *a, const void *b);
map<string, Student_t>stus;
map<string, Student_t>::iterator stus_it;

Student_t stus_out[10005];
int out_index = 0;

int main()
{
    int P, M, N;
    scanf("%d%d%d", &P, &M, &N);

    for (int i = 0 ; i < P + M + N; i++) {  //读入每个学生的成绩
        char id_str[25];
        int score;
        getchar();
        scanf("%s%d", id_str, &score);

        if (i < P) {
            stus[id_str].Gprog = score;
        } else if (P <= i && i < P + M) {
            stus[id_str].Gmid = score;
            stus[id_str].mid_exist = 1;
        } else {
            stus[id_str].Gfinal = score;
            stus[id_str].final_exist = 1;
        }
    }

    //遍历计算每个学生的成绩
    for (stus_it = stus.begin(); stus_it != stus.end(); stus_it++) {

        if (stus_it->second.mid_exist && stus_it->second.final_exist) { //两门都考了
            if (stus_it->second.Gprog < 200) {
                stus_it->second.is_qualified = 0;
            } else {
                if (stus_it->second.Gmid > stus_it->second.Gfinal) {
                    stus_it->second.Gscore = stus_it->second.Gmid * 0.4 + stus_it->second.Gfinal * 0.6 + 0.5;
                } else {
                    stus_it->second.Gscore = stus_it->second.Gfinal;
                }
                if (stus_it->second.Gscore >= 60) {
                    stus_it->second.is_qualified = 1;
                } else {
                    stus_it->second.is_qualified = 0;
                }
            }
            if (stus_it->second.is_qualified) { //如果合格就放进输出数组
                strcpy(stus_out[out_index].name, stus_it->first.c_str());
                stus_out[out_index].Gprog = stus_it->second.Gprog;
                stus_out[out_index].Gmid = stus_it->second.Gmid;
                stus_out[out_index].Gfinal = stus_it->second.Gfinal;
                stus_out[out_index].Gscore = stus_it->second.Gscore;
                out_index++;
            }
        }
        else if (stus_it->second.mid_exist && stus_it->second.final_exist == 0) { //只考了mid, 没考final
            if (stus_it->second.Gprog < 200) {
                stus_it->second.is_qualified = 0;
            } else {
                if (stus_it->second.Gmid > 0) {
                    stus_it->second.Gscore = stus_it->second.Gmid * 0.4 + 0.5;
                } else {
                    stus_it->second.Gscore = 0;
                }
                if (stus_it->second.Gscore >= 60) {
                    stus_it->second.is_qualified = 1;
                } else {
                    stus_it->second.is_qualified = 0;
                }
            }
            if (stus_it->second.is_qualified) { //如果合格就放进输出数组
                strcpy(stus_out[out_index].name, stus_it->first.c_str());
                stus_out[out_index].Gprog = stus_it->second.Gprog;
                stus_out[out_index].Gmid = stus_it->second.Gmid;
                stus_out[out_index].Gfinal = -1;
                stus_out[out_index].Gscore = stus_it->second.Gscore;
                out_index++;
            }
        }

        else if (stus_it->second.mid_exist == 0 && stus_it->second.final_exist) { //只考了final, 没考mid
            if (stus_it->second.Gprog < 200) {
                stus_it->second.is_qualified = 0;
            } else {
                if (stus_it->second.Gfinal > 0) {
                    stus_it->second.Gscore = stus_it->second.Gfinal;
                } else {
                    stus_it->second.Gscore = 0;
                }
                if (stus_it->second.Gscore >= 60) {
                    stus_it->second.is_qualified = 1;
                } else {
                    stus_it->second.is_qualified = 0;
                }
            }
            if (stus_it->second.is_qualified) { //如果合格就放进输出数组
                strcpy(stus_out[out_index].name, stus_it->first.c_str());
                stus_out[out_index].Gprog = stus_it->second.Gprog;
                stus_out[out_index].Gmid = -1;
                stus_out[out_index].Gfinal = stus_it->second.Gfinal;
                stus_out[out_index].Gscore = stus_it->second.Gscore;
                out_index++;
            }
        }

    }

    qsort(stus_out, out_index, sizeof(Student_t), cmp);

    for (int i = 0 ; i < out_index; i++) { //输出
        cout << stus_out[i].name << " ";
        printf("%d %d %d %d\n",
               stus_out[i].Gprog,
               stus_out[i].Gmid,
               stus_out[i].Gfinal,
               stus_out[i].Gscore);
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    Student_t *stuA = (Student_t *)a;
    Student_t *stuB = (Student_t *)b;

    if (stuA->Gscore > stuB->Gscore) {
        return -1;
    } else if (stuA->Gscore == stuB->Gscore) {

        if (strcmp(stuA->name, stuB->name) > 0) {
            return 1;
        } else {
            return -1;
        }

    } else {
        return 1;
    }
}
/*
2 2 2
11111 200
22222 200
11111 60
22222 60
11111 70
22222 70
*/
