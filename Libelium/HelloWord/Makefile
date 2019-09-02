# Makefile template to compile, build & install programs in Arduino Boards & Libelium Waspmote
# 
# Design & Implementation : Jesus Revilla de Lucas
# Copyright(C) 2019 IPE - CSIC
# Url: 		http://ipe.csic.es
# Name:     Makefile.tpl
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 2.1 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Version:	0.1
# Created:	24/07/2019 14:12:02
# Author:   jrevilla@ipe.csic.es
# 
# 
# Version 0.1. 
# Basic work with manual configuration

# Define creator & version
FILE_VERSION 	:= Version:	0.1
FILE_CREATEBY 	:= Design & Implementation : Jesus Revilla de Lucas
FILE_COPYRIGHT 	:= Copyright(C) 2019 IPE - CSIC
FILE_URL		:= Url: http://ipe.csic.es
FILE_BUGS 		:= Report bugs to <jrevilla@ipe.csic.es>


# Output paths
SRCDIR := .\\
OBJDIR := .\\objs
LIBDIR := .\\libs
TMPDIR := .\\tmp
COREOBJDIR := $(OBJDIR)\\core
APIOBJDIR := $(OBJDIR)\\api

OUTDIRS := $(SRCDIR) $(OBJDIR) $(LIBDIR) $(COREDIR) $(COREOBJDIR) $(APIOBJDIR) $(TMPDIR)


# Conditional compilation & program
ifeq ($(MAKECMDGOALS),server)
suffixName := .server
CXXFLAGS_DEFINE_INSTALL := -DSERVER
else ifeq ($(MAKECMDGOALS),client)
CXXFLAGS_DEFINE_INSTALL := -DCLIENT
suffixName := .client
endif


# Project targets definition
project  := HelloWord
libcore  :=  $(OBJDIR)\\libCore.a
targetelf  :=  $(OBJDIR)\\$(project)$(suffixName).elf
targeteep  :=  $(OBJDIR)\\$(project)$(suffixName).eep
target  :=  $(OBJDIR)\\$(project)$(suffixName).hex

###################################################################################
# To know CPU, flag values, path and programmer compile & upload (verbose mode both ) 
# with Libelium IDE for other Libelium Board and look for similar values
# Set your CPU type name & Definition
# Libelium CPU
CPU :=atmega1281
CXXFLAGS_CPU_FLAGS 	:= -DF_CPU=14745600L -DARDUINO=10613 -DARDUINO_AVR_WASP -DARDUINO_ARCH_AVR  
DEFAULT_PROGRAMMER := stk500v1 

# Waspmote Paths
IDE_DRIVE 	   := Z:/
# IDE_DRIVE := /cygdrive/z
IDE_PATH 	   := $(IDE_DRIVE)\\PROGRA~1\\WaspMote

###################################################################################

HARDWARE_PATH := $(IDE_PATH)\\hardware
CPU_PATH  := $(HARDWARE_PATH)\\tools\\avr
WASPMOTE_CORE_PATH := $(HARDWARE_PATH)\\waspmote\\avr\\cores\\waspmote-api
WASPMOTE_LIBS_PATH := $(IDE_PATH)\\libraries

PROJECT_LIBS_PATH := ..\\libraries

# Compiler, library, linker, programmer
GCC_PATH := $(CPU_PATH)\\bin
CC := $(GCC_PATH)\\avr-gcc
AR := $(GCC_PATH)\\avr-ar
OBJCOPY := $(GCC_PATH)\\avr-objcopy
LD := $(CC)
INSTALL := $(GCC_PATH)\\avrdude
SZ := $(GCC_PATH)\\avr-size

# Include directories
CXXFLAGS_INCLUDE_DIR :=-I.\\
CXXFLAGS_INCLUDE_DIR += -I$(PROJECT_LIBS_PATH)\\include
CXXFLAGS_INCLUDE_DIR += -I$(CPU_PATH)\\avr\\include
CXXFLAGS_INCLUDE_DIR += -I$(WASPMOTE_LIBS_PATH)

CXXFLAGS_INCLUDE_LIB_DIR :=-I.\\include
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
###################################################################################
# INSTALL OPTIONS & CONFIGURATION
# ConditionaL compilation & program cpu
ifeq ($(MAKECMDGOALS),server)
DEFAULT_PORT := 31
else ifeq ($(MAKECMDGOALS),client)
DEFAULT_PORT := 32
else
DEFAULT_PORT := 31
endif

