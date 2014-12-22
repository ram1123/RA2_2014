ROOTLIBS   = $(shell root-config --libs)
ROOTCFLAGS = $(shell root-config --cflags)

CFLAG      = -I $(ROOTCFLAGS)
LFLAG      = $(ROOTLIBS)

OBJ     = HelperClass.o main.o



FlexPrediction: $(OBJ)		
	g++ $(OBJ) $(LFLAG) -o FlexPrediction
	@echo -e 'Done.\n\n   Type "./FlexPrediction config-file-name"\n\n'
HelperClass.o: HelperClass.h SharedVariables.h HelperClass.cc 
	g++ $(CFLAG) -c  HelperClass.cc
main.o: main.cc SharedVariables.h HelperClass.h
	g++ $(CFLAG) -c  main.cc


clean:
	@rm -f *.o 
	@rm -f FlexPrediction
	@rm -f *~
	@rm -f *#
	@rm -f .#*


