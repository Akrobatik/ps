# [Platinum III] Palindromic Partitions - 15250 

[문제 링크](https://www.acmicpc.net/problem/15250) 

### 성능 요약

메모리: 19304 KB, 시간: 100 ms

### 분류

그리디 알고리즘, 해싱, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2025년 3월 14일 06:14:26

### 문제 설명

<p>A partition of a string s is a set of one or more non-overlapping non-empty substrings of s (call them a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, . . . , a<sub>d</sub>), such that s is their concatenation: s = a<sub>1</sub> +a<sub>2</sub> +a<sub>3</sub> +. . .+a<sub>d</sub>. We call these substrings "chunks" and define the length of such a partition to be the number of chunks, d.</p>

<p>We can represent the partition of a string by writing each chunk in parentheses. For example, the string "<code>decode</code>" can be partitioned as <code>(d)(ec)(ode)</code> or <code>(d)(e)(c)(od)(e)</code> or <code>(decod)(e)</code> or <code>(decode)</code> or <code>(de)(code)</code> or a number of other ways.</p>

<p>A partition is palindromic if its chunks form a palindrome when we consider each chunk as an atomic unit. For example, the only palindromic partitions of "<code>decode</code>" are <code>(de)(co)(de)</code> and <code>(decode)</code>. This also illustrates that every word has a trivial palindromic partition of length one.</p>

<p>Your task is to compute the maximal possible number of chunks in palindromic partition.</p>

### 입력 

 <p>The input starts with the number of test cases t in the first line. The following t lines describe individual test cases consisting of a single word s, containing only lowercase letters of the English alphabet. There are no spaces in the input.</p>

### 출력 

 <p>For every testcase output a single number: the length of the longest palindromic partition of the input word s.</p>

