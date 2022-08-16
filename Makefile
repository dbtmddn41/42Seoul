all:
	gcc deque_oper.c deque.c devide_cases.c devide.c main.c merge.c oper.c oper2.c oper3.c pattern.c utils.c push_swap.h -g
pattern:
	gcc test.c pattern.c utils.c push_swap.h -g -o pattern