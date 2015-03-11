GCC=g++
CCOPT=-std=c++11

# Add more as you please
OBJECTS=BlackJack.o

# Name of the final binary
EXEC=BlackJack

all: $(OBJECTS)
	$(GCC) $(CCOPT) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(GCC) $(CCOPT) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXEC)