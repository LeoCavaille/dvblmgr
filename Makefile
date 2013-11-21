CXX = clang++
CFLAGS = -Wall -Wextra -pedantic -g

LIBSRCS = adapter.cpp
LIBOBJS = $(LIBSRCS:.cpp=.o)

TARGETLIB = libdvblmgr.so
BINARIES = dvbld dvblmgr

GTEST_DIR = ./gtest-1.7.0

.PHONY: all test clean $(TARGETLIB) $(BINARIES)
all: $(TARGETLIB) $(BINARIES)

$(TARGETLIB): $(LIBOBJS)
	$(CXX) -shared -o $@ $^

$(SRCS:.cpp=.d):%.d:%.cpp
	$(CXX) $(CFLAGS) -MM $< >$@
 
include $(SRCS:.c=.d)

test:
	$(CXX) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
	$(CXX) -L . -ldvblmgr -isystem ${GTEST_DIR}/include -pthread TestMain.cpp $(wildcard Test_*.cpp) libgtest.a -o runtests
	LD_LIBRARY_PATH=. ./runtests

$(BINARIES):
	$(CXX) -o $@ -L . -ldvblmgr $@.cpp $

clean:
	-rm -f $(TARGETLIB) $(LIBOBJS) $(LIBSRCS:.cpp=.d) libgtest.a gtest-all.o runtests $(BINARIES)