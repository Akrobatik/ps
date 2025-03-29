# [Platinum IV] 루미의 생일파티장 꾸미기 - 33670 

[문제 링크](https://www.acmicpc.net/problem/33670) 

### 성능 요약

메모리: 3444 KB, 시간: 20 ms

### 분류

오일러 피 함수, 수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2025년 3월 29일 09:44:39

### 문제 설명

<p><strong>이 문제는 <a href="/problem/33671">루미의 생일파티장 꾸미기 (EX)</a>와 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>,</mo><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N,L$</span></mjx-container>의 제한만 다른 문제이다.</strong></p>

<p>루미의 친구들은 루미를 위한 깜짝 생일파티를 바쁘게 준비하고 있다. 케이크, 선물, 장소 대관 등 모든 것이 준비되었다! 그런데 단 한 가지 문제점이 있다. 루미의 친구들이 대관한 생일파티장의 디자인이 너무 밋밋하다는 점이다. 따라서 루미의 친구들은 직사각형 타일을 이용하여 생일파티장의 벽면을 아름답게 꾸미려고 한다. 루미의 친구들은 다음과 같은 조건을 만족하는 직사각형 타일을 선택해 벽면을 꾸미고자 한다.</p>

<ul>
	<li>직사각형 타일의 모든 변의 길이는 양의 정수이다.</li>
	<li>직사각형 타일의 가로의 길이가 세로의 길이보다 길거나 같다.</li>
	<li>직사각형 타일의 가로의 길이는 루미가 가장 좋아하는 양의 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$L$</span></mjx-container>의 배수이다.</li>
	<li>직사각형 타일의 가로의 길이는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$NL$</span></mjx-container> 이하이다.</li>
	<li>직사각형 타일의 세로의 길이와 가로의 길이는 서로소이다.</li>
</ul>

<p>루미의 친구들은 위 조건을 만족하는 직사각형 타일 중에서 합동이 아닌 서로 다른 모양의 타일이 총 몇 가지인지 궁금해졌다. 루미의 친구들을 도와주자.</p>

### 입력 

 <p>첫 번째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>,</mo><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N, L$</span></mjx-container>이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>조건을 만족하는 서로 다른 모양의 타일의 개수를 소수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c38"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>998</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>244</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>353</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$998\, 244\, 353$</span></mjx-container>으로 나눈 나머지를 출력하라.</p>

