GPP = g++ -O3 -Wall

UTILS = ../../Utilities

A = Main.o
M = MovingAverage.o
S = Scanner.o
SL = ScanLine.o
U = Utils.o

Aprog: $A $M $S $(SL) $U
	$(GPP) -o Aprog $A $M $S $(SL) $U

Main.o: Main.h Main.cpp
	$(GPP) -c Main.cpp

MovingAverage.o: MovingAverage.h MovingAverage.cpp
	$(GPP) -c MovingAverage.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -c $(UTILS)/Scanner.cpp

ScanLine.o: $(UTILS)/ScanLine.h $(UTILS)/ScanLine.cpp
	$(GPP) -c $(UTILS)/ScanLine.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -c $(UTILS)/Utils.cpp