PORT := $(DEFAULT_PORT)
# Windows port 
PORT_NUMBER := COM$(PORT)
# cygwin port to reset the device
DEVPORT := /dev/ttyS

DEFAULT_BAUD :=115200
BAUD := $(DEFAULT_BAUD)


PROGRAMMER := $(DEFAULT_PROGRAMMER) 

#install FLAGS
INSTALL_CONF :=$(CPU_PATH)\\etc\\avrdude.conf
INSTALL_FLAGS := -v -V -D -F 

###################################################################################
# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

CLEAN_FLAGS :=-f

# Compiler FLAGS
CXXFLAGS_CPP_DIALECT	:=-std=gnu++11  -x c++
CXXFLAGS_C_DIALECT		:=-std=gnu11  -x c
# CXXFLAGS_PP_OPTIONS:=-E -CC		 # Do only preprocess, to check syntax o
# CXXFLAGS_PP_OPTIONS:=-MMD
CXXFLAGS_C_OPTIONS	:= -c -Os
# CXXFLAGS_CPP_FLAGS  := -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics  -flto 
CXXFLAGS_CPP_FLAGS  := -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics  
CXXFLAGS_CPP_FLAGS  += -fpermissive
CXXFLAGS_CPU 		:= -mmcu=$(CPU)
			   
# CXXFLAGS_OUT_OPTIONS :=-o "nul"
CXXFLAGS_OUT_ASSEMBLER :=-S

# CXXFLAGS_OUT = $(CXXFLAGS_OUT_ASSEMBLER)

# CXXFLAGS_DBG_FLAGS :=-g

###################################################################################
# Define Flags



###################################################################################


# Define Flags
# CXXFLAGS_TESTING := -D__TESTING
CXXFLAGS_DEFINE :=-DDEBUG -D__NOVERBOSE $(CXXFLAGS_TESTING)
CXXFLAGS_DEFINE += $(WASP_DEFINE)

# Turn off all warnings
CXXFLAGS_WARNING := -w

# Turn on all warnings
# CXXFLAGS_WARNING := -Wall -Werror -Wextra -Wpedantic  -Wno-vla
# CXXFLAGS_WARNING := -Wall -Werror -Wextra -Wpedantic 
#CXXFLAGS_WARNING := -Wall -Werror -Wextra -Wno-vla
CXXFLAGS_WARNING += -Waggressive-loop-optimizations
CXXFLAGS_WARNING += -Wvla
CXXFLAGS_WARNING += -Wredundant-decls
CXXFLAGS_WARNING += -Winline 
CXXFLAGS_WARNING += -Wuninitialized
CXXFLAGS_WARNING += -Wstrict-aliasing
CXXFLAGS_WARNING += -Wstrict-overflow
CXXFLAGS_WARNING += -Wtrampolines
CXXFLAGS_WARNING += -Werror=narrowing 
CXXFLAGS_WARNING += -Werror=type-limits
# CXXFLAGS_WARNING += -Wconversion


ifeq ($(SAVETEMPS), yes)
SAVE_TEMPS := -save-temps
endif

# CXXFLAGS_PROGRESS := -v 

CXXFLAGS_CPP_COMMON := $(CXXFLAGS_INCLUDE_DIR)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_DBG_FLAGS)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_PP_OPTIONS)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_C_OPTIONS)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_WARNING)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_DEFINE)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_CPU) $(CXXFLAGS_CPU_FLAGS) 
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_CPP_FLAGS)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_PROGRESS)
CXXFLAGS_CPP_COMMON += $(SAVE_TEMPS)
CXXFLAGS_CPP_COMMON += $(CXXFLAGS_DEFINE_INSTALL)
CXXFLAGS_CPP_COMMON += $(USER_DEFINE)


CXXFLAGS_CPP := $(CXXFLAGS_CPP_DIALECT) $(CXXFLAGS_CPP_COMMON)
CXXFLAGS_C := $(CXXFLAGS_C_DIALECT) $(CXXFLAGS_CPP_COMMON)

CXXFLAGS_ASM :=  -c -g -x assembler-with-cpp 
CXXFLAGS_ASM += $(CXXFLAGS_CPU) $(CXXFLAGS_CPU_FLAGS) 


CXXFLAGS_CORE_C := -ffat-lto-objects

# Library FLAGS
ARFLAGS := rcsu  
# LIBFLAGS := -flto -fuse-linker-plugin


