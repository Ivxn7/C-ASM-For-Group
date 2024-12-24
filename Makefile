
CXX = g++

CXXFLAGS = -Wall -Werror -g

TARGET = main

TARGET_DEL = main.exe

SRCS = main.cpp myfunctions.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o *.exe