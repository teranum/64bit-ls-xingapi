#ifndef _AS1_H_
#define _AS1_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �ؿ��ֽ��ֹ�ü��(�̱�) ( key=8,group=1 )
#pragma pack( push, 1 )

#define NAME_AS1     "AS1"

// �Է�                           
typedef struct _AS1_InBlock
{
} AS1_InBlock, *LPAS1_InBlock;
#define NAME_AS1_InBlock     "InBlock"

// ���                           
typedef struct _AS1_OutBlock
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
    char    sMgmtBrnNo          [   3];    // [string,    3] ����������ȣ                    StartPos 247, Length 3
    char    sAcntNo             [  20];    // [string,   20] ���¹�ȣ                        StartPos 250, Length 20
    char    sAcntNm             [  40];    // [string,   40] ���¸�                          StartPos 270, Length 40
    char    sIsuNo              [  12];    // [string,   12] �����ȣ                        StartPos 310, Length 12
    char    sIsuNm              [  40];    // [string,   40] �����                          StartPos 322, Length 40
    char    sOrdNo              [  10];    // [long  ,   10] �ֹ���ȣ                        StartPos 362, Length 10
    char    sOrgOrdNo           [  10];    // [long  ,   10] ���ֹ���ȣ                      StartPos 372, Length 10
    char    sExecNO             [  10];    // [long  ,   10] ü���ȣ                        StartPos 382, Length 10
    char    sAbrdExecId         [  18];    // [long  ,   18] �ؿ�ü��ID                      StartPos 392, Length 18
    char    sOrdQty             [  16];    // [long  ,   16] �ֹ�����                        StartPos 410, Length 16
    char    sOrdPrc             [  13];    // [long  ,   13] �ֹ���                          StartPos 426, Length 13
    char    sExecQty            [  16];    // [long  ,   16] ü�����                        StartPos 439, Length 16
    char    sExecPrc            [  13];    // [long  ,   13] ü�ᰡ                          StartPos 455, Length 13
    char    sMdfyCnfQty         [  16];    // [long  ,   16] ����Ȯ�μ���                    StartPos 468, Length 16
    char    sMdfyCnfPrc         [  16];    // [long  ,   16] ����Ȯ�ΰ�                      StartPos 484, Length 16
    char    sCancCnfQty         [  16];    // [long  ,   16] ���Ȯ�μ���                    StartPos 500, Length 16
    char    sRjtQty             [  16];    // [long  ,   16] �źμ���                        StartPos 516, Length 16
    char    sOrdTrxPtnCode      [   4];    // [long  ,    4] �ֹ�ó�������ڵ�                StartPos 532, Length 4
    char    sMtiordSeqno        [  10];    // [long  ,   10] �����ֹ��Ϸù�ȣ                StartPos 536, Length 10
    char    sOrdCndi            [   1];    // [string,    1] �ֹ�����                        StartPos 546, Length 1
    char    sOrdprcPtnCode      [   2];    // [string,    2] ȣ�������ڵ�                    StartPos 547, Length 2
    char    sShtnIsuNo          [   9];    // [long  ,    9] ���������ȣ                    StartPos 549, Length 9
    char    sOpDrtnNo           [  12];    // [string,   12] ������ù�ȣ                    StartPos 558, Length 12
    char    sUnercQty           [  16];    // [string,   16] ��ü�����(�ֹ�)                StartPos 570, Length 16
    char    sOrgOrdUnercQty     [  16];    // [string,   16] ���ֹ���ü�����                StartPos 586, Length 16
    char    sOrgOrdMdfyQty      [  16];    // [long  ,   16] ���ֹ���������                  StartPos 602, Length 16
    char    sOrgOrdCancQty      [  16];    // [long  ,   16] ���ֹ���Ҽ���                  StartPos 618, Length 16
    char    sOrdAvrExecPrc      [  13];    // [long  ,   13] �ֹ����ü�ᰡ                  StartPos 634, Length 13
    char    sOrdAmt             [  16];    // [long  ,   16] �ֹ��ݾ�                        StartPos 647, Length 16
    char    sStdIsuNo           [  12];    // [long  ,   12] ǥ�������ȣ                    StartPos 663, Length 12
    char    sBnsTp              [   1];    // [long  ,    1] �Ÿű���                        StartPos 675, Length 1
    char    sCommdaCode         [   2];    // [string,    2] ��Ÿ�ü�ڵ�                    StartPos 676, Length 2
    char    sOrdAcntNo          [  20];    // [string,   20] �ֹ����¹�ȣ                    StartPos 678, Length 20
    char    sAgrgtBrnNo         [   3];    // [string,    3] ����������ȣ                    StartPos 698, Length 3
    char    sRegMktCode         [   2];    // [string,    2] ��Ͻ����ڵ�                    StartPos 701, Length 2
    char    sMnyMgnRat          [   7];    // [string,    7] �������űݷ�                    StartPos 703, Length 7
    char    sSubstMgnRat        [   9];    // [string,    9] ������űݷ�                    StartPos 710, Length 9
    char    sMnyExecAmt         [  16];    // [string,   16] ����ü��ݾ�                    StartPos 719, Length 16
    char    sSubstExecAmt       [  16];    // [string,   16] ���ü��ݾ�                    StartPos 735, Length 16
    char    sCmsnAmtExecAmt     [  16];    // [long  ,   16] ������ü��ݾ�                  StartPos 751, Length 16
    char    sPrdayRuseExecVal   [  16];    // [string,   16] ��������ü��ݾ�              StartPos 767, Length 16
    char    sCrdayRuseExecVal   [  16];    // [string,   16] ��������ü��ݾ�              StartPos 783, Length 16
    char    sSpotExecQty        [  16];    // [string,   16] �ǹ�ü�����                    StartPos 799, Length 16
    char    sStslExecQty        [  16];    // [string,   16] ���ŵ�ü�����                  StartPos 815, Length 16
    char    sStrtgCode          [   6];    // [string,    6] �����ڵ�                        StartPos 831, Length 6
    char    sGrpId              [  20];    // [string,   20] �׷�ID                          StartPos 837, Length 20
    char    sOrdSeqno           [  10];    // [string,   10] �ֹ�ȸ��                        StartPos 857, Length 10
    char    sOrdUserId          [  16];    // [long  ,   16] �ֹ���ID                        StartPos 867, Length 16
    char    sExecTime           [   9];    // [long  ,    9] ü��ð�                        StartPos 883, Length 9
    char    sRcptExecTime       [   9];    // [long  ,    9] �ŷ��Ҽ���ü��ð�              StartPos 892, Length 9
    char    sRjtRsn             [   8];    // [long  ,    8] �źλ���                        StartPos 901, Length 8
    char    sSecBalQty          [  16];    // [long  ,   16] �ܰ����                        StartPos 909, Length 16
    char    sSpotOrdAbleQty     [  16];    // [long  ,   16] �ǹ��ֹ����ɼ���                StartPos 925, Length 16
    char    sOrdAbleRuseQty     [  16];    // [long  ,   16] �ֹ������������              StartPos 941, Length 16
    char    sFlctQty            [  16];    // [long  ,   16] ��������                        StartPos 957, Length 16
    char    sSecBalQtyD2        [  16];    // [long  ,   16] �ܰ����(D2)                    StartPos 973, Length 16
    char    sSellAbleQty        [  16];    // [long  ,   16] �ŵ��ֹ����ɼ���                StartPos 989, Length 16
    char    sUnercSellOrdQty    [  16];    // [long  ,   16] ��ü��ŵ��ֹ�����              StartPos 1005, Length 16
    char    sAvrPchsPrc         [  13];    // [long  ,   13] ��ո��԰�                      StartPos 1021, Length 13
    char    sPchsAmt            [  16];    // [string,   16] ���Աݾ�                        StartPos 1034, Length 16
    char    sDeposit            [  16];    // [string,   16] ������                          StartPos 1050, Length 16
    char    sSubstAmt           [  16];    // [long  ,   16] ����                          StartPos 1066, Length 16
    char    sCsgnMnyMgn         [  16];    // [long  ,   16] ��Ź�������űݾ�                StartPos 1082, Length 16
    char    sCsgnSubstMgn       [  16];    // [long  ,   16] ��Ź������űݾ�                StartPos 1098, Length 16
    char    sOrdAbleMny         [  16];    // [long  ,   16] �ֹ���������                    StartPos 1114, Length 16
    char    sOrdAbleSubstAmt    [  16];    // [long  ,   16] �ֹ����ɴ��ݾ�                StartPos 1130, Length 16
    char    sRuseAbleAmt        [  16];    // [string,   16] ���밡�ɱݾ�                  StartPos 1146, Length 16
    char    sMgntrnCode         [   3];    // [string,    3] �ſ�ŷ��ڵ�                    StartPos 1162, Length 3
} AS1_OutBlock, *LPAS1_OutBlock;
#define NAME_AS1_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _AS1_H_
