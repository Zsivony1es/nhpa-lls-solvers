# QR Factorizer implementations - NHPA Homework 1

---

### Installation notes
To build the executables I use Makefile, with the following commands set up:
+ make test - build test executables and execute tests
+ make all - compile all source files and create executables
+ make clean - delete build and apps directory contents
+ **make matrix_gen** - build all executables and run the executable, which generates the test matrices to the res directory
+ **make run** - build all executables and run main

In the Makefile you will probably have to edit the `LIBS` variable, since I am explicitly setting the path to OpenBLAS on my machine. If you're also executing this on a MacBook, it should work without changes.