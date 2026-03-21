# ==============================
# Compiler settings
# ==============================
TARGET_ARCH ?= PC

ifeq ($(TARGET_ARCH), STM32)
	CXX := arm-none-eabi-g++
else
	CXX := g++
endif
CXXFLAGS := -std=c++17 -Wall -Wextra -IInc

# ==============================
# Target
# ==============================
TARGET := main

# ==============================
# Source files
# ==============================
SRCS := $(wildcard Src/*.cpp) main.cpp

# ==============================
# Object files
# ==============================
OBJS := $(SRCS:.cpp=.o)

# ==============================
# Build rules
# ==============================
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==============================
# Clean
# ==============================
clean:
	rm -f $(OBJS) $(TARGET)

# ==============================
# Run (for PC debug)
# ==============================
run: $(TARGET)
	./$(TARGET)