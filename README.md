# testingBasalt

# Build

First of all, install the necessary packages:

	sudo apt-get install cmake nlohmann-json-devel libcurl-devel gcc-c++

Next, run the following commands to build:

	mkdir build && cd build
	cmake ..
	make


# Installation

For install the package on the system, you need to run the following commands:

	chmod +x ./install.sh
	sudo ./install.sh

install.sh simply copies the contents of the build folder to /usr/bin and /usr/lib

# TODO

Figure out the RPM build and do it the right way, jesus christ

