#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//+1.23400E+10
//0.00123400


//+1.200000000E+0543


//+1.2456789E-05
//+12000000000
char input_str[100000];

int main()
{
    int bits = 0;
    int E_pos;
    int index;
    int len;
    gets(input_str);
    len = strlen(input_str);

    if (input_str[0] == '-') printf("%c", input_str[0]);
    //获取指数
    for (int i = len - 1; i >= 0; i--) {
        if (input_str[i] == 'E') {
            E_pos = i;
            for (int j = i + 2; j < len; j++) {
                bits++;
            }

            switch(bits) {
                case 2:
                    index = (input_str[len - 1] - 48) + (input_str[len - 2] - 48) * 10;
                    break;
                case 3:
                    index = (input_str[len - 1] - 48) + (input_str[len - 2] - 48) * 10 +
                    (input_str[len - 3] - 48) * 100;
                    break;
                case 4:
                    index = (input_str[len - 1] - 48) + (input_str[len - 2] - 48) * 10 +
                    (input_str[len - 3] - 48) * 100 + (input_str[len - 4] - 48) * 1000;
                    break;
                default:break;
            }

            break;
        }
    }

    if (index == 0) {
        for (int i = 1; input_str[i] != 'E'; i++) {
            printf("%c", input_str[i]);
        }
        return 0;
    }

    if (input_str[E_pos + 1] == '-') { //左移小数点
        printf("0.");
        for (int i = 0; i < index - 1; i++) printf("0");
        for (int i = 1; input_str[i] != 'E'; i++) {
            if (input_str[i] != '.') printf("%c" ,input_str[i]);
        }
        printf("\n");
//+1.200000000E+05
    } else if (input_str[E_pos + 1] == '+') { //右移小数点
        int len_tmp = len - 5 - bits; //23400

        if (index == len_tmp) {
            for (int i = 1; input_str[i] != 'E'; i++) {
                if (input_str[i] != '.') printf("%c" ,input_str[i]);
            }
        } else if (index > len_tmp) {
            for (int i = 1; input_str[i] != 'E'; i++) {
                if (input_str[i] != '.') printf("%c" ,input_str[i]);
            }
            for (int i = 0; i < index - len_tmp; i++) printf("0");
        } else {
            printf("%c", input_str[1]);
            for (int i = 0; i < index; i++) {
                printf("%c", input_str[i + 3]);
            }
            printf(".");
            for (int i = 0; i < len_tmp - index; i++) {
                printf("%c", input_str[i + 3 + index]);
            }
        }

        printf("\n");

    }


    return 0;
}
