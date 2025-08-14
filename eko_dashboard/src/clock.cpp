#include "inc/clock.h"

Clock::Clock(QObject *parent) : QObject(parent) {
    updateTime();
    connect(&timer_, &QTimer::timeout, this, &Clock::updateTime);
    timer_.start(1000);
}

QString Clock::time() const {
    return time_;
}

void Clock::updateTime() {
    QString current = QTime::currentTime().toString("HH:mm:ss");
    if(current != time_){
        time_ = current;
        emit timeChanged();
    }
}
