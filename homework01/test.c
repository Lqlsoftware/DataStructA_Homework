#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void main(){
    srand(time(0));
    FILE *fp3 = fopen("test.txt", "wb");		 //创建文件指针
	if (!fp3) {									  //检查是否正确创建文件
		printf("Writing file error!\n");
		system("PAUSE");
		exit(0);
	}
	int i = 0;
	while (i<20) {
        	char name[6];
        	for (int j=0;j<5;j++)
            		name[j]=65+rand()%25;
		fprintf(fp3, "%d %s %c %s\n",i+1,name,rand()%2?'M':'W',"计1503");       //向文件中写入结果
		++i;
	}
	fclose(fp3);
	printf("Saving successed!----result.txt\n");
	system("pause");
}
