TEMPLATE = app
TARGET = 2048qt

QT = core gui

#CONFIG += debug

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3

HEADERS += MainWindow.h GameButtonGrid.h GameButton.h Board.h
SOURCES += MainWindow.cpp GameButtonGrid.cpp GameButton.cpp \
	Board.cpp main.cpp
