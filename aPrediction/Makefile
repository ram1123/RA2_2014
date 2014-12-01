ROOTLIBS   = $(shell root-config --libs)
ROOTCFLAGS = $(shell root-config --cflags)

CFLAG      = -I $(ROOTCFLAGS)
LFLAG      = $(ROOTLIBS)

OBJ     = Config.o Prediction.o FlexPrediction.o main.o



run: $(OBJ)		
	g++ $(OBJ) $(LFLAG) -o run
	@echo -e 'Done.\n\n   Type "./run config-file-name"\n\n'
FlexPrediction.o: FlexPrediction.h FlexPrediction.C
	g++ $(CFLAG) -c  FlexPrediction.C
Prediction.o: Prediction.h Prediction.cc 
	g++ $(CFLAG) -c Prediction.cc

Config.o: Config.h Config.cc 
	g++ $(CFLAG) -c Config.cc
main.o: main.cc FlexPrediction.h Config.h
	g++ $(CFLAG) -c  main.cc


clean:
	@rm -f *.o 
	@rm -f run
	@rm -f *~
	@rm -f *#
	@rm -f .#*


