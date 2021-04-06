QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcustomer.cpp \
    addmark.cpp \
    addorder.cpp \
    connect.cpp \
    customer.cpp \
    customerrepo.cpp \
    genoffert.cpp \
    initdb.cpp \
    main.cpp \
    mainwindow.cpp \
    mark.cpp \
    operation.cpp \
    order.cpp \
    orderrepo.cpp \
    pricecalculation.cpp \
    tableeditor.cpp \
    viewfinalproducts.cpp \
    viewmark.cpp \
    viewprice.cpp \
    viewstocks.cpp

HEADERS += \
    Hider.h \
    addcustomer.h \
    addmark.h \
    addorder.h \
    connect.h \
    customer.h \
    customerrepo.h \
    genoffert.h \
    initdb.h \
    mainwindow.h \
    mark.h \
    operation.h \
    order.h \
    orderrepo.h \
    pdfEditor.h \
    pricecalculation.h \
    tableeditor.h \
    viewfinalproducts.h \
    viewmark.h \
    viewprice.h \
    viewstocks.h

FORMS += \
    addcustomer.ui \
    addmark.ui \
    addorder.ui \
    mainwindow.ui \
    pricecalculation.ui \
    tableeditor.ui \
    viewfinalproducts.ui \
    viewmark.ui \
    viewprice.ui \
    viewstocks.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
