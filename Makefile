CXX = clang++
CXXFLAGS = -Wall -Wextra -pedantic -g -std=c++11

LIBSRCS = adapter.cpp
LIBOBJS = $(LIBSRCS:.cpp=.o)

TARGETLIB = libdvblmgr.so
BINARIES = dvbld dvblmgr

LINK = -L . -ldvblmgr

GTEST_DIR = ./gtest-1.7.0

.PHONY: all test clean $(TARGETLIB) $(BINARIES)
all: $(TARGETLIB) $(BINARIES)

$(TARGETLIB): $(LIBOBJS)
	$(CXX) -fPIC -shared -o $@ $^

test: all
	$(CXX) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
	$(CXX) $(LINK) -std=c++11 -isystem ${GTEST_DIR}/include -pthread TestMain.cpp $(wildcard Test_*.cpp) libgtest.a -o runtests
	LD_LIBRARY_PATH=. ./runtests

$(BINARIES):
	$(CXX) $(CXXFLAGS) -o $@ $(LINK) $@.cpp $

clean:
	-rm -f $(TARGETLIB) $(LIBOBJS) libgtest.a gtest-all.o runtests $(BINARIES)