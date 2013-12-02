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

Install the dependencies :

```
# Debian like
apt-get install libyaml-cpp-dev
# Mac OS
brew install yaml-cpp
```


Compiling
---------

Create a fresh build directory, usually doing :

```
cd $MYDVBLMGRCODEROOT
mkdir build && cd build
cmake ..
make -j8
```

On *Mac OS* with homebrew you may have to use `-DYAMLCPP_STATIC_LIBRARY=1` in cmake because you doesn't have the dynamic library files for yaml-cpp.


Testing
-------

You can use the compiled runTests binary.
