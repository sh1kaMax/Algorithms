# 1296. Гиперпереход

| Ограничение времени |	1.0 секунды |
| ------------------- | --------- |
| Ограничение памяти  |	     64Mb |

Гиперпереход, открытый ещё в начале XXI-го века, и сейчас остаётся основным способом перемещения на расстояния до сотен тысяч парсеков. Но совсем недавно физиками открыто новое явление. Оказывается, длительностью альфа-фазы перехода можно легко управлять. Корабль, находящийся в альфа-фазе перехода, накапливает гравитационный потенциал. Чем больше накопленный гравитационный потенциал корабля, тем меньше энергии потребуется ему на прыжок сквозь пространство. Ваша цель — написать программу, которая позволит кораблю за счёт выбора времени начала альфа-фазы и её длительности накопить максимальный гравитационный потенциал.
В самой грубой модели грави-интенсивность — это последовательность целых чисел pi. Будем считать, что если альфа-фаза началась в момент i и закончилась в момент j, то накопленный в течение альфа-фазы потенциал — это сумма всех чисел, стоящих в последовательности на местах от i до j.

## Исходные данные

В первой строке записано целое число N — длина последовательности, отвечающей за грави-интенсивность (0 ≤ N ≤ 60000). Далее идут N строк, в каждой записано целое число pi (−30000 ≤ pi ≤ 30000).

## Результат

Выведите максимальный гравитационный потенциал, который может накопить корабль в альфа-фазе прыжка. Считается, что потенциал корабля в начальный момент времени равен нулю.

## Пример 1

|Ввод |	Вывод |
| --- | ----- |
| 10 <br> 31 <br> -41 <br> 59 <br> 26 <br> -53 <br> 58 <br> 97 <br> -93 <br> -23 <br> 84 | 187 |

## Пример 2

|Ввод |	Вывод |
| --- | ----- |
| 3 <br> -1 <br> -5 <br> -6 | 0 |
