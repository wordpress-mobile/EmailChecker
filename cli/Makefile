SOURCES=$(shell find ../common/ -name "*.cpp") email-checker-cli.cpp
OBJS=$(SOURCES:.cpp=.o)
BIN=email-checker-cli
CFLAGS+=-std=c++11 -I../common

$(BIN): $(OBJS)
	clang $(CLFAGS) $(OBJS) -lc++ -o $(BIN)

%.o: %.cpp
	clang $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BIN) $(OBJS)
