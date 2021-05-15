.PHONY: clean run debug

CXX = g++
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SOURCES = trial1.cpp
OBJECTS = trial1.o
EXECUTABLE = trial1.exe

all: $(EXECUTABLE) run


$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(SFMLFLAGS)

trial1.o:trial1.cpp
	$(CXX) -c trial1.cpp

clean:
	rm -f $(EXECUTABLE);rm -f $(OBJECTS) 

debug:
	$(CXX) -g -o debug.exe $(SOURCES)

run :
	./$(EXECUTABLE)