#ifndef _COSAQ00102_H_
#define _COSAQ00102_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽ� �����ֹ�ü�᳻����ȸ API ( SERVICE=COSAQ00102,headtype=B,CREATOR=������,CREDATE=2024-06-10 09 )
#pragma pack( push, 1 )

#define NAME_COSAQ00102     "COSAQ00102"

// In(*EMPTY*)                    
typedef struct _COSAQ00102InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    QryTpCode           [   1];    // [string,    1] ��ȸ�����ڵ�                    StartPos 5, Length 1
    char    BkseqTpCode         [   1];    // [string,    1] ���������ڵ�                    StartPos 6, Length 1
    char    OrdMktCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 7, Length 2
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 9, Length 20
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        StartPos 29, Length 8
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű����ڵ�                    StartPos 37, Length 1
    char    IsuNo               [  12];    // [string,   12] �����ȣ                        StartPos 38, Length 12
    char    SrtOrdNo            [  10];    // [long  ,   10] �����ֹ���ȣ                    StartPos 50, Length 10
    char    OrdDt               [   8];    // [string,    8] �ֹ�����                        StartPos 60, Length 8
    char    ExecYn              [   1];    // [string,    1] ü�Ῡ��                        StartPos 68, Length 1
    char    CrcyCode            [   3];    // [string,    3] ��ȭ�ڵ�                        StartPos 69, Length 3
    char    ThdayBnsAppYn       [   1];    // [string,    1] ���ϸŸ����뿩��                StartPos 72, Length 1
    char    LoanBalHldYn        [   1];    // [string,    1] �����ܰ�������                StartPos 73, Length 1
} COSAQ00102InBlock1, *LPCOSAQ00102InBlock1;
#define NAME_COSAQ00102InBlock1     "COSAQ00102InBlock1"

// In(*EMPTY*)                    
typedef struct _COSAQ00102OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    QryTpCode           [   1];    // [string,    1] ��ȸ�����ڵ�                    StartPos 5, Length 1
    char    BkseqTpCode         [   1];    // [string,    1] ���������ڵ�                    StartPos 6, Length 1
    char    OrdMktCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 7, Length 2
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 9, Length 20
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        StartPos 29, Length 8
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű����ڵ�                    StartPos 37, Length 1
    char    IsuNo               [  12];    // [string,   12] �����ȣ                        StartPos 38, Length 12
    char    SrtOrdNo            [  10];    // [long  ,   10] �����ֹ���ȣ                    StartPos 50, Length 10
    char    OrdDt               [   8];    // [string,    8] �ֹ�����                        StartPos 60, Length 8
    char    ExecYn              [   1];    // [string,    1] ü�Ῡ��                        StartPos 68, Length 1
    char    CrcyCode            [   3];    // [string,    3] ��ȭ�ڵ�                        StartPos 69, Length 3
    char    ThdayBnsAppYn       [   1];    // [string,    1] ���ϸŸ����뿩��                StartPos 72, Length 1
    char    LoanBalHldYn        [   1];    // [string,    1] �����ܰ�������                StartPos 73, Length 1
} COSAQ00102OutBlock1, *LPCOSAQ00102OutBlock1;
#define NAME_COSAQ00102OutBlock1     "COSAQ00102OutBlock1"

// Out(*EMPTY*)                   
typedef struct _COSAQ00102OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] ���¸�                          StartPos 5, Length 40
    char    JpnMktHanglIsuNm    [ 100];    // [string,  100] �Ϻ������ѱ������              StartPos 45, Length 100
    char    MgmtBrnNm           [  40];    // [string,   40] ����������                      StartPos 145, Length 40
    char    SellExecFcurrAmt    [  21];    // [double, 21.4] �ŵ�ü���ȭ�ݾ�                StartPos 185, Length 21
    char    SellExecQty         [  16];    // [long  ,   16] �ŵ�ü�����                    StartPos 206, Length 16
    char    BuyExecFcurrAmt     [  21];    // [double, 21.4] �ż�ü���ȭ�ݾ�                StartPos 222, Length 21
    char    BuyExecQty          [  16];    // [long  ,   16] �ż�ü�����                    StartPos 243, Length 16
} COSAQ00102OutBlock2, *LPCOSAQ00102OutBlock2;
#define NAME_COSAQ00102OutBlock2     "COSAQ00102OutBlock2"

