[호눅스](https://github.com/honux77/practice/wiki/learngit)님의 깃허브를 참고하여 공부하였다.

[영상 강의](https://opentutorials.org/course/3838)

  - https://opentutorials.org/course/3838

[참고서](https://backlog.com/git-tutorial/kr/)

  - https://backlog.com/git-tutorial/kr/

[교재](https://git-scm.com/book/ko/v2)

  - https://git-scm.com/book/ko/v2

## 22.09.26

# Git - 버전관리

## 버전 생성

- 프로젝트 파일에 들어가서 `git init .`을 통해 버전 정보를 새긴다.  `.git`이라는 파일이 생기고 이 파일이 버전 정보를 기록한다.

- 파일들은 **Working tree**, **Staging Area**, **Repasitory**로 나뉜다.

  - **Working tree**는 작업한 파일들이고 그 중 버전을 만들 파일들을 **Staging Area**에 올린다.  
  그리고 그 파일들을 git이 버전으로 만들어서 **Repasitory**에 올린다.

- `git status` : Working tree의 상태를 볼 수 있다.    
`git add` : Staging Area에 올릴 수 있다.  
`git commit` : 버전을 생성할 수 있다.  
`git log` : 버전들을 볼 수 있다.
