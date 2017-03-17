#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int check(int res[1000][10],int sb[10],int k) {
    int i = 0;
    int j;
    while (res[i][0] != -1) {
        for (j = 0;j<k;j++)
            if (res[i][j]!=sb[j])
                break;
        if (j == k)
            return 0;
        i++;
    }
    return 1;
}
void main() {
	srand(time(0));
	int i = 0,j;
	int k;
	int count = 0;
	int p[5] = { 0,0,0,0,0 };
    sqslink x = (sqslink)malloc(sizeof(sqstack));
	int res[1000][10];
    int sb[10];
    int flag = 1;
    printf("Exsist Qeuery:\n");
    res[0][0] = 1;
    res[0][1] = -1;
    res[1][0] = -1;
    while (flag) {
        ClearStack(x);
        count = 0;
        memset(sb,-1,10*sizeof(int));
        memset(p,0,5*sizeof(int));
        for (i = 0;i<10;i++) {
            // 搜索路径
            if (EmptyStack(x))
                sb[i] = 0;
            else
                sb[i] = 1;

            if (!check(res,sb,i+1)) {
                sb[i] = !sb[i];
                if (!check(res,sb,i)) {
                    //GG
                    if (i == 9) {
                        flag = 0;
                        break;
                    }
                    i = i - 1;
                    sb[i] = !sb[i];
                    
                    break;
                }
            }
            // push
            if (sb[i] == 0) {
                for (j = 0;j<5;j++)
                    if (p[j] != 1) {
                        Push(x, j+1);
                        p[j] = 1;
                        break;
                    }
                if (j == 5)
                    break;
            }
            else if (sb[i] == 1) {
                k = Pop(x);
                if (k != -1)
                    printf("pop %d\n", k);
                else 
                    break;
            }

        }
        for (int j = 0;j<i;j++) {
            res[count][j] = sb[j];
            printf(" %d ",sb[j]);
        }
        count ++;
        res[count][0] = -1;
        printf("\n");
        system("pause");
    }

















/*
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
                        break;
                    }
            }
        }
        printf("\n");
        i++;
    }
    i = 0;
    printf("Cannot Exsist Qeuery:\n");
   */
    system("pause");
}
