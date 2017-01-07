TEST_CXXFILES=  register.cc

TEST_OBJECTS=$(patsubst %.cc,%.o,$(TEST_CXXFILES))
TEST_PROG=register_test

GTEST_DIR=/home/pili/build/googletest/googletest/make
GTEST_CXXFLAGS=-isystem $(GTEST_DIR)/include -pthread 
GTEST_LDFLAGS=-pthread
GTEST_LIBS=$(GTEST_DIR)/libgtest.a
GTEST_MAIN=$(GTEST_DIR)/gtest_main.o

all: $(TEST_PROG)

check: $(TEST_PROG)
	./$(TEST_PROG)

$(TEST_PROG): $(TEST_OBJECTS) 
	@$(CXX) $(GTEST_LDFLAGS) $(LD_FLAGS) -o $@ $(GTEST_MAIN) $^ $(GTEST_LIBS)

clean:
	$(RM) -- $(TEST_OBJECTS) $(TEST_PROG) 

.PHONY: all check clean record.o

#DEPENDENCIES
record.o: record.cc 
	$(CXX) $(GTEST_CXXFLAGS) $(L_CXXFLAGS) $(CXXFLAGS) -c -o $@ $<



