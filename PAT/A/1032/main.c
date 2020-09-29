#include <stdio.h>
#include <stdlib.h>

//函数执行状态枚举
typedef enum {
	OK = 0,					/* (0) Succeeded */
	ERR1,					/* (1) 错误码1   */
	ERR2,					/* (2) 错误码2   */
	ERR3,					/* (3) 错误码3   */
	ERR4,					/* (4) 错误码4   */
	ERR5,					/* (5) 错误码5   */
} Status;

//数组最大长度设置
#define MAX_SIZE 1000

//元素类型定义
typedef int ElemType;

typedef struct
{
	ElemType data;   //数据
	int		 cur;	 //游标
}component, staticlink[MAX_SIZE];//定义结构体数组


Status InitLink(staticlink space);//初始化静态链表
int    GetLength(staticlink space);//获取长度
Status CreateValue(staticlink space, int num);//创建值
Status InsertNode(staticlink space, int index, ElemType e);//插入节点
Status DeleteNode(staticlink space, int index);//删除节点
Status PrintLink(staticlink space);//输出链表

/**********************************
初始化静态链表
输入值：链表的指针
输出值：状态码
功能：  将所以节点的游标指向后一个结点
***********************************/
Status InitLink(staticlink space)
{
	int i;
	for (i = 0; i<(MAX_SIZE - 1); i++)//遍历除最后一个结点外的所有结点
	{
		space[i].cur = i + 1;//将结点的游标指向下个结点
	}
	//最后一个结点的游标指向第一个结点
	space[MAX_SIZE - 1].cur = 0;

	return OK;
}
/*********************************
分配备用空间
输入值：链表的指针
输出值：备用节点的下标
功能：  获得第一个空闲结点的下标
*********************************/
static int mallocSpace(staticlink space)
{
	int i;

	i = space[0].cur;//取出第一个备用节点

	if (space[0].cur)//如果取出成功
		space[0].cur = space[i].cur;//第一个节点的指针往后移动

	return i;
}
/********************************
获取长度
输入值：链表的指针
输出值：长度值
功能：  返回链表中已用的节点个数
********************************/
int GetLength(staticlink space)
{
	int mov = MAX_SIZE - 1;
	int j = 0;//计数器初始值为0

	while (space[mov].cur)//遍历所有已用节点
	{
		mov = space[mov].cur;
		j++;
	}
	return j;
}
/*********************************
创建值
输入值：链表的指针，初始值个数
输出值：状态码
功能：  为链表初始化指定个数的随机值
*********************************/
Status CreateValue(staticlink space, int num)
{
	int i, mov = MAX_SIZE - 1;

	srand((unsigned int)time(0));//初始化随机数发生器

	space[mov].cur = 1;//最后一个结点的游标指向下标为1的结点
	for (i = 0; i<num; i++)
	{
		mov = space[mov].cur;//移动游标
		space[mov].data = rand() % 100 + 1;//初始化随机值
	}
	space[0].cur = space[mov].cur;//第一个节点游标指向备用节点
	space[mov].cur = 0;//为0标志已用链的结束

	return OK;
}
/*********************************
插入节点
输入值：链表的指针，插入位置(从1开始)
输出值：状态码
功能：  在指定的位置插入指定的值e
*********************************/
Status InsertNode(staticlink space, int index, ElemType e)
{
	int new, mov, i;

	//插入位置检查
	if (index<1 || index>GetLength(space)+1)return ERR1;

	mov = MAX_SIZE - 1;
	new = mallocSpace(space);//获得第一个空闲结点的下标
	if (new)//获取成功
	{
		space[new].data = e;//给新结点填充数据
		for (i = 1; i<index; i++)//定位插入节点的前一节点
			mov = space[mov].cur;

		space[new].cur = space[mov].cur;//连后
		space[mov].cur = new;//接前

		return OK;
	}

	return ERR2;
}
/***********************************
释放节点
输入值：链表的指针，释放节点的位置（要删除结点的位置）
输出值：状态码
功能:   将已用节点释放成备用节点
***********************************/
static Status freeNode(staticlink space, int target)
{
	space[target].cur = space[0].cur;//释放节点连接备用链表
	space[0].cur = target;//第一节点连接释放节点
	return OK;
}
/************************************
删除节点
输入值：链表的指针，删除位置(从1开始)
输出值：状态码
功能：  删除指定的节点
************************************/
Status DeleteNode(staticlink space, int index)
{
	int mov, next, i;

	//删除位置检查
	if (index<1 || index>GetLength(space))return ERR1;

	mov = MAX_SIZE - 1;
	for (i = 1; i<index; i++)//定位删除节点的前一节点
		mov = space[mov].cur;

	next = space[mov].cur;//获取被删节点下标
	space[mov].cur = space[next].cur; //前一节点连接被删节点的游标
	freeNode(space, next);//释放被删节点

	return OK;
}
/**********************************
输出链表
输入值：链表的指针
输出值：状态码
功能：  将链表的值一一输出
**********************************/
Status PrintLink(staticlink space)
{
	int mov = MAX_SIZE - 1;
	while (space[mov].cur)
	{
		mov = space[mov].cur;
		printf("[%d] ", space[mov].data);
	}
	printf("\n");
	return OK;
}


int main()
{
    int first, second, node_cnt;

    scanf("%d %d %d", &first, &second, &node_cnt)

	int num, value, index;
	staticlink L;

	InitLink(L);

	printf("[create]enter num:");
	scanf("%d", &num);
	CreateValue(L, num);
	PrintLink(L);
	printf("len = %d\n",GetLength(L));

	printf("[insert]enter index:");
	scanf("%d", &index);
	printf("[insert]enter value:");
	scanf("%d", &value);
	InsertNode(L, index, value);
	PrintLink(L);
	printf("len =%d\n", GetLength(L));

	printf("[delete]enter index:");
	scanf("%d", &index);
	DeleteNode(L, index);
	PrintLink(L);
	printf("len =%d\n", GetLength(L));


























    return 0;
}