# Linker FLAGS
CXXFLAGS_LD := -w -Os -g  -flto -fuse-linker-plugin
# LD_FLAGS := -flto -fuse-linker-plugin
LD_OPTIMA :=--gc-sections
LD_FLAGS :=-Wl,--gc-sections $(CXXFLAGS_CPU)

# Size flags
SZ_FLAGS :=  -C -d --mcu=$(CPU)

# Include libraries
LDLIBS := -lm
LDPATHS := -L$(COREDIR) -L$(COREOBJDIR) 

# Object copy FLAGS
OBJ_GEN_FLAGS_J := -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  
OBJ_GEN_FLAGS_R := -O ihex -R .eeprom  


# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# Libelium Core API Files

 # WaspMote API 
WaspMoteApiCppFiles:=	main.cpp \
						MemoryFree.cpp \
						WaspPWR.cpp \
						WaspRTC.cpp \
						WaspUSB.cpp \
						WaspUtils.cpp \
						WaspEEPROM.cpp \
						WaspUART.cpp \
						WaspI2C.cpp \
						WaspSPI.cpp \
						WaspOneWire.cpp \
						# WaspSD.cpp \
						# WaspACC.cpp \
						$(WaspXBeeCore) \


WaspMoteApiCFiles:=		WInterrupts.c wiring.c \
						wiring_digital.c wiring_serial.c \
						pins_waspmote.c wiring_analog.c \
						wiring_pulse.c wiring_shift.c

WaspMoteApiSFiles:=		\						

# Cores Paths
WaspMoteApiPath := $(WASPMOTE_CORE_PATH)
CXXFLAGS_INCLUDE_LIB_DIR += -I$(WaspMoteApiPath)


WaspMoteCppSrcs := $(addprefix $(WaspMoteApiPath)\\,$(WaspMoteApiCppFiles))
WaspMoteCppObjs := $(addprefix $(APIOBJDIR)\\,$(notdir $(WaspMoteApiCppFiles:.cpp=.o)))

WaspMoteCSrcs := $(addprefix $(WaspMoteApiPath)\\,$(WaspMoteApiCFiles))
WaspMoteCObjs += $(addprefix $(APIOBJDIR)\\,$(notdir $(WaspMoteApiCFiles:.c=.o)))

WaspMoteSSrcs := $(addprefix $(WaspMoteApiPath)\\,$(WaspMoteApiSFiles))
WaspMoteSObjs += $(addprefix $(APIOBJDIR)\\,$(notdir $(WaspMoteApiSFiles:.S=.So)))

WaspMoteObjs :=	$(WaspMoteCppObjs) \
				$(WaspMoteCObjs) \
				$(WaspMoteSObjs) \


$(WaspMoteCppObjs):$(APIOBJDIR)\\%.o : $(WaspMoteApiPath)\\%.cpp
	@echo WaspMoteApiPath:  $(WaspMoteApiPath)
	@echo Compiling file  $<  to  $@
	@$(CC) $(CXXFLAGS_CPP) $(CXXFLAGS_INCLUDE_LIB_DIR) $<  -o  $@

$(WaspMoteCObjs):$(APIOBJDIR)\\%.o : $(WaspMoteApiPath)\\%.c
	@echo Compiling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_C)  $(CXXFLAGS_INCLUDE_LIB_DIR) $<  -o  $@

$(WaspMoteSObjs):$(APIOBJDIR)\\%.So : $(WaspMoteApiPath)\\%.S
	@echo Assembling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_ASM) $(CXXFLAGS_INCLUDE_LIB_DIR)  $<  -o  $@
# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# Core to twi 
coreApitwiFiles = 	twi_megarf.c

coreApitwiPath := $(WASPMOTE_CORE_PATH)\\twi
CXXFLAGS_INCLUDE_LIB_DIR += -I$(coreApitwiPath)

coreApitwiSrcs := $(addprefix $(coreApitwiPath)\\,$(coreApitwiFiles))
coreApitwiObjs := $(addprefix $(APIOBJDIR)\\,$(coreApitwiFiles:.c=.o)) 

$(coreApitwiObjs):$(APIOBJDIR)\\%.o : $(coreApitwiPath)\\%.c
	@echo Compiling file  $<  to  $@
	@$(CC) $(CXXFLAGS_C) $(CXXFLAGS_INCLUDE_LIB_DIR) $<  -o  $@

# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# Core to eeprom_utilities 
coreApiEempromUtilsFiles = 	aes132_comm.c

coreApiEempromUtilsPath := $(WASPMOTE_CORE_PATH)\\eeprom_utilities
CXXFLAGS_INCLUDE_LIB_DIR += -I$(coreApiEempromUtilsPath)

