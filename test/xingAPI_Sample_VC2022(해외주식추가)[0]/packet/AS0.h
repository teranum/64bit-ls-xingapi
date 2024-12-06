#ifndef _AS0_H_
#define _AS0_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외주식주문접수(미국) ( key=8,group=1 )
#pragma pack( push, 1 )

#define NAME_AS0     "AS0"

// 입력                           
typedef struct _AS0_InBlock
{
} AS0_InBlock, *LPAS0_InBlock;
#define NAME_AS0_InBlock     "InBlock"

// 출력                           
typedef struct _AS0_OutBlock
{
    char    lineseq             [  10];    // [long  ,   10] 라인일련번호                    StartPos 0, Length 10
    char    accno               [  11];    // [string,   11] 계좌번호                        StartPos 10, Length 11
    char    user                [   8];    // [string,    8] 조작자ID                        StartPos 21, Length 8
    char    len                 [   6];    // [long  ,    6] 헤더길이                        StartPos 29, Length 6
    char    gubun               [   1];    // [string,    1] 헤더구분                        StartPos 35, Length 1
    char    compress            [   1];    // [string,    1] 압축구분                        StartPos 36, Length 1
    char    encrypt             [   1];    // [string,    1] 암호구분                        StartPos 37, Length 1
    char    offset              [   3];    // [long  ,    3] 공통시작지점                    StartPos 38, Length 3
    char    trcode              [   8];    // [string,    8] TRCODE                          StartPos 41, Length 8
    char    comid               [   3];    // [string,    3] 이용사번호                      StartPos 49, Length 3
    char    userid              [  16];    // [string,   16] 사용자ID                        StartPos 52, Length 16
    char    media               [   2];    // [string,    2] 접속매체                        StartPos 68, Length 2
    char    ifid                [   3];    // [string,    3] I/F일련번호                     StartPos 70, Length 3
    char    seq                 [   9];    // [string,    9] 전문일련번호                    StartPos 73, Length 9
    char    trid                [  16];    // [string,   16] TR추적ID                        StartPos 82, Length 16
    char    pubip               [  12];    // [string,   12] 공인IP                          StartPos 98, Length 12
    char    prvip               [  12];    // [string,   12] 사설IP                          StartPos 110, Length 12
    char    pcbpno              [   3];    // [string,    3] 처리지점번호                    StartPos 122, Length 3
    char    bpno                [   3];    // [string,    3] 지점번호                        StartPos 125, Length 3
    char    termno              [   8];    // [string,    8] 단말번호                        StartPos 128, Length 8
    char    lang                [   1];    // [string,    1] 언어구분                        StartPos 136, Length 1
    char    proctm              [   9];    // [long  ,    9] AP처리시간                      StartPos 137, Length 9
    char    msgcode             [   4];    // [string,    4] 메세지코드                      StartPos 146, Length 4
    char    outgu               [   1];    // [string,    1] 메세지출력구분                  StartPos 150, Length 1
    char    compreq             [   1];    // [string,    1] 압축요청구분                    StartPos 151, Length 1
    char    funckey             [   4];    // [string,    4] 기능키                          StartPos 152, Length 4
    char    reqcnt              [   4];    // [long  ,    4] 요청레코드개수                  StartPos 156, Length 4
    char    filler              [   6];    // [string,    6] 예비영역                        StartPos 160, Length 6
    char    cont                [   1];    // [string,    1] 연속구분                        StartPos 166, Length 1
    char    contkey             [  18];    // [string,   18] 연속키값                        StartPos 167, Length 18
    char    varlen              [   2];    // [long  ,    2] 가변시스템길이                  StartPos 185, Length 2
    char    varhdlen            [   2];    // [long  ,    2] 가변해더길이                    StartPos 187, Length 2
    char    varmsglen           [   2];    // [long  ,    2] 가변메시지길이                  StartPos 189, Length 2
    char    trsrc               [   1];    // [string,    1] 조회발원지                      StartPos 191, Length 1
    char    eventid             [   4];    // [string,    4] I/F이벤트ID                     StartPos 192, Length 4
    char    ifinfo              [   4];    // [string,    4] I/F정보                         StartPos 196, Length 4
    char    filler1             [  41];    // [string,   41] 예비영역                        StartPos 200, Length 41
    char    sOrdxctPtnCode      [   2];    // [string,    2] 주문체결유형코드                StartPos 241, Length 2
    char    sOrdMktCode         [   2];    // [string,    2] 주문시장코드                    StartPos 243, Length 2
    char    sOrdPtnCode         [   2];    // [string,    2] 주문유형코드                    StartPos 245, Length 2
    char    sOrgOrdNo           [  10];    // [long  ,   10] 원주문번호                      StartPos 247, Length 10
    char    sAcntNo             [  20];    // [string,   20] 계좌번호                        StartPos 257, Length 20
    char    sPwd                [   8];    // [string,    8] 비밀번호                        StartPos 277, Length 8
    char    sIsuNo              [  12];    // [string,   12] 종목번호                        StartPos 285, Length 12
    char    sShtnIsuNo          [   9];    // [string,    9] 단축종목번호                    StartPos 297, Length 9
    char    sIsuNm              [  40];    // [string,   40] 종목명                          StartPos 306, Length 40
    char    sOrdQty             [  16];    // [double,   16] 주문수량                        StartPos 346, Length 16
    char    sOrdPrc             [  13];    // [double,   13] 주문가                          StartPos 362, Length 13
    char    sOrdCndi            [   1];    // [string,    1] 주문조건                        StartPos 375, Length 1
    char    sOrdprcPtnCode      [   2];    // [string,    2] 호가유형코드                    StartPos 376, Length 2
    char    sStrtgCode          [   6];    // [long  ,    6] 전략코드                        StartPos 378, Length 6
    char    sGrpId              [  20];    // [string,   20] 그룹ID                          StartPos 384, Length 20
    char    sOrdSeqno           [  10];    // [string,   10] 주문회차                        StartPos 404, Length 10
    char    sCommdaCode         [   2];    // [string,    2] 통신매체코드                    StartPos 414, Length 2
    char    sOrdNo              [  10];    // [string,   10] 주문번호                        StartPos 416, Length 10
    char    sOrdTime            [   9];    // [string,    9] 주문시각                        StartPos 426, Length 9
    char    sPrntOrdNo          [  10];    // [string,   10] 모주문번호                      StartPos 435, Length 10
    char    sOrgOrdUnercQty     [  16];    // [string,   16] 원주문미체결수량                StartPos 445, Length 16
    char    sOrgOrdMdfyQty      [  16];    // [double,   16] 원주문정정수량                  StartPos 461, Length 16
    char    sOrgOrdCancQty      [  16];    // [double,   16] 원주문취소수량                  StartPos 477, Length 16
    char    sNmcpySndNo         [  10];    // [double,   10] 비회원사송신번호                StartPos 493, Length 10
    char    sOrdAmt             [  16];    // [double,   16] 주문금액                        StartPos 503, Length 16
    char    sBnsTp              [   1];    // [long  ,    1] 매매구분                        StartPos 519, Length 1
    char    sMtiordSeqno        [  10];    // [long  ,   10] 복수주문일련번호                StartPos 520, Length 10
    char    sOrdUserId          [  16];    // [double,   16] 주문사원번호                    StartPos 530, Length 16
    char    sSpotOrdQty         [  16];    // [double,   16] 실물주문수량                    StartPos 546, Length 16
    char    sRuseOrdQty         [  16];    // [double,   16] 재사용주문수량                  StartPos 562, Length 16
    char    sOrdMny             [  16];    // [double,   16] 주문현금                        StartPos 578, Length 16
    char    sOrdSubstAmt        [  16];    // [double,   16] 주문대용금액                    StartPos 594, Length 16
    char    sOrdRuseAmt         [  16];    // [double,   16] 주문재사용금액                  StartPos 610, Length 16
    char    sUseCmsnAmt         [  16];    // [double,   16] 사용수수료                      StartPos 626, Length 16
    char    sSecBalQty          [  16];    // [double,   16] 잔고수량                        StartPos 642, Length 16
    char    sSpotOrdAbleQty     [  16];    // [double,   16] 실물주문가능수량                StartPos 658, Length 16
    char    sOrdAbleRuseQty     [  16];    // [double,   16] 주문가능재사용수량              StartPos 674, Length 16
    char    sFlctQty            [  16];    // [double,   16] 변동수량                        StartPos 690, Length 16
    char    sSecBalQtyD2        [  16];    // [double,   16] 잔고수량(D2)                    StartPos 706, Length 16
    char    sSellAbleQty        [  16];    // [double,   16] 매도주문가능수량                StartPos 722, Length 16
    char    sUnercSellOrdQty    [  16];    // [double,   16] 미체결매도주문수량              StartPos 738, Length 16
    char    sAvrPchsPrc         [  13];    // [double,   13] 평균매입가                      StartPos 754, Length 13
    char    sPchsAmt            [  16];    // [double,   16] 매입금액                        StartPos 767, Length 16
    char    sDeposit            [  16];    // [double,   16] 예수금                          StartPos 783, Length 16
    char    sSubstAmt           [  16];    // [double,   16] 대용금                          StartPos 799, Length 16
    char    sCsgnMnyMgn         [  16];    // [double,   16] 위탁현금증거금액                StartPos 815, Length 16
    char    sCsgnSubstMgn       [  16];    // [double,   16] 위탁대용증거금액                StartPos 831, Length 16
    char    sOrdAbleMny         [  16];    // [double,   16] 주문가능현금                    StartPos 847, Length 16
    char    sOrdAbleSubstAmt    [  16];    // [double,   16] 주문가능대용금액                StartPos 863, Length 16
    char    sRuseAbleAmt        [  16];    // [double,   16] 재사용가능금액                  StartPos 879, Length 16
    char    sMgntrnCode         [   3];    // [string,    3] 신용거래코드                    StartPos 895, Length 3
} AS0_OutBlock, *LPAS0_OutBlock;
#define NAME_AS0_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _AS0_H_
