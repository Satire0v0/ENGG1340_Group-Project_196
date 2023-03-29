FLAGS = -pedantic-erros -std=c++0x
# FLAGS = -pedantic-erros -std=c++11
# 0x works on personal computer environment
# 11 works on school environment

map.o: map.cpp map.h
	g++ $(FLAGS) -c $<

main.o: main.cpp map.h
	g++ $(FLAGS) -c $<

main: main.o map.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o main

.PHONY: clean