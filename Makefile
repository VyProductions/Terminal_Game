OBJECTS=action_impl.o advent.o console.o input_map.o input.o system.o text.o

all: clean advent
	@rm *.o -f
	@clear

advent: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -lcurses $(OBJECTS) -o advent -lncurses

action_impl.o:
	$(CXX) $(CXXFLAGS) -lcurses action_impl.cpp -c

advent.o:
	$(CXX) $(CXXFLAGS) -lcurses advent.cpp -c

console.o:
	$(CXX) $(CXXFLAGS) -lcurses console.cpp -c

input_map.o:
	$(CXX) $(CXXFLAGS) -lcurses input_map.cpp -c

input.o:
	$(CXX) $(CXXFLAGS) -lcurses input.cpp -c

system.o:
	$(CXX) $(CXXFLAGS) -lcurses system.cpp -c

text.o:
	$(CXX) $(CXXFLAGS) -lcurses text.cpp -c

clean:
	@rm *.o advent -f