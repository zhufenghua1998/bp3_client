#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ʹ��curl.h�ľ���·�����������޸�
#include <F:/curl-7.80.0-win64-mingw/include/curl/curl.h>

int main(void)
{
	// ������ʽ�� 	system("bin\\curl --connect-timeout 10 -C - -o \"download\\�ļ���\" -L -X GET \"����\" -H \"User-Agent: pan.baidu.com\"");

	
	// 1.��ȡbp3���ӣ�
	char bp3_link[2000] = "";
	printf("���������������bp3�����ӣ�\n");
	printf("��ʾ������Ҽ��޷�ճ������������=���༭=��ճ��...\n");
	gets(bp3_link);
	// 2.�ָ����Ӻ��ļ���
	
	char split[10] = "|";
	
	char *url = "";
	char *fileName = "";
	
	char *sub = strtok(bp3_link,split);
	
	fileName = sub;
	if(sub){  // ��һ�ηָ�õ�Url
		url = sub;  
        sub=strtok(NULL,split);
	}
	if(sub){  // �ڶ��ηָ�õ�fileName
		fileName=sub;
	}

	// ����ƴ��cURL���
	char curl[2000] = "";
	
	strcat(curl,"bin\\curl --connect-timeout 10 -C - -o \"download\\");
	strcat(curl,fileName);
	strcat(curl,"\" -L -X GET \"");
	strcat(curl,url);
	strcat(curl,"\" -H \"User-Agent: pan.baidu.com\"");
	
	
	//printf("%s",curl);
	printf("�ļ���ʼ����...\n");
	printf("��ʾ�����Ȳ�Ҫ�������ӣ������ס��������ֱ�ӹرմ������´򿪲�ճ���ɶϵ�����...\n");
	
	// 4.ִ��curl
	system(curl);
	
	printf("������ϣ���رձ����ڣ�����downloadĿ¼�鿴�������ļ�...\n");
	printf("ע�⣺���download�ļ������Ѵ��ڸ��ļ����ֽڴ�Сһ�£�����ִ������...\n");
	printf("�����Ƿ����سɹ����ٴ�ʹ�������´򿪱�����...\n");
    system("pause");
}
