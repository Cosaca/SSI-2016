CXX=g++ 
CXXFLAGS=-g

OBJS = AES.o CBC.o main.o

all: ${OBJS}
	$(CXX)  $(CXXFLAGS) -o rijndael ${OBJS}

clean: 
	rm -rf *.o rijndael