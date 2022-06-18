CXX = g++
CXXFLAGS = -std=gnu++17 -DLOCAL_ -D_GLIBCXX_DEBUG -D_FORTIFY_SOURCE=2 -W -Wall -Wno-unknown-pragmas -O2 -fsanitize=address
INCLUDE = -I .

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
	cp template_test.cpp make_test.cpp
	cp template.cpp solver.cpp
	cp template.cpp a.cpp
	cp template.cpp b.cpp
	cp template.cpp c.cpp
	cp template.cpp d.cpp
	cp template.cpp e.cpp
	cp template.cpp f.cpp
	cp template.cpp g.cpp
	cp template.cpp h.cpp

clean:
	rm -f *.o *.exe data_structure/*.out graph/*.out math/*.out other_algorithm/*.out String/*.out \
		  a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp g.cpp h.cpp input.txt ans.txt output.txt make_test.cpp solver.cpp

.SECONDARY: make_test.o solver.o

.PHONY: test clean