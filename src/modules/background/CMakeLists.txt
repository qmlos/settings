liri_add_qml_plugin(background
    MODULE_PATH
        "Liri/Settings/Background"
    SOURCES
        backgroundsmodel.cpp
        backgroundsmodel.h
        colorsmodel.cpp
        colorsmodel.h
        plugin.cpp
    QML_FILES
        qmldir
    DEFINES
        #QT_NO_CAST_FROM_ASCII
        QT_NO_FOREACH
    LIBRARIES
        Qt5::Qml
        Qt5::Quick
)

liri_add_settings_module(Background
    CONTENTS
        contents/ColorButton.qml
        contents/GradientPage.qml
        contents/main.qml
        contents/SelectorPage.qml
        contents/Selector.qml
        contents/SolidPage.qml
        contents/WallpaperPage.qml
)
