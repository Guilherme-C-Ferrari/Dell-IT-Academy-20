@echo off
g++ -std=c++17 -c "./src/Source Files/bet.cpp"
@echo off
g++ -std=c++17 -c "./src/Source Files/bettor.cpp"
@echo off
g++ -std=c++17 -c "./src/Source Files/bookmaker.cpp"
@echo off
g++ -std=c++17 -c "./src/Source Files/edition.cpp"
@echo off
g++ -std=c++17 -c "./src/Source Files/main.cpp"
@echo off
g++ -o prog main.o bet.o bettor.o bookmaker.o edition.o 
@echo off
del main.o
@echo off
del bet.o
@echo off
del bettor.o
@echo off
del bookmaker.o
@echo off
del edition.o