#ifndef _g3202_H_
#define _g3202_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽ���ƮNTICK ( attr,block,svr=GTS,headtype=A )
#pragma pack( push, 1 )

#define NAME_g3202     "g3202"

// �⺻�Է�                       
typedef struct _g3202InBlock
{
    char    delaygb             [   1];    char    _delaygb             ;    // [string,    1] ��������                        StartPos 0, Length 1
    char    keysymbol           [  18];    char    _keysymbol           ;    // [string,   18] KEY�����ڵ�                     StartPos 2, Length 18
    char    exchcd              [   2];    char    _exchcd              ;    // [string,    2] �ŷ����ڵ�                      StartPos 21, Length 2
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] �����ڵ�                        StartPos 24, Length 16
    char    ncnt                [   4];    char    _ncnt                ;    // [long  ,    4] ����(nƽ)                       StartPos 41, Length 4
    char    qrycnt              [   4];    char    _qrycnt              ;    // [long  ,    4] ��û�Ǽ�(�ִ�-����:2000�����:5 StartPos 46, Length 4
    char    comp_yn             [   1];    char    _comp_yn             ;    // [string,    1] ���࿩��(Y:����N:�����)        StartPos 51, Length 1
    char    sdate               [   8];    char    _sdate               ;    // [string,    8] ��������                        StartPos 53, Length 8
    char    edate               [   8];    char    _edate               ;    // [string,    8] ��������                        StartPos 62, Length 8
    char    cts_seq             [  17];    char    _cts_seq             ;    // [long  ,   17] ���ӽ�����                      StartPos 71, Length 17
} g3202InBlock, *LPg3202InBlock;
#define NAME_g3202InBlock     "g3202InBlock"

// ���                           
typedef struct _g3202OutBlock
{
    char    delaygb             [   1];    char    _delaygb             ;    // [string,    1] ��������                        StartPos 0, Length 1
    char    keysymbol           [  18];    char    _keysymbol           ;    // [string,   18] KEY�����ڵ�                     StartPos 2, Length 18
    char    exchcd              [   2];    char    _exchcd              ;    // [string,    2] �ŷ����ڵ�                      StartPos 21, Length 2
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] �����ڵ�                        StartPos 24, Length 16
    char    cts_seq             [  17];    char    _cts_seq             ;    // [long  ,   17] ���ӽ�����                      StartPos 41, Length 17
    char    rec_count           [   7];    char    _rec_count           ;    // [long  ,    7] ���ڵ�ī��Ʈ                    StartPos 59, Length 7
    char    preopen             [  15];    char    _preopen             ;    // [double, 15.8] ���Ͻð�                        StartPos 67, Length 15
    char    prehigh             [  15];    char    _prehigh             ;    // [double, 15.8] ���ϰ�                        StartPos 83, Length 15
    char    prelow              [  15];    char    _prelow              ;    // [double, 15.8] ��������                        StartPos 99, Length 15
    char    preclose            [  15];    char    _preclose            ;    // [double, 15.8] ��������                        StartPos 115, Length 15
    char    prevolume           [  16];    char    _prevolume           ;    // [long  ,   16] ���ϰŷ���                      StartPos 131, Length 16
    char    open                [  15];    char    _open                ;    // [double, 15.8] ���Ͻð�                        StartPos 148, Length 15
    char    high                [  15];    char    _high                ;    // [double, 15.8] ���ϰ�                        StartPos 164, Length 15
    char    low                 [  15];    char    _low                 ;    // [double, 15.8] ��������                        StartPos 180, Length 15
    char    close               [  15];    char    _close               ;    // [double, 15.8] ��������                        StartPos 196, Length 15
    char    s_time              [   6];    char    _s_time              ;    // [string,    6] ����۽ð�(HHMMSS)              StartPos 212, Length 6
    char    e_time              [   6];    char    _e_time              ;    // [string,    6] ������ð�(HHMMSS)              StartPos 219, Length 6
    char    last_count          [   4];    char    _last_count          ;    // [string,    4] ������Tick�Ǽ�                  StartPos 226, Length 4
    char    timediff            [   4];    char    _timediff            ;    // [string,    4] ����                            StartPos 231, Length 4
} g3202OutBlock, *LPg3202OutBlock;
#define NAME_g3202OutBlock     "g3202OutBlock"

// ���1                          , occurs
typedef struct _g3202OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] ��¥                            StartPos 0, Length 8
    char    loctime             [   6];    char    _loctime             ;    // [string,    6] �����ð�                        StartPos 9, Length 6
    char    open                [  15];    char    _open                ;    // [double, 15.8] �ð�                            StartPos 16, Length 15
    char    high                [  15];    char    _high                ;    // [double, 15.8] ��                            StartPos 32, Length 15
    char    low                 [  15];    char    _low                 ;    // [double, 15.8] ����                            StartPos 48, Length 15
    char    close               [  15];    char    _close               ;    // [double, 15.8] ����                            StartPos 64, Length 15
    char    exevol              [  16];    char    _exevol              ;    // [long  ,   16] ü�ᷮ                          StartPos 80, Length 16
    char    jongchk             [  13];    char    _jongchk             ;    // [long  ,   13] ��������                        StartPos 97, Length 13
    char    prtt_rate           [   6];    char    _prtt_rate           ;    // [double,  6.2] ��������                        StartPos 111, Length 6
    char    pricechk            [  13];    char    _pricechk            ;    // [long  ,   13] �����ְ��ݿ��׸�                StartPos 118, Length 13
    char    sign                [   1];    char    _sign                ;    // [string,    1] �����������(1:����2:���3:���� StartPos 132, Length 1
} g3202OutBlock1, *LPg3202OutBlock1;
#define NAME_g3202OutBlock1     "g3202OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _g3202_H_
