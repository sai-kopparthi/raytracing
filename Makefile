LDLIBS = -lglut
CFLAGS:=
PROG = raytracing
CC = g++

OBJS = tracer.o vec.o eye.o came.o ray.o scene.o sobj.o sp.o light.o plight.o dlight.o

HDRS = rtracer.h vec.h eye.h cam.h ray.h scene.h sobj.h sp.h light.h plight.h dlight.h

$(PROG): $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o $(PROG)

%.o : %.cc $(HDRS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $<


clean:
	rm -rf *.o *.ppm $(PROG)

