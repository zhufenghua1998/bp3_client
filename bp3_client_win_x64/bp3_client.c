#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 使用curl.h的绝对路径，请自行修改
#include <F:/curl-7.80.0-win64-mingw/include/curl/curl.h>

int main(void)
{
	// 完整格式： 	system("bin\\curl --connect-timeout 10 -C - -o \"download\\文件名\" -L -X GET \"链接\" -H \"User-Agent: pan.baidu.com\"");

	
	// 1.获取bp3链接：
	char bp3_link[2000] = "";
	printf("请输入浏览器复制bp3的链接：\n");
	printf("提示：如果右键无法粘贴，请点击顶部=》编辑=》粘贴...\n");
	gets(bp3_link);
	// 2.分割链接和文件名
	
	char split[10] = "|";
	
	char *url = "";
	char *fileName = "";
	
	char *sub = strtok(bp3_link,split);
	
	fileName = sub;
	if(sub){  // 第一次分割，得到Url
		url = sub;  
        sub=strtok(NULL,split);
	}
	if(sub){  // 第二次分割，得到fileName
		fileName=sub;
	}

	// 尝试拼接cURL语句
	char curl[2000] = "";
	
	strcat(curl,"bin\\curl --connect-timeout 10 -C - -o \"download\\");
	strcat(curl,fileName);
	strcat(curl,"\" -L -X GET \"");
	strcat(curl,url);
	strcat(curl,"\" -H \"User-Agent: pan.baidu.com\"");
	
	
	//printf("%s",curl);
	printf("文件开始下载...\n");
	printf("提示：请先不要丢弃链接，如果卡住不动，请直接关闭窗口重新打开并粘贴可断点续传...\n");
	
	// 4.执行curl
	system(curl);
	
	printf("下载完毕，请关闭本窗口，并在download目录查看已下载文件...\n");
	printf("注意：如果download文件下中已存在该文件且字节大小一致，不会执行下载...\n");
	printf("无论是否下载成功，再次使用请重新打开本程序...\n");
    system("pause");
}
