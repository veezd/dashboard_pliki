#ifndef CAN_H
#define CAN_H

#include "includes.h"

class CAN{
    public:
        CAN(const std::string& interface_name = "vcan0");
        ~CAN();

        can_frame readFrame();
        bool writeFrame(const can_frame& frame);
        void start();

    private:
        int can_socket;
        sockaddr_can addr{};
        ifreq ifr{};
};



#endif // CAN_H