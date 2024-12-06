# 64bit-ls-xingapi (dll mode)
LS증권 64비트 XingApi
DLL버전만 지원 (COM버전 지원안함)

# 설치방법
xingAPI64.zip 압축 해제후 파일들을 LS증권 XingApi폴더로 이동 (C:\LS_SEC\xingAPI)

# cpp 소스파일수정
  1. LoadLibrary("xingAPI64.dll")
  2. BOOL XING64_Init(LPCTSTR xing_folder_path) 함수 호출<br/>
      XING64_Init("xingAPI64.dll")<br/>
       true: 성공, false: XingApi설치 안됨
  4. 기타 소스코드는 32비트와 동일

# 참고
* 메모리 IPC통신을 이용하여 LS증권의 32비트 모듈과 데이터 통신진행.
* 64비트와 32비트 사이 데이터 통신이 진행되며, 요청/응답 사이 추가적인 시간비용 발생.
* 빠른 응답이 필요치 않는 데이터 분석, 또는 64비트 여야만 할 경우 이용
