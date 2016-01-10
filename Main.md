# Installing the contribution #

## Configuring gecode ##

To enable support for the FloatVars contribution, configure gecode in the following way:

```
configure CXXFLAGS="-DGECODE_HAS_FLOAT_VARS" CPPFLAGS="-DGECODE_HAS_FLOAT_VARS" --prefix=/usr/local/gecode2.2 --enable-debug --enable-gist
o
CC=/usr/bin/gcc-4.3 CXX=/usr/bin/g++-4.3 ./configure CXXFLAGS="-DGECODE_HAS_FLOAT_VARS" CPPFLAGS="-DGECODE_HAS_FLOAT_VARS" --prefix=/opt/gecode --enable-debug --enable-gist
```

## Building gecode ##

As usual:
```
make 
make install
```

## Building the contribution ##

```
cmake -DCMAKE_PREFIX_PATH=/usr/local/gecode2.2 /path/to/cpfloatvars
o
cmake -DCMAKE_PREFIX_PATH=/opt/gecode /path/to/cpfloatvars
```

## Adding contribution to Gecode ##

```
cp ../libgecodefloat.so /usr/local/gecode2.2/lib
cp ../gecode/float /usr/local/gecode2.2/include/gecode -r
o
cp ../libgecodefloat.so /opt/gecode/lib
cp ../gecode/float /opt/gecode/include/gecode -r
```
Edit file /usr/local/gecode2.2/lib/pkgconfig/gecode.pc o /opt/gecode/lib/pkgconfig/gecode.pc and complete the following line:
Libs: -L${exec\_prefix}/lib -lgecodecpltset -lgecodeset -lgecodeint -lgecodekernel -lgecodesupport
with new float library -lgecodefloat


## Environment variables ##

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/gecode2.2/lib
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/gecode2.2/lib/pkgconfig/

o

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/gecode/lib/
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/opt/gecode/lib/pkgconfig/
```

## Compiling by console ##

```
g++ -I/usr/local/gecode2.2/include/ -c example.cpp -DGECODE_HAS_FLOAT_VARS
g++ -o example -L/usr/local/gecode2.2/lib/ example.o -lgecodeint -lgecodesearch -lgecodekernel -lgecodesupport -lgecodefloat

o

g++ -I/opt/gecode/include/ -c example.cpp -DGECODE_HAS_FLOAT_VARS
g++ -o example -L/opt/gecode/lib/ example.o -lgecodeint -lgecodesearch -lgecodekernel -lgecodesupport -lgecodefloat
```


# Details #

Add your content here.  Format your content with:
  * Text in **bold** or _italic_
  * Headings, paragraphs, and lists
  * Automatic links to other wiki pages