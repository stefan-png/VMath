FLAGS = -std=c++17
EXECNAME = VectorTest

bin/$(EXECNAME): test/main.cpp
	g++ test/main.cpp -o bin/$(EXECNAME) $(FLAGS)


.PHONY: test clean
test: bin/$(EXECNAME)
	bin/$(EXECNAME)

clean:
	rm bin/$(EXECNAME)