CC=arm-linux-gcc
#CC=/usr/local/arm/4.3.2/bin/arm-linux-gcc
#CC=gcc
CFLAGS=-Wall -O2
TARGET=CreateBlackList
HDFLAGS=-I./include
LDFLAGS=-L./lib

blacklist: $(TARGET)
phonebook: $(TARGET1)
showbook: $(TARGET2)

$(TARGET): createblacklist.o
	$(CC) -o $(TARGET) createblacklist.o $(HDFLAGS) $(LDFLAGS) -lxml2
	
%.o: %.c
	$(CC) -c $< $(CLAGS) $(HDFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGET)

