main: main.c
	gcc main.c chapter2\LinkList.c chapter2\SqList.c chapter4\SString.c -o .\target\main.exe
	.\target\main.exe

clean:
	rm -rf target/*.*