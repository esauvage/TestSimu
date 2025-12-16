QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app
INCLUDEPATH += ../../github/Simu/
SOURCES +=  tst_testpointmateriel.cpp \
	../../github/Simu/frame.cpp \
	../../github/Simu/lienressort.cpp \
	../../github/Simu/pointmassif.cpp

HEADERS += \
	../../github/Simu/frame.h \
	../../github/Simu/grandeur.h \
	../../github/Simu/lienressort.h \
	../../github/Simu/pointmassif.h
