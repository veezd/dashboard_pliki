#ifndef VALUEINFO_H
#define VALUEINFO_H

#include "includes.h"

class ValueInfo : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit ValueInfo(const QVariant defaultType = 0, QObject *parent = nullptr) : QObject(parent) , value_(defaultType) {}
    // Jakby byl jakis problem z typami ValueInfo to bym sie przyjrzal konstruktorowi. 
    QVariant value() const {return value_;}
    Q_INVOKABLE void setValue(QVariant newValue);

signals:
    void valueChanged();

private:
    QVariant value_;
};

#endif // VALUEINFO_H
