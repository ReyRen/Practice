//
//  MainClass.cpp
//  C++Demo07
//
//  Created by Rey Ren on 2018/4/4.
//  Copyright © 2018年 whoami. All rights reserved.
//


#include "iostream"
using namespace std;
//#include "SocketProtocol.hpp"

#include "MySocket1.hpp"

//中石油框架
int MainOP(SocketProtocol *sp, unsigned char *buf, int buflen, unsigned char *out, int *outlen)
{
    int ret = 0;
    ret =  sp->cltSocketInit();
    ret = sp->cltSocketSend(buf, buflen);
    ret = sp->cltSocketRev(out, outlen);
    ret = sp->cltSocketDestory();
    return ret;
}

//业务框架（升级成类）
class MainOPClass
{
public:
    MainOPClass()
    {
        sp = NULL;
    }
    static int MainOP2(SocketProtocol *sp, unsigned char *buf, int buflen, unsigned char *out, int *outlen)
    {
        int ret = 0;
        ret =  sp->cltSocketInit();
        ret = sp->cltSocketSend(buf, buflen);
        ret = sp->cltSocketRev(out, outlen);
        ret = sp->cltSocketDestory();
        return ret;
    }
    
    int MainOP1( unsigned char *buf, int buflen, unsigned char *out, int *outlen)
    {
        int ret = 0;
        
        ret =  sp->cltSocketInit();
        ret = sp->cltSocketSend(buf, buflen);
        ret = sp->cltSocketRev(out, outlen);
        ret = sp->cltSocketDestory();
        return ret;
    }
public:
    SocketProtocol * getSp() const
    {
        return sp;
    }
    void setSp(SocketProtocol * val)
    {
        sp = val;
    }
protected:
private:
    //在框架类中集成了一个协议类。。。。
    SocketProtocol *sp;
    
};

//业务层，集成第三个厂商的硬件。。接口。。。
int main()
{
    int ret = 0;
    char buf[1024] = {0};
    int buflen = 10;
    
    char out[1024] = {0};
    int outlen = 10;
    SocketProtocol *sp = NULL;
    strcpy(buf, "dddddddddddddssssssssssssssssss");
    /*
     ret =  sp->cltSocketInit();
     ret = sp->cltSocketSend((unsigned char *)buf, buflen);
     ret = sp->cltSocketRev((unsigned char *)out, &outlen);
     ret = sp->cltSocketDestory();
     */
    
    sp = new CMySocketImp();
    
//    ret = MainOP(sp,  (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
//    printf("out:%s ", out);

    MainOPClass mainOpClass;
    mainOpClass.setSp(sp); //注入，其实就是把这个类射进去了，类中的参数就不需要协议类了.
    
    //在MainOPClass中包含了一个协议类sp，这种关系强
    mainOpClass.MainOP1((unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
    
    //对sp 做函数参数。。。。
    //sp只是做函数参数，关系弱。。。
    mainOpClass.MainOP2(sp, (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
    
    //这样的mainOpClass都不需要了
    MainOPClass::MainOP2(sp, (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
    printf("out:%s \n", out);
    
    delete sp;
    
    return 0;
}
