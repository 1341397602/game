//
//  Observer.h
//  singleton
//
//  Created by chenyafei on 15-4-7.
//  Copyright (c) 2015年 cyf. All rights reserved.
//

#ifndef __singleton__Observer__
#define __singleton__Observer__

#include <iostream>
using namespace std;
class Observer
{
public:
    virtual void Update() = 0;//纯虚函数，抽象类
    virtual ~Observer(){}
};

#pragma mark - 注册中心
class Engine//注册中心
{
public:
    Engine(Observer& observer):_observer(observer){}
public:
    void Download()
    {
        //漫长的下载。。。。。。
 		cout<<"Subject finished!"<<endl;
 		_observer.Update();
    }
private:
    Observer& _observer;
};
#pragma mark - 继承 观察者
class AppUI:public Observer//继承 观察者
{
private:
    Engine* _engine;
public:
    AppUI()
    {
        _engine = new Engine(*this);//注册
    }
    ~AppUI()
    {
        delete _engine;//调用fu类析构
    }
public:
    void start()
    {
        cout<<"The subject is called!"<<endl;
		_engine->Download();//
    }
public:
    void Update()
    {
        cout<<"the observer is called!"<<endl;
    }
};



#endif /* defined(__singleton__Observer__) */
