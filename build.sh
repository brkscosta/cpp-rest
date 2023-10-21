#!/bin/bash

if [ ! -d "build" ]; then
    mkdir src/build
fi

cd src/build

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
