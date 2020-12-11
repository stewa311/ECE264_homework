WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw18: $(OBJS)
	$(GCC) $(OBJS) -o hw18

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5

test1: hw18
	./hw18 inputs/input1 inputs/test1 out1 > output1

test2: hw18
	./hw18 inputs/input2 | sort > output2
	diff -w output2 expectedhw17/expected2

test3: hw18
	./hw18 inputs/input3 | sort > output3
	diff -w output3 expectedhw17/expected3

test4: hw18
	./hw18 inputs/input4 | sort > output4
	diff -w output4 expectedhw17/expected4

test5: hw18
	./hw18 inputs/input5 | sort > output5
	diff -w output5 expectedhw17/expected5

memory: hw18
	$(VAL) ./hw18 inputs/input5 

clean: # remove all machine generated files
	rm -f hw18 *.o output? vallog testgen
