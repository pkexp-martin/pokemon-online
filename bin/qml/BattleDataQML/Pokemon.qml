import QtQuick 1.0
import pokemononline.battlemanager.proxies 1.0

Item {
    id: main
    width: grid.cellWidth
    height: grid.cellHeight

    Image {
        id: img
        x: main.x
        y: main.y

        /* In order to use animations, we can't use the main level component as
          it technically is the same item, so we need to animate the image.

          So we set the image's position relative to the parent instead, so
          we can animate its coordinates properly */
        parent: grid

        Behavior on x { enabled: grid.loaded; NumberAnimation { duration: 400; easing.type: Easing.InOutCubic}}
        Behavior on y { enabled: grid.loaded; NumberAnimation { duration: 400; easing.type: Easing.InOutCubic}}

        source: "image://pokeinfo/icon/"+ pokemon.numRef
        width: 32
        height: 32
    }

    Component.onCompleted: {
        loaded = true;
    }
}