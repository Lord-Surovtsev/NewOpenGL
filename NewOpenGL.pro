QT += core #gui opengl
#TEMPLATE = app
#CONFIG += console
#CONFIG -= app_bundle
#CONFIG -= qt

#LIBS += libfreeglut -lopengl32 -lglu32 -luser32 -lsfml-system
#INCLUDEPATH += /usr/include

LIBS += -lGL -lGLU -lX11 -lSOIL
#LIBS += -lGLEW #-lglut -lGL -lGLU
LIBS += -lglut -lGL -lGLU -lGLEW
LIBS += -lsfml-system -lsfml-window

SOURCES += \
    main.cpp
