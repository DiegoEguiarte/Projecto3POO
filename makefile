OBJECTS = main.o disco.o fecha.o libro.o material.o reserva.o software.o

all: main

main: $(OBJECTS)
	g++ $(OBJECTS) -o $@

disco.o: disco.cpp
	g++ -c $< -o $@

fecha.o: fecha.cpp
	g++ -c $< -o $@

libro.o: libro.cpp
	g++ -c $< -o $@

material.o: material.cpp
	g++ -c $< -o $@

reserva.o: reserva.cpp
	g++ -c $< -o $@

software.o: software.cpp
	g++ -c $< -o $@

clean:
	rm -rf *.o