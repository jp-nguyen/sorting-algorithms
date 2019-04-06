CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

main: main.cpp
	@echo ----- creating executable main from main.cpp -----
	g++ -ggdb $(CXXFLAGS) main.cpp -o main


clean:
	@echo ----- removing executables and possible cores -----
	/bin/rm -rf main.dSYM main *.o *core*