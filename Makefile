COMPILE_FLAGS = -fno-elide-constructors
CPP   		  = g++ $(COMPILE_FLAGS)

OBJ = Obj/
SRC	= Src/
EXE = Exe/run

all: $(OBJ)NotInt.o
	$(CPP) $(SRC)main.cpp $(OBJ)NotInt.o -o $(EXE)

$(OBJ)NotInt.o: $(SRC)NotInt/NotInt.cpp $(SRC)NotInt/NotInt.h
	$(CPP) -c $(SRC)NotInt/NotInt.cpp -o $(OBJ)NotInt.o

run:  all
	./$(EXE) > log

clean:
	-cd $(OBJ); rm *
	-rm $(EXE)