// ST_COSAQ00102_OUT(*EMPTY*)     , occurs
typedef struct _COSAQ00102OutBlock3
{
    char    MgmtBrnNo           [   3];    // [string,    3] ����������ȣ                    StartPos 0, Length 3
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 3, Length 20
    char    AcntNm              [  40];    // [string,   40] ���¸�                          StartPos 23, Length 40
    char    ExecTime            [   9];    // [string,    9] ü��ð�                        StartPos 63, Length 9
    char    OrdTime             [   9];    // [string,    9] �ֹ��ð�                        StartPos 72, Length 9
    char    OrdNo               [  10];    // [long  ,   10] �ֹ���ȣ                        StartPos 81, Length 10
    char    OrgOrdNo            [  10];    // [long  ,   10] ���ֹ���ȣ                      StartPos 91, Length 10
    char    ShtnIsuNo           [   9];    // [string,    9] ���������ȣ                    StartPos 101, Length 9
    char    OrdTrxPtnNm         [  50];    // [string,   50] �ֹ�ó��������                  StartPos 110, Length 50
    char    OrdTrxPtnCode       [   9];    // [long  ,    9] �ֹ�ó�������ڵ�                StartPos 160, Length 9
    char    MrcAbleQty          [  16];    // [long  ,   16] ������Ұ��ɼ���                StartPos 169, Length 16
    char    OrdQty              [  16];    // [long  ,   16] �ֹ�����                        StartPos 185, Length 16
    char    OvrsOrdPrc          [  22];    // [double, 22.7] �ؿ��ֹ���                      StartPos 201, Length 22
    char    ExecQty             [  16];    // [long  ,   16] ü�����                        StartPos 223, Length 16
    char    OvrsExecPrc         [  28];    // [double, 28.7] �ؿ�ü�ᰡ                      StartPos 239, Length 28
    char    OrdprcPtnCode       [   2];    // [string,    2] ȣ�������ڵ�                    StartPos 267, Length 2
    char    OrdprcPtnNm         [  40];    // [string,   40] ȣ��������                      StartPos 269, Length 40
    char    OrdPtnNm            [  40];    // [string,   40] �ֹ�������                      StartPos 309, Length 40
    char    OrdPtnCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 349, Length 2
    char    MrcTpCode           [   1];    // [string,    1] ������ұ����ڵ�                StartPos 351, Length 1
    char    MrcTpNm             [  10];    // [string,   10] ������ұ��и�                  StartPos 352, Length 10
    char    AllExecQty          [  16];    // [long  ,   16] ��üü�����                    StartPos 362, Length 16
    char    CommdaCode          [   2];    // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 378, Length 2
    char    OrdMktCode          [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 380, Length 2
    char    MktNm               [  40];    // [string,   40] �����                          StartPos 382, Length 40
    char    CommdaNm            [  40];    // [string,   40] ��Ÿ�ü��                      StartPos 422, Length 40
    char    JpnMktHanglIsuNm    [ 100];    // [string,  100] �Ϻ������ѱ������              StartPos 462, Length 100
    char    UnercQty            [  16];    // [long  ,   16] ��ü�����                      StartPos 562, Length 16
    char    CnfQty              [  16];    // [long  ,   16] Ȯ�μ���                        StartPos 578, Length 16
    char    CrcyCode            [   3];    // [string,    3] ��ȭ�ڵ�                        StartPos 594, Length 3
    char    RegMktCode          [   2];    // [string,    2] ��Ͻ����ڵ�                    StartPos 597, Length 2
    char    IsuNo               [  12];    // [string,   12] �����ȣ                        StartPos 599, Length 12
    char    BrkTpCode           [   2];    // [string,    2] �߰��α����ڵ�                  StartPos 611, Length 2
    char    OppBrkNm            [  40];    // [string,   40] ����߰��θ�                    StartPos 613, Length 40
    char    BnsTpCode           [   1];    // [string,    1] �Ÿű����ڵ�                    StartPos 653, Length 1
    char    LoanDt              [   8];    // [string,    8] ��������                        StartPos 654, Length 8
    char    LoanAmt             [  16];    // [long  ,   16] ����ݾ�                        StartPos 662, Length 16
} COSAQ00102OutBlock3, *LPCOSAQ00102OutBlock3;
#define NAME_COSAQ00102OutBlock3     "COSAQ00102OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _COSAQ00102_H_
