# [Platinum II] Hidden Password - 3789 

[문제 링크](https://www.acmicpc.net/problem/3789) 

### 성능 요약

메모리: 2664 KB, 시간: 4 ms

### 분류

문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 3월 14일 02:36:03

### 문제 설명

<p>Some time the programmers have very strange ways to hide their passwords. See for example how Billy “Hacker” Geits hide his password. Billy chooses a string S composed of small Latin letters with length L. Then he makes all L-1 one-letter left cyclic shifts of the string and takes as a password one prefix of the lexicographically first of the obtained strings (including S). For example let consider the string alabala. The cyclic one-letter left shifts (including the initial string) are:</p>

<pre>alabala
labalaa
abalaal
balaala
alaalab
laalaba
aalabal</pre>

<p>and lexicographically first of them is the string aalabal. The first letter of this string is in position 6 in the initial string (the positions in the string are counted from 0).</p>

<p>Write a program that for given string S finds the start position of the smallest lexicographically one-letter left cyclic shift of this string. If the smallest lexicographically left shift appears more than once then the program have to output the smallest initial position.</p>

### 입력 

 <p>Your program has to be ready to solve more than one test case. The first line of the input file will contains only the number T of the test cases. Each of the following T lines will describe one test case – first the length L of the string (5≤L≤100000) and then, separated by one space, the string S itself.</p>

### 출력 

 <p>The output file have to contain exactly T lines with a single number each – the initial position found by your program.</p>

