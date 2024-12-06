# 64bit-ls-xingapi (dll mode)
LS증권 64비트 XingApi
DLL방식만 지원 (COM방식 지원안함)

# 설치방법
lib.zip압축 해제후 파일들을 LS증권 XingApi폴더로 이동 (C:\LS_SEC\xingAPI)

# Cpp파일수정
1. LoadLibrary("xingAPI64.dll")
2. XING64_Init("C:\LS_SEC\xingAPI") 호출
기타 소스는 32비트와 동일
