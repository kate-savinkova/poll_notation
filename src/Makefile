GCC = gcc -Wall -Wextra -Werror
POLL = ../bin/graph

all: poll
clean: 
	rm -rf *.out *.o $(POLL)
rebuild: clean all

poll: graph.c poll_notation.c parcing.c stack.c drawing.c calc.c
	$(GCC) $^ -o $(POLL) 

run: $(POLL)
	./$(POLL)