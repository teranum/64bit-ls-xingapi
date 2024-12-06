#ifndef _GSH_H_
#define _GSH_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외주식 호가(GSH) ( attr,svr=OVS,key=18,group=1 )
#pragma pack( push, 1 )

#define NAME_GSH     "GSH"

// 입력                           
typedef struct _GSH_InBlock
{
    char    keysymbol           [  18];                                      // [string,   18] 종목코드                        StartPos 0, Length 18
} GSH_InBlock, *LPGSH_InBlock;
#define NAME_GSH_InBlock     "InBlock"

// 출력                           
typedef struct _GSH_OutBlock
{
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] 종목코드                        StartPos 0, Length 16
    char    loctime             [   6];    char    _loctime             ;    // [string,    6] 현지호가시간                    StartPos 17, Length 6
    char    kortime             [   6];    char    _kortime             ;    // [string,    6] 한국호가시간                    StartPos 24, Length 6
    char    offerho1            [  15];    char    _offerho1            ;    // [double, 15.6] 매도호가 1                      StartPos 31, Length 15
    char    bidho1              [  15];    char    _bidho1              ;    // [double, 15.6] 매수호가 1                      StartPos 47, Length 15
    char    offerrem1           [  10];    char    _offerrem1           ;    // [long  ,   10] 매도호가 잔량 1                 StartPos 63, Length 10
    char    bidrem1             [  10];    char    _bidrem1             ;    // [long  ,   10] 매수호가 잔량 1                 StartPos 74, Length 10
    char    offerno1            [  10];    char    _offerno1            ;    // [long  ,   10] 매도호가 건수 1                 StartPos 85, Length 10
    char    bidno1              [  10];    char    _bidno1              ;    // [long  ,   10] 매수호가 건수 1                 StartPos 96, Length 10
    char    offerho2            [  15];    char    _offerho2            ;    // [double, 15.6] 매도호가 2                      StartPos 107, Length 15
    char    bidho2              [  15];    char    _bidho2              ;    // [double, 15.6] 매수호가 2                      StartPos 123, Length 15
    char    offerrem2           [  10];    char    _offerrem2           ;    // [long  ,   10] 매도호가 잔량 2                 StartPos 139, Length 10
    char    bidrem2             [  10];    char    _bidrem2             ;    // [long  ,   10] 매수호가 잔량 2                 StartPos 150, Length 10
    char    offerno2            [  10];    char    _offerno2            ;    // [long  ,   10] 매도호가 건수 2                 StartPos 161, Length 10
    char    bidno2              [  10];    char    _bidno2              ;    // [long  ,   10] 매수호가 건수 2                 StartPos 172, Length 10
    char    offerho3            [  15];    char    _offerho3            ;    // [double, 15.6] 매도호가 3                      StartPos 183, Length 15
    char    bidho3              [  15];    char    _bidho3              ;    // [double, 15.6] 매수호가 3                      StartPos 199, Length 15
    char    offerrem3           [  10];    char    _offerrem3           ;    // [long  ,   10] 매도호가 잔량 3                 StartPos 215, Length 10
    char    bidrem3             [  10];    char    _bidrem3             ;    // [long  ,   10] 매수호가 잔량 3                 StartPos 226, Length 10
    char    offerno3            [  10];    char    _offerno3            ;    // [long  ,   10] 매도호가 건수 3                 StartPos 237, Length 10
    char    bidno3              [  10];    char    _bidno3              ;    // [long  ,   10] 매수호가 건수 3                 StartPos 248, Length 10
    char    offerho4            [  15];    char    _offerho4            ;    // [double, 15.6] 매도호가 4                      StartPos 259, Length 15
    char    bidho4              [  15];    char    _bidho4              ;    // [double, 15.6] 매수호가 4                      StartPos 275, Length 15
    char    offerrem4           [  10];    char    _offerrem4           ;    // [long  ,   10] 매도호가 잔량 4                 StartPos 291, Length 10
    char    bidrem4             [  10];    char    _bidrem4             ;    // [long  ,   10] 매수호가 잔량 4                 StartPos 302, Length 10
    char    offerno4            [  10];    char    _offerno4            ;    // [long  ,   10] 매도호가 건수 4                 StartPos 313, Length 10
    char    bidno4              [  10];    char    _bidno4              ;    // [long  ,   10] 매수호가 건수 4                 StartPos 324, Length 10
    char    offerho5            [  15];    char    _offerho5            ;    // [double, 15.6] 매도호가 5                      StartPos 335, Length 15
    char    bidho5              [  15];    char    _bidho5              ;    // [double, 15.6] 매수호가 5                      StartPos 351, Length 15
    char    offerrem5           [  10];    char    _offerrem5           ;    // [long  ,   10] 매도호가 잔량 5                 StartPos 367, Length 10
    char    bidrem5             [  10];    char    _bidrem5             ;    // [long  ,   10] 매수호가 잔량 5                 StartPos 378, Length 10
    char    offerno5            [  10];    char    _offerno5            ;    // [long  ,   10] 매도호가 건수 5                 StartPos 389, Length 10
    char    bidno5              [  10];    char    _bidno5              ;    // [long  ,   10] 매수호가 건수 5                 StartPos 400, Length 10
    char    offerho6            [  15];    char    _offerho6            ;    // [double, 15.6] 매도호가 6                      StartPos 411, Length 15
    char    bidho6              [  15];    char    _bidho6              ;    // [double, 15.6] 매수호가 6                      StartPos 427, Length 15
    char    offerrem6           [  10];    char    _offerrem6           ;    // [long  ,   10] 매도호가 잔량 6                 StartPos 443, Length 10
    char    bidrem6             [  10];    char    _bidrem6             ;    // [long  ,   10] 매수호가 잔량 6                 StartPos 454, Length 10
    char    offerno6            [  10];    char    _offerno6            ;    // [long  ,   10] 매도호가 건수 6                 StartPos 465, Length 10
    char    bidno6              [  10];    char    _bidno6              ;    // [long  ,   10] 매수호가 건수 6                 StartPos 476, Length 10
    char    offerho7            [  15];    char    _offerho7            ;    // [double, 15.6] 매도호가 7                      StartPos 487, Length 15
    char    bidho7              [  15];    char    _bidho7              ;    // [double, 15.6] 매수호가 7                      StartPos 503, Length 15
    char    offerrem7           [  10];    char    _offerrem7           ;    // [long  ,   10] 매도호가 잔량 7                 StartPos 519, Length 10
    char    bidrem7             [  10];    char    _bidrem7             ;    // [long  ,   10] 매수호가 잔량 7                 StartPos 530, Length 10
    char    offerno7            [  10];    char    _offerno7            ;    // [long  ,   10] 매도호가 건수 7                 StartPos 541, Length 10
    char    bidno7              [  10];    char    _bidno7              ;    // [long  ,   10] 매수호가 건수 7                 StartPos 552, Length 10
    char    offerho8            [  15];    char    _offerho8            ;    // [double, 15.6] 매도호가 8                      StartPos 563, Length 15
    char    bidho8              [  15];    char    _bidho8              ;    // [double, 15.6] 매수호가 8                      StartPos 579, Length 15
    char    offerrem8           [  10];    char    _offerrem8           ;    // [long  ,   10] 매도호가 잔량 8                 StartPos 595, Length 10
    char    bidrem8             [  10];    char    _bidrem8             ;    // [long  ,   10] 매수호가 잔량 8                 StartPos 606, Length 10
    char    offerno8            [  10];    char    _offerno8            ;    // [long  ,   10] 매도호가 건수 8                 StartPos 617, Length 10
    char    bidno8              [  10];    char    _bidno8              ;    // [long  ,   10] 매수호가 건수 8                 StartPos 628, Length 10
    char    offerho9            [  15];    char    _offerho9            ;    // [double, 15.6] 매도호가 9                      StartPos 639, Length 15
    char    bidho9              [  15];    char    _bidho9              ;    // [double, 15.6] 매수호가 9                      StartPos 655, Length 15
    char    offerrem9           [  10];    char    _offerrem9           ;    // [long  ,   10] 매도호가 잔량 9                 StartPos 671, Length 10
    char    bidrem9             [  10];    char    _bidrem9             ;    // [long  ,   10] 매수호가 잔량 9                 StartPos 682, Length 10
    char    offerno9            [  10];    char    _offerno9            ;    // [long  ,   10] 매도호가 건수 9                 StartPos 693, Length 10
    char    bidno9              [  10];    char    _bidno9              ;    // [long  ,   10] 매수호가 건수 9                 StartPos 704, Length 10
    char    offerho10           [  15];    char    _offerho10           ;    // [double, 15.6] 매도호가 10                     StartPos 715, Length 15
    char    bidho10             [  15];    char    _bidho10             ;    // [double, 15.6] 매수호가 10                     StartPos 731, Length 15
    char    offerrem10          [  10];    char    _offerrem10          ;    // [long  ,   10] 매도호가 잔량 10                StartPos 747, Length 10
    char    bidrem10            [  10];    char    _bidrem10            ;    // [long  ,   10] 매수호가 잔량 10                StartPos 758, Length 10
    char    offerno10           [  10];    char    _offerno10           ;    // [long  ,   10] 매도호가 건수 10                StartPos 769, Length 10
    char    bidno10             [  10];    char    _bidno10             ;    // [long  ,   10] 매수호가 건수 10                StartPos 780, Length 10
    char    totoffercnt         [  10];    char    _totoffercnt         ;    // [long  ,   10] 매도호가총건수                  StartPos 791, Length 10
    char    totbidcnt           [  10];    char    _totbidcnt           ;    // [long  ,   10] 매수호가총건수                  StartPos 802, Length 10
    char    totofferrem         [  10];    char    _totofferrem         ;    // [long  ,   10] 매도호가총수량                  StartPos 813, Length 10
    char    totbidrem           [  10];    char    _totbidrem           ;    // [long  ,   10] 매수호가총수량                  StartPos 824, Length 10
} GSH_OutBlock, *LPGSH_OutBlock;
#define NAME_GSH_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _GSH_H_
