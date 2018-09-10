#include "Ringboard.h"
#include <QtMath>
#include <QtGlobal>
#include <QRadialGradient>
#include <QConicalGradient>
#include <QTranslator>
Ringboard::Ringboard() {
    soundStrong = new QSound(":/strongS.wav", this);
    soundWeak = new QSound(":/weakS.wav", this);
    mEmptystring = "";
    connect(&mTimer, &QTimer::timeout, this, &Ringboard::timeoutSlot);
    mTimer.start(1000 / 60);
    //红橙黄绿青蓝紫
    mColors << QColor(255,   0, 0, 255)
            << QColor(255, 125, 0, 240)
            << QColor(255, 255, 0, 200)
            << QColor(  0, 255, 0, 150)
            << QColor(  0,   0, 255, 100)
            << QColor(  0, 255, 255, 50)
            << QColor(255,   0, 255, 1);
}

void Ringboard::timeoutSlot() {
    update();
}

void Ringboard::paint(QPainter *painter) {
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);

    const qreal cx = width() / 2.0;
    const qreal cy = height() / 2.0;
    QPainterPath path;
    //起点
    path.arcMoveTo(cx - radiusOuter(), cy - radiusOuter(),
                   radiusOuter() * 2, radiusOuter() * 2,
                   startAngle());
    //画外圆弧
    path.arcTo(cx - radiusOuter(), cy - radiusOuter(),
               radiusOuter() * 2, radiusOuter() * 2,
               startAngle(), spanAngle() );
    //    if (roundConer()) {
    //        //外弧到内弧的圆角
    //        auto radius = (radiusOuter() - radiusInner()) / 2;
    //        auto rx = cx + (radiusInner() + radius) * cos(qDegreesToRadians(startAngle() + spanAngle()));
    //        auto ry = cy - (radiusInner() + radius) * sin(qDegreesToRadians(startAngle() + spanAngle()));
    //        path.arcTo(rx - radius, ry - radius,
    //                   radius * 2, radius * 2,
    //                   startAngle() + spanAngle(), -180);
    //    }
    //内弧，方向与外弧相反
    path.arcTo(cx - radiusInner(), cy - radiusInner(),
               radiusInner() * 2, radiusInner() * 2,
               startAngle() + spanAngle(), - spanAngle());
    //闭合path
    path.closeSubpath();
    int colorCount = mColors.count();

    //单一颜色brush
    if (gradient() == RadialGradiant) {
        //辐射渐变
        QRadialGradient grad;
        grad.setCenter(cx, cy);
        grad.setCenterRadius(radiusInner());
        grad.setRadius(radiusOuter());
        grad.setFocalPoint(cx, cy);
        qreal len = radiusOuter() - radiusInner();
        qreal percentStep = (len / radiusOuter()) / colorCount;
        for (int i = 0; i < colorCount; ++i) {
            grad.setColorAt(1.0 - i * percentStep, mColors.at(i));
        }
        QBrush brush(grad);
        painter->fillPath(path, brush);
    } else if (gradient() == ConicalGradiant) {

        //角度渐变
        QConicalGradient grad;
        grad.setCenter(cx, cy);
        grad.setAngle(startAngle());
        qreal maxPercent = fabs(spanAngle() / 360.0);
        qreal percentStep = maxPercent / colorCount;

        for (int i = 0; i < colorCount; ++i) {
            grad.setColorAt(1.0 - i * percentStep, mColors.at(i));
        }
        QBrush brush(grad);
        painter->fillPath(path, brush);
    } else if (gradient() == LinearGradient){
        QLinearGradient grad;
        grad.setColorAt(0,Qt::blue);
        grad.setColorAt(1,Qt::green);
        grad.setSpread(QGradient::RepeatSpread);
        QBrush brush(grad);
        painter->fillPath(path,brush);
    } else if (gradient() == LinearGradientlight){
        QLinearGradient grad;
        grad.setColorAt(0,Qt::black);
        grad.setColorAt(1,Qt::black);
        grad.setSpread(QGradient::RepeatSpread);
        QBrush brush(grad);
        painter->fillPath(path,brush);
    }else {
        QBrush brush;
        brush.setColor(Qt::lightGray);
        brush.setStyle(Qt::SolidPattern);

        painter->fillPath(path, brush);
    }
    painter->restore();
}

qreal Ringboard::startAngle() const {
    return mStartAngle;
}

qreal Ringboard::spanAngle() const {
    return mSpanAngle;
}

qreal Ringboard::radiusInner() const {
    return mRadiusInner;
}

qreal Ringboard::radiusOuter() const {
    return mRadiusOuter;
}

bool Ringboard::roundConer() const {
    return mRoundConer;
}

Ringboard::Gradient Ringboard::gradient() const {
    return mGradient;
}

QString Ringboard::emptystring() const
{

    return mEmptystring;
}

void Ringboard::setStartAngle(qreal startAngle) {
    if (qFuzzyCompare(mStartAngle, startAngle))
        return;

    mStartAngle = startAngle;
    emit startAngleChanged(mStartAngle);
}

void Ringboard::setSpanAngle(qreal spanAngle) {
    if (qFuzzyCompare(mSpanAngle, spanAngle))
        return;

    mSpanAngle = spanAngle;
    emit spanAngleChanged(mSpanAngle);
}

void Ringboard::setRadiusInner(qreal radiusInner) {
    if (qFuzzyCompare(mRadiusInner, radiusInner))
        return;

    mRadiusInner = radiusInner;
    emit radiusInnerChanged(mRadiusInner);
}

void Ringboard::setRadiusOuter(qreal radiusOuter) {
    if (qFuzzyCompare(mRadiusOuter, radiusOuter))
        return;

    mRadiusOuter = radiusOuter;
    emit radiusOuterChanged(mRadiusOuter);
}

void Ringboard::setRoundConer(bool roundConer) {
    if (mRoundConer == roundConer)
        return;

    mRoundConer = roundConer;
    emit roundConerChanged(mRoundConer);
}

void Ringboard::setGradient(Ringboard::Gradient gradient) {
    if (mGradient == gradient)
        return;

    mGradient = gradient;
    emit gradientChanged(mGradient);
}

void Ringboard::setlanguage(int language)
{

    //    sound->stop();//停止

    //    sound->setLoops(value);//设置循环次数
    if (language){
        p_translator = new QTranslator();
        p_translator->load(":/zh_CN.qm");
        qApp->installTranslator(p_translator);
        mEmptystring = "";
        emit siglanguageChanged();
    } else {
        qApp->removeTranslator(p_translator);
        mEmptystring = "";
        emit siglanguageChanged();
    }
}

void Ringboard::soundStrongPlay()
{
    soundStrong->play();//播放
}

void Ringboard::soundWeakPlay()
{
    soundWeak->play();//播放
}

