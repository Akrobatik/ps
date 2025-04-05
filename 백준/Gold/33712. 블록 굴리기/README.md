# [Gold II] 블록 굴리기 - 33712 

[문제 링크](https://www.acmicpc.net/problem/33712) 

### 성능 요약

메모리: 2312 KB, 시간: 4 ms

### 분류

너비 우선 탐색, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 구현

### 제출 일자

2025년 4월 5일 09:09:19

### 문제 설명

<p>민규는 요즘 유행하는 퍼즐 게임, <블록 굴리기>의 레벨 제작 기능을 사용해 보고 있다.</p>

<p>이 게임은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>×</mo><mn>1</mn><mo>×</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2\times 1\times 1$</span></mjx-container> 크기의 직육면체 블록을 굴려서 특정한 목표 지점에 도달하도록 하는 게임이다. 구체적으로 아래와 같은 규칙을 갖고 있다.</p>

<ul>
	<li>블록과 이동방식: <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>×</mo><mn>1</mn><mo>×</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2\times 1\times 1$</span></mjx-container> 크기의 블록에 대해, 블록의 여섯 면 중 크기가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>×</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\times 1$</span></mjx-container>인 면이 바닥과 맞닿으면 세워진 상태, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>×</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2\times 1$</span></mjx-container>인 면이 바닥과 맞닿으면 눕혀진 상태라고 정의한다. 블록은 앞뒤좌우 네 방향으로 굴릴 수 있다. 블록을 굴리면 굴린 방향의 옆면이 인접한 바닥과 맞닿는 방향으로 이동한다.</li>
	<li>맵과 타일: 맵은 격자형 평면으로 구성되며, 블록이 이동할 수 있는 일반 타일과 목표 타일로 이루어져 있다. 블록은 맵 내부에서만 이동이 가능하여 경계를 벗어나면 즉시 실패 처리된다.</li>
	<li>목표: 블록을 굴려 목표 타일에 정확히 세워진 상태로 도착하는 것이 목표이다.</li>
	<li>레벨 제작 제한사항: 목표 타일은 1개만 지정할 수 있고, 목표 타일을 포함한 모든 타일은 인접한 변을 통해 연결되어 있어야 한다. 또한 블록은 세워진 상태로 배치해야 하며 일반 타일 위에만 배치할 수 있다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/234acb3e-78a9-4961-87de-e2b230c6acd4/-/preview/" style="width: 500px; max-width:75%"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/85604d2f-cd6a-4426-9b5f-0bceb9bbcb95/-/preview/" style="width: 500px; max-width:75%"></p>

<p style="text-align: center;"><em style="color: #898989;"><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi><mo>=</mo><mn>6</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K = 6$</span></mjx-container>일 때 목표 지점인 주황색 타일에 대해 파란색 타일을 시작 지점으로 정할 수 있다.</em></p>

<p>민규는 맵을 제작하던 중 특정 타일에서는 목표 타일에 도달할 수 없음을 알게 되었다. 민규를 도와 주어진 맵에서 정해진 횟수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>만큼 이동하여 목표 지점의 타일에 도달할 수 있는 시작 지점의 개수를 구하시오.</p>

### 입력 

 <p>첫 번째 줄에 격자 평면의 가로, 세로 길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>과 이동 횟수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>가 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 걸쳐 격자 평면의 상태가 공백으로 구분되어 주어진다. <span style="color:#e74c3c;"><code>0</code></span>은 경계 바깥, <span style="color:#e74c3c;"><code>1</code></span>은 일반 타일, <span style="color:#e74c3c;"><code>2</code></span>는 목표 지점의 타일을 나타낸다.</p>

### 출력 

 <p>첫 번째 줄에 정확히 주어진 이동 횟수만큼 움직였을 때 목표 지점에 도달할 수 있는 시작 지점의 개수를 출력한다.</p>

