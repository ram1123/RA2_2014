ROOTLIBS   = $(shell root-config --libs)
ROOTCFLAGS = $(shell root-config --cflags)

CFLAG      = -I $(ROOTCFLAGS)
LFLAG      = $(ROOTLIBS)

OBJ     = Analyzer.o HelperClass.o main.o



FlexPrediction: $(OBJ)		
	g++ $(OBJ) $(LFLAG) -o FlexPrediction
	@echo -e 'Done.\n\n   Type "./FlexPrediction config-file-name"\n\n'
Analyzer.o: HelperClass.h Analyzer.h Analyzer.cc SharedVariables.h
	g++ $(CFLAG) -c  Analyzer.cc
HelperClass.o: HelperClass.h SharedVariables.h HelperClass.cc 
	g++ $(CFLAG) -c  HelperClass.cc
main.o: main.cc SharedVariables.h HelperClass.h Analyzer.h
	g++ $(CFLAG) -c  main.cc


clean:
	@rm -f *.o 
	@rm -f FlexPrediction
	@rm -f *~
	@rm -f *#
	@rm -f .#*


