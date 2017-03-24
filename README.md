# Template Project #

## Overview ##

This project is the proverbial Hello World for the Authors algorithm development activities and is used as a starting point for a platform independent code development. 
## Credits: ##
Creadits for the build enviorement goto the authors of the lwext4 project.      

## Matlab Toolbox ##

Matlab is the workhorse for algorithm development, and much of the Authors algorithms begins as a Matlab implementation which subsequently is migrated to C, often targeting embedded application. As part of this design flow, a mex wrapper is used to develop a Matlab executable version of the algorithm. This approach accelerates the Matlab runtime and provides a test-bench to the same C code that is eventually cross-compiled for the target platform. These C reference becomes the 'Gold-Standard' for the algorithms and will form the based of subsequent implementation.  

## Toolchains and Target Architectures: ##

The project and associated libraries compiled for many targets. Here are an examples for 8/16/32/64 bit architectures.
* generic for x86 or amd64
* arm-none-eabi-gcc for ARM cortex-m0/m3/m4 microcontrollers
* avr-gcc for AVR xmega microcontrollers

### Cross compile for embedded architectures ###

#### Build cortex-m0 library: ####
------------
```
make cortex-m0
cd build_cortex-m0
make lib
```
#### Build cortex-m3 library: #### 
------------
```
make cortex-m3
cd build_cortex-m3
make lib
```
#### Build cortex-m4 library: #### 
------------
```
make cortex-m4
cd build_cortex-m4
make lib
```
### Cmake and your favorite IDE: ###
One of the nice feature of CMake is the ability to generate project files for various IDEs.

Build xcode project:
------------
```
make xcode
cd xcode
xcode 
```
