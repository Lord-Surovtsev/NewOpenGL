QT += core #gui opengl
#TEMPLATE = app
#CONFIG += console
#CONFIG -= app_bundle
#CONFIG -= qt

#LIBS += libfreeglut -lopengl32 -lglu32 -luser32 -lsfml-system
#INCLUDEPATH += /usr/include

#LIBS += -lSDL2 -lGL -lGLU -lgl3w -lX11
#LIBS += -lGLEW #-lglut -lGL -lGLU
LIBS += -lglut -lGL -lGLU -lGLEW
LIBS += -lsfml-system

SOURCES += \
    main.cpp
