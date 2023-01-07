CXX = g++
CXXFLAGS = -std=gnu++17 -DLOCAL_ -D_GLIBCXX_DEBUG -D_FORTIFY_SOURCE=2 -W -Wall -Wno-unknown-pragmas -O2 -fsanitize=address
INCLUDE = -I ./ac-library/

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^

test%: %.o make_test.o judge.o
	./make_test.o > input.txt 
	./$< < input.txt >> input.txt 
	./judge.o < input.txt
	if [ $$? -eq 0 ]; then echo "OK"; else echo "Failed"; exit 1; fi

fetch:
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_a -d "testa/" && \
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_b -d "testb/" && \
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_c -d "testc/" && \
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_d -d "testd/" && \
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_e -d "teste/" && \
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_f -d "testf/" && \
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_g -d "testg/" && \
	oj d https://atcoder.jp/contests/$(ATCODER_CONTEST)/tasks/$(ATCODER_CONTEST)_h -d "testh/"

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

atest: a.o 
	oj t -c "./a.o" -d "testa/"

btest: b.o 
	oj t -c "./b.o" -d "testb/"

ctest: c.o 
	oj t -c "./c.o" -d "testc/"

dtest: d.o 
	oj t -c "./d.o" -d "testd/"

etest: e.o 
	oj t -c "./e.o" -d "teste/"

ftest: f.o 
	oj t -c "./f.o" -d "testf/"

gtest: g.o 
	oj t -c "./g.o" -d "testg/"

htest: h.o 
	oj t -c "./h.o" -d "testh/"

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

setup-%:
	export ATCODER_CONTEST=${@:setup-%=%}
	cp template/test.cpp make_test.cpp
	cp template/algorithm.cpp solver.cpp
	cp template/algorithm.cpp judge.cpp
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
	mv $$HOME/Downloads/tools ./tools
	mkdir tools/out

# run one case
main: main.o
	./main.o < tools/in/0000.txt > tools/out/0000.txt 
	cd tools && \
	cargo run --release --bin vis in/0000.txt out/0000.txt && \
	echo See the result from `pwd`/vis.html

# miscellaneous 

clean:
	rm -f *.o *.exe data_structure/*.out graph/*.out math/*.out other_algorithm/*.out string/*.out \
		  a.cpp b.cpp c.cpp d.cpp e.cpp f.cpp g.cpp h.cpp input.txt ans.txt output.txt make_test.cpp solver.cpp \
		  main.cpp score_calc.cpp main.o judge.cpp judge.o 
	rm -rf testa testb testc testd teste testf testg testh

.SECONDARY: make_test.o solver.o judge.o

.PHONY: test clean