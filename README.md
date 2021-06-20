# Konkuk_SW
- 2021학년도 1학기, 4-1 SW 활동 장학 중 '자료구조' 강의 조교 활동 기록
- 주로 미리 과제 구현한 코드로 구성됨

## 과제1
1. Factorial 프로그램을 Recursion Version과 Iteration Version으로 각각 구현하고, 입력 값을 1~10까지 증가시키면서 화면에 출력되게 실행하시오.
2. Factorial Recursion Vesion의 경우, n이 증가함에 따라 어느 정도의 n에서까지는 수행이 되고, 어느 정도의 n에서는 stack overflow가 발생하는지를 보이시오.
3. Iteration Version은 2번에서 stack overflow가 발생하는 n에서도 제대로 실행이 됨을 보이시오.

## 과제2
1. Array와 Singly Linked List를 구현하시오.<br>
(1) Insertion을 구현하고 0부터 100,000 까지 차례대로 insert 하시오. 이 때, Singly Linked List는 head쪽으로 insert 하세요.<br>
(2) Read를 구현하고 random한 index를 발생시켜, 해당 index를 읽고 그 값들의 합을 출력하는 프로그램을 작성하세요. <br>
(3) Deletion을 구현하고 random한 index를 발생시켜, 해당 index에 있는 값을 삭제하세요. 이 때, Array의 경우, 해당 data를 삭제하고 shift하는 것 까지 구현하시오.<br>
2. 1번을 1만부터 10만까지 1만씩 증가시키면서 time complexity를 측정하세요.

## 과제3
1. Stack을 Dynamic Array와 Linked List를 이용하여 구현하시오.<br>
(1) Push를 100만번 한 후, pop을 100만번하는 실험, 200만번, 300만번, ... 1000만번하는 실험을 dynamic array와 linked list에서 각각 수행하여 수행시간을 비교하시오. <br>
(2) (1)번에서 수행한 것에 대해서 1회 수행시간을 측정하세요. <br>
(3) Dynamic Array를 이용하는 경우, array를 2배로 증가시킬 때, 수행시간이 다른 경우에 비해 증가하는 것을 실험으로 측정하여 보이시오. <br>
(4) Push를 1번, Pop을 1번씩 교대로 100만번, 200만번,... 1000만번 수행하는 실험을 해서 실행 시간을 비교하시오. <br>

## 과제4
1. Linear Search와 Binary Search를 array 바탕으로 구현하여 수행시간을 분석하시오.<br>
(1) Linear Search : array size가 1000만일 때, Random한 데이터를 찾는 operation을 1000번 수행하여 실행시간을 측정하여, 1번 search하는 평균 시간을 계산할 것 (array size를 1000만부터 1억개까지 1000만씩 증가시키면서 할 것)<br>
(2) Binary Search : array size가 1000만일 때, Random한 데이터를 찾는 operation을 1000번 수행하여 실행시간을 측정하여, 1번 search하는 평균 시간을 계산할 것 (array size를 1000만부터 1억개까지 1000만씩 증가시키면서 할 것)<br>

## 과제5
1. 여러가지 sorting algorithm들을 구현하여 수행시간을 분석하세요 : Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort<br>
(1) 구현한 sorting algorithm들이 정확히 동작하는지를 보이시오. (30번까지 출력하세요)<br>
(2) array의 크기가 증가한에 따라서, 평균의 경우 각 sorting algorithm의 time complexity를 측정해 보자. array의 크기를 만부터 10만까지 만씩 증가시키면서 random한 데이터를 array에 넣고 각 sorting algorithm이 sorting을 수행한 시간을 순차적으로 측정하시오. (이 때, 모든 sorting algorithm에 대해서 같은 내용의 array를 사용하세요)<br>
(3) 위에서 구현한 sorting algorithm들과 추가로 random quick sort를 구현하여, 이미 sorting된 데이터들을 입력했을 때의 time complexity를 측정하시오.<br>

## 과제6
1. BST와 AVL Tree를 구현하고 insert, find 함수를 구현하시오.<br>
(1) 위의 두 트리에 대해서, n까지의 integer를 랜덤하게 발생시켜서 insert하는 작업을 n번 수행한 후, 수행 시간을 측정하여 1회 평균 수행시간을 구하시오. 또한, n까지의 숫자를 랜덤하게 발생시켜 find하는 작업을 n번 수행하는 실험을 하여 수행시간을 측정하여 1회 평균 수행시간을 구하시오. (n = 10만, 20만, ... 100만)<br>
(2) 위의 두 트리에 대해서, n까지의 integer를 순서대로 insert하는 작업을 n번 수행한 후, 수행 시간을 측정하여 1회 평균 수행시간을 구하시오. 또한, n까지의 숫자를 순서대로 find하는 작업을 n번 수행하는 실험을 하여 수행시간을 측정하여 1회 평균 수행시간을 구하시오. (n = 10만, 20만, ... 100만)
