Opt:
	g++ -Wall -O2 -c -fopt-info-vec -ftree-vectorize -fopt-info-vec-missed main_opt.cpp
	g++ -o main_opt main_opt.o

Opt_debug:
	g++ -o main -Wall -ggdb main_opt.cpp

Nopt:
	g++ -Wall -O2 -c -fopt-info-vec -ftree-vectorize -fopt-info-vec-missed main_nopt.cpp
	g++ -o main_nopt main_nopt.o

Nopt_debug:
	g++ -o main -Wall -ggdb main_nopt.cpp
