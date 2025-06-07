objects = bin/simulation.o bin/controller.o bin/telemetry.o bin/flywheel.o bin/ball.o bin/graphics.o bin/renderer.o bin/keyframe.o bin/events.o bin/input.o bin/timer.o bin/physics.o

bin/app.exe: $(objects)
	gcc $(objects) -o bin/app.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_gfx

bin/simulation.o: src/simulation/simulation.c
	gcc -c src/simulation/simulation.c -o bin/simulation.o

bin/controller.o: src/simulation/controller.c
	gcc -c src/simulation/controller.c -o bin/controller.o

bin/telemetry.o: src/simulation/telemetry.c
	gcc -c src/simulation/telemetry.c -o bin/telemetry.o

bin/flywheel.o: src/simulation/flywheel.c src/simulation/flywheel.h
	gcc -c src/simulation/flywheel.c -o bin/flywheel.o

bin/ball.o: src/simulation/ball.c src/simulation/ball.h
	gcc -c src/simulation/ball.c -o bin/ball.o

bin/graphics.o: src/graphics/graphics.c src/graphics/graphics.h
	gcc -c src/graphics/graphics.c -o bin/graphics.o

bin/renderer.o: src/graphics/renderer.c src/graphics/renderer.h
	gcc -c src/graphics/renderer.c -o bin/renderer.o

bin/keyframe.o: src/graphics/keyframe.c src/graphics/keyframe.h
	gcc -c src/graphics/keyframe.c -o bin/keyframe.o

bin/events.o: src/system/events.c src/system/events.h
	gcc -c src/system/events.c -o bin/events.o

bin/input.o: src/system/input.c src/system/input.h
	gcc -c src/system/input.c -o bin/input.o

bin/timer.o: src/system/timer.c src/system/timer.h
	gcc -c src/system/timer.c -o bin/timer.o

bin/physics.o: src/physics/physics.c src/physics/physics.h
	gcc -c src/physics/physics.c -o bin/physics.o

run: bin/app.exe
	./bin/app.exe