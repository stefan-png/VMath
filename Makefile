FLAGS = -std=c++17
EXECNAME = VectorTest

$(EXECNAME): main.cpp
	g++ main.cpp -o $(EXECNAME) $(FLAGS)


.PHONY: test clean
test: $(EXECNAME)
	./$(EXECNAME)

clean:
	rm $(EXECNAME)