//
// Created by lingweitao on 2023/2/17.
//

#include <iostream>
#include <memory>
#include "metadata.h"
#include "utils/head/tinyxml.h"
#include <cassert>

using namespace std;


int main(int argNum, char *argv[]) {
#if 1
    shared_ptr<TiXmlDocument> pDocument = make_shared<TiXmlDocument>();
    if (pDocument == nullptr)
    {
        std::cout << "NULL == pDocument" << std::endl;
        return -1;
    }

    if (!pDocument ->LoadFile("../../camera/data.xml", TIXML_ENCODING_UNKNOWN))
    {
        std::cout << "无法加载xml文件！" << std::endl;
        return -1;
    }

    TiXmlElement* pRootElement = pDocument->RootElement();
    if (nullptr == pRootElement)
    {
        std::cout << "NULL == pRootElement" << std::endl;
        return -1;
    }

    auto pR = pRootElement->FirstChildElement("model1");
    auto name = pR->FirstChildElement("name");
    cout << name->GetText() << endl;
    auto weight = pR->FirstChildElement("weight");
    cout << weight->GetText() << endl;
    auto pp = pRootElement->FirstChildElement("model2");
    auto name1 = pp->FirstChildElement("name");
    cout << name1->GetText() << endl;
    auto weight1 = pp->FirstChildElement("weight");
    cout << weight1->GetText() << endl;
    pDocument->Print();


#elif 0
    FILE *p = fopen("data.xml", "rb");
    if(!p) {
        cout << "xml not exist!" << endl;
    }
    int *a = nullptr;
    assert(a != nullptr);
#endif
    return 0;
}
