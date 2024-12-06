#ifndef _CEXAT11300_H_
#define _CEXAT11300_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ������ ����ֹ� ( SERVICE=CEXAT11300,headtype=B,CREATOR=�̽���,CREDATE=2012/06/27 21 )
#pragma pack( push, 1 )

#define NAME_CEXAT11300     "CEXAT11300"

// In(*EMPTY*)                    
typedef struct _CEXAT11300InBlock1
{
    char    OrgOrdNo            [  10];    // [long  ,   10] ���ֹ���ȣ                      
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                
} CEXAT11300InBlock1, *LPCEXAT11300InBlock1;
#define NAME_CEXAT11300InBlock1     "CEXAT11300InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAT11300OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      
    char    OrgOrdNo            [  10];    // [long  ,   10] ���ֹ���ȣ                      
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                
    char    CancQty             [  16];    // [long  ,   16] ��Ҽ���                        
    char    CommdaCode          [   2];    // [string,    2] ��Ÿ�ü�ڵ�                    
} CEXAT11300OutBlock1, *LPCEXAT11300OutBlock1;
#define NAME_CEXAT11300OutBlock1     "CEXAT11300OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CEXAT11300OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      
    char    OrdNo               [  10];    // [long  ,   10] �ֹ���ȣ                        
    char    BrnNm               [  40];    // [string,   40] ������                          
    char    AcntNm              [  40];    // [string,   40] ���¸�                          
    char    IsuNm               [  50];    // [string,   50] �����                          
    char    OrdAbleAmt          [  16];    // [long  ,   16] �ֹ����ɱݾ�                    
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] �����ֹ����ɱݾ�                
    char    OrdMgn              [  16];    // [long  ,   16] �ֹ����űݾ�                    
    char    MnyOrdMgn           [  16];    // [long  ,   16] �����ֹ����űݾ�                
    char    OrdAbleQty          [  16];    // [long  ,   16] �ֹ����ɼ���                    
} CEXAT11300OutBlock2, *LPCEXAT11300OutBlock2;
#define NAME_CEXAT11300OutBlock2     "CEXAT11300OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAT11300_H_
