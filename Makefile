CC=g++
FLAGS=-std=c++2a
TARGET=driver.exe

$(TARGET): driver.o
	$(CC) driver.o -o $(TARGET) $(FLAGS)
driver.o: driver.cpp
	$(CC) -c driver.cpp -o driver.o $(FLAGS)
clean:
	rm *.o $(TARGET)
run: $(TARGET)
	chmod 700 $(TARGET)
	./$(TARGET)
