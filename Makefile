objects = bin/app.o bin/graphics.o

bin/app.exe: $(objects)
	gcc $(objects) -o bin/app.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

bin/app.o: src/app.c
	gcc -c src/app.c -o bin/app.o

bin/graphics.o: src/graphics.c src/graphics.h
	gcc -c src/graphics.c -o bin/graphics.o

run: bin/app.exe
	./bin/app.exe