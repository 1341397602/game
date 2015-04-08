//
//  CSystemControl.cpp
//  singleton
//
//  Created by chenyafei on 15-4-7.
//  Copyright (c) 2015年 cyf. All rights reserved.
//

#include "CSystemControl.h"


CSystemControl* CSystemControl::_instance = NULL;//单例对象
CSystemControl* CSystemControl::Instance()//单例函数
{
    if (_instance==NULL) {
        _instance = new CSystemControl;
    }
    return _instance;
}

void CSystemControl::destroy()
{
    if (_instance) {
        delete _instance;//调用析构  删除成员变量 也是类的对象
        _instance = NULL;
    }

}
CSystemControl::~CSystemControl()
{
    //释放开辟空间的属性
}

void CSystemControl::print()
{
    cout<<"Call the print method!"<<endl;
}

CSystemControl::CSystemControl()
{
    cout<<"Construct a SystemControl object"<<endl;
}



