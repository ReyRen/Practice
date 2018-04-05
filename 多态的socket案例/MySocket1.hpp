//
//  MySocket1.hpp
//  C++Demo07
//
//  Created by Rey Ren on 2018/4/4.
//  Copyright © 2018年 whoami. All rights reserved.
//

#ifndef MySocket1_hpp
#define MySocket1_hpp

//这个是产商1
#include "SocketProtocol.hpp"
class CMySocketImp :public SocketProtocol
{
public:
    CMySocketImp(void);
    ~CMySocketImp(void);
    
    //客户端初始化 获取handle上下
    virtual int cltSocketInit();
    
    //客户端发报文
    virtual int cltSocketSend( unsigned char *buf /*in*/,  int buflen /*in*/);
    
    //客户端收报文
    virtual int cltSocketRev( unsigned char *buf /*in*/, int *buflen /*in out*/);
    
    
    //客户端释放资源
    virtual int cltSocketDestory();
    
private:
    char *pbuf;
    int len;
    
};



#endif /* MySocket1_hpp */
