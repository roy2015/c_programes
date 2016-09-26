# CFLAGS inculde头文件

CFLAGS=-I/usr/local/Cellar/glib/2.46.2/include/glib-2.0 \
-I/usr/local/Cellar/glib/2.46.2/lib/glib-2.0/include

edit : main.o testQueue.o testThread.o
	cc `/usr/local/bin/pkg-config --libs --cflags glib-2.0 gthread-2.0` \
main.o testQueue.o testThread.o -o c_program   


main.o : main.c testQueue.h testThread.h
	cc -c $(CFLAGS)  main.c -o  main.o

testThread.o : testThread.c testThread.h
	cc -c $(CFLAGS)  testThread.c -o testThread.o

testQueue.o :  testQueue.c testQueue.h
	cc -c $(CFLAGS) testQueue.c -o testQueue.o

clean :	
	rm c_program  main.o testQueue.o testThread.o

