//
// Created by lingweitao on 2023/2/17.
//

#ifndef TEST_METADATA_H
#define TEST_METADATA_H

#include <string>

typedef struct faceinfo {
    unsigned char *name;
    unsigned int weight;
    unsigned int height;
    unsigned char *data;
    unsigned int size;
    unsigned int type;
} __attribute__((unused)) faceinfo;

typedef struct metadata {
    faceinfo *data;
    unsigned int size;
} metadata;


#endif //TEST_METADATA_H
