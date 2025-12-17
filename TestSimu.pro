QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app
INCLUDEPATH += ../Simu/
SOURCES +=  tst_testpointmateriel.cpp \
	../Simu/frame.cpp \
	../Simu/lienressort.cpp \
	../Simu/force.cpp \
	../Simu/pointMateriel.cpp

HEADERS += \
	../Simu/frame.h \
	../Simu/grandeur.h \
	../Simu/lienressort.h \
	../Simu/force.h \
	../Simu/pointMateriel.h
