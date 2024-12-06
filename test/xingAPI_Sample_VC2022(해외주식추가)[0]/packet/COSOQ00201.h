#ifndef _COSOQ00201_H_
#define _COSOQ00201_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽ� �����ܰ��� API ( SERVICE=COSOQ00201,ENCRYPT,headtype=B,CREATOR=������,CREDATE=2024-06-19 13 )
#pragma pack( push, 1 )

#define NAME_COSOQ00201     "COSOQ00201"

// In(*EMPTY*)                    
typedef struct _COSOQ00201InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
    char    BaseDt              [   8];    // [string,    8] ��������                        StartPos 33, Length 8
    char    CrcyCode            [   3];    // [string,    3] ��ȭ�ڵ�                        StartPos 41, Length 3
    char    AstkBalTpCode       [   2];    // [string,    2] �ؿ������ܰ����ڵ�            StartPos 44, Length 2
} COSOQ00201InBlock1, *LPCOSOQ00201InBlock1;
#define NAME_COSOQ00201InBlock1     "COSOQ00201InBlock1"

// In(*EMPTY*)                    
typedef struct _COSOQ00201OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] ���¹�ȣ                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] ��й�ȣ                        StartPos 25, Length 8
    char    BaseDt              [   8];    // [string,    8] ��������                        StartPos 33, Length 8
    char    CrcyCode            [   3];    // [string,    3] ��ȭ�ڵ�                        StartPos 41, Length 3
    char    AstkBalTpCode       [   2];    // [string,    2] �ؿ������ܰ����ڵ�            StartPos 44, Length 2
} COSOQ00201OutBlock1, *LPCOSOQ00201OutBlock1;
#define NAME_COSOQ00201OutBlock1     "COSOQ00201OutBlock1"

// Out1(*EMPTY*)                  
typedef struct _COSOQ00201OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] ���ڵ尹��                      StartPos 0, Length 5
    char    ErnRat              [  18];    // [double, 18.6] ������                          StartPos 5, Length 18
    char    DpsConvEvalAmt      [  16];    // [long  ,   16] ������ȯ���򰡱ݾ�              StartPos 23, Length 16
    char    StkConvEvalAmt      [  16];    // [long  ,   16] �ֽ�ȯ���򰡱ݾ�                StartPos 39, Length 16
    char    DpsastConvEvalAmt   [  16];    // [long  ,   16] ��Ź�ڻ�ȯ���򰡱ݾ�            StartPos 55, Length 16
    char    WonEvalSumAmt       [  16];    // [long  ,   16] ��ȭ���հ�ݾ�                StartPos 71, Length 16
    char    ConvEvalPnlAmt      [  16];    // [long  ,   16] ȯ���򰡼��ͱݾ�                StartPos 87, Length 16
    char    WonDpsBalAmt        [  16];    // [long  ,   16] ��ȭ�������ܰ�ݾ�              StartPos 103, Length 16
    char    D2EstiDps           [  16];    // [long  ,   16] D2����������                    StartPos 119, Length 16
    char    LoanAmt             [  16];    // [long  ,   16] ����ݾ�                        StartPos 135, Length 16
} COSOQ00201OutBlock2, *LPCOSOQ00201OutBlock2;
#define NAME_COSOQ00201OutBlock2     "COSOQ00201OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _COSOQ00201OutBlock3
{
    char    CrcyCode            [   3];    // [string,    3] ��ȭ�ڵ�                        StartPos 0, Length 3
    char    FcurrDps            [  21];    // [double, 21.4] ��ȭ������                      StartPos 3, Length 21
    char    FcurrEvalAmt        [  21];    // [double, 21.4] ��ȭ�򰡱ݾ�                    StartPos 24, Length 21
    char    FcurrEvalPnlAmt     [  21];    // [double, 21.4] ��ȭ�򰡼��ͱݾ�                StartPos 45, Length 21
    char    PnlRat              [  18];    // [double, 18.6] ������                          StartPos 66, Length 18
    char    BaseXchrat          [  15];    // [double, 15.4] ����ȯ��                        StartPos 84, Length 15
    char    DpsConvEvalAmt      [  16];    // [long  ,   16] ������ȯ���򰡱ݾ�              StartPos 99, Length 16
    char    PchsAmt             [  16];    // [long  ,   16] ���Աݾ�                        StartPos 115, Length 16
    char    StkConvEvalAmt      [  16];    // [long  ,   16] �ֽ�ȯ���򰡱ݾ�                StartPos 131, Length 16
    char    ConvEvalPnlAmt      [  16];    // [long  ,   16] ȯ���򰡼��ͱݾ�                StartPos 147, Length 16
    char    FcurrBuyAmt         [  21];    // [double, 21.4] ��ȭ�ż��ݾ�                    StartPos 163, Length 21
    char    FcurrOrdAbleAmt     [  19];    // [double, 19.2] ��ȭ�ֹ����ɱݾ�                StartPos 184, Length 19
    char    LoanAmt             [  16];    // [long  ,   16] ����ݾ�                        StartPos 203, Length 16
} COSOQ00201OutBlock3, *LPCOSOQ00201OutBlock3;
#define NAME_COSOQ00201OutBlock3     "COSOQ00201OutBlock3"

