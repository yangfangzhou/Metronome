import QtQuick 2.6
import Boards 1.0
Rectangle {
    id: root
    visible: true
    width: 1200
    height: 400
    color: "black"

    property int radianShow: 0
    property int value: radianShow
    property string cur: "10"  //88
    //    property int waitDuration: 1000 /*(60 / Number(cur) * 1000).toFixed(0)*/
    Behavior on value { SpringAnimation { spring: 5.0; damping: 0.5; epsilon: 0.8 } }
    property int strongFlag: 0
    property int curnumerator: 0
    property int curdenominator: 0
    property int languageInt: 0
    property int  combiAngle: 0

    onRadianShowChanged: {
        bodard.scale = 1
        combiAngle = 0
        swing.stop()
        valuechange.stop()
        root.value = radianShow
        valuechange.start()
        swing.start()

    }
    SequentialAnimation {
        id: valuechange
        running: true
        loops: Animation.Infinite
        PauseAnimation {
            id: pausetim
            duration: 1000 }
        ScriptAction {
            script: {
                if (strongFlag > curnumerator) {
                    strongFlag = 0
                }

                if(0 === strongFlag)
                {
                    bodard.soundStrongPlay();
                    strongFlag += 1;
                } else if(strongFlag > 0 && strongFlag < curnumerator) {
                    bodard.soundWeakPlay();
                    strongFlag += 1;
                } else if(strongFlag === curnumerator){
                    bodard.soundStrongPlay();
                    strongFlag = 1;
                }

                root.value += radianShow;
            }
        }
    }
    Behavior on combiAngle { SpringAnimation { spring: 5.0; damping: 0.5; epsilon: 0.8 } }
    SequentialAnimation {
        id: swing
        running: false
        loops: Animation.Infinite
        PauseAnimation {
            id: pausetim1
            duration: pausetim.duration - 10
        }
        ScriptAction {
            script: {
                combiAngle = 30;
            }
        }
        PauseAnimation {
            id: pausetim2
            duration: pausetim.duration - 10
        }
        ScriptAction {
            script: {
                combiAngle = -30;
            }
        }
    }
    SequentialAnimation {
        id: bodardOne
        running: 1 === curnumerator?swing.running : false
        loops: Animation.Infinite
        PauseAnimation {
            id: pausetime3
            duration: pausetim.duration - 200
        }

        NumberAnimation {
            target: bodard
            property: "scale"
            to:1.01
            duration: 150
            easing.type: Easing.InOutQuad
        }
        NumberAnimation {
            target: bodard
            property: "scale"
            to:1
            duration: 50
            easing.type: Easing.InOutQuad
        }
        PauseAnimation {
            id: pausetime23
            duration: pausetim.duration - 200
        }
        NumberAnimation {
            target: bodard
            property: "scale"
            to:1.01
            duration: 150
            easing.type: Easing.InOutQuad
        }
        NumberAnimation {
            target: bodard
            property: "scale"
            to:1
            duration: 50
            easing.type: Easing.InOutQuad
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
        //        roundConer: false
        gradient: Ringboard.LinearGradient
    }

    Item {
        id: boardlightrotation
        x: 401
        y: 0
        width: 400
        height: 400
        Ringboard {
            id: boardlight
            width: 400
            height: 400
            startAngle: 270
            spanAngle: radianShow - 360
            radiusInner: 130
            radiusOuter: 180
            //            roundConer: false
            gradient: Ringboard.LinearGradientlight
        }
        rotation: root.value
    }

    Text {
        id: beat
        x: 280
        y: 0
        text: qsTr("battere") + bodard.emptystring
        color: "white"
        font.pixelSize: 50
    }
    Text {
        id: separator
        x: 318
        y: 130
        text: "/"
        color: "white"
        font.pixelSize: 40
    }

    ListModel {
        id: numeratorMode
    }
    ListView {
        id: numeratorView
        x: 280
        y: 100
        width: 50
        height: 100
        clip: true
        model: numeratorMode
        snapMode: ListView.SnapToItem
        delegate:  Rectangle {
            width: 50
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
        }
    }

    ListModel {
        id: denominatorMode
    }
    ListView {
        id: denominatorView
        x: 330
        y: 100
        width: 50
        height: 100
        clip: true
        model: denominatorMode
        snapMode: ListView.SnapToItem
        delegate:  Rectangle {
            width: 50
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
        }
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
        onContentYChanged: {
            if(!dragArea.pressed) {
                rectM.y = beatmode.get(beatview.contentY / 100).listtext
                showtimer.running = true
            } else {
                showtimer.running = true
            }
        }
    }

    Timer {
        id: showtimer
        running: true
        repeat: true
        interval:  200
        onTriggered: {
            if (!beatview.moving){
                swing.stop()
                valuechange.stop()
                combiAngle = 0
                root.value = radianShow
                cur = beatmode.get(beatview.contentY / 100).listtext
                pausetim.duration = (60 / Number(cur) * 1000).toFixed(0)
                valuechange.start()
                swing.start()
            }
            showtimer.running = false
        }
    }

    Timer {
        id: adjusttimer
        running: true
        repeat: true
        interval:  200
        onTriggered: {
            curnumerator = Number(numeratorMode.get(numeratorView.contentY / 100).listtext)
            curdenominator = Number(denominatorMode.get(denominatorView.contentY / 100).listtext)
            switch (curdenominator) {
            case 4:
                if(curnumerator === 1){
                    radianShow = 360;
                } else if(curnumerator === 2){
                    radianShow = 180;
                } else if(curnumerator === 3){
                    radianShow = 120;
                } else if(curnumerator === 4){
                    radianShow = 90;
                }
                break;
            case 8:
                if(curnumerator === 3){
                    radianShow = 120;
                } else if(curnumerator === 6){
                    radianShow = 60;
                }
                break;
            default:
                break;
            }
        }
    }


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
                if (swing.running === true) {
                    swing.stop()
                    valuechange.stop()
                    combiAngle = 0
                    root.value = radianShow
                } else {
                    swing.start()
                    valuechange.start()
                }
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
                            swing.stop()
                            valuechange.stop()
                            beatview.contentY =  (0.61538 * y).toFixed(0) * 100
                            swing.start()
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

    Component.onCompleted: {
        for(var i = 40; i <= 200 ;i++)
        {
            beatmode.append({"listtext":i})
        }
        for(var i = 1; i <= 16 ;i++)
        {
            if (i != 5 && i != 7 && i <9){
                numeratorMode.append({"listtext":i})
            }
            if (i == 4 || i == 8 || i == 16){
                denominatorMode.append({"listtext":i})
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
