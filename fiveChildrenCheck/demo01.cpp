//
// Created by lingweitao on 2023/3/3.
//

//写一个五子棋的判断成功的逻辑
//定义N*N的棋盘
#include <iostream>

#define N 10

#define printstr(paramter) paramter  //转字符串

void checkFiveChess(int chessboardArray[N][N], int , int);

//先定义一个枚举表示白黑棋子
enum Color {
    EMPTY = 0, WRITE, BLACK
};
typedef struct Data{
    int chessboardArray[N][N] = {{0,1,0,2,2},{1,1,2,2,2},{2,1,2,0,0},{0,2,0,2,1},{2,1,2,1,2}};
    int length{N};
    int x{0};
    int y{0};
    Color c{WRITE};
} Data;
bool check_Y(Data &data);
bool check_X(Data &data);
bool check_X_Y_right(Data &data);
bool check_X_Y_left(Data &data);
/*{
 * {0,1,0,2,2},
 * {1,1,2,2,2},
 * {2,1,2,0,0},
 * {0,2,0,2,1},
 * {2,1,2,1,2}}*/
int main() {
    int arr[N][N] = {{0,1,0,2,2},{1,1,2,2,2},{2,1,2,0,0},{0,2,0,2,1},{2,1,2,1,2}};
    checkFiveChess(arr, 0, 4);
    return 0;
}

/**
 * 任意的坐标棋子，判断它的横纵坐标是否存在相同的五子连接
 * @param chessboardArray
 * @param i
 * @param j
 */

void checkFiveChess(int chessboardArray[N][N], int i, int j) {
    //先判空
    if (chessboardArray == nullptr || i >= N || i < 0 || j >= N || j < 0) {
        return;
    }

    Color C = WRITE;
    if (chessboardArray[i][j] == BLACK) {
        C = BLACK;
    }
    Data data{};
    for (int k = 0; k < N; ++k) {
        for (int l = 0; l < N; ++l) {
            data.chessboardArray[k][l] = chessboardArray[k][l];
        }
    }
    data.x = i;
    data.y = j;
    data.length = N;
    data.c = C;
    bool checkflag = check_Y(data);
    if (checkflag) {
        std::cout << (C == 1 ? "write " : "black ") << "win!" << std::endl;
        return;
    }

    checkflag = check_X(data);
    if (checkflag) {
        std::cout << (C == 1 ? "write " : "black ") << "win!" << std::endl;
        return;
    }

    checkflag = check_X_Y_right(data);
    if (checkflag) {
        std::cout << (C == 1 ? "write " : "black ") << "win!" << std::endl;
        return;
    }

    checkflag = check_X_Y_left(data);
    if (checkflag) {
        std::cout << (C == 1 ? "write " : "black ") << "win!" << std::endl;
        return;
    }
}
//纵坐标检查
bool check_Y(Data &data){
    int count = 0, index = 1;
    for (int k = 1; k < 6; ++k) {
        if (count == 4) {
            return true;
        }

        if ((data.x + k < data.length) && data.chessboardArray[data.x + k][data.y] == data.c) {
            count++;
        } else if ((data.x - index >= 0) && data.chessboardArray[data.x - index][data.y] == data.c) {
            count++;
            index++;
        }

    }
    return false;
}

//横坐标检查
bool check_X(Data &data){
    //考虑横坐标
    int count = 0, index = 1;
    for (int k = 1; k < 6; ++k) {
        if (count == 4) {
            return true;
        }

        if ((data.x + k < data.length) && data.chessboardArray[data.x][data.y + k] == data.c) {
            count++;
        } else if ((data.y - index >= 0) && data.chessboardArray[data.x][data.y - index] == data.c) {
            count++;
            index++;
        }
    }
    return false;
}

//右斜检查
bool check_X_Y_right(Data &data){
    int count = 0, index = 1;
    for (int k = 1; k < 6; ++k) {
        if (count == 4) {
            return true;
        }

        if ((data.x + k < data.length) && (data.y + k < data.length) && data.chessboardArray[data.x + k][data.y + k] == data.c) {
            count++;
        } else if ((data.x - index >= 0) && (data.y - index >= 0) && data.chessboardArray[data.x - index][data.y - index] == data.c) {
            count++;
            index++;
        }
    }
    return false;
}
//左斜检查
bool check_X_Y_left(Data &data){
    int count = 0, index = 1;
    for (int k = 1; k < 6; ++k) {
        if (count == 4) {
            return true;
        }

        if ((data.x - k >= 0) && (data.y + k < data.length) && data.chessboardArray[data.x - k][data.y + k] == data.c) {
            count++;
        } else if ((data.x + index < data.length) && (data.y - index >= 0) && data.chessboardArray[data.x + index][data.y - index] == data.c) {
            count++;
            index++;
        }
    }

    return false;
}
