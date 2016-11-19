# Macros
#   syntax: 
#       <macro_name> = <macro_string>

# Entries
#   syntax:
#       <target>: [ <dependency> ]*
#           [ <TAB> <command> <endl> ] +

# object files
OBJS = main.o robotPart.o torso.o head.o arm.o locomotor.o battery.o order.o

# compiler
#   since fltk-config --cxx displays the c++ compiler that was used to compile FLTK (g++)
#       we just use it instead of ... for safety purpose
CC = -std=c++11
CXX = $(shell fltk-config --cxx)

# debugging flag
DEBUG = -g

# flags used in compiling and creating object files
#   - fltk-config --cxxflags displays C++ complier options to use when compiling FLTK
#       source files
#       + can also be used when compiling non FLTK files
#   - Wall: tells compiler to print all warnings
#   - c: is needed to create object file, i.e. .o files
CXXFLAGS = $(shell fltk-config --cxxflags) -Wall -c $(DEBUG)

# flags used in linking
#   - fltk-config --ldflags displays the linker options to use when linking a FLTK app
#   - ??? fltk-config --ldstaticflags ... when lking a FLTK app to the static FLTK libraries
LFLAGS = $(shell fltk-config --ldflags) -Wall $(DEBUG)
# may need below options when using images
# LINKFLTK_IMG = $(shell fltk-config --use-images --ldstaticflags)

# FLTK libraries 
# FLTKLIB = -lfltk

executable: $(OBJS)
	$(CC) $(CXX) $(LFLAGS) $(OBJS) $(FLTKLIB) $(LINKFLTK_IMG)

main.o: main.cpp robotPart.h order.h 
	$(CC) $(CXX) $(CXXFLAGS) $(LINKFLTK_IMG) main.cpp

robotPart.o : robotPart.cpp robotPart.h std_lib_facilities.h torso.h head.h arm.h locomotor.h battery.h 
	$(CC) $(CXX) $(CXXFLAGS) $(LINKFLTK_IMG) robotPart.cpp

torso.o : torso.cpp torso.h std_lib_facilities.h
	$(CC) $(CXX) $(CXXFLAGS) torso.cpp

head.o : head.cpp head.h std_lib_facilities.h
	$(CC) $(CXX) $(CXXFLAGS) head.cpp

arm.o : arm.cpp arm.h std_lib_facilities.h
	$(CC) $(CXX) $(CXXFLAGS) arm.cpp

locomotor.o : locomotor.cpp locomotor.h std_lib_facilities.h
	$(CC) $(CXX) $(CXXFLAGS) locomotor.cpp

battery.o : battery.cpp battery.h std_lib_facilities.h
	$(CC) $(CXX) $(CXXFLAGS) battery.cpp

order.o : order.cpp order.h robotPart.h 
	$(CC) $(CXX) $(CXXFLAGS) order.cpp

clean:
	rm *.o a.out    
