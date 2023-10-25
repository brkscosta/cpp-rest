#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

cd build

cmake -DBUILD_SSL=NO -DBUILD_TESTS=NO ..

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
