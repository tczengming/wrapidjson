CXX=g++
CCFLAG=-I../

%.o : %.cpp
	$(CXX) $(CCFLAG) -c $< -o $@

example.out:example.o ../wrapidjson.o
	$(CXX) $(CCFLAG) -o $@ $?
