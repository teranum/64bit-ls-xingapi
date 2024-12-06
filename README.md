# 64bit-ls-xingapi (dll mode)
LS증권 64비트 XingApi
DLL방식만 지원 (COM방식 지원안함)

# 설치방법
lib.zip압축 해제후 파일들을 LS증권 XingApi폴더로 이동 (C:\LS_SEC\xingAPI)

# Cpp파일수정
1. LoadLibrary("xingAPI64.dll")
2. XING64_Init("C:\LS_SEC\xingAPI") 호출
기타 소스는 32비트와 동일

# 참고
* 메모리 IPC통신을 이용하여 LS증권의 32비트 모듈과 데이터 통신진행.
* 64비트와 32비트 사이 데이터 통신이 진행되며, 요청/응답 사이 추가적인 시간비용 발생.
* 빠른 응답이 필요치 않는 데이터 분석, 또는 64비트 여야만 할 경우 이용
