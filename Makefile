CC        = cc
CFLAGS     = -mmacosx-version-min=10.6 -std=c99 -arch x86_64 -O2 -Wall
FRAMEWORKS = -framework IOKit
SRC        = smc.c
OBJ        = smc.o
LIB        = libsmc.a
LIB_DY     = libsmc.dylib

exe: static
	${CC} ${CFLAGS} ${FRAMEWORKS} -o smcprint smcprint.c ${LIB}
	${CC} ${CFLAGS} ${FRAMEWORKS} -o smcdump smcdump.c ${LIB}

exe_dy: dynamic
	${CC} ${CFLAGS} -o smcprint smcprint.c ${LIB_DY}

static:
	${CC} ${CFLAGS} -c -o ${OBJ} ${SRC}
	libtool -static -o ${LIB} ${OBJ}

dynamic:
	${CC} ${CFLAGS} ${FRAMEWORKS} -dynamiclib -o ${LIB_DY} ${SRC}

clean: 
	rm *.o *.a *.dylib
