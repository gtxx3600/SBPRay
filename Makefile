CC = g++
CFLAGS  = -g -Wall
INCLUDES = -I./
LIBS = -lm

SRCS = main.cc base/Color.cc base/Ray.cc base/Vec.cc engine/PathTracingEngine.cc engine/RayTracingEngine.cc materials/Material.cc objects/Object.cc objects/Sphere.cc pic/PPMFile.cc scene/Camera.cc scene/Intersect.cc scene/Scene.cc
OBJS = $(SRCS:.cc=.o)

MAIN = sbpray

.PHONY: depend clean

all:  clean  $(MAIN)

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cc.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) base/*.o engine/*.o materials/*.o objects/*.o pic/*.o scene/*.o $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

