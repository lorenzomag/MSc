######################################################################
# Project: TMVA - Toolkit for Multivariate Data Analysis             #
# Code   : Example usage for TMVA analyses                           #
###################################################################### 
BINS = TMVAnalyse


CXX = g++
CCFLAGS = $(shell root-config --cflags) -ggdb


LD = g++
LDFLAGS = 

LIBS = $(shell root-config --libs) -lMLP -lMinuit -lTreePlayer -lTMVA -lTMVAGui -lXMLIO  -lMLP -lm -lRooFit -lRooFitCore


default : $(BINS)

$(BINS): % : %.C XicstBG.cxx PowerLaw.cxx
	@echo -n "Building $@ ... "
	$(CXX) $(CCFLAGS) $< $(LIBS) -o $@
	@echo "Done"


clean: 
	rm -f *.o	$(BINS) *.d *.pcm *.so

