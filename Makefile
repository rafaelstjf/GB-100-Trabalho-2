Opt:
	g++ -Wall -O2 -c -fopt-info-vec -ftree-vectorize -fopt-info-vec-missed main_opt.cpp
	
Opt_intel:
	icc -O2 -qopt-report=1 -qopt-report-phase=vec -vec main_opt.cpp -o main_opt

Opt_debug:
	g++ -o main -Wall -ggdb main_opt.cpp

Nopt:
	g++ -Wall -O2 -c -fopt-info-vec -ftree-vectorize -fopt-info-vec-missed main_nopt.cpp
	g++ -o main_nopt main_nopt.o

Nopt_debug:
	g++ -o main -Wall -ggdb main_nopt.cpp

Nopt_intel:
	icc -O2 -qopt-report=1 -qopt-report-phase=vec -vec main_nopt.cpp -o main_nopt
