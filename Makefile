CXX      = g++
CXXFLAGS = -std=c++17 -Wall
SRC      = main.cpp Driver.cpp Team.cpp Library.cpp Menu.cpp
TARGET   = f1_library

all: $(TARGET)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -f $(TARGET)
