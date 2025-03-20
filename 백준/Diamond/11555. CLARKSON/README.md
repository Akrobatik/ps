# [Diamond V] CLARKSON - 11555 

[문제 링크](https://www.acmicpc.net/problem/11555) 

### 성능 요약

메모리: 9084 KB, 시간: 208 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 매개 변수 탐색, 세그먼트 트리, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 3월 20일 17:45:25

### 문제 설명

<p>"Jeremy Clarkson Beatbox" is a popular YouTube video montage of the former Top Gear host performing beatbox. The video consists of a series of scenes from the show, stitched together to produce an entertaining musical performance. The video was published on YouTube in 2009 and it has been viewed almost three million times since then.</p>

<p>This year Jeremy Clarkson departed from the BBC, following a disciplinary ruling. To commemorate the iconic show, we want to produce a sequel to the popular YouTube montage, using scenes from more recent episodes. The lyrics of the new video are already chosen by the fans of the show, but making the montage is not an easy thing.</p>

<p>The problem is that, no matter how skillfully the separate pieces of the video are stitched together, the transitions are always noticeable to the viewers. If two transitions occur within a short period of time, it can even be irritating for some viewers. Therefore, the goal is to keep the transitions as far apart as possible by maximizing the length of the shortest piece in the montage.</p>

<p>Write a program that takes two lines of input: the lyrics of the song on the first line, and the script of an episode of Top Gear on the second line. The program should then find the best way to construct the lyrics out of substrings of the script by maximizing the length of the shortest substring. It should output the length of the shortest substring in that optimal variant of the song. If it’s impossible to construct the song out of the given episode, it should output −1. </p>

### 입력 

 <p>Your program should read from the standard input two lines of text, containing only English uppercase and lowercase letters.</p>

### 출력 

 <p>Your program has to write to the standard output one integer, which is equal to the length of the shortest substring in the optimal variant of the song, or -1 if construction is impossible.</p>

