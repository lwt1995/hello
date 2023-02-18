//
// Created by lingweitao on 2023/2/10.
//

#include<cstdlib> //使用atexit()函数必须包含头文件stdlib.h
#include<cstdio>
#include <iostream>
#include <deque>

using namespace std;

void fn1(void);
void fn2(void);
//class Base {
//public:
//     int a;
//     string b;
//};
//
//class A : private Base {
//public:
//   using Base::a;
//};

int main(void)
{
atexit(fn1); //使用atexit注册fn1()函数
 atexit(fn2); //使用atexit注册fn2()函数
 deque<int> d;
 d.emplace_front();
 printf("main exit...\n");

 return 0;
 }

 void fn1()
 {
 printf("calling fn1()...\n"); //fn1()函数打印内容
 }

 void fn2()
 {
 printf("calling fn2()...\n"); //fn2()函数打印内容
 }

