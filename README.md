# DRAWING-APP
## GET STARTED TO DRAW 
A simple cross platform template for setting up a project with the bleeding edge raylib code.
Works with C or C++.

## Supported Platforms
Quickstart supports the main 3 desktop platforms
* Windows
* Linux
* MacOS

# VSCode Users (all platforms)
* Download the quickstart
* Rename the folder to your game name
* Open the folder in VSCode.
* Press F5 to build
* You are good to go.

# Windows Users
There are two compiler toolchains avialble for windows, MinGW-W64 (a free compiler using GCC), and Microsoft Visual Studio
## Using MinGW-W64
* Double click the build-MinGW-W64.bat file.
* cd into the folder in your terminal
* run make
* You are good to go

### Note on MinGW-64 versions
Make sure you have a modern version of MinGW-W64 (not mingw).
The best place to get it is from the W64devkit from
https://github.com/skeeto/w64devkit/releases
or the version installed with the raylib installer
#### If you have installed rayib from the installer
Make sure you have added the path

 C:\raylib\w64devkit\bin 

To your path environment varialbe so that the compiler that came with raylib can be found..

DO NOT INSALL ANOTHER MinGW-W64 from another source such as msys2, you don't need it.

## Microsoft Visual Studio
* Run the build-VisualStudio2022.bat
* double click the .sln file that is geneated.
* develop your game
* you are good to go.

# Linux Users
* CD into the build folder
* run ./premake5 gmake2
* CD back to the root
* run make
* you are good to go

# MacOS Users
* CD into the build folder
* run ./premake5.osx gmake2
* CD back to the root
* run make
* you are good to go

# Output files
The built code will be in the bin dir

# Working directories and the resources folder
The example uses a utility function from path_utils.h that will find the resources dir and set it as the current working directory. This is very useful when starting out. If you wish to manage your own working directory you can simply remove the call to the function and the header.

# Changing to C++
Simply rename src/main.c to src/main.cpp and re-run the steps above and do a clean build.

# Using your own code
Simply remove src/main.c and replace it with your code, and re-run the steps above and do a clean build.

# Building for other OpenGL targets
If you need to build for a different OpenGL version than the default (OpenGL 3.3) you can specify an openGL version in your premake command line. Just modify the bat file or add the following to your command line

## For OpenGL 1.1
--graphics=opengl11

## For OpenGL 2.1
--graphics=opengl21

## For OpenGL 4.3
--graphics=opengl43

## For OpenGLES 2.0
--graphics=opengles2

## For OpenGLES 3.0
--graphics=opengles3
