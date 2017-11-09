.PHONY: greet build rebuild run clean 

greet:
	@echo "Terminating make - please specify target explicitly"
	@echo "    build   : fast rebuild / build"
	@echo "    rebuild : full rebuild"
	@echo "    run     : run after fast rebuild / build"
	@echo "    clean   : perform full clean"
	
build: lab4
rebuild: clean lab4
run: build
	./lab4
	
lab4: lab4.o
	gcc -o lab4 lab4.o -lpthread

lab4.o: lab4.c
	gcc -c -o lab4.o lab4.c 
clean:
	rm -rvf *.o lab4 log


