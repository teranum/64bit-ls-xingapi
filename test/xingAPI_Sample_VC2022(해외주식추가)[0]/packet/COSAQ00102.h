#ifndef _COSAQ00102_H_
#define _COSAQ00102_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외주식 계좌주문체결내역조회 API ( SERVICE=COSAQ00102,headtype=B,CREATOR=이유리,CREDATE=2024-06-10 09 )
#pragma pack( push, 1 )

#define NAME_COSAQ00102     "COSAQ00102"

// In(*EMPTY*)                    
typedef struct _COSAQ00102InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    QryTpCode           [   1];    // [string,    1] 조회구분코드                    StartPos 5, Length 1
    char    BkseqTpCode         [   1];    // [string,    1] 역순구분코드                    StartPos 6, Length 1
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 7, Length 2
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 9, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 29, Length 8
    char    BnsTpCode           [   1];    // [string,    1] 매매구분코드                    StartPos 37, Length 1
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 38, Length 12
    char    SrtOrdNo            [  10];    // [long  ,   10] 시작주문번호                    StartPos 50, Length 10
    char    OrdDt               [   8];    // [string,    8] 주문일자                        StartPos 60, Length 8
    char    ExecYn              [   1];    // [string,    1] 체결여부                        StartPos 68, Length 1
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 69, Length 3
    char    ThdayBnsAppYn       [   1];    // [string,    1] 당일매매적용여부                StartPos 72, Length 1
    char    LoanBalHldYn        [   1];    // [string,    1] 대출잔고보유여부                StartPos 73, Length 1
} COSAQ00102InBlock1, *LPCOSAQ00102InBlock1;
#define NAME_COSAQ00102InBlock1     "COSAQ00102InBlock1"

// In(*EMPTY*)                    
typedef struct _COSAQ00102OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    QryTpCode           [   1];    // [string,    1] 조회구분코드                    StartPos 5, Length 1
    char    BkseqTpCode         [   1];    // [string,    1] 역순구분코드                    StartPos 6, Length 1
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 7, Length 2
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 9, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 29, Length 8
    char    BnsTpCode           [   1];    // [string,    1] 매매구분코드                    StartPos 37, Length 1
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 38, Length 12
    char    SrtOrdNo            [  10];    // [long  ,   10] 시작주문번호                    StartPos 50, Length 10
    char    OrdDt               [   8];    // [string,    8] 주문일자                        StartPos 60, Length 8
    char    ExecYn              [   1];    // [string,    1] 체결여부                        StartPos 68, Length 1
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 69, Length 3
    char    ThdayBnsAppYn       [   1];    // [string,    1] 당일매매적용여부                StartPos 72, Length 1
    char    LoanBalHldYn        [   1];    // [string,    1] 대출잔고보유여부                StartPos 73, Length 1
} COSAQ00102OutBlock1, *LPCOSAQ00102OutBlock1;
#define NAME_COSAQ00102OutBlock1     "COSAQ00102OutBlock1"

// Out(*EMPTY*)                   
typedef struct _COSAQ00102OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    JpnMktHanglIsuNm    [ 100];    // [string,  100] 일본시장한글종목명              StartPos 45, Length 100
    char    MgmtBrnNm           [  40];    // [string,   40] 관리지점명                      StartPos 145, Length 40
    char    SellExecFcurrAmt    [  21];    // [double, 21.4] 매도체결외화금액                StartPos 185, Length 21
    char    SellExecQty         [  16];    // [long  ,   16] 매도체결수량                    StartPos 206, Length 16
    char    BuyExecFcurrAmt     [  21];    // [double, 21.4] 매수체결외화금액                StartPos 222, Length 21
    char    BuyExecQty          [  16];    // [long  ,   16] 매수체결수량                    StartPos 243, Length 16
} COSAQ00102OutBlock2, *LPCOSAQ00102OutBlock2;
#define NAME_COSAQ00102OutBlock2     "COSAQ00102OutBlock2"

// ST_COSAQ00102_OUT(*EMPTY*)     , occurs
typedef struct _COSAQ00102OutBlock3
{
    char    MgmtBrnNo           [   3];    // [string,    3] 관리지점번호                    StartPos 0, Length 3
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 3, Length 20
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 23, Length 40
    char    ExecTime            [   9];    // [string,    9] 체결시각                        StartPos 63, Length 9
    char    OrdTime             [   9];    // [string,    9] 주문시각                        StartPos 72, Length 9
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 81, Length 10
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 91, Length 10
    char    ShtnIsuNo           [   9];    // [string,    9] 단축종목번호                    StartPos 101, Length 9
    char    OrdTrxPtnNm         [  50];    // [string,   50] 주문처리유형명                  StartPos 110, Length 50
    char    OrdTrxPtnCode       [   9];    // [long  ,    9] 주문처리유형코드                StartPos 160, Length 9
    char    MrcAbleQty          [  16];    // [long  ,   16] 정정취소가능수량                StartPos 169, Length 16
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 185, Length 16
    char    OvrsOrdPrc          [  22];    // [double, 22.7] 해외주문가                      StartPos 201, Length 22
    char    ExecQty             [  16];    // [long  ,   16] 체결수량                        StartPos 223, Length 16
    char    OvrsExecPrc         [  28];    // [double, 28.7] 해외체결가                      StartPos 239, Length 28
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 267, Length 2
    char    OrdprcPtnNm         [  40];    // [string,   40] 호가유형명                      StartPos 269, Length 40
    char    OrdPtnNm            [  40];    // [string,   40] 주문유형명                      StartPos 309, Length 40
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 349, Length 2
    char    MrcTpCode           [   1];    // [string,    1] 정정취소구분코드                StartPos 351, Length 1
    char    MrcTpNm             [  10];    // [string,   10] 정정취소구분명                  StartPos 352, Length 10
    char    AllExecQty          [  16];    // [long  ,   16] 전체체결수량                    StartPos 362, Length 16
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 378, Length 2
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 380, Length 2
    char    MktNm               [  40];    // [string,   40] 시장명                          StartPos 382, Length 40
    char    CommdaNm            [  40];    // [string,   40] 통신매체명                      StartPos 422, Length 40
    char    JpnMktHanglIsuNm    [ 100];    // [string,  100] 일본시장한글종목명              StartPos 462, Length 100
    char    UnercQty            [  16];    // [long  ,   16] 미체결수량                      StartPos 562, Length 16
    char    CnfQty              [  16];    // [long  ,   16] 확인수량                        StartPos 578, Length 16
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 594, Length 3
    char    RegMktCode          [   2];    // [string,    2] 등록시장코드                    StartPos 597, Length 2
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 599, Length 12
    char    BrkTpCode           [   2];    // [string,    2] 중개인구분코드                  StartPos 611, Length 2
    char    OppBrkNm            [  40];    // [string,   40] 상대중개인명                    StartPos 613, Length 40
    char    BnsTpCode           [   1];    // [string,    1] 매매구분코드                    StartPos 653, Length 1
    char    LoanDt              [   8];    // [string,    8] 대출일자                        StartPos 654, Length 8
    char    LoanAmt             [  16];    // [long  ,   16] 대출금액                        StartPos 662, Length 16
} COSAQ00102OutBlock3, *LPCOSAQ00102OutBlock3;
#define NAME_COSAQ00102OutBlock3     "COSAQ00102OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _COSAQ00102_H_
