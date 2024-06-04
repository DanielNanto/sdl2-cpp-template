#!/usr/bin/env bash
clear
# Check if the user wants to run the install script.
if [[ $1 == '-i' ]]; then
  # Check if the install script has execution permissions.
  if [[ ! -x "./dev/install.sh" ]]; then
    echo '[!] Warning: The install script needs execution permissions.'
    echo 'This script will run the command "chmod a+x ./dev/install.sh".'
    echo 'Please enter "y" to continue or any other key to cancel.'
    read input
    if [[ $input == 'y' ]]; then
      echo '[o] Elevating install script permissions.'
      chmod a+x ./dev/install.sh
    else
      echo '[x] Unable to execute installation script.'
      echo '[x] Terminating project compilation and execution.'
      exit 1
    fi
  fi
  echo '[o] Running install script.'
  ./dev/install.sh # read this input
  if [[ $? -ne 0 ]]; then
    echo '[x] Installation script failed.'
    echo '[x] Terminating project compilation and execution.'
    exit 1
  fi
fi
# Run the build script.
# LINUX
if [[ $OSTYPE == "linux-gnu"* ]]; then
  echo '[o] Linux detected.'
  echo '[o] CMake:'
  cmake -B./build -H./
  if [[ $? -ne 0 ]]; then
    echo '[x] Cmake failed.'
    exit 1
  fi
  echo '[o] Make:'
  make -C ./build
  if [[ $? -ne 0 ]]; then
    echo '[x] Build failed.'
    exit 1
  fi
  echo 'Launching program:'
  ./build/sdl2-cpp-template
  # To-Do: Create a shortcut in the parent directory.
  # if [[ $1 == '-v' ]]; then
  #   echo '[o] Launching program with Valgrind'
  #   valgrind ./build/sdl2-cpp-template > log.txt 2>&1
  # else
  #   echo '[o] Launching program:'
  #   ./build/sdl2-cpp-template
  # fi
# WINDOWS
elif [[ $OSTYPE == "msys" ]] || [[ $OSTYPE == "win32" ]]; then
  echo '[o] Windows detected.'
  echo '[o] CMake:'
  cmake -B./build -H./
  if [[ $? -ne 0 ]]; then
    echo '[x] Cmake failed.'
    exit 1
  fi
  echo '[o] Ninja:'
  ninja -C ./build 
  if [[ $? -ne 0 ]]; then
    echo '[x] Build failed.'
    exit 1
  fi
  echo '[o] Creating a shortcut in the project directory:'
  powershell '
    $WshShell = New-Object -comObject WScript.Shell
    $Shortcut = $WshShell.CreateShortcut("sdl2-cpp-template.lnk")
    $Shortcut.TargetPath = (Resolve-Path "build\sdl2-cpp-template.exe").Path
    $Shortcut.Save() '
  if [[ $? -ne 0 ]]; then # Test this - Powershell may not return an error code.
    echo '[x] Shortcut creation failed.'
    exit 1
  fi
  echo '[o] Launching program:'
  ./build/sdl2-cpp-template.exe
# MACOS
elif [[ $OSTYPE == "darwin"* ]]; then
  echo '[o] MacOS detected.'
  echo '[o] CMake:'
  cmake -B./build -H./ -GXcode
  if [[ $? -ne 0 ]]; then
    echo '[x] Cmake failed.'
    exit 1
  fi
  echo '[o] Make:' 
  xcodebuild -project ./build/sdl2-cpp-template.xcodeproj -configuration Release
  if [[ $? -ne 0 ]]; then
    echo '[x] Build failed.'
    exit 1
  fi
  echo '[o] Creating a shortcut in the project directory:'
  ln -sf "$(pwd)/build/Release/sdl2-cpp-template" "../sdl2-cpp-template"
  if [[ $? -ne 0 ]]; then
    echo '[x] Shortcut creation failed.'
    exit 1
  fi
  echo 'Launching program:'
  ./build/Release/sdl2-cpp-template
fi
