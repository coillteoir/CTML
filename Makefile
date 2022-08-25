CC=gcc
CFLAGS= -Wall -Wextra -Werror -o
OUT=hello.html
BIN=bin/ctml
SRC=src/main.c
BRS=firefox
TEST=src/demo.ctml
INST=/usr/bin/ctml


compile:
	$(CC) $(CFLAGS) $(BIN) $(SRC) 

run:
	./$(BIN) $(TEST) $(OUT)

both:
	$(CC) $(CFLAGS) $(BIN) $(SRC)  	
	$(BIN) $(TEST) $(OUT)

test:
	$(BRS) $(OUT) &

install:
	$(CC) $(CFLAGS) $(INST) $(SRC)  

