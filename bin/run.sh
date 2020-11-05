#!/bin/sh

export LD_LIBRARY_PATH=../lib:../lib/hisi:../lib/opencv:$LD_LIBRARY_PATH

./yolov5_demo $1

