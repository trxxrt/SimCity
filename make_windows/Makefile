# makefile customisé pour le projet SimCity

# 1. nom du programme
EXE=SimCity.exe

# 2. flags de compilation allegro
FLAGS= -Wall -Winit-self -O3

# 3. liste des fichiers à compiler
SHARED=$(wildcard src/shared/*.c)
MODEL=$(wildcard src/model/*.c)
VIEW=$(wildcard src/view/*.c)
CONTROLLER=$(wildcard src/controller/*.c)
ROOT=$(wildcard src/*.c)
SRC=$(SHARED) $(MODEL) $(VIEW) $(CONTROLLER) $(ROOT)

# 4. liste des fichiers objets à linker
OBJ=$(SRC:.c=.o)

###################################################

all: $(EXE) clean_obj

Debug: $(EXE) clean_obj
	mkdir bin
	mkdir bin\Debug
	cp $(EXE) bin\Debug
	cp -R res bin\Debug
	cp configuration.cfg bin\Debug

Release: $(EXE) clean_obj
	mkdir bin
	mkdir bin\Release
	cp $(EXE) bin\Release
	cp -R res bin\Release
	cp configuration.cfg bin\Release

$(EXE): $(OBJ) 
	"C:\Program Files (x86)\CodeBlocks\MinGW\bin\mingw32-gcc.exe" -L"C:\Program Files (x86)\CodeBlocks\MinGW\lib" -o $@ $^ $(FLAGS) -lALLEG -lpthread

%.o: %.c %.h
	"C:\Program Files (x86)\CodeBlocks\MinGW\bin\mingw32-gcc.exe" -o $@ -I"C:\Program Files (x86)\CodeBlocks\MinGW\include" -c $< $(FLAGS)
	
cleanDebug : clean

cleanRelease : clean

clean: clean_obj
	$(RM) -f $(EXE)
	$(RM) -Rf bin
	
clean_obj:
	$(RM) -f $(OBJ)
