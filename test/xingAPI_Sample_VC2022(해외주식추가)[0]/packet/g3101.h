#ifndef _g3101_H_
#define _g3101_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽ����簡(g3101) ( attr,block,svr=GTS,headtype=A )
#pragma pack( push, 1 )

#define NAME_g3101     "g3101"

// �⺻�Է�                       
typedef struct _g3101InBlock
{
    char    delaygb             [   1];    char    _delaygb             ;    // [string,    1] ��������                        StartPos 0, Length 1
    char    keysymbol           [  18];    char    _keysymbol           ;    // [string,   18] KEY�����ڵ�                     StartPos 2, Length 18
    char    exchcd              [   2];    char    _exchcd              ;    // [string,    2] �ŷ����ڵ�                      StartPos 21, Length 2
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] �����ڵ�                        StartPos 24, Length 16
} g3101InBlock, *LPg3101InBlock;
#define NAME_g3101InBlock     "g3101InBlock"

// ���                           
typedef struct _g3101OutBlock
{
    char    delaygb             [   1];    char    _delaygb             ;    // [string,    1] ��������                        StartPos 0, Length 1
    char    keysymbol           [  18];    char    _keysymbol           ;    // [string,   18] KEY�����ڵ�                     StartPos 2, Length 18
    char    exchcd              [   2];    char    _exchcd              ;    // [string,    2] �ŷ����ڵ�                      StartPos 21, Length 2
    char    exchange            [   4];    char    _exchange            ;    // [string,    4] �ŷ���ID                        StartPos 24, Length 4
    char    suspend             [   1];    char    _suspend             ;    // [string,    1] �ŷ�����                        StartPos 29, Length 1
    char    sellonly            [   1];    char    _sellonly            ;    // [string,    1] �Ÿű���                        StartPos 31, Length 1
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] �����ڵ�                        StartPos 33, Length 16
    char    korname             [  64];    char    _korname             ;    // [string,   64] �ѱ������                      StartPos 50, Length 64
    char    induname            [  40];    char    _induname            ;    // [string,   40] �����ѱ۸�                      StartPos 115, Length 40
    char    floatpoint          [   1];    char    _floatpoint          ;    // [string,    1] �Ҽ����ڸ���                    StartPos 156, Length 1
    char    currency            [   4];    char    _currency            ;    // [string,    4] ��ȯ�ڵ�                        StartPos 158, Length 4
    char    price               [  15];    char    _price               ;    // [double, 15.6] ���簡                          StartPos 163, Length 15
    char    sign                [   1];    char    _sign                ;    // [string,    1] ���ϴ�񱸺�                    StartPos 179, Length 1
    char    diff                [  15];    char    _diff                ;    // [double, 15.6] ���ϴ��                        StartPos 181, Length 15
    char    rate                [   6];    char    _rate                ;    // [float ,  6.2] �����                          StartPos 197, Length 6
    char    volume              [  16];    char    _volume              ;    // [long  ,   16] �ŷ���                          StartPos 204, Length 16
    char    amount              [  15];    char    _amount              ;    // [long  ,   15] �ŷ����                        StartPos 221, Length 15
    char    high52p             [  15];    char    _high52p             ;    // [double, 15.6] 52���ְ�                      StartPos 237, Length 15
    char    low52p              [  15];    char    _low52p              ;    // [double, 15.6] 52��������                      StartPos 253, Length 15
    char    uplimit             [  15];    char    _uplimit             ;    // [double, 15.6] ���Ѱ�                          StartPos 269, Length 15
    char    dnlimit             [  15];    char    _dnlimit             ;    // [double, 15.6] ���Ѱ�                          StartPos 285, Length 15
    char    open                [  15];    char    _open                ;    // [double, 15.6] �ð�                            StartPos 301, Length 15
    char    high                [  15];    char    _high                ;    // [double, 15.6] ��                            StartPos 317, Length 15
    char    low                 [  15];    char    _low                 ;    // [double, 15.6] ����                            StartPos 333, Length 15
    char    perv                [   9];    char    _perv                ;    // [double,  9.2] PER                             StartPos 349, Length 9
    char    epsv                [   9];    char    _epsv                ;    // [double,  9.2] EPS                             StartPos 359, Length 9
} g3101OutBlock, *LPg3101OutBlock;
#define NAME_g3101OutBlock     "g3101OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _g3101_H_
