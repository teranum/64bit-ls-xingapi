#ifndef _COSAT00301_H_
#define _COSAT00301_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �̱������ֹ� API ( SERVICE=COSAT00301,headtype=B,CREATOR=������,CREDATE=2024-05-21 16 )
#pragma pack( push, 1 )

#define NAME_COSAT00301     "COSAT00301"

// In(*EMPTY*)                    
typedef struct _COSAT00301InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    OrdPtnCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 5, Length 2
    char    OrgOrdNo            [  10];    // [long  ,   10] ���ֹ���ȣ                      StartPos 7, Length 10
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 17, Length 20
    char    InptPwd             [   8];    // [string,    8] �Էº�й�ȣ                    StartPos 37, Length 8
    char    OrdMktCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 45, Length 2
    char    IsuNo               [  12];    // [string,   12] �����ȣ                        StartPos 47, Length 12
    char    OrdQty              [  16];    // [long  ,   16] �ֹ�����                        StartPos 59, Length 16
    char    OvrsOrdPrc          [  28];    // [double, 28.7] �ؿ��ֹ���                      StartPos 75, Length 28
    char    OrdprcPtnCode       [   2];    // [string,    2] ȣ�������ڵ�                    StartPos 103, Length 2
    char    BrkTpCode           [   2];    // [string,    2] �߰��α����ڵ�                  StartPos 107, Length 2
} COSAT00301InBlock1, *LPCOSAT00301InBlock1;
#define NAME_COSAT00301InBlock1     "COSAT00301InBlock1"

// In(*EMPTY*)                    
typedef struct _COSAT00301OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    OrdPtnCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 5, Length 2
    char    OrgOrdNo            [  10];    // [long  ,   10] ���ֹ���ȣ                      StartPos 7, Length 10
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 17, Length 20
    char    InptPwd             [   8];    // [string,    8] �Էº�й�ȣ                    StartPos 37, Length 8
    char    OrdMktCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 45, Length 2
    char    IsuNo               [  12];    // [string,   12] �����ȣ                        StartPos 47, Length 12
    char    OrdQty              [  16];    // [long  ,   16] �ֹ�����                        StartPos 59, Length 16
    char    OvrsOrdPrc          [  28];    // [double, 28.7] �ؿ��ֹ���                      StartPos 75, Length 28
    char    OrdprcPtnCode       [   2];    // [string,    2] ȣ�������ڵ�                    StartPos 103, Length 2
    char    RegCommdaCode       [   2];    // [string,    2] �����Ÿ�ü�ڵ�                StartPos 105, Length 2
    char    BrkTpCode           [   2];    // [string,    2] �߰��α����ڵ�                  StartPos 107, Length 2
} COSAT00301OutBlock1, *LPCOSAT00301OutBlock1;
#define NAME_COSAT00301OutBlock1     "COSAT00301OutBlock1"

// Out(*EMPTY*)                   
typedef struct _COSAT00301OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] �ֹ���ȣ                        StartPos 5, Length 10
    char    AcntNm              [  40];    // [string,   40] ���¸�                          StartPos 15, Length 40
    char    IsuNm               [  40];    // [string,   40] �����                          StartPos 55, Length 40
} COSAT00301OutBlock2, *LPCOSAT00301OutBlock2;
#define NAME_COSAT00301OutBlock2     "COSAT00301OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _COSAT00301_H_
