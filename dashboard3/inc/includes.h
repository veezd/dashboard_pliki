
#include <QObject>
#include <QTimer>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>   
#include <linux/can.h>    
#include <linux/can/raw.h> 
#include <net/if.h>       
#include <cstring>        
#include <unistd.h> 
#include <sys/ioctl.h>
#include <QTime>
#include <QVariant>

#include "blinker.h"
#include "can.h"
#include "clock.h"
#include "dbc.h"
//#include "system.h"
#include "valueinfo.h"


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>