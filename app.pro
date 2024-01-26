TARGET = myapp
QT = core gui widgets
CONFIG += c++11
SOURCES += \
    main.cpp \
    $$PWD/src/gui/*.cpp
    
    

HEADERS += \
    $$PWD/src/gui/*.h
    
    