OUTFOLDER=./bin
OUTFILE=${OUTFOLDER}/main

build:
	g++ -w -std=c++17 \
	./src/*.cpp \
	-o ${OUTFILE} \
	-lSDL2;

clean:
	rm -rf ${OUTFOLDER}/*;

run:
	${OUTFILE};

debug:
	gdb ${OUTFILE};

br:
	make build;
	make run;

bd:
	make build;
	make debug;
