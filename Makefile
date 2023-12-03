CXX := g++
CXXFLAGS := -std=c++17 -fPIC -lsqlite3

INCLUDE := -I src/include/
DOCTEST += -I src/test/doctest.h

SRC_DIR := src/core
TEST_DIR := src/tests

BIN_DIR := bin
BUILD_DIR := build


SRC_FILES := $(filter-out src/core/main.cpp, $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp))
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

DEP_FILES := $(SRC_FILES:.cpp=.d)
DEP_FILES += $(TEST_FILES:.cpp=.d)

OBJ_SRC_FILES := $(SRC_FILES:.cpp=.o)
OBJ_TEST_FILES := $(OBJ_SRC_FILES)
OBJ_TEST_FILES += $(TEST_FILES:.cpp=.o)

run: $(BIN_DIR)/taskmanager
	@$(BIN_DIR)/taskmanager run

$(BIN_DIR)/taskmanager: $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES)) $(BUILD_DIR)/libtask.so
	@echo "🔧 Preparing executable..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) src/core/main.cpp $^ -L$(BUILD_DIR) -ltask -o $@ -lsqlite3

build: $(BUILD_DIR)/libtask.so

$(BUILD_DIR)/libtask.so: $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Preparing library ..."
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -shared $^ -o $(BUILD_DIR)/libtask.so

test: $(BIN_DIR)/test
	@$(BIN_DIR)/test

$(BIN_DIR)/test: $(addprefix $(BUILD_DIR)/,$(OBJ_TEST_FILES))
	@echo "🔧 Preparing test suite ..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS)  $^ -o $@ -lsqlite3

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -D STORAGE_DIR=\"$(STORAGE_DIR)\" -MMD -MP -c $< -o $@

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $(DOCTEST)  -MMD -MP -c $< -o $@ 

clean:
	@echo "🧹 Cleaning ..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)