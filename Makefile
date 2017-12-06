CXX = g++
CFLAGS = -Wall
LDFLAGS = 

target = res
srcs = main.cpp State.cpp
objs = $(srcs:.cpp=.o)
headers = $(wildcard *.h)


.PHONY: all
all: $(target)

$(target): $(objs) $(headers)
	$(CXX) $(LDFLAGS) -o $(target) $(objs)

$(objs):%.o:%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(target) *.o

