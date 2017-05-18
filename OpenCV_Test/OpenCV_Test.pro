TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

##pkg-config --cflags opencv #find include folder
#INCLUDEPATH += /usr/local/include

#pkg-config --libs opencv #find lib directory and all libs
LIBS += -L/usr/local/libs -lopencv_core -lopencv_highgui \
-lopencv_imgcodecs -lopencv_imgproc \
-lopencv_video -lopencv_videoio

include(deployment.pri)
qtcAddDeployment()

