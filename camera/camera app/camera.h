//
// Created by lingweitao on 2023/2/17.
//

#ifndef TEST_CAMERA_H
#define TEST_CAMERA_H
#include "../metadata.h"
#define SIZE 256

class camera {
public:
    void init();
    void exectueCamera();
    void destory();

private:
    char data[SIZE];
};


#endif //TEST_CAMERA_H
