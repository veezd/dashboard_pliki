#ifndef BLINKER_H
#define BLINKER_H

#include "includes.h"


class Blinker : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool state READ state WRITE newState NOTIFY stateChanged)
    Q_PROPERTY(double blinkState READ blinkState NOTIFY blinkChanged)

public:
    explicit Blinker(QObject* parent = nullptr);

    bool state() const {return currentState_; }
    void newState(bool updated);

    double blinkState() const { return blinkState_ ? 1.0 : 0.0; }

signals:
    void stateChanged();
    void blinkChanged();

private slots:
    void blinkEdit();

private:
    bool currentState_;
    bool blinkState_;
    QTimer timer_;
};

#endif // BLINKER_H
