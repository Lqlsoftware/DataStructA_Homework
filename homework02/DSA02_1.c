/*
随机输出可能和不可能的出栈序列
@Auther Robin Lu
(这些方法写的我真是日了狗了 woc我为何不用java写)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  MAXSIZE 5              //栈最大容量
#define datatype int
typedef  struct {
	datatype  data[MAXSIZE];    //栈的存储空间
	int top;                    //栈顶指针（或游标）
} sqstack, *sqslink;             //顺序栈说明符

int EmptyStack(sqslink s) {
	if(s->top < 0)
		return 1;   //栈空返回1
	else
		return 0;                     //栈非空返回0
}

int Push(sqslink s, datatype x) {
	if (s->top >= MAXSIZE - 1)
		return -1;          //栈满溢出
	s->top++;
	s->data[s->top] = x;    //x进栈
	return 0;               //成功
}

int Pop(sqslink s) {
	if (EmptyStack(s))
		return -1;          //栈空，返回-1
	s->top--;
	return s->data[s->top + 1];
}

void ClearStack(sqslink s) {
	s->top = -1;
}

int GetTop(sqslink s) {
	if (EmptyStack(s))
		return -1;          //栈空，返回-1
	return s->data[s->top];
}

void main() {
	srand(time(0));
	int i = 0;
	int k;
	int count = 0;
	int p[5] = { 1,1,1,1,1 };
	sqslink x = (sqslink)malloc(sizeof(sqstack));
    printf("Exsist Qeuery:\n");
    while (i<5) {
        ClearStack(x);
        count = 0;
        for (int j = 0;j<5;j++)
            p[j] = 1;
        while (count != 5) {
            // pop
            if (rand() % 2 == 1) {
                k = Pop(x);
                if (k != -1) {
                    p[k - 1]=1;
                    printf("pop %d\n", k);
                    count++;
                }
            }
            // Push
            else {
                for (int j = 0;j<5;j++)
                    if (p[j] != 0) {
                        Push(x, j+1);
                        p[j] = 0;
                    }
            }
        }
        printf("\n");
        i++;
    }
    i = 0;
    printf("Cannot Exsist Qeuery:\n");
    while (i<5) {
        ClearStack(x);
        count = 0;
        for (int j = 0;j<5;j++)
            p[j] = 1;
        while (count != 5) {
            // pop
            if (rand() % 2 == 1) {
                k = Pop(x);
                if (k != -1) {
                    p[k - 1]=1;
                    if (GetTop(x)) {
                        printf("pop %d\n", GetTop(x));
                        count++;
                    }
                }
            }
            // Push
            else {
                for (int j = 0;j<5;j++)
                    if (p[j] != 0) {
                        Push(x, j+1);
                        p[j] = 0;
                    }
            }
        }
        printf("\n");
        i++;
    }
    system("pause");
}
