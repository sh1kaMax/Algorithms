# I. Машинки

| Ограничение времени |	1 секунды |
| ------------------- | --------- |
| Ограничение памяти  |	     256Mb |
| Ввод |	стандартный ввод |
| Вывод |	стандартный вывод |

Петя, которому три года, очень любит играть с машинками. Всего у Пети N различных машинок, которые хранятся на полке шкафа так высоко, что он сам не может до них дотянуться. Одновременно на полу комнаты может находиться не более K машинок. Петя играет с одной из машинок на полу и если он хочет поиграть с другой машинкой, которая также находится на полу, то дотягивается до нее сам. Если же машинка находится на полке, то он обращается за помощью к маме. Мама может достать для Пети машинку с полки и одновременно с этим поставить на полку любую машинку с пола. Мама очень хорошо знает своего ребенка и может предугадать последовательность, в которой Петя захочет играть с машинками. При этом, чтобы не мешать Петиной игре, она хочет совершить как можно меньше операций по подъему машинки с пола, каждый раз правильно выбирая машинку, которую следует убрать на полку. Ваша задача состоит в том, чтобы определить минимальное количество операций. Перед тем, как Петя начал играть, все машинки стоят на полке.

## Формат ввода

В первой строке содержаться три числа N, K и P (1≤ K, N ≤ 100000, 1≤ P ≤ 500000). В следующих P строках записаны номера машинок в том порядке, в котором Петя захочет играть с ними.

## Формат Вывода

Выведите единственное число: минимальное количество операций, которое надо совершить Петиной маме.

## Пример
|Ввод |	Вывод |
| --- | ----- |
|3 2 7 <br> 1 <br> 2 <br> 3 <br> 1 <br> 3 <br> 1 <br> 2 | 4 |
