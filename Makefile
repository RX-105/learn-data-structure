main: main.c SqList.c
	gcc main.c SqList.c LinkList.c -o .\target\main.exe
	.\target\main.exe

clean:
	rm -rf target/*.*