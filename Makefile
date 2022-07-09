CXX = g++
CXXFLAGS = -std=gnu++17 -DLOCAL_ -D_GLIBCXX_DEBUG -D_FORTIFY_SOURCE=2 -W -Wall -Wno-unknown-pragmas -O2 -fsanitize=address
INCLUDE = -I ./ac-library/

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^

test%: %.o make_test.o solver.o
	./test.sh $< 20

a: a.o
	./a.o

b: b.o
	./b.o

c: c.o
	./c.o

d: d.o
	./d.o

e: e.o
	./e.o

f: f.o
	./f.o

g: g.o
	./g.o

h: h.o
	./h.o

aca: a.exe
	./a.exe

acb: b.exe
	./b.exe

acc: c.exe
	./c.exe

acd: d.exe
	./d.exe

ace: e.exe
	./e.exe

acf: f.exe
	./f.exe

acg: g.exe
	./g.exe

ach: h.exe
	./h.exe

setup:
	cp template/test.cpp make_test.cpp
	cp template/algorithm.cpp solver.cpp
	cp template/algorithm.cpp a.cpp
	cp template/algorithm.cpp b.cpp
	cp template/algorithm.cpp c.cpp
	cp template/algorithm.cpp d.cpp
	cp template/algorithm.cpp e.cpp
	cp template/algorithm.cpp f.cpp
	cp template/algorithm.cpp g.cpp
	cp template/algorithm.cpp h.cpp

# for marathon 

marathon:
	cp template/test.cpp make_test.cpp
	cp template/algorithm.cpp score_calc.cpp
	cp template/marathon.cpp main.cpp

# run one case
main: main.o
	./main.o < input.txt > output.txt 

clean:
	rm -f *.o *.exe data_structure/*.out graph/*.out math/*.out other_algorithm/*.out string/*.out \
		  a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp g.cpp h.cpp input.txt ans.txt output.txt make_test.cpp solver.cpp \
		  main.cpp score_calc.cpp

.SECONDARY: make_test.o solver.o

.PHONY: test clean