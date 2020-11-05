PROJECT_HOME = ../..
OPENCV_PATH=${PROJECT_HOME}/lib/opencv
CUXX = arm-himix200-linux-gcc

BIN = ${PROJECT_HOME}/bin/yolov5_demo

SRCS = ./src/main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -std=c++11 -O3 -I${PROJECT_HOME}/include -I${PROJECT_HOME}/include/hisi

LIBFLAGS = -lpthread -lm -ldl -lstdc++ -L${PROJECT_HOME}/lib -lsdk_yolov5 -L${PROJECT_HOME}/lib/hisi -lnnie -live -lmpi -lVoiceEngine -ldnvqe -lsecurec -lupvqe -L${OPENCV_PATH} -lopencv_core -lopencv_imgcodecs -lopencv_imgproc

all: $(BIN)

$(OBJS):

%.o: %.cpp
	$(CUXX) -c $(CFLAGS) $< -o $@

$(BIN): $(OBJS)
	$(CUXX) $^ $(LIBFLAGS) -o $@ 

clean:
	rm -f $(BIN) ./src/*.o

