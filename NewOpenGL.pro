TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += libfreeglut -lopengl32 -lglu32 -luser32

SOURCES += \
    main.cpp
