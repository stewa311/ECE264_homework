
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_CALCULATE -DTEST_READLIST -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETENODE # -DDEBUG

SRCS = main.c calculate.c calculate.h list.c list.h
OBJS = $(SRCS:%.c=%.o)

# diff -w means do not care about space

hw13: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw13

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5

test1: hw13
	./hw13 inputs/test1 > output1
	diff -w output1 expected/expected1

test2: hw13
	./hw13 inputs/test2 > output2
	diff -w output2 expected/expected2

test3: hw13
	./hw13 inputs/test3 > output3
	diff -w output3 expected/expected3

test4: hw13
	./hw13 inputs/test4 > output4
	diff -w output4 expected/expected4

test5: hw13
	./hw13 inputs/test5 > output5
	diff -w output5 expected/expected5

clean: # remove all machine generated files
	rm -f hw13 *.o output*


