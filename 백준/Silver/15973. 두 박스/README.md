# [Silver I] 두 박스 - 15973 

[문제 링크](https://www.acmicpc.net/problem/15973) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

많은 조건 분기, 기하학, 수학

### 제출 일자

2025년 2월 25일 12:45:05

### 문제 설명

<p>2차원 좌표 평면 위에 두 개의 박스(직사각형) <em>P</em>, <em>Q</em>가 놓여 있다. 각 박스의 변은 x축이나 y축에 평행하다. 박스를 연구하는 학수는 이 두 박스의 교차 상태를 파악하여 내부가 겹쳐 있는지 (FACE), 그렇지 않고 선분에서 만나는 지(LINE), 그렇지 않고 한 점에서 만나는지(POINT), 아예 만나지 않는지 (NULL) 구별하려고 한다.</p>

<p>다음 그림은 두 박스의 여러 가지 교차 상태의 예를 보여준다.</p>

<table class="table table table table-bordered" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width: 20%; text-align: center; vertical-align: center;"><img alt="" src="https://upload.acmicpc.net/301ce57f-b7af-4259-abe7-00cf03c4f79a/-/preview/" style="width: 108px; height: 120px;"></td>
			<td style="width: 20%; text-align: center; vertical-align: center;"><img alt="" src="https://upload.acmicpc.net/346e12cd-911f-42c7-b121-bfb5ab6b741e/-/preview/" style="width: 113px; height: 91px;"></td>
			<td style="width: 20%; text-align: center; vertical-align: center;"><img alt="" src="https://upload.acmicpc.net/3d0c520c-cc01-440c-83e0-6dccf5262f05/-/preview/" style="width: 117px; height: 99px;"></td>
			<td style="width: 20%; text-align: center; vertical-align: center;"><img alt="" src="https://upload.acmicpc.net/319c53ad-b1f0-4de5-b43e-db2c930b73e3/-/preview/" style="width: 119px; height: 75px;"></td>
			<td style="width: 20%; text-align: center; vertical-align: center;"><img alt="" src="https://upload.acmicpc.net/f757cc24-4dc4-4219-a118-9e878fb68747/-/preview/" style="width: 108px; height: 111px;"></td>
		</tr>
	</tbody>
	<tfoot>
		<tr>
			<th style="width: 20%; text-align: center;">(a) POINT</th>
			<th style="width: 20%; text-align: center;">(b) LINE</th>
			<th style="width: 20%; text-align: center;">(c) FACE</th>
			<th style="width: 20%; text-align: center;">(d) FACE</th>
			<th style="width: 20%; text-align: center;">(e) NULL</th>
		</tr>
	</tfoot>
</table>

<p>FACE인 경우에는 (d)처럼 어느 한 박스가 다른 박스에 포함될 수도 있다는 점에 유의해야 한다.</p>

<p>두 박스의 정보가 주어졌을 때, 두 박스의 교차 상태를 출력하는 프로그램을 작성하시오.</p>

### 입력 

 <p>표준 입력으로 두 박스의 정보가 한 줄에 하나씩 주어진다. 각 박스의 정보는 왼쪽 아래 꼭짓점 좌표 (<em>x</em><sub>1</sub>, <em>y</em><sub>1</sub>)과 오른쪽 위 꼭짓점 좌표 (<em>x</em><sub>2</sub>, <em>y</em><sub>2</sub>)로 구성되는데 이들 좌푯값 <em>x</em><sub>1</sub>, <em>y</em><sub>1</sub>, <em>x</em><sub>2</sub>, <em>y</em><sub>2</sub> (<em>x</em><sub>1</sub> < <em>x</em><sub>2</sub>, <em>y</em><sub>1</sub> < <em>y</em><sub>2</sub>)가 공백을 사이에 두고 주어진다.</p>

### 출력 

 <p>표준 출력으로 두 박스의 교차 상태를 POINT, LINE, FACE, NULL 중의 하나로 출력한다. 두 박스의 교차 상태는 모두 대문자로 출력한다.</p>

