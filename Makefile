CC=arm-linux-gcc
#CC=/usr/local/arm/4.3.2/bin/arm-linux-gcc
#CC=gcc
CFLAGS=-Wall -O2
TARGET=CreatePhoneBook
TARGET2=ShowPhoneBook
#HDFLAGS=-I/usr/local/include/libxml2
#LDFLAGS=-L/usr/local/lib/
HDFLAGS=-I./include
LDFLAGS=-L./lib

create: $(TARGET)
show: $(TARGET2)

$(TARGET): create_phone_book.o
	$(CC) -o $(TARGET) create_phone_book.o $(HDFLAGS) $(LDFLAGS) -lxml2

$(TARGET2): phone_book.o
	$(CC) -o $(TARGET2) phone_book.o $(HDFLAGS) $(LDFLAGS) -lxml2
	
%.o: %.c
	$(CC) -c $< $(CLAGS) $(HDFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(TARGET2)

