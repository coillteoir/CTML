
CC=gcc
OUT=hello.html

compile:
	$(CC) -o bin/ctml src/main.c 

run:
	./bin/ctml src/demo.ctml $(OUT)

both:
	$(CC) -o bin/ctml src/main.c 	
	./bin/ctml src/demo.ctml $(OUT)

test:
	firefox $(OUT) &

install:
	$(CC) -o bin/ctml src/main.c 
	mv ./bin/ctml /usr/bin/ctml

