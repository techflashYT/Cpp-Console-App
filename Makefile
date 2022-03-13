#=========================================================================================
# Set basic stuff up.
#=========================================================================================
NAME			:= test
TARGET			:= $(notdir $(NAME))

#=========================================================================================
# Set up C++ Compiler and flags.
#=========================================================================================
ifeq ($(SANIKS_BUILD),TRUE)
CPPC			:= /c/msys64/mingw64/bin/g++
else
CPPC			:= g++
endif
CFLAGS_G		:= -fdiagnostics-color=always \
				   -Wall -Wextra -Werror \
				   -std=c++2b \
				   -Lsrc/inc/libs/GL \
				   -lopengl32 -lglu32 -lfreeglut
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
ifeq ($(PLATFORM),WIN)
	@powershell -Command "if (Test-Path -Path bin) {} else { mkdir bin | Out-Null}"
	@powershell -Command "if (Test-Path -Path bin/assets) {} else { mkdir bin/assets | Out-Null"}
	@powershell -Command "if (Test-Path -Path bin/assets/models) {} else { mkdir bin/assets/models | Out-Null"}
	@powershell -Command "cp src/models/*.obj bin/assets/models/ | Out-Null"
	@powershell -Command "cp src/models/*.mtl bin/assets/models/ | Out-Null"
	$(CPPC) $(CFLAGS_G) $(CFLAGS_REL) src/*.cpp -o "$(OUTPUT).exe"
endif
ifeq ($(PLATFORM),LINUX)
# TODO: Check for path on linux
	$(CPPC) $(CFLAGS_G) $(CFLAGS_REL) src/*.cpp -o "$(OUTPUT).out"
endif
ifneq ($(PLATFORM),LINUX)
ifneq ($(PLATFORM),WIN)
	@echo "Assuming that you're running Windows, as you didn't specify.  If this is wrong, stop now."
	@powershell -Command "if (Test-Path -Path bin) {} else { mkdir bin | Out-Null}"
	@powershell -Command "if (Test-Path -Path bin/assets) {} else { mkdir bin/assets | Out-Null"}
	@powershell -Command "if (Test-Path -Path bin/assets/models) {} else { mkdir bin/assets/models | Out-Null"}
	@powershell -Command "cp src/models/*.obj bin/assets/models/ | Out-Null"
	@powershell -Command "cp src/models/*.mtl bin/assets/models/ | Out-Null"
	$(CPPC) $(CFLAGS_G) $(CFLAGS_REL) src/*.cpp -o "$(OUTPUT).exe"
endif
endif

debug:
ifeq ($(PLATFORM),WIN)
	@powershell -Command "if (Test-Path -Path bin) {} else { mkdir bin | Out-Null}"
	@powershell -Command "if (Test-Path -Path bin/assets) {} else { mkdir bin/assets | Out-Null"}
	@powershell -Command "if (Test-Path -Path bin/assets/models) {} else { mkdir bin/assets/models | Out-Null"}
	@powershell -Command "cp src/models/*.obj bin/assets/models/ | Out-Null"
	@powershell -Command "cp src/models/*.mtl bin/assets/models/ | Out-Null"
	$(CPPC) $(CFLAGS_G) $(CFLAGS_DEB) src/*.cpp -o "$(OUTPUT).exe"
endif
ifeq ($(PLATFORM),LINUX)
# TODO: Check for path on linux
	$(CPPC) $(CFLAGS_G) $(CFLAGS_DEB) src/*.cpp -o "$(OUTPUT).out"
endif
ifneq ($(PLATFORM),LINUX)
ifneq ($(PLATFORM),WIN)
	@echo "Assuming that you're running Windows, as you didn't specify.  If this is wrong, stop now."
	@powershell -Command "if (Test-Path -Path bin) {} else { mkdir bin | Out-Null}"
	@powershell -Command "if (Test-Path -Path bin/assets) {} else { mkdir bin/assets | Out-Null"}
	@powershell -Command "if (Test-Path -Path bin/assets/models) {} else { mkdir bin/assets/models | Out-Null"}
	@powershell -Command "cp src/models/*.obj bin/assets/models/ | Out-Null"
	@powershell -Command "cp src/models/*.mtl bin/assets/models/ | Out-Null"


	$(CPPC) $(CFLAGS_G) $(CFLAGS_DEB) src/*.cpp -o "$(OUTPUT).exe"
endif
endif


clean:
	@powershell -Command "if (Test-Path -Path bin) {rm -r -Force bin}"
	@powershell -Command "if (Test-Path -Path build) {rm -r -Force bin}"
