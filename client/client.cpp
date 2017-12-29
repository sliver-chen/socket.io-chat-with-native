#include "SIOClient.h"
#include "SIOEventTarget.h"

#define log(fmt,...)\
            do {\
               printf(fmt,##__VA_ARGS__);\
            } while(0)

SIOClient *io = NULL;

class MsgRcver : public SIOEventTarget {
public:
    void onMessage(const void *pSender, Array::Ptr& arg);
};

void MsgRcver::onMessage(const void *pSender, Array::Ptr& arg) {
    int i = 0;
    std::string msg;
    
    for (i = 0; i < arg->size(); i++) {
        msg += arg->get(i).toString();
    }

    log("receive: %s\n", msg.c_str());
}

int main(int argc, char **argv) {
    io = SIOClient::connect("http://localhost:3000");
    if (!io) {
        log("failed to connect\n");
        return -1;
    } else {
        log("connect to server\n");
    }

    MsgRcver *rcv = new MsgRcver();
    io->on("message", rcv, callback(&MsgRcver::onMessage));

    int status = 0;
    char str[1024];
    while (!status) {
        scanf("%s", str);
        log("send: %s\n", str);
        io->emit("message", str);
    }
    return 0;
}
