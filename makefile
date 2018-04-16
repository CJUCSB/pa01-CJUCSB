stattest: stats.o
	g++ stattest.cpp stats.o -o stattest
stats.o: stats.cpp stats.h
	g++ stats.cpp -c
statexam: stats.o
	g++ statexam.cpp stats.o -o statexam
clean_test:
	rm stattest stats.o
clean_exam:
	rm statexam stats.o
clean:
	rm stats.o stattest statexam
