#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    double score;           //满分值
    int choice_count;       //选项个数
    int right_choice_count; //正确选项个数
    char right_choice[10];  //所有正确选项
    int wrong_times[5];     //每个选项(a, b, c, d, e)错的次数
    int order;              //题目编号
} Question_t;


typedef struct {
    int order;
    char choice;
    int times;
} OutPut_t;


/*
返回1, 全对
返回2, 部分对
返回3, 错
*/
int getScoreAndWrong(Question_t *quest, char *answer)
{
    int has_more_choice = 0; //默认没有多选的
    int has_less_choice = 0; //默认没有漏选的
    int righ_array[5] = {0};
    int ans_array[5] = {0};
    int res_array[5] = {0};

    for (int i = 0; quest->right_choice[i] != 0; i++) { //构造正确答案数组
        righ_array[quest->right_choice[i] - 97] = 1;
    }
    for (int i = 0; answer[i] != 0; i++) { //构造答题者答题结果数组
        ans_array[answer[i] - 97] = 1;
    }

    for (int i = 0; i < 5; i++) { //两数组相减
        res_array[i] = righ_array[i] - ans_array[i];
    }


    //遍历结果
    for (int i = 0; i < 5; i++) {
        if (res_array[i] < 0) {  //多选
            has_more_choice = 1;
            quest->wrong_times[i]++;
        } else if (res_array[i] > 0) { //漏选
            has_less_choice = 1;
            quest->wrong_times[i]++;
        }
    }
    if (has_more_choice) { //有多选的
        return 3;
    } else if (has_less_choice) { //有漏选的
        return 2;
    } else {
        return 1;
    }
}
//把每个题目错的选项存到outputs里
int InsertOutput(OutPut_t *out, Question_t *quest, int question_count)
{
    int index = 0;

    for (int i = 0; i < question_count; i++) {
        for (int j = 0; j < 5; j++) {
            if (quest[i].wrong_times[j] != 0) {
                out[index].choice = j + 97;
                out[index].order = i + 1;
                out[index].times = quest[i].wrong_times[j];
                index++;
            }
        }
    }

    return index;
}

int cmp (const void *a, const void *b)
{
	OutPut_t *outA = (OutPut_t *)a;
	OutPut_t *outB = (OutPut_t *)b;

    if (outA->times > outB->times) {
        return -1;
    } else if (outA->times == outB->times) {

        if (outA->order > outB->order) {
            return 1;
        } else if (outA->order == outB->order) {

            if (outA->choice > outB->choice) {
                return 1;
            } else {
                return -1;
            }

        } else {
            return -1;
        }

    } else {
        return 1;
    }
}

int main()
{
    int i, j, k;
    int studens_count, question_count;
    double got_score;
    int choice_count;
    int no_one_wrong = 1; //默认没有人错

    scanf("%d%d", &studens_count, &question_count);

    double outvalue[studens_count];
    int out_index = 0;;
    Question_t questions[question_count];

    for (i = 0; i < question_count; i++) {
        scanf("%lf %d %d", &questions[i].score, &questions[i].choice_count, &questions[i].right_choice_count);
        for (j = 0; j < questions[i].right_choice_count; j++) {
            scanf(" %c", &questions[i].right_choice[j]);
        }
        questions[i].right_choice[j] = 0; //字符串末尾
        for (j = 0; j < 5; j++) {
            questions[i].wrong_times[j] = 0;     //默认没人错
        }
        questions[i].order = i + 1;       //题目编号
    }

    for (i = 0; i < studens_count; i++) {

        getchar();
        got_score = 0;
        for (j = 0; j < question_count; j++) {

            scanf("(%d", &choice_count);
            char answer[choice_count + 1];
            for (k = 0; k < choice_count; k++) {
                if (k == choice_count - 1) {
                    scanf(" %c)", &answer[k]);
                } else {
                    scanf(" %c", &answer[k]);
                }
            }
            answer[k] = 0; //字符串末尾

            if (j != question_count - 1) {
                getchar();
            }

            //统计该题的对错情况
            int res = getScoreAndWrong(&questions[j], answer);
            if (res == 1) { //答案完全正确
                got_score += questions[j].score;
            } else if (res == 2) {  //部分正确
                got_score += questions[j].score / 2.0;
            } else if (res == 3) { //错误
                no_one_wrong = 0;
            }
        }
//        printf("%.1lf\n", got_score);
        outvalue[out_index++] = got_score; //记录每个学生的成绩
    }

    //输出分数结果
    for (i = 0; i < out_index; i++) {
        printf("%.1lf\n", outvalue[i]);
    }
    if (no_one_wrong) {
        printf("Too simple\n");
    } else {

        //把每个题目错的选项存到outputs里
        OutPut_t outputs[5 * question_count];
        int outputs_len = InsertOutput(outputs, questions, question_count);

//        printf("outputs_len = %d\n", outputs_len);


        //按每个题的错误选项排序
        qsort(outputs, outputs_len, sizeof(OutPut_t), cmp);
        for (i = 0; i < outputs_len; i++) {
			if (outputs[0].times != outputs[i].times) {
                break;
			} else {
                printf("%d %d-%c\n", outputs[i].times, outputs[i].order, outputs[i].choice); //2 2 3 4
			}
        }
    }

    return 0;
}


