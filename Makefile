# FLAGS = -pedantic-errors -std=c++0x
FLAGS = -pedantic-errors -std=c++11
# 0x works on personal computer environment
# 11 works on school environment

# ENDNC = -lncurses # Using <ncurses.h> to get keyboard buttion initially

player.o: player.cpp player.h
	g++ $(FLAGS) -c $<

map.o: map.cpp map.h
	g++ $(FLAGS) -c $<

base.o: base.cpp base.h
	g++ $(FLAGS) -c $<

saving.o: saving.cpp saving.h
	g++ $(FLAGS) -c $<

main.o: main.cpp map.h
	g++ $(FLAGS) -c $<

main: main.o map.o base.o player.o saving.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f *.o

.PHONY: clean
