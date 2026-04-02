# ==============================
# Compiler settings
# ==============================
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -IInc

# デバッグ用フラグ（make debug で使用）
DEBUGFLAGS := -g -O0

# ==============================
# Target
# ==============================
TARGET := state_machine_test

# ==============================
# Source files
# ==============================
SRCS := \
	main.cpp \
	Src/Debug/CsvLogger.cpp \
	Src/Safety/SafetyManager.cpp \

# ==============================
# Object files
# ==============================
OBJS := $(SRCS:.cpp=.o)

# ==============================
# Default target
# ==============================
all: $(TARGET)

# ==============================
# Link
# ==============================
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# ==============================
# Compile
# ==============================
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==============================
# Debug build
# ==============================
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)

# ==============================
# Run
# ==============================
run: $(TARGET)
	./$(TARGET)

# ==============================
# Clean
# ==============================
clean:
	rm -f $(OBJS) $(TARGET)

# ==============================
# CSVログ削除（任意）
# ==============================
clean-log:
	rm -f *.csv

# ==============================
# 完全初期化
# ==============================
distclean: clean clean-log