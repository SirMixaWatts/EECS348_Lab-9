CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

matrix_operations: main.o matrix.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp

clean:
	rm -f *.o matrix_operations