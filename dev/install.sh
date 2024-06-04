#!/usr/bin/env bash
# Verify that the user wants to run the install script.
function request_confirmation()
{
  echo 'Please enter "y" to continue or any other key to cancel.'
  read input
  if [[ $input == 'y' ]]; then
    echo '[o] Install script confirmed.'
  else
    echo '[x] Install script canceled.'
    exit 1
  fi
}
echo '[o] Installing required packages:'
# LINUX - Needs testing.
if [[ $OSTYPE == "linux-gnu"* ]]; then
  echo '[!] Warning: This script is about to run "sudo apt-get update" and'
  echo '"sudo apt-get upgrade".'
  request_confirmation
  sudo apt-get update
  sudo apt-get upgrade
  sudo apt-get install build-essential
  sudo apt-get install cmake
  sudo apt-get install git
  sudo apt-get install libsdl2-dev
  sudo apt-get install libsdl2-image-dev
  sudo apt-get install libsdl2-mixer-dev
  sudo apt-get install libsdl2-ttf-dev
# WINDOWS
elif [[ $OSTYPE == "msys" ]] || [[ $OSTYPE == "win32" ]]; then
  echo '[!] Warning: This script is about to run "pacman -Syu".'
  request_confirmation
  pacman -Syu
  pacman -S base-devel
  pacman -S git
  pacman -S mingw-w64-x86_64-gcc
  pacman -S mingw-w64-x86_64-make
  pacman -S mingw-w64-x86_64-cmake
  pacman -S mingw-w64-x86_64-SDL2
  pacman -S mingw-w64-x86_64-SDL2_image
  pacman -S mingw-w64-x86_64-SDL2_mixer
  pacman -S mingw-w64-x86_64-SDL2_ttf
# MACOS - Needs testing.
elif [[ $OSTYPE == "darwin"* ]]; then
  if ! command -v brew >/dev/null 2>&1; then
    echo 'Brew is not detected on your system.'
    echo 'This script requires Brew to run. Would you like to install Brew now?'
    echo 'Please enter "y" to continue or any other key to cancel.'
    read input
    if [[ $input == 'y' ]]; then
      echo '[o] Installing Brew:'
      /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    else
      echo '[x] Install script canceled. Brew is required.'
      exit 1
    fi
  fi
  echo '[!] Warning: This script is about to run "brew update" and'
  echo '"brew upgrade".'
  request_confirmation
  brew update
  brew upgrade
  brew install git
  brew install cmake
  brew install sdl2
  brew install sdl2_image
  brew install sdl2_mixer
  brew install sdl2_ttf
fi
