make: main.c
	gcc -o build/main main.c -I. -L/usr/local/lib/ -L/usr/include -lssl -lcrypto -lm

# mt: mt.c
# 	gcc -o mt mt.c -L/usr/local/lib/ -I. -L/usr/local/lib/ -L/usr/include -lssl -lcrypto -lm