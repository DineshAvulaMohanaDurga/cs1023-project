.PHONY: clean run debug

CXX = g++
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = trial2.cpp
OBJECTS = trial2.o
EXECUTABLE = trial2.exe

all: $(EXECUTABLE) run


$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(SFMLFLAGS)

trial2.o:trial2.cpp
	$(CXX) -c trial2.cpp

clean:
	rm -f $(EXECUTABLE);rm -f $(OBJECTS) 

debug:
	$(CXX) -g -o debug.exe $(SOURCES)

run :
	./$(EXECUTABLE)