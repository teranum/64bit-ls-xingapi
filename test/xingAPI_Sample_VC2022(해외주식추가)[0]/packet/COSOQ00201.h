#ifndef _COSOQ00201_H_
#define _COSOQ00201_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외주식 종합잔고평가 API ( SERVICE=COSOQ00201,ENCRYPT,headtype=B,CREATOR=이유리,CREDATE=2024-06-19 13 )
#pragma pack( push, 1 )

#define NAME_COSOQ00201     "COSOQ00201"

// In(*EMPTY*)                    
typedef struct _COSOQ00201InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    BaseDt              [   8];    // [string,    8] 기준일자                        StartPos 33, Length 8
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 41, Length 3
    char    AstkBalTpCode       [   2];    // [string,    2] 해외증권잔고구분코드            StartPos 44, Length 2
} COSOQ00201InBlock1, *LPCOSOQ00201InBlock1;
#define NAME_COSOQ00201InBlock1     "COSOQ00201InBlock1"

// In(*EMPTY*)                    
typedef struct _COSOQ00201OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    BaseDt              [   8];    // [string,    8] 기준일자                        StartPos 33, Length 8
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 41, Length 3
    char    AstkBalTpCode       [   2];    // [string,    2] 해외증권잔고구분코드            StartPos 44, Length 2
} COSOQ00201OutBlock1, *LPCOSOQ00201OutBlock1;
#define NAME_COSOQ00201OutBlock1     "COSOQ00201OutBlock1"

// Out1(*EMPTY*)                  
typedef struct _COSOQ00201OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    ErnRat              [  18];    // [double, 18.6] 수익율                          StartPos 5, Length 18
    char    DpsConvEvalAmt      [  16];    // [long  ,   16] 예수금환산평가금액              StartPos 23, Length 16
    char    StkConvEvalAmt      [  16];    // [long  ,   16] 주식환산평가금액                StartPos 39, Length 16
    char    DpsastConvEvalAmt   [  16];    // [long  ,   16] 예탁자산환산평가금액            StartPos 55, Length 16
    char    WonEvalSumAmt       [  16];    // [long  ,   16] 원화평가합계금액                StartPos 71, Length 16
    char    ConvEvalPnlAmt      [  16];    // [long  ,   16] 환산평가손익금액                StartPos 87, Length 16
    char    WonDpsBalAmt        [  16];    // [long  ,   16] 원화예수금잔고금액              StartPos 103, Length 16
    char    D2EstiDps           [  16];    // [long  ,   16] D2추정예수금                    StartPos 119, Length 16
    char    LoanAmt             [  16];    // [long  ,   16] 대출금액                        StartPos 135, Length 16
} COSOQ00201OutBlock2, *LPCOSOQ00201OutBlock2;
#define NAME_COSOQ00201OutBlock2     "COSOQ00201OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _COSOQ00201OutBlock3
{
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 0, Length 3
    char    FcurrDps            [  21];    // [double, 21.4] 외화예수금                      StartPos 3, Length 21
    char    FcurrEvalAmt        [  21];    // [double, 21.4] 외화평가금액                    StartPos 24, Length 21
    char    FcurrEvalPnlAmt     [  21];    // [double, 21.4] 외화평가손익금액                StartPos 45, Length 21
    char    PnlRat              [  18];    // [double, 18.6] 손익율                          StartPos 66, Length 18
    char    BaseXchrat          [  15];    // [double, 15.4] 기준환율                        StartPos 84, Length 15
    char    DpsConvEvalAmt      [  16];    // [long  ,   16] 예수금환산평가금액              StartPos 99, Length 16
    char    PchsAmt             [  16];    // [long  ,   16] 매입금액                        StartPos 115, Length 16
    char    StkConvEvalAmt      [  16];    // [long  ,   16] 주식환산평가금액                StartPos 131, Length 16
    char    ConvEvalPnlAmt      [  16];    // [long  ,   16] 환산평가손익금액                StartPos 147, Length 16
    char    FcurrBuyAmt         [  21];    // [double, 21.4] 외화매수금액                    StartPos 163, Length 21
    char    FcurrOrdAbleAmt     [  19];    // [double, 19.2] 외화주문가능금액                StartPos 184, Length 19
    char    LoanAmt             [  16];    // [long  ,   16] 대출금액                        StartPos 203, Length 16
} COSOQ00201OutBlock3, *LPCOSOQ00201OutBlock3;
#define NAME_COSOQ00201OutBlock3     "COSOQ00201OutBlock3"

