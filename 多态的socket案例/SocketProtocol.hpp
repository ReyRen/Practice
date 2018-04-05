//
//  SocketProtocol.hpp
//  C++Demo07
//
//  Created by Rey Ren on 2018/4/4.
//  Copyright © 2018年 whoami. All rights reserved.
//

#ifndef SocketProtocol_hpp
#define SocketProtocol_hpp

#include "iostream"
using namespace std;

//中石油制定的厂商入围接口。。。。
class SocketProtocol
{
public:
    SocketProtocol(void){
        
    }
    virtual ~SocketProtocol(void){
        
    }
    
    //客户端初始化 获取handle上下
    virtual int cltSocketInit( /*out*/) = 0;
    
    //客户端发报文
    virtual int cltSocketSend( unsigned char *buf /*in*/,  int buflen /*in*/) = 0;
    
    //客户端收报文
    virtual int cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/) = 0;
    
    //客户端释放资源
    virtual int cltSocketDestory() =  0;
};



#endif /* SocketProtocol_hpp */
