runStackWithArray: stackDriver.o stack_array.o
	gcc -o runStackWithArray stackDriver.o stack_array.o
	./runStackWithArray

runStackWithLL: stackDriver.o stack_ll.o
	gcc -o runStackWithLL stackDriver.o stack_ll.o

stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c

stack_array.o: stack_array.c stack.h heap_usage.c
	gcc -c stack_array.c heap_usage.c

stack_ll.o: stack_ll.c stack.h linked_list.h heap_usage.h
	gcc -c stack_ll.c linked_list.c heap_usage.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

clean:
	rm -f *.o runStackWithArray