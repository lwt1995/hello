//
// Created by lingweitao on 2023/2/17.
//

#include <iostream>
#include "utils/head/tinyxml.h"

using namespace std;


int main(int argNum, char *argv[]) {
#if 1
    TiXmlDocument *pDocument = new TiXmlDocument();
    if (pDocument == nullptr)
    {
        std::cout << "NULL == pDocument" << std::endl;
        delete pDocument;
        return -1;
    }

    if (!pDocument ->LoadFile("C:/Users/lingweitao/CLionProjects/hello/camera/data.xml", TIXML_ENCODING_UNKNOWN))
    {
        std::cout << "无法加载xml文件！" << std::endl;
        delete pDocument;
        return -1;
    }

    TiXmlElement* pRootElement = pDocument->RootElement();
    if (nullptr == pRootElement)
    {
        std::cout << "NULL == pRootElement" << std::endl;
        delete pDocument;
        return -1;
    }
    auto pR = pRootElement->FirstChildElement();
    auto name = pR->FirstChildElement("name");
    cout << name->GetText() << endl;
    auto weight = pR->FirstChildElement("weight");
    cout << weight->GetText() << endl;
    pDocument->Print();


    delete pDocument;
#elif 0
    FILE *p = fopen("data.xml", "rb");
    if(!p) {
        cout << "xml not exist!" << endl;
    }
#endif
    return 0;
}
