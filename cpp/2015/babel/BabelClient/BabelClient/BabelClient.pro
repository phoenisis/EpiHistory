HEADERS += \
    portaudio.h \
    pa_win_wmme.h \
    pa_win_waveformat.h \
    pa_win_wasapi.h \
    pa_win_ds.h \
    pa_mac_core.h \
    pa_linux_alsa.h \
    pa_jack.h \
    pa_asio.h \
    Codec.h \
    Audio.h \
    Network.h \
    qbabel.h \
    dial.h

SOURCES += \
    Codec.cpp \
    Audio.cpp \
    Network.cpp \
    Main.cpp \
    qbabel.cpp \
    dial.cpp

OTHER_FILES +=

QT += network

FORMS += \
    qbabel.ui \
    dial.ui

TEMPLATE    =   app
