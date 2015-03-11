GCC=g++
CCOPT=-std=c++11

# Add more as you please
OBJECTS=Oppvarming.o

# Name of the final binary
EXEC=Oppvarming

all: $(OBJECTS)
	$(GCC) $(CCOPT) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(GCC) $(CCOPT) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXEC)