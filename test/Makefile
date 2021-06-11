CXX=g++
CCFLAG=-I../

%.o : %.cpp
	$(CXX) $(CCFLAG) -c $< -o $@

test.out:test.o ../wrapidjson.o
	$(CXX) $(CCFLAG) -o $@ $?
