import QtQuick 2.6
import Boards 1.0
Rectangle {
    id: root
    visible: true
    width: 1200
    height: 400
    color: "black"

    property int value: 90
    property string cur: "10"  //88
    //    property int waitDuration: 1000 /*(60 / Number(cur) * 1000).toFixed(0)*/
    Behavior on value { SpringAnimation { spring: 5.0; damping: 0.5; epsilon: 0.8 } }
    SequentialAnimation {
        id: valuechange
        running: true
        loops: Animation.Infinite
        PauseAnimation {
            id: pausetim
            duration: 1000 }
        ScriptAction {
            script: {
                root.value += 120;
            }
        }
    }

    Ringboard {
        id:bodard
        x: 401
        y: 0
        width: 400
        height: 400
        visible: true
        startAngle: 270
        spanAngle: -360
        radiusInner: 130
        radiusOuter: 180
        roundConer: false
        gradient: Ringboard.LinearGradient
    }

    Item {
        x: 401
        y: 0
        width: 400
        height: 400
        Ringboard {
            id: boardlight
            width: 400
            height: 400
            startAngle: 270
            spanAngle: -240
            radiusInner: 130
            radiusOuter: 180
            roundConer: false
            gradient: Ringboard.LinearGradientlight
        }
        rotation: root.value
    }


    ListModel {
        id:beatmode
    }
    ListView {
        id:beatview
        anchors.centerIn: bodard
        width: 200
        height: 100
        clip: true
        model: beatmode
        snapMode: ListView.SnapToItem
        delegate:  Rectangle {
            width: 200
            height: 100
            color: "transparent"
            Text {
                text: listtext
                color: "white"
                anchors.centerIn: parent
                font.pixelSize: 50
            }
        }
        onCurrentIndexChanged: {
        }
        onContentYChanged: {
            if(!dragArea.pressed) {
                rectM.y = beatmode.get(beatview.contentY / 100).listtext
                showtimer.running = true
            } else {
                showtimer.running = true
            }
        }
    }
    Component.onCompleted: {
        for(var i = 40; i <= 200 ;i++)
        {
            beatmode.append({"listtext":i})
        }
    }
    Timer {
        id: showtimer
        running: true
        repeat: true
        interval:  200
        onTriggered: {
            if (!beatview.moving){
                valuechange1.stop()
                valuechange.stop()
                root.value = 120
                cur = beatmode.get(beatview.contentY / 100).listtext
                pausetim.duration = (60 / Number(cur) * 1000).toFixed(0)
                valuechange.start()
                valuechange1.start()
            }
            showtimer.running = false
        }
    }

    property int languageInt: 0
    Text {
        id: language
        anchors.horizontalCenter: fruit.horizontalCenter
        y: 0
        text: qsTr("italiana") + bodard.emptystring
        color: "white"
        font.pixelSize: 50
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(0 === languageInt){
                    languageInt = 1;
                    bodard.setlanguage(languageInt);
                } else {
                    languageInt = 0;
                    bodard.setlanguage(languageInt);
                }
            }
        }
        onTextChanged: {
            if (languageInt) {
                for (var i =0 ; i< fruitModel.count;i++){
                    fruitModel.setProperty(i,"hznumText1Show",qsTr(fruitModel.get(i).hznumText1Show))
                }
            } else {
                fruitModelReflash();
            }
        }
    }


    Item {
        id: fruit
        x:100
        y:100
        width: 100
        height: 300
        Component.onCompleted:{
            fruitModelReflash();
        }

        ListModel {
            id: fruitModel

        }
        Component {
            id: fruitDelegate
            Column {
                x:0
                Rectangle
                {
                    z: 11
                    width: 100
                    height: 30
                    color: "black"
                    Text
                    {
                        id:hznumText1
                        z: 11
                        text:hznumText1Show + bodard.emptystring
                        visible: true
                        anchors.centerIn: parent
                        font.pixelSize: 30
                        color: "white"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                beatview.contentY = hznumText1contentY
                            }
                        }
                    }
                }
            }
        }
        ListView {
            anchors.fill: parent
            model: fruitModel
            delegate: fruitDelegate
        }
    }

    Rectangle {
        anchors.right: parent.right
        width: 80
        height: 40
        color: "yellow"
        opacity: 0
        Item {
            id: fpsItem
            property int fps: 0
            property int frameCount: 0
            NumberAnimation on rotation {
                from: 0
                to: 100
                loops: Animation.Infinite
                duration: 300
            }
            onRotationChanged: frameCount++
        }
        Text {
            x: 10
            y: 10
            text: "FPS: " + fpsItem.fps
            color: "green"
            font.pixelSize: 18
        }
        Timer {
            interval: 1000
            repeat: true
            running: true
            onTriggered: {
                fpsItem.fps = fpsItem.frameCount;
                fpsItem.frameCount = 0;
                //            console.log("FPS:", fpsItem.fps)
            }
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.opacity = parent.opacity === 1 ? 0 : 1
            }
        }
    }
    property int  combiAngle: 0
    DropArea {
        id: dorpShow
        x:900
        y:50
        width: 200
        height: 300
        MouseArea {
            id: dorpShowArea
            anchors.fill: parent
            onClicked: {
                valuechange1.stop()
                valuechange.stop()
                    combiAngle = 0
            }
        }
        Item {
            anchors.fill: parent
            Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                width: 10
                height: 300
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "lightgray" }
                    GradientStop { position: 1.0; color: "lightsteelblue" }
                }
                Rectangle {
                    id: rectM
                    x: -25
                    y: 50
                    width: 60
                    height: 40
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "lightgray" }
                        GradientStop { position: 1.0; color: "lightsteelblue" }
                    }
                    onYChanged: {
                        if(dragArea.pressed) {
                        valuechange1.stop()
                        valuechange.stop()
                        beatview.contentY =  (0.61538 * y).toFixed(0) * 100
                        valuechange1.start()
                        valuechange.start()
                        }
                    }

                    Drag.active: dragArea.drag.active

                    MouseArea {
                        id: dragArea
                        anchors.fill: parent
                        drag.target: parent
                        drag.axis: Drag.YAxis
                        drag.minimumY: 0
                        drag.maximumY: 260
                    }
                }
                transform: Rotation { origin.x: 5; origin.y: 300; angle: combiAngle}
            }
        }
    }
    Behavior on combiAngle { SpringAnimation { spring: 5.0; damping: 0.5; epsilon: 0.8 } }
    SequentialAnimation {
        id: valuechange1
        running: false
        loops: Animation.Infinite
        PauseAnimation {
            id: pausetim1
            duration: pausetim.duration
        }
        ScriptAction {
            script: {
                combiAngle = 30;
            }
        }
        PauseAnimation {
            id: pausetim2
            duration: pausetim.duration
        }
        ScriptAction {
            script: {
                combiAngle = -30;
            }
        }
    }

    function fruitModelReflash (){
        fruitModel.clear()
        fruitModel.append({"hznumText1Show":qsTr("largo"),"hznumText1contentY": "0"})
        fruitModel.append({"hznumText1Show":qsTr("lento"),"hznumText1contentY": "1200"})
        fruitModel.append({"hznumText1Show":qsTr("adagio"),"hznumText1contentY": "1600"})
        fruitModel.append({"hznumText1Show":qsTr("andante"),"hznumText1contentY": "2600"})
        fruitModel.append({"hznumText1Show":qsTr("andantino"),"hznumText1contentY": "2900"})
        fruitModel.append({"hznumText1Show":qsTr("moderato"),"hznumText1contentY": "4800"})
        fruitModel.append({"hznumText1Show":qsTr("allegretto"),"hznumText1contentY": "6800"})
        fruitModel.append({"hznumText1Show":qsTr("allegro"),"hznumText1contentY": "9200"})
        fruitModel.append({"hznumText1Show":qsTr("presto"),"hznumText1contentY": "14400"})
    }
}
