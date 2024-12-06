#ifndef _CEXAT11100_H_
#define _CEXAT11100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ������ �ż�/�ŵ��ֹ� ( SERVICE=CEXAT11100,headtype=B,CREATOR=�̽���,CREDATE=2012/06/27 20 )
#pragma pack( push, 1 )

#define NAME_CEXAT11100     "CEXAT11100"

// In(*EMPTY*)                    
typedef struct _CEXAT11100InBlock1
{
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű���                        
    char    ErxPrcCndiTpCode    [   1];    // [string,    1] �������������Ǳ����ڵ�          
    char    OrdPrc              [  15];    // [double, 15.2] �ֹ�����                        
    char    OrdQty              [  16];    // [long  ,   16] �ֹ�����                        
} CEXAT11100InBlock1, *LPCEXAT11100InBlock1;
#define NAME_CEXAT11100InBlock1     "CEXAT11100InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAT11100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű���                        
    char    ErxPrcCndiTpCode    [   1];    // [string,    1] �������������Ǳ����ڵ�          
    char    OrdPrc              [  15];    // [double, 15.2] �ֹ�����                        
    char    OrdQty              [  16];    // [long  ,   16] �ֹ�����                        
    char    OrdCndiPrc          [  25];    // [double, 25.8] �ֹ����ǰ���                    
    char    CommdaCode          [   2];    // [string,    2] ��Ÿ�ü�ڵ�                    
} CEXAT11100OutBlock1, *LPCEXAT11100OutBlock1;
#define NAME_CEXAT11100OutBlock1     "CEXAT11100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CEXAT11100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      
    char    OrdNo               [  10];    // [long  ,   10] �ֹ���ȣ                        
    char    BrnNm               [  40];    // [string,   40] ������                          
    char    AcntNm              [  40];    // [string,   40] ���¸�                          
    char    IsuNm               [  50];    // [string,   50] �����                          
    char    OrdAbleAmt          [  16];    // [long  ,   16] �ֹ����ɱݾ�                    
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] �����ֹ����ɱݾ�                
    char    OrdMgn              [  16];    // [long  ,   16] �ֹ����ű�                      
    char    MnyOrdMgn           [  16];    // [long  ,   16] �����ֹ����ű�                  
    char    OrdAbleQty          [  16];    // [long  ,   16] �ֹ����ɼ���                    
} CEXAT11100OutBlock2, *LPCEXAT11100OutBlock2;
#define NAME_CEXAT11100OutBlock2     "CEXAT11100OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAT11100_H_