coreApiEempromUtilsSrcs := $(addprefix $(coreApiEempromUtilsPath)\\,$(coreApiEempromUtilsFiles))
coreApiEempromUtilsObjs := $(addprefix $(APIOBJDIR)\\,$(coreApiEempromUtilsFiles:.c=.o)) 

$(coreApiEempromUtilsObjs):$(APIOBJDIR)\\%.o : $(coreApiEempromUtilsPath)\\%.c
	@echo Compiling file  $<  to  $@
	@$(CC) $(CXXFLAGS_C) $(CXXFLAGS_INCLUDE_LIB_DIR) $<  -o  $@

# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

# anyLibrary
anyLibraryFiles = 	

anyLibraryPath := $(CORE_LIBS_PATH)\\anyLibrary\\src
CXXFLAGS_INCLUDE_LIB_DIR += -I$(anyLibraryPath)

anyLibrarySrcs := $(addprefix $(anyLibraryPath)\\,$(anyLibraryFiles))
anyLibraryObjs := $(addprefix $(APIOBJDIR)\\,$(anyLibraryFiles:.cpp=.o)) 

$(anyLibraryObjs):$(APIOBJDIR)\\%.o : $(anyLibraryPath)\\%.cpp
	@echo Compiling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_CPP) $(CXXFLAGS_INCLUDE_LIB_DIR)  $<  -o  $@


# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
ApiLibObjs := 	$(coreApitwiObjs) \
				$(coreApiEempromUtilsObjs) \
				$(anyLibraryObjs) \


# ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
###################################################################################

# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# Core to access to user library
# Duplicate & modified as necessary
UserWaspMoteFiles = 

UserWaspMotePath := $(CORE_LIBS_PATH)\\userWaspMotePath\\
CXXFLAGS_INCLUDE_LIB_DIR += -I$(UserWaspMotePath)

WaspMoteYourLibrarySrcs := $(addprefix $(UserWaspMotePath)\\,$(UserWaspMoteFiles))
UserWaspMoteObjs := $(addprefix $(APIOBJDIR)\\,$(UserWaspMoteFiles:.cpp=.o)) 


$(UserWaspMoteObjs):$(APIOBJDIR)\\%.o : $(UserWaspMotePath)\\%.cpp
	@echo Compiling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_CPP) $(CXXFLAGS_INCLUDE_LIB_DIR)  $<  -o  $@

# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# PROJECT  FILES

# Project Main Files
projectCppFiles:=	HelloWord.cpp \
					
projectSrc := $(SRCDIR)

projectCppObjs := $(addprefix $(OBJDIR)\\,$(projectCppFiles:.cpp=.o))
projectCppSrcs := $(addprefix $(SRCDIR)\\, $(projectCppFiles))
serverFiles := $(addprefix $(SRCDIR)\\, $(serverFiles))


$(projectCppObjs):$(OBJDIR)\\%.o : $(projectSrc)\\%.cpp
	@echo Compiling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_CPP) $(CXXFLAGS_INCLUDE_LIB_DIR)  $<  -o  $@

###################################################################################
# Project Libraries USER-api Files

# USER-api
# projectUserApiCppFiles:=	

ProjectUserApiPath := $(PROJECT_LIBS_PATH)\\User-api
CXXFLAGS_INCLUDE_LIB_DIR += -I$(ProjectUserApiPath)

projectUserApiCSrcs := $(addprefix $(ProjectUserApiPath)\\,$(projectUserApiCppFiles))
projectUserApiCObjs := $(addprefix $(OBJDIR)\\,$(notdir $(projectUserApiCppFiles:.cpp=.o)))

$(projectUserApiCObjs):$(OBJDIR)\\%.o : $(ProjectUserApiPath)\\%.cpp
	@echo Compiling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_CPP) $(CXXFLAGS_INCLUDE_LIB_DIR)  $<  -o  $@
	
# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# Project Libraries Libs Files

ProjectUSERlibsCppFiles :=	

ProjectUSERlibsPath := $(PROJECT_LIBS_PATH)\\User-libs 
CXXFLAGS_INCLUDE_LIB_DIR += -I$(ProjectUSERlibsPath)

ProjectUSERlibsCSrcs := $(addprefix $(ProjectUSERUSERlibsPath)\\,$(ProjectUSERlibsCppFiles))
ProjectUSERlibsCObjs := $(addprefix $(OBJDIR)\\,$(notdir $(ProjectUSERlibsCppFiles:.cpp=.o)))

