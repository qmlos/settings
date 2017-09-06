import qbs 1.0

Project {
    name: "Settings"

    readonly property string version: "0.9.0"

    condition: qbs.targetOS.contains("linux")

    minimumQbsVersion: "1.8.0"

    qbsSearchPaths: ["qbs"]

    references: [
        "app/app.qbs",
        "declarative/declarative.qbs",
        "modules/appearance/appearance.qbs",
        "modules/background/background.qbs",
        "modules/display/display.qbs",
        "modules/info/info.qbs",
        "modules/keyboard/keyboard.qbs",
        "modules/power/power.qbs",
        "modules/sound/sound.qbs",
        "modules/users/users.qbs",
    ]
}