
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_COUNTWORD # -DDEBUG

SRCS = main.c filestr.c
OBJS = $(SRCS:%.c=%.o)

# diff -w means do not care about space

hw08: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw08

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5

test1: hw08
	./hw08 inputs/test1.bin > output1
	diff -w output1 expected/expected1.bin

test2: hw08
	./hw08 inputs/test2.bin > output2
	diff -w output2 expected/expected2.bin

test3: hw08
	./hw08 inputs/test3.bin > output3
	diff -w output3 expected/expected3.bin

test4: hw08
	./hw08 inputs/test4.bin > output4
	diff -w output4 expected/expected4.bin

test5: hw08
	./hw08 inputs/test5.bin > output5
	diff -w output5 expected/expected5.bin

clean: # remove all machine generated files
	rm -f hw08 *.o output*


