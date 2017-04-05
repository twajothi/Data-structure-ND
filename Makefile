CMP = g++
MAIN = main
CLASS = C4Col
CLASS2 = C4Board

$(MAIN): $(CLASS).o $(MAIN).o $(CLASS2).o
		$(CMP) -o $(MAIN) $(CLASS).o  $(CLASS2).o $(MAIN).o

$(MAIN).o: $(MAIN).cpp
		$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp
		$(CMP) -c $(CLASS).cpp

$(CLASS2).o: $(CLASS2).cpp
		$(CMP) -c $(CLASS2).cpp

clean:
		rm $(MAIN) *.o
