#ifndef _CEXAT11200_H_
#define _CEXAT11200_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ������ �����ֹ� ( SERVICE=CEXAT11200,headtype=B,CREATOR=�̽���,CREDATE=2012/06/27 21 )
#pragma pack( push, 1 )

#define NAME_CEXAT11200     "CEXAT11200"

// In(*EMPTY*)                    
typedef struct _CEXAT11200InBlock1
{
    char    OrgOrdNo            [  10];    // [long  ,   10] ���ֹ���ȣ                      
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                
    char    OrdPrc              [  15];    // [double, 15.2] �ֹ�����                        
} CEXAT11200InBlock1, *LPCEXAT11200InBlock1;
#define NAME_CEXAT11200InBlock1     "CEXAT11200InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAT11200OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      
    char    OrgOrdNo            [  10];    // [long  ,   10] ���ֹ���ȣ                      
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű����ڵ�                    
    char    ErxPrcCndiTpCode    [   1];    // [string,    1] �������������Ǳ����ڵ�          
    char    OrdPrc              [  15];    // [double, 15.2] �ֹ�����                        
    char    MdfyQty             [  16];    // [long  ,   16] ��������                        
    char    OrdCndiPrc          [  25];    // [double, 25.8] �ֹ����ǰ���                    
    char    CommdaCode          [   2];    // [string,    2] ��Ÿ�ü�ڵ�                    
} CEXAT11200OutBlock1, *LPCEXAT11200OutBlock1;
#define NAME_CEXAT11200OutBlock1     "CEXAT11200OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CEXAT11200OutBlock2
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
} CEXAT11200OutBlock2, *LPCEXAT11200OutBlock2;
#define NAME_CEXAT11200OutBlock2     "CEXAT11200OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAT11200_H_