$(ProjectUSERlibsCObjs):$(OBJDIR)\\%.o : $(ProjectUSERlibsPath)\\%.cpp
	@echo Compiling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_CPP) $(CXXFLAGS_INCLUDE_LIB_DIR)  $<  -o  $@


.PHONY: checkfiles
checkfiles:
	@echo Files of ProjectUSERlibs
	@echo
	@echo ProjectUSERlibsCSrcs = $(ProjectUSERlibsCSrcs)
	@echo
	@echo ProjectUSERlibsCObjs = $(ProjectUSERlibsCObjs)
	@echo USER_DEFINE = $(USER_DEFINE)
	@echo CORE_API_PATH = -I$(CORE_API_PATH)
	@echo CORE_LIBS_PATH = -I$(CORE_LIBS_PATH)
	@echo CXXFLAGS_INCLUDE_LIB_DIR = $(CXXFLAGS_INCLUDE_LIB_DIR)
	@echo

# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
# USER Utils
ProjectUSERutilsCppFiles:=	

ProjectUSERutilsPath := $(PROJECT_LIBS_PATH)\\User-utils
CXXFLAGS_INCLUDE_LIB_DIR += -I$(ProjectUSERutilsPath)

ProjectUSERutilsCSrcs := $(addprefix $(ProjectUSERUSERutilsPath)\\,$(ProjectUSERutilsCppFiles))
ProjectUSERutilsCObjs := $(addprefix $(OBJDIR)\\,$(notdir $(ProjectUSERutilsCppFiles:.cpp=.o)))

$(ProjectUSERutilsCObjs):$(OBJDIR)\\%.o : $(ProjectUSERutilsPath)\\%.cpp
	@echo Compiling file  $<  to  $@
	@$(CC)  $(CXXFLAGS_CPP) $(CXXFLAGS_INCLUDE_LIB_DIR)  $<  -o  $@

###################################################################################
CORE_FILES := 	$(WaspMoteObjs) \
				$(ApiLibObjs) \
				$(UserWaspMoteObjs) \
				

PROJECT_FILES := 	$(projectCppObjs) \
					$(projectUserApiCObjs) \
					$(ProjectUSERlibsCObjs) \
					$(ProjectUSERutilsCObjs) 

# Clean files
CLEAN_FILES := $(PROJECT_FILES) $(CORE_FILES)  $(libcore) $(targetelf)  $(target) $(targeteep)

# -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-
###################################################################################
# Targets start here

.PHONY: all install server client core clean projectclean coreclean doconfig help
$(libcore): $(CORE_FILES)
	@echo Doing core library :  $(libcore)
	@$(AR) $(ARFLAGS) $(libcore) $(CORE_FILES) 
	@echo Core library $(libcore) Done

core: $(libcore)
	@echo 
	

ifndef SAVE_TEMPS
_projectAPI: $(PROJECT_FILES)
	@echo Built all project files $(project)
else
_projectAPI: $(PROJECT_FILES)
	@echo Moving all temporary file to $(TMPDIR)
	@mv -f 	 *.s -t $(TMPDIR)
	@mv -f 	 *.ii -t $(TMPDIR)
endif

projectAPI: _projectAPI

$(targetelf): core projectAPI
	@echo Linking to $(targetelf)
	@$(LD)  $(CXXFLAGS_LD) $(LD_FLAGS) -o $(targetelf) $(PROJECT_FILES) $(coreApitwiObjs) $(libcore) $(LDPATHS) $(LDLIBS)
ifdef SHOW_SIZE	
	@$(SZ) $(SZ_FLAGS) $(targetelf) 
endif
	@echo Done link: $(targetelf)

targetelf: $(targetelf)

$(target): $(targetelf)
	@echo Generating target HEX files: $(targeteep) and $(target)
	@$(OBJCOPY) $(OBJ_GEN_FLAGS_J) $(targetelf) $(targeteep)
	@$(OBJCOPY) $(OBJ_GEN_FLAGS_R) $(targetelf) $(target)
	@echo Done target: $(target)

target: $(target)


all: target
	@echo Done all

install: all
	-@let st=$(PORT)-1 && echo Reset port $(PORT_NUMBER) on $(DEVPORT)$$st && stty -F $(DEVPORT)$$st 1200
	$(INSTALL) -C$(INSTALL_CONF) $(INSTALL_FLAGS) -p$(CPU) -c$(PROGRAMMER) -P$(PORT_NUMBER) -b$(BAUD) -Uflash:w:$(target):i
	@echo Installed $(target) on port $(PORT_NUMBER)


