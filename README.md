dvblmgr
=======

Manage your TV/Radio broadcast

Configuration
-------------

Unzip the googletest framework in your lib directory.

```
cd lib/
wget https://googletest.googlecode.com/files/gtest-1.7.0.zip
unzip gtest-1.7.0.zip
rm -f gtest-1.7.0.zip
```


Compiling
---------

Create a fresh build directory, usually doing ;

```
cd $MYDVBLMGRCODEROOT
mkdir build && cd build
cmake ..
make -j8
```


Testing
-------

You can use the compiled runTests binary.
