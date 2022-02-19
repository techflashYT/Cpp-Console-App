#=========================================================================================
# Set basic stuff up.
#=========================================================================================
NAME			:= test
TARGET			:= $(notdir $(NAME).exe)

#=========================================================================================
# Set up C++ Compiler and flags.
#=========================================================================================
ifeq ($(SANIKS_BUILD),TRUE)
CPPC			:= /c/msys64/mingw64/bin/g++
else
CPPC			:= g++
endif
CFLAGS_G		:= -fdiagnostics-color=always -Wall -Wextra -Werror -std=c++2b
CFLAGS_REL		:= -O3
CFLAGS_DEB		:= -g


#=========================================================================================
# Set up output stuff.
#=========================================================================================


export OUTPUT	:= bin/$(TARGET)


#=========================================================================================
# Compile.
#=========================================================================================
release:
	@pwsh -C "if (Test-Path -Path bin) {} else { mkdir bin }"
	$(CPPC) $(CFLAGS_G) $(CFLAGS_REL) src/*.cpp -o "$(OUTPUT)"

debug:
	@pwsh -C "if (Test-Path -Path bin) {} else { mkdir bin }"
	$(CPPC) $(CFLAGS_G) $(CFLAGS_DEB) src/*.cpp -o "$(OUTPUT)"
