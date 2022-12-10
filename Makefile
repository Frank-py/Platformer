all:
	g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include && g++ *.o -o bin/debug/main -L -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer && ./bin/debug/main && rm *.o
windows:
	g++ -c src/*.cpp -I includeSDL -L lib --std=c++14 -g -Wall -m64 -I include -lmingw32 -lSDL2main -lSDL2 && g++ *.o -o bin/debug/main -L -lmingw32 -lSDL2main -lSDL2 -lSDL2_image  && start bin/debug/main.exe && del *.o

release:
	g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include && g++ *.o -o bin/release/main -s -L -lSDL2main -lSDL2 -lSDL2_image &&  ./bin/release/main
clean:
	del *.o
