# [Platinum V] Suffix reconstruction - 7887 

[문제 링크](https://www.acmicpc.net/problem/7887) 

### 성능 요약

메모리: 6560 KB, 시간: 272 ms

### 분류

해 구성하기, 그리디 알고리즘, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 3월 15일 20:31:56

### 문제 설명

<p>Given a text s[1..n] of length n, we create its suffix array by taking all its suffixes:</p>

<p style="text-align: center;">s[1..n], s[2..n], . . . , s[n..n]</p>

<p>and sorting them lexicographically. As a result we get a sorted list of suffixes:</p>

<p style="text-align: center;">s[p(1)..n], s[p(2)..n], . . . , s[p(n)..n]</p>

<p>and call the sequence p(1), p(2), . . . , p(n) the suffix array of s[1..n]. For example, if s = abbaabab, the sorted list of all suffixes becomes:</p>

<p style="text-align: center;">aabab, ab, abab, abbaabab, b, baabab, bab, bbaabab</p>

<p>and the suffix array is 4, 7, 5, 1, 8, 3, 6, 2.</p>

<p>It turns out that it is possible to construct this array in a linear time. Your task will be completely different, though: given p(1), p(2), p(3), . . . , p(n) you should check if there exist at least one text consisting of lowercase letters of the English alphabet for which this sequence is the suffix array. If so, output any such text. Otherwise output -1.</p>

### 입력 

 <p>The input contains several descriptions of suffix arrays. The first line contains the number of descriptions t (t ≤ 100). Each description begins with a line containing the length of both the text and the array n (1 ≤ n ≤ 500000). Next line contains integers p(1), p(2), . . . , p(n). You may assume that 1 ≤ p(i) ≤ n and no value of p(i) occurs twice. Total size of the input will not exceed 50MB.</p>

### 출력 

 <p>For each test case output <strong>any</strong> text resulting in the given suffix array. In case there is no such text consisting of lowercase letters of the English alphabet, output -1.</p>

