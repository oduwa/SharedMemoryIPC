
cmake_minimum_required(VERSION 2.8)
project(HelloWorld)
set(CMAKE_BUILD_TYPE Release)

#However, the file(GLOB...) allows for wildcard additions:
#file(GLOB *.c)
 
#Generate the shared library from the sources
#add_library(StudentLibrary SHARED ${SOURCES})

add_executable(SimpleIPCClient IPCClient.c)
 
#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
#install(TARGETS StudentLibrary DESTINATION libs)