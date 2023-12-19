#!/bin/bash

if ! command -v pip &> /dev/null
then
  echo "WARNING: pip not found. Attempting to install pip..."
  sudo apt-get update
  sudo apt-get install -y python3-pip
fi

if ! command -v conan &> /dev/null
then
  echo "Conan not found. Installing..."
  pip install conan==1.59
fi

BUILD_DIR="build"
if [ ! -d "$BUILD_DIR" ]; then
  echo "Creating build directory..."
  mkdir "$BUILD_DIR"
fi

if ! conan profile show default &> /dev/null; then
  echo "Creating default profile..."
  conan profile new --detect default
fi

cd "$BUILD_DIR"

if ! conan profile show default | grep "compiler.libcxx=libstdc++11"; then
  echo "Updating default profile to use libstdc++11..."
  conan profile update settings.compiler.libcxx=libstdc++11 default
fi

if ! conan profile show default | grep "compiler.version=9.5"; then
  echo "Updating default profile to use compiler version 9.5..."
  conan profile update settings.compiler.version=9.5 default
fi

if [ -f "../.env" ]; then
  source ../.env
fi

conan install .. --build=missing

cmake -DSERVER_PORT="${SERVER_PORT:-8080}" -DHAS_GTEST=ON -DVERSION="${VERSION:-1.0.0}" -DCMAKE_BUILD_TYPE=Debug ..

cmake --build .

if [ $? -eq 0 ]; then
  echo "
  ##############################################################
  #                                                            #
  #                  COMPILATION FINISHED                      #
  #                                                            #
  ##############################################################
  "
else
  echo "
  ##############################################################
  #                                                            #
  #                   FAIL ON COMPILATION                      #
  #                                                            #
  ##############################################################
  "
fi
