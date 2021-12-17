@echo off

echo "开始编译bp3_client..."

gcc bp3_client.c -o bp3_client.exe -Wall -l libcurl

echo "bp3_client.exe已生成..."

pause