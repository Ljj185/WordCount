#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int wordsCount=1;
	int charsCount=0;
	char buffer[1000];
	int length;
	int i=0;
	int opt;
	FILE* fp = fopen("data.txt", "r");
	if(fp==NULL) {
		printf("�ļ�Ϊ�ջ��ļ�������");
		return 0;
	}
	while(fscanf(fp, "%s", buffer)!= EOF) {
		for (i=0;buffer[i]!='\0';i++) {
			charsCount++;	
			if(buffer[0]==' '||buffer[0]==','){
				wordsCount=0;
			}
			if((buffer[i]==' '&&buffer[i+1]!=' ')||(buffer[i]==','&&buffer[i+1]!=',')){
				wordsCount++;
			}
		}
	}
	
	
	while((opt=getopt(argc,argv,"cw"))!= -1)
    {
        switch(opt)
        {
            //-w ָ����ʾ������ 
            case 'w': 
                printf("��������%d",wordsCount);	
                break;  
            //-c ָ����ʾ�ַ��� 
            case 'c': 
                printf("�ַ�����%d\n",charsCount);	
                break;
		}
    }
	return 0;
} 
