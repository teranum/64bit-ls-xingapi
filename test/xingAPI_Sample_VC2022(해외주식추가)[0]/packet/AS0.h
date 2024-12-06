#ifndef _AS0_H_
#define _AS0_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽ��ֹ�����(�̱�) ( key=8,group=1 )
#pragma pack( push, 1 )

#define NAME_AS0     "AS0"

// �Է�                           
typedef struct _AS0_InBlock
{
} AS0_InBlock, *LPAS0_InBlock;
#define NAME_AS0_InBlock     "InBlock"

// ���                           
typedef struct _AS0_OutBlock
{
    char    lineseq             [  10];    // [long  ,   10] �����Ϸù�ȣ                    StartPos 0, Length 10
    char    accno               [  11];    // [string,   11] ���¹�ȣ                        StartPos 10, Length 11
    char    user                [   8];    // [string,    8] ������ID                        StartPos 21, Length 8
    char    len                 [   6];    // [long  ,    6] �������                        StartPos 29, Length 6
    char    gubun               [   1];    // [string,    1] �������                        StartPos 35, Length 1
    char    compress            [   1];    // [string,    1] ���౸��                        StartPos 36, Length 1
    char    encrypt             [   1];    // [string,    1] ��ȣ����                        StartPos 37, Length 1
    char    offset              [   3];    // [long  ,    3] �����������                    StartPos 38, Length 3
    char    trcode              [   8];    // [string,    8] TRCODE                          StartPos 41, Length 8
    char    comid               [   3];    // [string,    3] �̿���ȣ                      StartPos 49, Length 3
    char    userid              [  16];    // [string,   16] �����ID                        StartPos 52, Length 16
    char    media               [   2];    // [string,    2] ���Ӹ�ü                        StartPos 68, Length 2
    char    ifid                [   3];    // [string,    3] I/F�Ϸù�ȣ                     StartPos 70, Length 3
    char    seq                 [   9];    // [string,    9] �����Ϸù�ȣ                    StartPos 73, Length 9
    char    trid                [  16];    // [string,   16] TR����ID                        StartPos 82, Length 16
    char    pubip               [  12];    // [string,   12] ����IP                          StartPos 98, Length 12
    char    prvip               [  12];    // [string,   12] �缳IP                          StartPos 110, Length 12
    char    pcbpno              [   3];    // [string,    3] ó��������ȣ                    StartPos 122, Length 3
    char    bpno                [   3];    // [string,    3] ������ȣ                        StartPos 125, Length 3
    char    termno              [   8];    // [string,    8] �ܸ���ȣ                        StartPos 128, Length 8
    char    lang                [   1];    // [string,    1] ����                        StartPos 136, Length 1
    char    proctm              [   9];    // [long  ,    9] APó���ð�                      StartPos 137, Length 9
    char    msgcode             [   4];    // [string,    4] �޼����ڵ�                      StartPos 146, Length 4
    char    outgu               [   1];    // [string,    1] �޼�����±���                  StartPos 150, Length 1
    char    compreq             [   1];    // [string,    1] �����û����                    StartPos 151, Length 1
    char    funckey             [   4];    // [string,    4] ���Ű                          StartPos 152, Length 4
    char    reqcnt              [   4];    // [long  ,    4] ��û���ڵ尳��                  StartPos 156, Length 4
    char    filler              [   6];    // [string,    6] ���񿵿�                        StartPos 160, Length 6
    char    cont                [   1];    // [string,    1] ���ӱ���                        StartPos 166, Length 1
    char    contkey             [  18];    // [string,   18] ����Ű��                        StartPos 167, Length 18
    char    varlen              [   2];    // [long  ,    2] �����ý��۱���                  StartPos 185, Length 2
    char    varhdlen            [   2];    // [long  ,    2] �����ش�����                    StartPos 187, Length 2
    char    varmsglen           [   2];    // [long  ,    2] �����޽�������                  StartPos 189, Length 2
    char    trsrc               [   1];    // [string,    1] ��ȸ�߿���                      StartPos 191, Length 1
    char    eventid             [   4];    // [string,    4] I/F�̺�ƮID                     StartPos 192, Length 4
    char    ifinfo              [   4];    // [string,    4] I/F����                         StartPos 196, Length 4
    char    filler1             [  41];    // [string,   41] ���񿵿�                        StartPos 200, Length 41
    char    sOrdxctPtnCode      [   2];    // [string,    2] �ֹ�ü�������ڵ�                StartPos 241, Length 2
    char    sOrdMktCode         [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 243, Length 2
    char    sOrdPtnCode         [   2];    // [string,    2] �ֹ������ڵ�                    StartPos 245, Length 2
    char    sOrgOrdNo           [  10];    // [long  ,   10] ���ֹ���ȣ                      StartPos 247, Length 10
    char    sAcntNo             [  20];    // [string,   20] ���¹�ȣ                        StartPos 257, Length 20
    char    sPwd                [   8];    // [string,    8] ��й�ȣ                        StartPos 277, Length 8
    char    sIsuNo              [  12];    // [string,   12] �����ȣ                        StartPos 285, Length 12
    char    sShtnIsuNo          [   9];    // [string,    9] ���������ȣ                    StartPos 297, Length 9
    char    sIsuNm              [  40];    // [string,   40] �����                          StartPos 306, Length 40
    char    sOrdQty             [  16];    // [double,   16] �ֹ�����                        StartPos 346, Length 16
    char    sOrdPrc             [  13];    // [double,   13] �ֹ���                          StartPos 362, Length 13
    char    sOrdCndi            [   1];    // [string,    1] �ֹ�����                        StartPos 375, Length 1
    char    sOrdprcPtnCode      [   2];    // [string,    2] ȣ�������ڵ�                    StartPos 376, Length 2
    char    sStrtgCode          [   6];    // [long  ,    6] �����ڵ�                        StartPos 378, Length 6
    char    sGrpId              [  20];    // [string,   20] �׷�ID                          StartPos 384, Length 20
    char    sOrdSeqno           [  10];    // [string,   10] �ֹ�ȸ��                        StartPos 404, Length 10
    char    sCommdaCode         [   2];    // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 414, Length 2
    char    sOrdNo              [  10];    // [string,   10] �ֹ���ȣ                        StartPos 416, Length 10
    char    sOrdTime            [   9];    // [string,    9] �ֹ��ð�                        StartPos 426, Length 9
    char    sPrntOrdNo          [  10];    // [string,   10] ���ֹ���ȣ                      StartPos 435, Length 10
    char    sOrgOrdUnercQty     [  16];    // [string,   16] ���ֹ���ü�����                StartPos 445, Length 16
    char    sOrgOrdMdfyQty      [  16];    // [double,   16] ���ֹ���������                  StartPos 461, Length 16
    char    sOrgOrdCancQty      [  16];    // [double,   16] ���ֹ���Ҽ���                  StartPos 477, Length 16
    char    sNmcpySndNo         [  10];    // [double,   10] ��ȸ����۽Ź�ȣ                StartPos 493, Length 10
    char    sOrdAmt             [  16];    // [double,   16] �ֹ��ݾ�                        StartPos 503, Length 16
    char    sBnsTp              [   1];    // [long  ,    1] �Ÿű���                        StartPos 519, Length 1
    char    sMtiordSeqno        [  10];    // [long  ,   10] �����ֹ��Ϸù�ȣ                StartPos 520, Length 10
    char    sOrdUserId          [  16];    // [double,   16] �ֹ������ȣ                    StartPos 530, Length 16
    char    sSpotOrdQty         [  16];    // [double,   16] �ǹ��ֹ�����                    StartPos 546, Length 16
    char    sRuseOrdQty         [  16];    // [double,   16] �����ֹ�����                  StartPos 562, Length 16
    char    sOrdMny             [  16];    // [double,   16] �ֹ�����                        StartPos 578, Length 16
    char    sOrdSubstAmt        [  16];    // [double,   16] �ֹ����ݾ�                    StartPos 594, Length 16
    char    sOrdRuseAmt         [  16];    // [double,   16] �ֹ�����ݾ�                  StartPos 610, Length 16
    char    sUseCmsnAmt         [  16];    // [double,   16] ��������                      StartPos 626, Length 16
    char    sSecBalQty          [  16];    // [double,   16] �ܰ����                        StartPos 642, Length 16
    char    sSpotOrdAbleQty     [  16];    // [double,   16] �ǹ��ֹ����ɼ���                StartPos 658, Length 16
    char    sOrdAbleRuseQty     [  16];    // [double,   16] �ֹ������������              StartPos 674, Length 16
    char    sFlctQty            [  16];    // [double,   16] ��������                        StartPos 690, Length 16
    char    sSecBalQtyD2        [  16];    // [double,   16] �ܰ����(D2)                    StartPos 706, Length 16
    char    sSellAbleQty        [  16];    // [double,   16] �ŵ��ֹ����ɼ���                StartPos 722, Length 16
    char    sUnercSellOrdQty    [  16];    // [double,   16] ��ü��ŵ��ֹ�����              StartPos 738, Length 16
    char    sAvrPchsPrc         [  13];    // [double,   13] ��ո��԰�                      StartPos 754, Length 13
    char    sPchsAmt            [  16];    // [double,   16] ���Աݾ�                        StartPos 767, Length 16
    char    sDeposit            [  16];    // [double,   16] ������                          StartPos 783, Length 16
    char    sSubstAmt           [  16];    // [double,   16] ����                          StartPos 799, Length 16
    char    sCsgnMnyMgn         [  16];    // [double,   16] ��Ź�������űݾ�                StartPos 815, Length 16
    char    sCsgnSubstMgn       [  16];    // [double,   16] ��Ź������űݾ�                StartPos 831, Length 16
    char    sOrdAbleMny         [  16];    // [double,   16] �ֹ���������                    StartPos 847, Length 16
    char    sOrdAbleSubstAmt    [  16];    // [double,   16] �ֹ����ɴ��ݾ�                StartPos 863, Length 16
    char    sRuseAbleAmt        [  16];    // [double,   16] ���밡�ɱݾ�                  StartPos 879, Length 16
    char    sMgntrnCode         [   3];    // [string,    3] �ſ�ŷ��ڵ�                    StartPos 895, Length 3
} AS0_OutBlock, *LPAS0_OutBlock;
#define NAME_AS0_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _AS0_H_
