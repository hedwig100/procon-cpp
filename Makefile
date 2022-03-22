CXX = g++
CXXFLAGS = -std=gnu++17 -DLOCAL_ -D_GLIBCXX_DEBUG -D_FORTIFY_SOURCE=2 -W -Wall -Wno-unknown-pragmas -O2 -fsanitize=address

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

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
	rm -f *.o

.SECONDARY: make_test.o solver.o

.PHONY: test clean