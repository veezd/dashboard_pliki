#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Clock : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString time READ time NOTIFY timeChanged)

public:
    explicit Clock(QObject *parent = nullptr);

    QString time() const;

signals:
    void timeChanged();

private slots:
    void updateTime();

private:
    QTimer timer_;
    QString time_;
};



#endif // CLOCK_H
