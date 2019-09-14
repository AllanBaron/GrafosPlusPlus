TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Grafo/Grafo.cpp \
    Grafo/GrafoMatriz.cpp \
    Grafo/GrafoLista.cpp

HEADERS += \
    Grafo/Grafo.h \
    Grafo/GrafoMatriz.h \
    Grafo/GrafoLista.h \
    Grafo/Adjacente.h
