# makefile customisé pour le projet SimCity

# 1. nom du programme
EXE=SimCity

# 2. flags de compilation allegro
FLAGS=`allegro-config --libs` -Wall -Winit-self -O3

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
	mkdir bin || true
	mkdir bin/Debug || true
	cp $(EXE) bin/Debug
	cp -R res bin/Debug
	cp configuration.cfg bin/Debug

Release: $(EXE) clean_obj
	mkdir bin || true
	mkdir bin/Release || true
	cp $(EXE) bin/Release
	cp -R res bin/Release
	cp configuration.cfg bin/Release

$(EXE): $(OBJ)
	@echo "\n=== linking des objets ==="
	gcc -o $@ $^ $(FLAGS)

%.o: %.c %.h
	@echo "\ncompilation de $<"
	gcc -o $@ -c $< $(FLAGS)

cleanDebug: clean

cleanRelease: clean

clean: clean_obj
	rm -f $(EXE)
	rm -f SimCity.layout SimCity.depend
	rm -Rf bin
	
clean_obj:
	@echo "\n=== Clean  ===\n"
	rm -f $(OBJ)
