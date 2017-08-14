## OpenCV / C++ Template

This template project consists of a single library, an executable that uses the library and tests for the library with the `catch` framework. `CMake` is used for the build system.

Additinaly, the OpenCV library can be enabled with a `WITH_OPENCV_DEBUG` flag.

##### How to use
```bash
> git clone https://github.com/cirquit/opencv-template
> cd opencv-template
> rm .git
> cd ..
> mv opencv-template <your-project-name>
> cd <your-project-name>
> vim CMakeLists.txt 
(modify the project names)
```

##### How to install OpenCV

* Go to the [OpenCV hompage](http://opencv.org/releases.html), download the latest stable source (I it tested with 3.3).
* Extract the folder `opencv-3.3` anywhere
* You probably will have to install multiple dependencies, which are missing. This depends on, e.g Java and Python bindings, use of `gstreamer` etc. Modify the `opencv-3.3/CMakeLists.txt` file accordingly and install the tools. Almost any errors you will encounter are easily searchable, which point to a single `apt-get install` command.
* Here is one, which covers the basics requirements `sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev`

```bash
> cd opencv-3.3
> mkdir build && cd build
```

If you want to finalize your OpenCV program and run it on a e.g Jetson TX1, use the following command (this improves the overall performance):

```bash
> cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local .. 
```

Otherwise, to be able to find bugs easier with `gdb`, compile with

```bash
> cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/usr/local ..
```

Afterwards, install the library:

```bash
> make
> sudo make install
```

##### How to enable opencv while compiling
```bash
> cd <your-project-name>
> mkdir build && cd build
> cmake .. -DWITH_OPENCV_DEBUG=ON
> make
```

##### How run example program

```bash
> cd <your-project-name>
> mkdir build && cd build
> cmake .. -DWITH_OPENCV_DEBUG=ON
> make
> cd src
> ./opencv-exec
```
