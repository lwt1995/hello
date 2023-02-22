#include <iostream>
#include <sstream>
#include <vector>
#include "shared/fourOperations.h"
#include "customizationSort.cpp"

using namespace  std;

void stringRevrse(){
    vector<int> v;
    //1、将一行带有特殊字符,.?的句子中单词反转
    //例如,how are you?  倒装之后 woh era uoy?
    string str;
    getline(cin, str);
    int count = 0;
    for(auto s : str) {
        if(s == ' ') {
            count++;
        } else {
            if(count == 0) {
                continue;
            }
            v.emplace_back(count);
            count = 0;
        }
    }

//    for(auto a : v) {
//        cout << a << endl;
//    }
    stringstream st;
    st << str;
    string ss;
    int num = 0;
    while(st >> str) {
        int i = 0,j = str.length() - 1;
        while(i < j){
            if(!isalpha(str[i])) {
                i++;
                continue;
            }
            if(!isalpha(str[j])) {
                j--;
                continue;
            }
            swap(str[i], str[j]);
            i++;
            j--;
        }

        ss.append(str);
        for (int k = 0; k < v[num]; ++k) {
            ss.append(" ");
        }
        num++;
//        if (cin.get() == '\n')  //关键在这里，\n不能用双引号。。。
//        {
//            break;
//        }
    }

    cout << ss << endl;
}
int main() {
//    std::cout << "Hello, World!" << std::endl;
//    cout << add(1, 2) << endl;
//    cout << subtract(1, 2) << endl;
//    cout << multiply(1, 2) << endl;
//    cout << except(1, 2) << endl;
//    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
//    int len = (int) sizeof(arr) / sizeof(*arr);
//    bubble_sort(arr, len);
//    for (int i = 0; i < len; i++)
//        cout << arr[i] << ' ';
//    cout << endl;
//    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
//    len = (float) sizeof(arrf) / sizeof(*arrf);
//    bubble_sort(arrf, len);
//    for (int i = 0; i < len; i++)
//        cout << arrf[i] << ' '<< endl;
    return 0;
}
