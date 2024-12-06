#ifndef _CFOAT00100_H_
#define _CFOAT00100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �����ɼ� �����ֹ� ( SERVICE=CFOAT00100,ENCRYPT,SIGNATURE,HEADTYPE=B,CREATOR=������,CREDATE=2022/02/16 14:20:59 )
#pragma pack( push, 1 )

#define NAME_CFOAT00100     "CFOAT00100"

// In(*EMPTY*)                    
typedef struct _CFOAT00100InBlock1
{
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 0, Length 20
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        StartPos 20, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                StartPos 28, Length 12
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű���                        StartPos 40, Length 1
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] �����ɼ�ȣ�������ڵ�            StartPos 41, Length 2
    char    FnoOrdPrc           [  27];    // [double, 27.8] �����ɼ��ֹ�����                StartPos 43, Length 27
    char    OrdQty              [  16];    // [long  ,   16] �ֹ�����                        StartPos 70, Length 16
} CFOAT00100InBlock1, *LPCFOAT00100InBlock1;
#define NAME_CFOAT00100InBlock1     "CFOAT00100InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOAT00100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    OrdMktCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 5, Length 2
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 7, Length 20
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        StartPos 27, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] �����ɼ������ȣ                StartPos 35, Length 12
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű���                        StartPos 47, Length 1
    char    FnoOrdPtnCode       [   2];    // [string,    2] �����ɼ��ֹ������ڵ�            StartPos 48, Length 2
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] �����ɼ�ȣ�������ڵ�            StartPos 50, Length 2
    char    FnoTrdPtnCode       [   2];    // [string,    2] �����ɼǰŷ������ڵ�            StartPos 52, Length 2
    char    FnoOrdPrc           [  27];    // [double, 27.8] �����ɼ��ֹ�����                StartPos 54, Length 27
    char    OrdQty              [  16];    // [long  ,   16] �ֹ�����                        StartPos 81, Length 16
    char    CommdaCode          [   2];    // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 97, Length 2
    char    DscusBnsCmpltTime   [   9];    // [string,    9] ���ǸŸſϷ�ð�                StartPos 99, Length 9
    char    GrpId               [  20];    // [string,   20] �׷�ID                          StartPos 108, Length 20
    char    OrdSeqno            [  10];    // [long  ,   10] �ֹ��Ϸù�ȣ                    StartPos 128, Length 10
    char    PtflNo              [  10];    // [long  ,   10] ��Ʈ��������ȣ                  StartPos 138, Length 10
    char    BskNo               [  10];    // [long  ,   10] �ٽ��Ϲ�ȣ                      StartPos 148, Length 10
    char    TrchNo              [  10];    // [long  ,   10] Ʈ��ġ��ȣ                      StartPos 158, Length 10
    char    ItemNo              [  16];    // [long  ,   16] �׸��ȣ                        StartPos 168, Length 16
    char    OpDrtnNo            [  12];    // [string,   12] ������ù�ȣ                    StartPos 184, Length 12
    char    MgempNo             [   9];    // [string,    9] ���������ȣ                    StartPos 196, Length 9
    char    FundId              [  12];    // [string,   12] �ݵ�ID                          StartPos 205, Length 12
    char    FundOrdNo           [  10];    // [long  ,   10] �ݵ��ֹ���ȣ                    StartPos 217, Length 10
} CFOAT00100OutBlock1, *LPCFOAT00100OutBlock1;
#define NAME_CFOAT00100OutBlock1     "CFOAT00100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOAT00100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] �ֹ���ȣ                        StartPos 5, Length 10
    char    BrnNm               [  40];    // [string,   40] ������                          StartPos 15, Length 40
    char    AcntNm              [  40];    // [string,   40] ���¸�                          StartPos 55, Length 40
    char    IsuNm               [  50];    // [string,   50] �����                          StartPos 95, Length 50
    char    OrdAbleAmt          [  16];    // [long  ,   16] �ֹ����ɱݾ�                    StartPos 145, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] �����ֹ����ɱݾ�                StartPos 161, Length 16
    char    OrdMgn              [  16];    // [long  ,   16] �ֹ����ű�                      StartPos 177, Length 16
    char    MnyOrdMgn           [  16];    // [long  ,   16] �����ֹ����ű�                  StartPos 193, Length 16
    char    OrdAbleQty          [  16];    // [long  ,   16] �ֹ����ɼ���                    StartPos 209, Length 16
} CFOAT00100OutBlock2, *LPCFOAT00100OutBlock2;
#define NAME_CFOAT00100OutBlock2     "CFOAT00100OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOAT00100_H_
