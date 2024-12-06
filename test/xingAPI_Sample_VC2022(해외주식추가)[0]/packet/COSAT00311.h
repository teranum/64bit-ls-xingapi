#ifndef _COSAT00311_H_
#define _COSAT00311_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 미국시장 정정주문 API ( SERVICE=COSAT00311,headtype=B,CREATOR=이유리,CREDATE=2024-05-21 16 )
#pragma pack( push, 1 )

#define NAME_COSAT00311     "COSAT00311"

// In(*EMPTY*)                    
typedef struct _COSAT00311InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 5, Length 2
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 7, Length 10
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 17, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 37, Length 8
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 45, Length 2
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 47, Length 12
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 59, Length 16
    char    OvrsOrdPrc          [  28];    // [double, 28.7] 해외주문가                      StartPos 75, Length 28
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 103, Length 2
    char    BrkTpCode           [   2];    // [string,    2] 중개인구분코드                  StartPos 107, Length 2
} COSAT00311InBlock1, *LPCOSAT00311InBlock1;
#define NAME_COSAT00311InBlock1     "COSAT00311InBlock1"

// In(*EMPTY*)                    
typedef struct _COSAT00311OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 5, Length 2
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 7, Length 10
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 17, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 37, Length 8
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 45, Length 2
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 47, Length 12
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 59, Length 16
    char    OvrsOrdPrc          [  28];    // [double, 28.7] 해외주문가                      StartPos 75, Length 28
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 103, Length 2
    char    RegCommdaCode       [   2];    // [string,    2] 등록통신매체코드                StartPos 105, Length 2
    char    BrkTpCode           [   2];    // [string,    2] 중개인구분코드                  StartPos 107, Length 2
} COSAT00311OutBlock1, *LPCOSAT00311OutBlock1;
#define NAME_COSAT00311OutBlock1     "COSAT00311OutBlock1"

// Out(*EMPTY*)                   
typedef struct _COSAT00311OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 5, Length 10
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 15, Length 40
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 55, Length 40
} COSAT00311OutBlock2, *LPCOSAT00311OutBlock2;
#define NAME_COSAT00311OutBlock2     "COSAT00311OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _COSAT00311_H_
