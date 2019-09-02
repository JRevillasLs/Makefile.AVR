# Makefile for Arduino
+ [About](#about)
+ [Features](#features)
+ [Prerequisites] (#prerequisites)
+ [Installing] (#installing)
+ [Usage](#usage)
+ [Example](#example)
+ [TODO](#todo)
+ [License](#license)

## About
Makefile for make utilties to work faster with large Arduino projects than Arduino IDE.

## Features

	Work with make utilities
	Only rebuilds modified files
	Install program into device
	Take all advantage of GNU make utilities & gcc compiler
	Can live with a Arduino project
	

### Prerequisites
	
	[Arduino IDE](https://www.arduino.cc):  get it from [https://www.arduino.cc](https://www.arduino.cc)

```
	Windows 7 system:
		[Cygwin](https://cygwin.com) for windows: get it from [https://cygwin.com](https://cygwin.com)
		Add to enviroment varialbe PATH Cygwin location
	
```

### Installing

	No install required. Just copy **Makefile.tpl** to your project directory as **Makefile** and modified as needed

## Getting Started
	
	Copy **Makefile.tpl** from Arduino or Libelium path to your project directory as **Makefile** and modified as needed
	Open a console and change to the project directory, then execute
	```
		make config
		make all
		make install
	```

## Usage
	Copy **Makefile.tpl** to your project directory as **Makefile** 
	This is for Arduino UNO Board. More details inside Makefile as a comments
	Edit Makefile and modified the following variables to fit your system and project:
	```
	project  := projectname
	IDE_DRIVE 	   := Z:/
	IDE_PATH 	   := $(IDE_DRIVE)\\PROGRA~1\\Arduino
	IDE_PATH 	   := $(PROGFILE_PATH)\\Arduino
	DEFAULT_PORT   := 38
	projectCppFiles:=	projectfiles.cpp \
	```
	Then, it is work just a any Makefile
	```
		make clean all 
		make help
		make -k install
		etc ... 
	```


## Example

	HelloWord for Arduino UNO and for Libelium  are provided as examples. 
	Also Tasks configuration to work with Visual Code is provide with the example
	```
		Connect you Arduino UNO to your computer
		Find out which serial port is assigned to Arduino UNO. For example COM7
		Open command line shell
		Change to HelloWord directory
		type 'make config' to create all destination directories
		type 'make all' to build project. Optional
		type 'make install PORT=38' to build project (if needed) and install
		Open a serial terminal on port COM7 and see the result. For example serial monitor on Arduino IDE at 125200 baudios
	```	


## TODO

	Create dependencies rules.
	Automatic configuration.
	Automatic configuration for any CPU.
	Modified to work with Linux.

## Authors

* **Jesús Revilla de Lucas** -  [JRevillasLs](https://github.com/JRevillasLs)

## License

This project is licensed under GNU Lesser General Public License - see the [LICENSE.txt](LICENSE.txt) file for details

