#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 32
#define TestDel_Sno 14

// 定义顺序表存储空间
typedef struct {
	int Sno;
	char Name[20];
	char sex;
	char Class[20];
}student;
typedef struct {
	student stu[MAX_NUM];
	int last;
}sqlist, *sqlink;

// 从test.txt中读取学生信息
void read(sqlink L, student* TestAdd) {
	FILE* fp = fopen("test.txt", "r");
	if (!fp) {
		printf("Reading file error!\n");
		system("PAUSE");
		exit(0);
	}
	int i = 0;
	L->last = 0;
	while (i<20) {
		fscanf(fp, "%d %s %c %s\n", &(L->stu[i].Sno), L->stu[i].Name, &(L->stu[i].sex), L->stu[i].Class);
		++i;
		L->last++;
	}
	fscanf(fp, "%d %s %c %s\n", &((*TestAdd).Sno), (*TestAdd).Name, &((*TestAdd).sex), (*TestAdd).Class);
	fclose(fp);
}

// 按学号从小到大插入顺序表
void insert_s(sqlink S, student x) {
	// 判断顺序表是否还有空间
	if (S->last >= MAX_NUM) {
		return;
	}
	int i = 0;
	while (i<S->last && x.Sno > S->stu[i].Sno) {
		i++;
	}
	// 序号后面的内存后挪一个student大小
	for (int j = S->last - 1;j >= i;j--) {
		memcpy(&(S->stu[j + 1]), &(S->stu[j]), sizeof(student));
	}
	// 将新的数据拷贝进顺序表空间
	memcpy(&(S->stu[i]), &(x), sizeof(student));
	S->last++;
}

// 删除 Sno = y 的记录
void delete_s(sqlink S, int y) {

	// 表中没有数据
	if (S->last == 0) {
		return;
	}

	// 查找Sno = y的记录
	int left = 0;
	int right = S->last - 1;
	int result;
	while (1) {
		if (left == right) {
			if (y == S->stu[left].Sno) {
				result = left;
				break;
			}
			return;
		}
		if (y < S->stu[(left + right) / 2].Sno) {
			right = (left + right) / 2;
		}
		else if (y > S->stu[(left + right) / 2].Sno) {
			left = (left + right) / 2;
		}
		else {
			result = (left + right) / 2;
			break;
		}
	}

	// 序号后面的内存前挪一个student大小
	for (int i = result;i < S->last;i++) {
		memcpy(&(S->stu[i]), &(S->stu[i + 1]), sizeof(student));
	}
	S->last--;
}

void main() {

	// 申请顺序表空间
	sqlink L = (sqlink)malloc(sizeof(sqlist));

	// 读取测试数据
	student TestAdd;
	read(L, &TestAdd);

	// 输出测试数据
	printf("Before:\n");
	printf("Sno   Name     Sex    Class\n\n");
	int i = 0;
	while (i<L->last) {
		printf("%04d  %-8s %-6s %s\n", L->stu[i].Sno, L->stu[i].Name, L->stu[i].sex == 'M' ? "MEN" : "WOMEN", L->stu[i].Class);
		++i;
	}
	printf("\n---------------------------\n");

	// 进行运算
	insert_s(L, TestAdd);
	delete_s(L, TestDel_Sno);

	// 输出结果
	printf("After:\n");
	printf("Sno   Name     Sex    Class\n\n");
	i = 0;
	while (i<L->last) {
		printf("%04d  %-8s %-6s %s\n", L->stu[i].Sno, L->stu[i].Name, L->stu[i].sex == 'M' ? "MEN" : "WOMEN", L->stu[i].Class);
		++i;
	}

	system("pause");
}