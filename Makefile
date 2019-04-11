CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

FILES=bubble_sort.cpp main.cpp

main: $(FILES) 
	@echo ----- creating executable main from main.cpp -----
	g++ -ggdb $(CXXFLAGS) $(FILES) -o main

clean:
	@echo ----- removing executables and possible cores -----
	/bin/rm -rf main.dSYM main *.o *core*