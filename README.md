# Калькулятор с вычислением математических выражений

Этот проект представляет собой простой калькулятор, который может вычислять математические выражения, поддерживающие базовые операции:
сложение, вычитание, умножение, деление и возведение в степень. Калькулятор работает с целыми числами и числами с плавающей запятой. 
Он также включает обработку ошибок для некорректных выражений, таких как деление на ноль или неверные операторы.

## Обновления
**14.12.2024**
- Закончена работа над калькулятором, он верно считывает выражения и решает их

**30.03.2025**
- Изменен способ проверки сообщения на корректность — теперь оно проверяется с помощью `regex`
- Добавлены способы динамической и статической сборки проекта

## Функции
- Поддержка следующих операций: `+`, `-`, `*`, `/`, `^`
- Работа с числами с плавающей запятой и отрицательными числами
- Обработка ошибок для неверных вводов (например, деление на ноль, неправильные операторы или выражения)
- Вычисление математических выражений, например: `2+3`, `3*2.5`, `2^3+4` и т.д.

## Структура проекта
- `calc.h` — заголовочный файл, содержащий объявления функций.
- `calc.cpp` — реализация функций для вычислений и проверки выражений.
- `main.cpp` — точка входа в программу (если требуется).
- `tests.cpp` — тесты, написанные с использованием библиотеки Doctest.


## Как использовать

1. Добавьте файлы в свой проект.
2. Введите математическое выражение, когда будет предложено.
3. Программа выведет результат вычисления и снова предложит ввести мат. выражение.
4. Чтобы выйти из программы, введите команду `stop`.


### Примеры выражений
- Корректные:
- ```bash
    1+2
    2.5*4.2
    15.34^2
    3--5 — вычитание отрицательного числа.
- Некорректные:
- ```bash
    1.2.3 — более одной точки в числе.
    2+*3 — два оператора подряд.
