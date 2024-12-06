#ifndef _g3190_H_
#define _g3190_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽĸ�������ȸ(g3190) ( attr,block,svr=GTS,headtype=A )
#pragma pack( push, 1 )

#define NAME_g3190     "g3190"

// �⺻�Է�                       
typedef struct _g3190InBlock
{
    char    delaygb             [   1];    char    _delaygb             ;    // [string,    1] ��������                        StartPos 0, Length 1
    char    natcode             [   2];    char    _natcode             ;    // [string,    2] ��������                        StartPos 2, Length 2
    char    exgubun             [   1];    char    _exgubun             ;    // [string,    1] �ŷ��ұ���                      StartPos 5, Length 1
    char    readcnt             [   4];    char    _readcnt             ;    // [long  ,    4] ��ȸ����                        StartPos 7, Length 4
    char    cts_value           [  16];    char    _cts_value           ;    // [string,   16] ���ӱ���                        StartPos 12, Length 16
} g3190InBlock, *LPg3190InBlock;
#define NAME_g3190InBlock     "g3190InBlock"

// ���                           
typedef struct _g3190OutBlock
{
    char    delaygb             [   1];    char    _delaygb             ;    // [string,    1] ��������                        StartPos 0, Length 1
    char    natcode             [   2];    char    _natcode             ;    // [string,    2] ��������                        StartPos 2, Length 2
    char    exgubun             [   1];    char    _exgubun             ;    // [string,    1] �ŷ��ұ���                      StartPos 5, Length 1
    char    cts_value           [  16];    char    _cts_value           ;    // [string,   16] ���ӱ���                        StartPos 7, Length 16
    char    rec_count           [   7];    char    _rec_count           ;    // [long  ,    7] ���ڵ�ī��Ʈ                    StartPos 24, Length 7
} g3190OutBlock, *LPg3190OutBlock;
#define NAME_g3190OutBlock     "g3190OutBlock"

// ���1                          , occurs
typedef struct _g3190OutBlock1
{
    char    keysymbol           [  18];    char    _keysymbol           ;    // [string,   18] KEY�����ڵ�                     StartPos 0, Length 18
    char    natcode             [   2];    char    _natcode             ;    // [string,    2] �����ڵ�                        StartPos 19, Length 2
    char    exchcd              [   2];    char    _exchcd              ;    // [string,    2] �ŷ����ڵ�                      StartPos 22, Length 2
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] �����ڵ�                        StartPos 25, Length 16
    char    seccode             [  18];    char    _seccode             ;    // [string,   18] �ŷ��������ڵ�                  StartPos 42, Length 18
    char    korname             [  64];    char    _korname             ;    // [string,   64] �ѱ������                      StartPos 61, Length 64
    char    engname             [  64];    char    _engname             ;    // [string,   64] ���������                      StartPos 126, Length 64
    char    currency            [   4];    char    _currency            ;    // [string,    4] ��ȯ�ڵ�                        StartPos 191, Length 4
    char    isin                [  12];    char    _isin                ;    // [string,   12] ISIN                            StartPos 196, Length 12
    char    floatpoint          [   1];    char    _floatpoint          ;    // [string,    1] FLOATPOINT                      StartPos 209, Length 1
    char    indusury            [   4];    char    _indusury            ;    // [string,    4] �����ڵ�                        StartPos 211, Length 4
    char    share               [  16];    char    _share               ;    // [long  ,   16] �����ֽļ�                      StartPos 216, Length 16
    char    marketcap           [  16];    char    _marketcap           ;    // [long  ,   16] �ں���                          StartPos 233, Length 16
    char    par                 [  15];    char    _par                 ;    // [double, 15.6] �׸鰡                          StartPos 250, Length 15
    char    parcurr             [   4];    char    _parcurr             ;    // [string,    4] �׸鰡��ȯ�ڵ�                  StartPos 266, Length 4
    char    bidlotsize2         [   8];    char    _bidlotsize2         ;    // [string,    8] �ż��ֹ�����2                   StartPos 271, Length 8
    char    asklotsize2         [   8];    char    _asklotsize2         ;    // [string,    8] �ŵ��ֹ�����2                   StartPos 280, Length 8
    char    clos                [  15];    char    _clos                ;    // [double, 15.6] ���ذ�                          StartPos 289, Length 15
    char    listed_date         [   8];    char    _listed_date         ;    // [string,    8] ��������                        StartPos 305, Length 8
    char    expire_date         [   8];    char    _expire_date         ;    // [string,    8] ��������                        StartPos 314, Length 8
    char    suspend             [   1];    char    _suspend             ;    // [string,    1] �ŷ���������                    StartPos 323, Length 1
    char    bymd                [   8];    char    _bymd                ;    // [string,    8] ��������                        StartPos 325, Length 8
    char    sellonly            [   8];    char    _sellonly            ;    // [string,    8] SELLONLY����                    StartPos 334, Length 8
    char    stamp               [   1];    char    _stamp               ;    // [string,    1] ����������                      StartPos 343, Length 1
    char    ticktype            [   8];    char    _ticktype            ;    // [string,    8] TICKSIZETYPE                    StartPos 345, Length 8
    char    pcls                [  15];    char    _pcls                ;    // [double, 15.6] ��������                        StartPos 354, Length 15
    char    vcmf                [   1];    char    _vcmf                ;    // [string,    1] VCM�������                     StartPos 370, Length 1
    char    casf                [   1];    char    _casf                ;    // [string,    1] CAS�������                     StartPos 372, Length 1
    char    posf                [   1];    char    _posf                ;    // [string,    1] POS�������                     StartPos 374, Length 1
    char    point               [   1];    char    _point               ;    // [string,    1] �Ҽ����ŸŰ�������              StartPos 376, Length 1
} g3190OutBlock1, *LPg3190OutBlock1;
#define NAME_g3190OutBlock1     "g3190OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _g3190_H_
