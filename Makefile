CXX = g++
CXXFLAGS = -std=gnu++17 -DLOCAL_ -W -Wall -Wno-unknown-pragmas -O2 -fsanitize=address

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

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

.PHONY: test clean