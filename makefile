foo:
	gcc -o strTest strfuncTest.c

clean:
	rm *~

run: strTest
	./strTest
