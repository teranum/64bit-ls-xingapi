# 64bit-ls-xingapi
LS증권 64비트 XingApi (DLL, COM버전 모두 지원)

# 설치방법
xingAPI64.zip 압축 해제후 파일들을 LS증권 XingApi폴더로 이동 (C:\LS_SEC\xingAPI)
<br/>
# COM 이용방법(Python, C# 등)
  1. 설치.bat 파일을 관리자권한으로 실행
  2. 개발환경만 64비트로 설정, 소스코드는 32비트와 동일


# DLL 이용방법(C++)<br/>
   (DLL 이용시 COM등록이 필요없음)
  1. IXingAPI.h 파일에서 "xingAPI.dll" -> "xingAPI64.dll" 로 수정
  2. 기타 소스코드는 32비트와 동일


# 참고
* 메모리 IPC통신을 이용하여 LS증권의 32비트 모듈과 데이터 통신진행.
* 64비트와 32비트 사이 데이터 통신이 진행되며, 요청/응답 사이 추가적인 시간비용 발생.
* 빠른 응답이 필요치 않는 데이터 분석, 또는 64비트 여야만 할 경우 이용