.PHONY: size
size: 
	@(ls  $(targetelf) > null || make all) && $(SZ) $(SZ_FLAGS) $(targetelf)

clean:
	@rm $(CLEAN_FLAGS) $(CLEAN_FILES)  $(addprefix $(TMPDIR)/,$(notdir $(CLEAN_FILES:.o=.ii))) $(addprefix $(TMPDIR)/,$(notdir $(CLEAN_FILES:.o=.s)))
	@echo Delete all built files, core and project, witch extension: .o, .ii, .s

# @echo Borrando los archivos del proyecto: 
coreclean:
	@rm $(CLEAN_FLAGS) $(CORE_FILES)  $(libcore)  $(addprefix $(TMPDIR)\\,$(notdir $(CORE_FILES:.o=.ii))) $(addprefix $(TMPDIR)\\,$(notdir $(CORE_FILES:.o=.s)))
	@echo Delete all built core files witch extension: .o, .ii, .s

# @echo Borrando los archivos del proyecto: 
projectclean:
	@rm $(CLEAN_FLAGS) $(PROJECT_FILES)   $(addprefix $(TMPDIR)\\,$(notdir $(PROJECT_FILES:.o=.ii))) $(addprefix $(TMPDIR)\\,$(notdir $(PROJECT_FILES:.o=.s)))
	@echo Delete all built projecto files witch extension: .o, .ii, .s

.PHONY: makedirs
makedirs: 
	@for dir in $(OUTDIRS); do \
		echo Creating directory: $$dir; \
		mkdir -p $$dir; \
	done

config: makedirs
	@echo All configurations are done

version:
	@echo Makefile for Arduino project
	@echo "$(FILE_VERSION)"
	@echo "$(FILE_CREATEBY)"
	@echo "$(FILE_URL)"
	@echo "$(FILE_COPYRIGHT)"
	@echo "$(FILE_BUGS)"

.DEFAULT: all

.PHONY: help
help:
	@echo -e "\t Usage make [options] [target] ..."
	@echo -e "\t Options: in adiction to make options, there are the following ones."
	@echo -e "\t\t SAVETEMPS=yes  \t Save temporary files when compile. Default no."
	@echo -e "\t\t PORT=number \t\t Override default port number."
	@echo -e "\t\t USER_DEFINE=-Dvalue \t User define values."
	@echo -e "\t\t -k \t\t\t Continue as much as possible after an error."
	@echo -e "\t\t --trace \t\t Show tracing information for make execution. Prints the entire recipe to be executed."
	@echo -e " "
	@echo -e "Targets: one or more of the followings by order of execution. "
	@echo -e "\t help \t\t\t Print this message."
	@echo -e "\t all \t\t\t Compile the entire program. Default target."
	@echo -e "\t install \t\t Compile the entire program and install the program in the device."
	@echo -e "\t server \t\t Conditional compile with server options and install. Touch files to compile."
	@echo -e "\t client	\t\t Conditional compile with client options and install. Touch files to compile."
	@echo -e "\t core \t\t\t Compile all file of the core system."
	@echo -e "\t clean \t\t\t Delete all files that are created by building the program."
	@echo -e "\t projectclean \t\t Delete all files that are created by building the program but only the specifics ones of the project."
	@echo -e "\t coreclean \t\t Delete all files that are created by building for the core system."
	@echo -e "\t config \t\t Create all directories [and dependencies] needed to build the program."
	@echo -e "\t version \t\t Print version of this file."
	@echo  
	@echo -e "\t This makefile is tested in Windows 7 system with Cygwin & Arduino IDE installed and set in the path."
	@echo -e "\t To work in Linux modified the path separator as needed."
	@echo -e "\t GNU Cygwin: https://cygwin.com"
	@echo -e "\t WaspMote IDE: http://www.libelium.com/development/waspmote/sdk_applications"
	@echo -e "\t TODO:"
	@echo -e "\t\t - create dependencies rules."
	@echo -e "\t\t - automatic configuration."
	@echo -e "\t\t - automatic configuration for any CPU."
	@echo -e "\t\t - modified to work with Linux."
	@echo  
	@echo -e "\tThis project is licensed under GNU Lesser General Public License - see the [LICENSE.txt](LICENSE.txt) file for details"
	@echo -e "\t# Design & Implementation : Jesus Revilla de Lucas  <jrevilla@ipe.csic.es>
	@echo -e "\t# Copyright(C) 2019 IPE - CSIC
	@echo 	
