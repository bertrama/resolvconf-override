localize.so:
	gcc -Wall -g -shared -fPIC -ldl -o localize.so localize.c

clean:
	rm localize.so
