# [Bronze III] Balancing Weights - 11131 

[문제 링크](https://www.acmicpc.net/problem/11131) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

사칙연산, 구현, 수학

### 제출 일자

2025년 4월 2일 01:49:18

### 문제 설명

<p>Ever since you started studying, your whole family have been expecting you to know the answers to a whole lot of difficult questions. What is wrong with my computer? What is the name of Prince Harry’s new girlfriend? Have you seen my new pants? Your grandfather has just found a new problem for you, and you are yet again under the pressure of finding the answers to one of life’s most fundamental questions.</p>

<p>You are given a 20 meter long lever balanced exactly on the middle by a massless support. A number of weights are applied to the lever. You need to figure out which side will drop, if any. Being such a brilliant mind, you immediately notice that each of the weights will contribute to the total torque applied on the lever, and that this will determine the answer. The torque from a single weight is determined by</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D70F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D451 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>τ</mi><mo>=</mo><mi>m</mi><mo>×</mo><mi>d</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[\tau  = m \times d\]</span> </mjx-container></p>

<p>where <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D70F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>τ</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\tau\)</span></mjx-container> is the total torque applied, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(m\)</span></mjx-container> is the mass of the weight and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D451 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>d</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(d\)</span></mjx-container> is its distance from the center. The lever’s angular acceleration can then be found by the equation</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D6FC TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D70F TEX-I"></mjx-c></mjx-mi><mjx-texatom texclass="ORD"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2F"></mjx-c></mjx-mo></mjx-texatom><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43C TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>α</mi><mo>=</mo><mi>τ</mi><mrow data-mjx-texclass="ORD"><mo>/</mo></mrow><mi>I</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[\alpha = \tau / I\]</span> </mjx-container></p>

<p>where <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D6FC TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>α</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\alpha\)</span></mjx-container> is the angular acceleration and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43C TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>I</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(I\)</span></mjx-container> is the lever’s moment of inertia. The moment of inertia is given by the function</p>

<p><mjx-container class="MathJax" jax="CHTML" display="true" style="font-size: 109%; position: relative;"> <mjx-math display="true" class="MJX-TEX" aria-hidden="true" style="margin-left: 0px; margin-right: 0px;"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43C TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mo class="mjx-lop" space="4"><mjx-c class="mjx-c222B TEX-S2"></mjx-c></mjx-mo><mjx-texatom space="2" texclass="ORD"><mjx-msup><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: 0.413em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D451 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-texatom></mjx-math><mjx-assistive-mml unselectable="on" display="block"><math xmlns="http://www.w3.org/1998/Math/MathML" display="block"><mi>I</mi><mo>=</mo><mo data-mjx-texclass="OP">∫</mo><mrow data-mjx-texclass="ORD"><msup><mi>r</mi><mn>2</mn></msup><mi>d</mi><mi>m</mi></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\[I = \int {r^2dm}\]</span> </mjx-container></p>

<p>where <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>r</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(r\)</span></mjx-container> is the perpendicular distance to the axis of rotation.</p>

### 입력 

 <p>The first line of input contains a single number T, the number of test cases to follow. Each test case starts with a line containing N, the number of weights in the test case. This is followed by a line containing N numbers, W<sub>1</sub> W<sub>2</sub> ... W<sub>N</sub> the locations of the N weights.</p>

<ul>
	<li>0 < T ≤ 100</li>
	<li>0 < N ≤ 100</li>
	<li>−1000 ≤ W<sub>i</sub> ≤ 1000</li>
	<li>A negative Wi means that the weight is located to the left of the center, while a positive one means that it is located to the right.</li>
	<li>The weight of the lever is exactly 2000 grams, uniformly distributed. Each weight weighs 100 grams.</li>
	<li>Weights are modeled as single point masses.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing Left if the weight tips to the left, Right if the weight tips to the right or Equilibrium if the weight does not tip to any of the sides.</p>

