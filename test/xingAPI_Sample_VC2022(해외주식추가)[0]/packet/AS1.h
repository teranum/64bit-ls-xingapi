#ifndef _AS1_H_
#define _AS1_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외주식주문체결(미국) ( key=8,group=1 )
#pragma pack( push, 1 )

#define NAME_AS1     "AS1"

// 입력                           
typedef struct _AS1_InBlock
{
} AS1_InBlock, *LPAS1_InBlock;
#define NAME_AS1_InBlock     "InBlock"

// 출력                           
typedef struct _AS1_OutBlock
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
    char    sMgmtBrnNo          [   3];    // [string,    3] 관리지점번호                    StartPos 247, Length 3
    char    sAcntNo             [  20];    // [string,   20] 계좌번호                        StartPos 250, Length 20
    char    sAcntNm             [  40];    // [string,   40] 계좌명                          StartPos 270, Length 40
    char    sIsuNo              [  12];    // [string,   12] 종목번호                        StartPos 310, Length 12
    char    sIsuNm              [  40];    // [string,   40] 종목명                          StartPos 322, Length 40
    char    sOrdNo              [  10];    // [long  ,   10] 주문번호                        StartPos 362, Length 10
    char    sOrgOrdNo           [  10];    // [long  ,   10] 원주문번호                      StartPos 372, Length 10
    char    sExecNO             [  10];    // [long  ,   10] 체결번호                        StartPos 382, Length 10
    char    sAbrdExecId         [  18];    // [long  ,   18] 해외체결ID                      StartPos 392, Length 18
    char    sOrdQty             [  16];    // [long  ,   16] 주문수량                        StartPos 410, Length 16
    char    sOrdPrc             [  13];    // [long  ,   13] 주문가                          StartPos 426, Length 13
    char    sExecQty            [  16];    // [long  ,   16] 체결수량                        StartPos 439, Length 16
    char    sExecPrc            [  13];    // [long  ,   13] 체결가                          StartPos 455, Length 13
    char    sMdfyCnfQty         [  16];    // [long  ,   16] 정정확인수량                    StartPos 468, Length 16
    char    sMdfyCnfPrc         [  16];    // [long  ,   16] 정정확인가                      StartPos 484, Length 16
    char    sCancCnfQty         [  16];    // [long  ,   16] 취소확인수량                    StartPos 500, Length 16
    char    sRjtQty             [  16];    // [long  ,   16] 거부수량                        StartPos 516, Length 16
    char    sOrdTrxPtnCode      [   4];    // [long  ,    4] 주문처리유형코드                StartPos 532, Length 4
    char    sMtiordSeqno        [  10];    // [long  ,   10] 복수주문일련번호                StartPos 536, Length 10
    char    sOrdCndi            [   1];    // [string,    1] 주문조건                        StartPos 546, Length 1
    char    sOrdprcPtnCode      [   2];    // [string,    2] 호가유형코드                    StartPos 547, Length 2
    char    sShtnIsuNo          [   9];    // [long  ,    9] 단축종목번호                    StartPos 549, Length 9
    char    sOpDrtnNo           [  12];    // [string,   12] 운용지시번호                    StartPos 558, Length 12
    char    sUnercQty           [  16];    // [string,   16] 미체결수량(주문)                StartPos 570, Length 16
    char    sOrgOrdUnercQty     [  16];    // [string,   16] 원주문미체결수량                StartPos 586, Length 16
    char    sOrgOrdMdfyQty      [  16];    // [long  ,   16] 원주문정정수량                  StartPos 602, Length 16
    char    sOrgOrdCancQty      [  16];    // [long  ,   16] 원주문취소수량                  StartPos 618, Length 16
    char    sOrdAvrExecPrc      [  13];    // [long  ,   13] 주문평균체결가                  StartPos 634, Length 13
    char    sOrdAmt             [  16];    // [long  ,   16] 주문금액                        StartPos 647, Length 16
    char    sStdIsuNo           [  12];    // [long  ,   12] 표준종목번호                    StartPos 663, Length 12
    char    sBnsTp              [   1];    // [long  ,    1] 매매구분                        StartPos 675, Length 1
    char    sCommdaCode         [   2];    // [string,    2] 통신매체코드                    StartPos 676, Length 2
    char    sOrdAcntNo          [  20];    // [string,   20] 주문계좌번호                    StartPos 678, Length 20
    char    sAgrgtBrnNo         [   3];    // [string,    3] 집계지점번호                    StartPos 698, Length 3
    char    sRegMktCode         [   2];    // [string,    2] 등록시장코드                    StartPos 701, Length 2
    char    sMnyMgnRat          [   7];    // [string,    7] 현금증거금률                    StartPos 703, Length 7
    char    sSubstMgnRat        [   9];    // [string,    9] 대용증거금률                    StartPos 710, Length 9
    char    sMnyExecAmt         [  16];    // [string,   16] 현금체결금액                    StartPos 719, Length 16
    char    sSubstExecAmt       [  16];    // [string,   16] 대용체결금액                    StartPos 735, Length 16
    char    sCmsnAmtExecAmt     [  16];    // [long  ,   16] 수수료체결금액                  StartPos 751, Length 16
    char    sPrdayRuseExecVal   [  16];    // [string,   16] 전일재사용체결금액              StartPos 767, Length 16
    char    sCrdayRuseExecVal   [  16];    // [string,   16] 금일재사용체결금액              StartPos 783, Length 16
    char    sSpotExecQty        [  16];    // [string,   16] 실물체결수량                    StartPos 799, Length 16
    char    sStslExecQty        [  16];    // [string,   16] 공매도체결수량                  StartPos 815, Length 16
    char    sStrtgCode          [   6];    // [string,    6] 전략코드                        StartPos 831, Length 6
    char    sGrpId              [  20];    // [string,   20] 그룹ID                          StartPos 837, Length 20
    char    sOrdSeqno           [  10];    // [string,   10] 주문회차                        StartPos 857, Length 10
    char    sOrdUserId          [  16];    // [long  ,   16] 주문자ID                        StartPos 867, Length 16
    char    sExecTime           [   9];    // [long  ,    9] 체결시각                        StartPos 883, Length 9
    char    sRcptExecTime       [   9];    // [long  ,    9] 거래소수신체결시각              StartPos 892, Length 9
    char    sRjtRsn             [   8];    // [long  ,    8] 거부사유                        StartPos 901, Length 8
    char    sSecBalQty          [  16];    // [long  ,   16] 잔고수량                        StartPos 909, Length 16
    char    sSpotOrdAbleQty     [  16];    // [long  ,   16] 실물주문가능수량                StartPos 925, Length 16
    char    sOrdAbleRuseQty     [  16];    // [long  ,   16] 주문가능재사용수량              StartPos 941, Length 16
    char    sFlctQty            [  16];    // [long  ,   16] 변동수량                        StartPos 957, Length 16
    char    sSecBalQtyD2        [  16];    // [long  ,   16] 잔고수량(D2)                    StartPos 973, Length 16
    char    sSellAbleQty        [  16];    // [long  ,   16] 매도주문가능수량                StartPos 989, Length 16
    char    sUnercSellOrdQty    [  16];    // [long  ,   16] 미체결매도주문수량              StartPos 1005, Length 16
    char    sAvrPchsPrc         [  13];    // [long  ,   13] 평균매입가                      StartPos 1021, Length 13
    char    sPchsAmt            [  16];    // [string,   16] 매입금액                        StartPos 1034, Length 16
    char    sDeposit            [  16];    // [string,   16] 예수금                          StartPos 1050, Length 16
    char    sSubstAmt           [  16];    // [long  ,   16] 대용금                          StartPos 1066, Length 16
    char    sCsgnMnyMgn         [  16];    // [long  ,   16] 위탁현금증거금액                StartPos 1082, Length 16
    char    sCsgnSubstMgn       [  16];    // [long  ,   16] 위탁대용증거금액                StartPos 1098, Length 16
    char    sOrdAbleMny         [  16];    // [long  ,   16] 주문가능현금                    StartPos 1114, Length 16
    char    sOrdAbleSubstAmt    [  16];    // [long  ,   16] 주문가능대용금액                StartPos 1130, Length 16
    char    sRuseAbleAmt        [  16];    // [string,   16] 재사용가능금액                  StartPos 1146, Length 16
    char    sMgntrnCode         [   3];    // [string,    3] 신용거래코드                    StartPos 1162, Length 3
} AS1_OutBlock, *LPAS1_OutBlock;
#define NAME_AS1_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _AS1_H_
