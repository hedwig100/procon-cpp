CXX = g++
CXXFLAGS = -std=gnu++14 -D LOCAL_

a: 
	$(CXX) $(CXXFLAGS) -o a.o a.cpp
	./a.o

b: 
	$(CXX) $(CXXFLAGS) -o b.o b.cpp
	./b.o

c: 
	$(CXX) $(CXXFLAGS) -o c.o c.cpp
	./c.o

d:
	$(CXX) $(CXXFLAGS) -o d.o d.cpp
	./d.o

e:
	$(CXX) $(CXXFLAGS) -o e.o e.cpp
	./e.o

f:
	$(CXX) $(CXXFLAGS) -o f.o f.cpp
	./f.o

g:
	$(CXX) $(CXXFLAGS) -o g.o g.cpp
	./g.o

h:
	$(CXX) $(CXXFLAGS) -o h.o h.cpp
	./h.o

clean:
	rm -f *.o

.PHONY: test clean