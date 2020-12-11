
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose
TESTFALGS =

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

# diff -w means do not care about space

hw19: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw19

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5 test6

test1: hw19
	./hw19 inputs/maze1 > output1
	diff -w output1 expected/expected1

test2: hw19
	./hw19 inputs/maze2 > output2
	diff -w output2 expected/expected2

test3: hw19
	./hw19 inputs/maze3 > output3
	diff -w output3 expected/expected3
	
test4: hw19
	./hw19 inputs/maze4 > output4
	diff -w output4 expected/expected4
	
test5: hw19
	./hw19 inputs/maze5 > output5
	diff -w output5 expected/expected5
	
test6: hw19
	./hw19 inputs/maze6 > output6
	diff -w output6 expected/expected6
	
test7: hw19
	./hw19 inputs/maze7 > output7
	diff -w output7 expected/expected7
	
test8: hw19
	./hw19 inputs/maze8 > output8
	diff -w output8 expected/expected8
	
memory: hw19
	$(VAL) ./hw19 inputs/maze1 
	

clean: # remove all machine generated files
	rm -f hw19 *.o output*


