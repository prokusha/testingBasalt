# testingBasalt

# Build

First of all, install the necessary packages:

	sudo apt-get install cmake nlohmann-json-devel libcurl-devel gcc-c++ rpmbuild-helper

Next, run the following commands to build the RPM package:

	mkdir build && cd build
	cmake ..
	cmake --build .
	cpack -G RPM

Once in the build folder, you will find the file like

	branchApp-X.X.X-Linux.rpm

which can be used for installation.

# Installation

For install the package on the system, you need to run the following command:

	sudo rmp --install /path/to/branchApp-X.X.X-Linux.rpm

