#include "can.h"

CAN::CAN(const std::string& interface_name){
    can_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW); // Otwarcie socketu

    if (can_socket < 0) {
            perror("Error while opening CAN socket");
            exit(1);
    }

    strcpy(ifr.ifr_name, interface_name.c_str());

    if (ioctl(can_socket, SIOCGIFINDEX, &ifr) < 0) {
            perror("Error getting interface index");
            close(can_socket);
            exit(1);
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(can_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding CAN socket");
        close(can_socket);
        exit(1);
    }
}

CAN::~CAN(){
    close(can_socket);
}



can_frame CAN::readFrame(){
    can_frame frame{};
    int nbytes = read(can_socket, &frame, sizeof(can_frame));
    if (nbytes < 0) {
        perror("CAN read error");
        return can_frame{}; // zwróć pustą ramkę
    }
    return frame;
}

bool CAN::writeFrame(const can_frame& frame) {
        int nbytes = write(can_socket, &frame, sizeof(can_frame));
        if (nbytes < 0) {
            perror("CAN write error");
            return false;
        }
        return true;
    }