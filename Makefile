CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

ifeq ($(shell uname -s),Linux)
	CFLAGS += -lm
endif

TEST_FLAGS = -lcheck
ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lrt -lsubunit -lpthread -lm
endif

RUN_TEST = ./s21_test/run_test.c
TEST_FUNC = $(wildcard ./s21_test/test_func/*.c)
SOURCE = s21_*.c
OBJECTS = s21_*.o

all: s21_matrix.a

s21_matrix.a:

	$(CC) -c $(SOURCE)
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a
	rm -rf *.o

test: s21_matrix.a

	$(CC) $(RUN_TEST) $(TEST_FUNC)  s21_matrix.a $(TEST_FLAGS) -o test
	./test

clean:
	rm -rf *.o *.out *.a
	rm -rf *.gcno *.gcda *.gcov_report
	rm -rf *.info
	rm -rf s21_test_gcov
	rm -rf ./report/
	rm -rf test

gcov_report:

	gcc --coverage $(SOURCE) $(RUN_TEST) $(TEST_FUNC) -o s21_test_gcov $(TEST_FLAGS)
	./s21_test_gcov
	lcov -t "s21_test_gcov" -o s21_test_gcov.info -c -d .
	genhtml -o report s21_test_gcov.info
	open ./report/index.html

make_clang:

	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i ./s21_test/*.c ./s21_test/*.h
	clang-format -style=Google -i ./s21_test/test_func/*.c 

check_clang:

	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n ./s21_test/*.c ./s21_test/*.h
	clang-format -style=Google -n ./s21_test/test_func/*.c 

rebuild: clean all