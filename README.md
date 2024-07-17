# SDL2-Cpp-Template
This is a basic SDL2 template. It is written in C++ and uses Cmake.

# Setup
  There are several ways to set up your project. I have outlined a few possible 
  methods below.  
  *Optionally, I have also provided an installation [bash script](#scripts) that
  can be executed on macOS, MSYS2 on Windows 11, and some Linux systems.*  
## GNU-Linux
  * Open a terminal and install the following packages:
  * `$ sudo apt-get update`
  * `$ sudo apt-get upgrade`
  * `$ sudo apt-get install build-essential`
  * `$ sudo apt-get install cmake`
  * `$ sudo apt-get install libsdl2-dev`
  * `$ sudo apt-get install libsdl2-image-dev`
  * `$ sudo apt-get install libsdl2-mixer-dev`
  * `$ sudo apt-get install libsdl2-ttf-dev`
## MacOS
  * Download and install Brew from their 
  [GitHub repository](https://github.com/Homebrew/brew) or their
  [website](https://brew.sh/).
  * In a terminal, install the required packages with the following commands:
  * `$ brew update`
  * `$ brew upgrade`
  * `$ brew install git`
  * `$ brew install cmake`
  * `$ brew install sdl2`
  * `$ brew install sdl2_image`
  * `$ brew install sdl2_mixer`
  * `$ brew install sdl2_ttf`
  * Make sure your Mac is up to date.  
  * Make sure you have the most recent version of Xcode installed.  
## Windows 11 - MSYS2 MinGW (64-bit)
  * Download and install MSYS2 from their 
  [GitHub repository](https://github.com/msys2/msys2.github.io) or their 
  [website](www.msys2.org).
  * Wherever you install MSYS, make sure to add the path to the mingw64 bin
  ("C:\msys64\mingw64\bin" for example) to the path environment variable.
  * `$ sudo pacman -Syu`
  * `$ pacman -S base-devel`
  * `$ pacman -S git`
  * `$ pacman -S mingw-w64-x86_64-gcc`
  * `$ pacman -S mingw-w64-x86_64-make`
  * `$ pacman -S mingw-w64-x86_64-cmake`
  * `$ pacman -S mingw-w64-x86_64-SDL2`
  * `$ pacman -S mingw-w64-x86_64-SDL2_image`
  * `$ pacman -S mingw-w64-x86_64-SDL2_mixer`
  * `$ pacman -S mingw-w64-x86_64-SDL2_ttf`

# Scripts
Bash scripts may need execution permissions to run on your system. You may need 
to use a command such as 'chmod'.  
`$ chmod a+x run.sh`  
If you would like to run the install script, you can either run it directly from
[dev/install.sh](./dev/), or amend the argument '-i' to the run script.  
`$ ./run.sh -i`  
<!-- If using GNU-Linux, the argument '-v' can be used with run.sh to run the 
program through Valgrind.  
`$ ./run.sh -v`   -->

# Project Directory Layout Example
<ol type="I">
  <li> project_folder/
    <ol type="A">
      <li> build/ </li>
      <li> data/ </li>
        <ol type="1">
          <li> ttf/ </li>
        </ol>
      <li> dev/ </li>
        <ol type="1">
          <li> install.sh </li>
        </ol>
      <li> doc/ </li>
      <li> dlls/ </li>
      <li> external/ </li>
      <li> include/ </li>
      <li> src/ </li>
      <li> run.sh </li>
    </ol>
  </li>
</ol>

*Note: Your project can be easily renamed by searching "sdl2-cpp-template" 
within your project directory and replacing all instances of it.*  
