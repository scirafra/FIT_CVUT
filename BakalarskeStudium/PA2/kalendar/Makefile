LD=g++
CXX=g++
CXXFLAGS=-std=c++17 -Wall -pedantic -g
src_folder = src
build_folder = src/build

all: compile
compile: deps scirafra
scirafra: $(build_folder)/main.o \
		  $(build_folder)/CCommand.o \
		  $(build_folder)/CEventDisplay.o \
		  $(build_folder)/CDailyDisplay.o \
		  $(build_folder)/CWeeklyDisplay.o \
		  $(build_folder)/CMonthlyDisplay.o \
		  $(build_folder)/CCalendar.o \
		  $(build_folder)/CEvent.o \
		  $(build_folder)/CTime.o   
	$(LD) -o $@ $^ 
run: scirafra
	./scirafra
$(build_folder)/%.o: $(src_folder)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
clean:
	rm $(build_folder)/*.o scirafra
.PHONY: doc
doc:	
	doxygen doc/Doxyfile
deps: 
	$(CXX) -MM $(src_folder)/*.cpp > Makefile.d
-include Makefile.d