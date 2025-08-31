#include "valueinfo.h"



void ValueInfo::setValue(QVariant newValue){
    if( newValue == value_ ) {return;}

    value_ = newValue;
    emit valueChanged();

}
