CC=gcc
OUT=hello.html
BIN=bin/ctml
SRC=src/main.c
BRS=firefox
TEST=src/demo.ctml
INST=/usr/bin/ctml


compile:
	$(CC) -o $(BIN) $(SRC) 

run:
	./$(BIN) $(TEST) $(OUT)

both:
	$(CC) -o $(BIN) $(SRC)  	
	$(BIN) $(TEST) $(OUT)

test:
	$(BRS) $(OUT) &

install:
	$(CC) -o $(INST) $(SRC)  

