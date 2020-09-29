#include <stdio.h>
#include <stdlib.h>

/* 数据类型定义 */
#define io volatile

typedef unsigned char _char;

typedef signed int   s32;
typedef signed short s16;
typedef signed char  s8;

typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef enum {FALSE = 0, TRUE = !FALSE} BoolStatus;
typedef enum {RESET = 0, SET = !RESET} FlagStatus;
typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

#ifndef NULL
#define NULL 0
#endif

//判断num是否是偶数
BoolStatus isEven(s32 num)
{
    return (num % 2 == 0) ? TRUE : FALSE;
}


int main()
{
	s32 a;
	s32 count = 0;

	scanf("%d", &a);

	while (a != 1) {
		count++;
        if (isEven(a) == TRUE) {
            a /= 2;

		} else {
            a = (3 * a + 1) / 2;
		}
	}

    printf("%d\n", count);
    return 0;
}