// Out3(*EMPTY*)                  , occurs
typedef struct _COSOQ00201OutBlock4
{
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 0, Length 3
    char    ShtnIsuNo           [   9];    // [string,    9] 단축종목번호                    StartPos 3, Length 9
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 12, Length 12
    char    JpnMktHanglIsuNm    [ 100];    // [string,  100] 일본시장한글종목명              StartPos 24, Length 100
    char    AstkBalTpCode       [   2];    // [string,    2] 해외증권잔고구분코드            StartPos 124, Length 2
    char    AstkBalTpCodeNm     [  40];    // [string,   40] 해외증권잔고구분코드명          StartPos 126, Length 40
    char    AstkBalQty          [  28];    // [double, 28.6] 해외증권잔고수량                StartPos 166, Length 28
    char    AstkSellAbleQty     [  28];    // [double, 28.6] 해외증권매도가능수량            StartPos 194, Length 28
    char    FcstckUprc          [  24];    // [double, 24.4] 외화증권단가                    StartPos 222, Length 24
    char    FcurrBuyAmt         [  21];    // [double, 21.4] 외화매수금액                    StartPos 246, Length 21
    char    FcstckMktIsuCode    [  18];    // [string,   18] 외화증권시장종목코드            StartPos 267, Length 18
    char    OvrsScrtsCurpri     [  28];    // [double, 28.7] 해외증권시세                    StartPos 285, Length 28
    char    FcurrEvalAmt        [  21];    // [double, 21.4] 외화평가금액                    StartPos 313, Length 21
    char    FcurrEvalPnlAmt     [  21];    // [double, 21.4] 외화평가손익금액                StartPos 334, Length 21
    char    PnlRat              [  18];    // [double, 18.6] 손익율                          StartPos 355, Length 18
    char    BaseXchrat          [  15];    // [double, 15.4] 기준환율                        StartPos 373, Length 15
    char    PchsAmt             [  16];    // [long  ,   16] 매입금액                        StartPos 388, Length 16
    char    DpsConvEvalAmt      [  16];    // [long  ,   16] 예수금환산평가금액              StartPos 404, Length 16
    char    StkConvEvalAmt      [  16];    // [long  ,   16] 주식환산평가금액                StartPos 420, Length 16
    char    ConvEvalPnlAmt      [  16];    // [long  ,   16] 환산평가손익금액                StartPos 436, Length 16
    char    AstkSettQty         [  28];    // [double, 28.6] 해외증권결제수량                StartPos 452, Length 28
    char    MktTpNm             [  20];    // [string,   20] 시장구분명                      StartPos 480, Length 20
    char    FcurrMktCode        [   2];    // [string,    2] 외화시장코드                    StartPos 500, Length 2
    char    LoanDt              [   8];    // [string,    8] 대출일자                        StartPos 502, Length 8
    char    LoanDtlClssCode     [   2];    // [string,    2] 대출상세분류코드                StartPos 510, Length 2
    char    LoanAmt             [  16];    // [long  ,   16] 대출금액                        StartPos 512, Length 16
    char    DueDt               [   8];    // [string,    8] 만기일자                        StartPos 528, Length 8
    char    AstkBasePrc         [  28];    // [double, 28.6] 해외증권기준가격                StartPos 536, Length 28
} COSOQ00201OutBlock4, *LPCOSOQ00201OutBlock4;
#define NAME_COSOQ00201OutBlock4     "COSOQ00201OutBlock4"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _COSOQ00201_H_
