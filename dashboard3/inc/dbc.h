#ifndef DBC_H
#define DBC_H

struct messageReceived{
    uint32_t canId;
    uint8_t data[8];
};




#endif // DBC_H

/*
{
    CAN ID 0x77
    Name : Hazard_Lights
    Start bit : 0
    Legth : 1
    Valuetype : boolean
    Initial value : 0
    Factor (A) : -
    Offset (B) : -
    Min(C) : -
    Max(D) : -
    Unit : -
    Rate : ???? 500ms??

}*/