# [Platinum II] Prefix와 Suffix - 13576 

[문제 링크](https://www.acmicpc.net/problem/13576) 

### 성능 요약

메모리: 4608 KB, 시간: 20 ms

### 분류

문자열, 접미사 배열과 LCP 배열, z

### 제출 일자

2025년 3월 9일 00:11:16

### 문제 설명

<p>문자열 S = S<sub>1</sub>S<sub>2</sub>...S<sub>|S|</sub>가 주어진다. |S|는 문자열 S의 길이이며, S<sub>i</sub>는 i번째 글자이다.</p>

<ul>
	<li>문자열 S의 부분 문자열 S[i..j] (1 ≤ i ≤ j ≤ |S|)는 S<sub>i</sub>S<sub>i+1</sub>...S<sub>j</sub> 이다.</li>
	<li>문자열 S의 길이가 l (1 ≤ l ≤ |S|)인 Prefix는 S[1..l] 이다.</li>
	<li>문자열 S의 길이가 l (1 ≤ l ≤ |S|)인 Suffix는 S[|S|-l+1..|S|] 이다.</li>
</ul>

<p>S의 Prefix인 동시에 Suffix인 문자열을 찾고, 그러한 문자열이 S의 부분 문자열로 몇 번 등장하는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 문자열 S가 주어진다. (1 ≤ |S| ≤ 100,000)</p>

### 출력 

 <p>첫째 줄에 S의 Prefix인 동시에 Suffix인 문자열의 개수 K를 출력한다.</p>

<p>다음 K개의 줄에는 l<sub>i</sub>와 c<sub>i</sub>를 출력한다. 여기서 l<sub>i</sub>는 길이가 l<sub>i</sub>인 Prefix가 길이가 l<sub>i</sub>인 Suffix와 일치하고, 문자열 S의 부분 문자열로 c<sub>i</sub>번 등장한다는 의미이다.</p>

<p>l<sub>i</sub>가 증가하는 순서대로 출력해야 한다.</p>

