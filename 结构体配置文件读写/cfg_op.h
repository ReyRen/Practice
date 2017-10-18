//
//  cfg_op.h
//  Practice
//
//  Created by Rey Ren on 2017/10/16.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

// cfg_op.h

#ifndef _INC_CFG_OP_H
#define _INC_CFG_OP_H

#ifdef  __cplusplus
extern "C" {
#endif
    
    int GetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/);
    int SetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in*/, int ValueLen /*in*/);
    
    
    //int CfgItem_Init(void *pHandle, int iType);
    //int GetCfgItem(void *pHandle /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/);
    //int WriteCfgItem(void *pFileName /*in*/, char *pItemName /*in*/, char *pItemValue/*in*/, int itemValueLen /*in*/);
    //int CfgItem_Destory(void *pHandle);
    
#ifdef  __cplusplus
}
#endif

#endif

