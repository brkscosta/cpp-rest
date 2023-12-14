#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

cd build

# Carrega as variáveis do arquivo .env
if [ -f "../.env" ]; then
    source ../.env
fi

: ${VERSION:="1.0.0"}

cmake -DVERSION=${VERSION} -DCMAKE_BUILD_TYPE=Debug -DBUILD_SSL=${BUILD_SSL:-NO} -DBUILD_TESTS=${BUILD_TESTS:-NO} ..

make

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
