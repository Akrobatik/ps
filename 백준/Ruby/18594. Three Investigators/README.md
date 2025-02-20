# [Ruby IV] Three Investigators - 18594 

[문제 링크](https://www.acmicpc.net/problem/18594) 

### 성능 요약

메모리: 13772 KB, 시간: 1164 ms

### 분류

자료 구조, 그리디 알고리즘, 구현, 가장 긴 증가하는 부분 수열: O(n log n), 트리를 사용한 집합과 맵

### 제출 일자

2025년 2월 21일 01:08:52

### 문제 설명

<p>Chitanda owns a sequence a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> with n integers, and she wants to play a game with Skywalkert.</p>

<p>First, Chitanda will select a parameter k and remove a<sub>k+1</sub>, a<sub>k+2</sub>, . . . , a<sub>n</sub>. Thus there will be exactly k integers in sequence a.</p>

<p>Then Skywalkert can select a subsequence of a and remove it from a. Assume the selected subsequence is a<sub>p<sub>1</sub></sub>, a<sub>p<sub>2</sub></sub>, . . . , a<sub>p<sub>m</sub></sub>. He should ensure that p<sub>1</sub> < p<sub>2</sub> < . . . < p<sub>m</sub> and a<sub>p<sub>1</sub></sub> ≤ a<sub>p<sub>2</sub></sub> ≤ . . . ≤ a<sub>p<sub>m</sub></sub>.</p>

<p>Skywalkert can do the above operation for no more than 5 times. His score is the sum of all the integers selected by him in these no more than 5 operations.</p>

<p>For each possible parameter k selected by Chitanda, write a program to help Skywalkert know the maximum score he can achieve.</p>

### 입력 

 <p>The first line of the input contains an integer T (1 ≤ T ≤ 10 000), denoting the number of test cases.</p>

<p>In each test case, there is one integer n (1 ≤ n ≤ 100 000) on the first line, denoting the length of a.</p>

<p>In the second line of a test case, there are n integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>), denoting the sequence.</p>

<p>It is guaranteed that the sum of n in all test cases is at most 500 000.</p>

### 출력 

 <p>For each test case, print a single line containing n integers s<sub>1</sub>, s<sub>2</sub>, . . . , s<sub>n</sub>, where si denotes the maximum score of Skywalkert when k = i.</p>

