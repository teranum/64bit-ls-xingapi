#ifndef _GSC_H_
#define _GSC_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽ� ü��(GSC) ( attr,svr=OVS,key=18,group=1 )
#pragma pack( push, 1 )

#define NAME_GSC     "GSC"

// �Է�                           
typedef struct _GSC_InBlock
{
    char    keysymbol           [  18];                                 ;    // [string,   18] �����ڵ�                        StartPos 0, Length 18
} GSC_InBlock, *LPGSC_InBlock;
#define NAME_GSC_InBlock     "InBlock"

// ���                           
typedef struct _GSC_OutBlock
{
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] �����ڵ�                        StartPos 0, Length 16
    char    ovsdate             [   8];    char    _ovsdate             ;    // [string,    8] ü������(����)                  StartPos 17, Length 8
    char    kordate             [   8];    char    _kordate             ;    // [string,    8] ü������(�ѱ�)                  StartPos 26, Length 8
    char    trdtm               [   6];    char    _trdtm               ;    // [string,    6] ü��ð�(����)                  StartPos 35, Length 6
    char    kortm               [   6];    char    _kortm               ;    // [string,    6] ü��ð�(�ѱ�)                  StartPos 42, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] ���ϴ�񱸺�                    StartPos 49, Length 1
    char    price               [  15];    char    _price               ;    // [double, 15.6] ü�ᰡ��                        StartPos 51, Length 15
    char    diff                [  15];    char    _diff                ;    // [double, 15.6] ���ϴ��                        StartPos 67, Length 15
    char    rate                [   6];    char    _rate                ;    // [float ,  6.2] �����                          StartPos 83, Length 6
    char    open                [  15];    char    _open                ;    // [double, 15.6] �ð�                            StartPos 90, Length 15
    char    high                [  15];    char    _high                ;    // [double, 15.6] ��                            StartPos 106, Length 15
    char    low                 [  15];    char    _low                 ;    // [double, 15.6] ����                            StartPos 122, Length 15
    char    trdq                [  10];    char    _trdq                ;    // [long  ,   10] �Ǻ�ü�����                    StartPos 138, Length 10
    char    totq                [  15];    char    _totq                ;    // [string,   15] ����ü�����                    StartPos 149, Length 15
    char    cgubun              [   1];    char    _cgubun              ;    // [string,    1] ü�ᱸ��                        StartPos 165, Length 1
    char    lSeq                [   3];    char    _lSeq                ;    // [string,    3] �ʴ������                      StartPos 167, Length 3
    char    amount              [  16];    char    _amount              ;    // [string,   16] �����ŷ����                    StartPos 171, Length 16
    char    high52p             [  15];    char    _high52p             ;    // [double, 15.6] 52�ְ�                        StartPos 188, Length 15
    char    low52p              [  15];    char    _low52p              ;    // [double, 15.6] 52������                        StartPos 204, Length 15
} GSC_OutBlock, *LPGSC_OutBlock;
#define NAME_GSC_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _GSC_H_
