ROOTLIBS   = $(shell root-config --libs)
ROOTCFLAGS = $(shell root-config --cflags)

CFLAG      = -I $(ROOTCFLAGS)
LFLAG      = $(ROOTLIBS)

OBJ     = FlexPrediction.o main.o



run: $(OBJ)		
	g++ $(OBJ) $(LFLAG) -o run
	@echo -e 'Done.\n\n   Type "./run config-file-name"\n\n'
FlexPrediction.o: FlexPrediction.h FlexPrediction.C
	g++ $(CFLAG) -c  FlexPrediction.C
#Prediction.o: Prediction.h Prediction.cc 
#	g++ $(CFLAG) -c Prediction.cc
main.o: main.cc FlexPrediction.h
	g++ $(CFLAG) -c  main.cc


clean:
	@rm -f *.o 
	@rm -f run
	@rm -f *~
	@rm -f *#
	@rm -f .#*


