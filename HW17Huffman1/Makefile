WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw17: $(OBJS)
	$(GCC) $(OBJS) -o hw17

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5

test1: hw17
	./hw17 inputs/input1 | sort > output1
	diff -w output1 expected/expected1

test2: hw17
	./hw17 inputs/input2 | sort > output2
	diff -w output2 expected/expected2

test3: hw17
	./hw17 inputs/input3 | sort > output3
	diff -w output3 expected/expected3

test4: hw17
	./hw17 inputs/input4 | sort > output4
	diff -w output4 expected/expected4

test5: hw17
	./hw17 inputs/input5 | sort > output5
	diff -w output5 expected/expected5

memory: hw17
	$(VAL) ./hw17 inputs/input5 

clean: # remove all machine generated files
	rm -f hw17 *.o output? vallog testgen
