all:
	g++ regex_matching.cpp
run:
	.\a.exe
debug:
	g++ regex_matching.cpp -g
	gdb .\a.exe
