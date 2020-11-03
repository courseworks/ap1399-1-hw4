CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/course.o ./obj/student.o ./obj/prof.o ./obj/person.o ./obj/theorical.o ./obj/lab.o ./obj/er.o ./obj/main.o ./obj/aphw4_unittest.o 
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/er.o: ./cpp/er.cpp 
	$(CXX) $(CXXFLAGS) ./cpp/er.cpp -o ./obj/er.o
./obj/lab.o: ./cpp/lab.cpp ./h/er.h 
	$(CXX) $(CXXFLAGS) ./cpp/lab.cpp -o ./obj/lab.o
./obj/theorical.o: ./cpp/theorical.cpp ./h/er.h 
	$(CXX) $(CXXFLAGS) ./cpp/theorical.cpp -o ./obj/theorical.o
./obj/person.o: ./cpp/person.cpp
	$(CXX) $(CXXFLAGS) ./cpp/person.cpp -o ./obj/person.o
./obj/prof.o: ./cpp/prof.cpp ./h/person.h ./cpp/person.cpp
	$(CXX) $(CXXFLAGS) ./cpp/prof.cpp -o ./obj/prof.o
./obj/student.o: ./cpp/student.cpp ./h/person.h ./cpp/person.cpp
	$(CXX) $(CXXFLAGS) ./cpp/student.cpp -o ./obj/student.o
./obj/course.o: ./cpp/course.cpp
	$(CXX) $(CXXFLAGS) ./cpp/course.cpp -o ./obj/course.o
./obj/aphw4_unittest.o: ./cpp/aphw4_unittest.cpp
	$(CXX) $(CXXFLAGS) ./cpp/aphw4_unittest.cpp -o ./obj/aphw4_unittest.o
./obj/main.o: ./cpp/main.cpp
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