// Out3(*EMPTY*)                  , occurs
typedef struct _COSOQ00201OutBlock4
{
    char    CrcyCode            [   3];    // [string,    3] ��ȭ�ڵ�                        StartPos 0, Length 3
    char    ShtnIsuNo           [   9];    // [string,    9] ���������ȣ                    StartPos 3, Length 9
    char    IsuNo               [  12];    // [string,   12] �����ȣ                        StartPos 12, Length 12
    char    JpnMktHanglIsuNm    [ 100];    // [string,  100] �Ϻ������ѱ������              StartPos 24, Length 100
    char    AstkBalTpCode       [   2];    // [string,    2] �ؿ������ܰ����ڵ�            StartPos 124, Length 2
    char    AstkBalTpCodeNm     [  40];    // [string,   40] �ؿ������ܰ����ڵ��          StartPos 126, Length 40
    char    AstkBalQty          [  28];    // [double, 28.6] �ؿ������ܰ����                StartPos 166, Length 28
    char    AstkSellAbleQty     [  28];    // [double, 28.6] �ؿ����Ǹŵ����ɼ���            StartPos 194, Length 28
    char    FcstckUprc          [  24];    // [double, 24.4] ��ȭ���Ǵܰ�                    StartPos 222, Length 24
    char    FcurrBuyAmt         [  21];    // [double, 21.4] ��ȭ�ż��ݾ�                    StartPos 246, Length 21
    char    FcstckMktIsuCode    [  18];    // [string,   18] ��ȭ���ǽ��������ڵ�            StartPos 267, Length 18
    char    OvrsScrtsCurpri     [  28];    // [double, 28.7] �ؿ����ǽü�                    StartPos 285, Length 28
    char    FcurrEvalAmt        [  21];    // [double, 21.4] ��ȭ�򰡱ݾ�                    StartPos 313, Length 21
    char    FcurrEvalPnlAmt     [  21];    // [double, 21.4] ��ȭ�򰡼��ͱݾ�                StartPos 334, Length 21
    char    PnlRat              [  18];    // [double, 18.6] ������                          StartPos 355, Length 18
    char    BaseXchrat          [  15];    // [double, 15.4] ����ȯ��                        StartPos 373, Length 15
    char    PchsAmt             [  16];    // [long  ,   16] ���Աݾ�                        StartPos 388, Length 16
    char    DpsConvEvalAmt      [  16];    // [long  ,   16] ������ȯ���򰡱ݾ�              StartPos 404, Length 16
    char    StkConvEvalAmt      [  16];    // [long  ,   16] �ֽ�ȯ���򰡱ݾ�                StartPos 420, Length 16
    char    ConvEvalPnlAmt      [  16];    // [long  ,   16] ȯ���򰡼��ͱݾ�                StartPos 436, Length 16
    char    AstkSettQty         [  28];    // [double, 28.6] �ؿ����ǰ�������                StartPos 452, Length 28
    char    MktTpNm             [  20];    // [string,   20] ���屸�и�                      StartPos 480, Length 20
    char    FcurrMktCode        [   2];    // [string,    2] ��ȭ�����ڵ�                    StartPos 500, Length 2
    char    LoanDt              [   8];    // [string,    8] ��������                        StartPos 502, Length 8
    char    LoanDtlClssCode     [   2];    // [string,    2] ����󼼺з��ڵ�                StartPos 510, Length 2
    char    LoanAmt             [  16];    // [long  ,   16] ����ݾ�                        StartPos 512, Length 16
    char    DueDt               [   8];    // [string,    8] ��������                        StartPos 528, Length 8
    char    AstkBasePrc         [  28];    // [double, 28.6] �ؿ����Ǳ��ذ���                StartPos 536, Length 28
} COSOQ00201OutBlock4, *LPCOSOQ00201OutBlock4;
#define NAME_COSOQ00201OutBlock4     "COSOQ00201OutBlock4"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _COSOQ00201_H_
