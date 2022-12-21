# Шахматы
## Состав команды

Камкин Илья - проектировщик

Стебенев Павел - разработчик

Шишкина Алина - разработчик

Дадонов Александр - тестировщик

## Основные правила

Игра происходит на доске, поделённой на равные квадратные клетки, или поля. Размер доски — 8×8 клеток. Вертикальные ряды полей (вертикали) обозначаются латинскими буквами от а до h слева направо, горизонтальные ряды (горизонтали) — цифрами от 1 до 8 снизу вверх; каждое поле обозначается сочетанием соответствующих буквы и цифры. Поля раскрашены в тёмный и светлый цвета (и называются, соответственно, чёрными и белыми) так, что соседние по вертикали и горизонтали поля раскрашены в разные цвета. Доска располагается так, чтобы ближнее угловое поле справа от игрока было белым (для белых это поле h1, для чёрных — поле а8).

У игроков в начале игры имеется по одинаковому набору фигур. Фигуры одного из игроков условно называются «белыми», другого — «чёрными». Белые фигуры окрашены в светлый цвет, чёрные — в тёмный. Сами игроки называются «белые» и «чёрные» по цвету своих фигур.

Игра заключается в том, что игроки поочерёдно делают ходы. Первый ход делают белые.

### Типы фигур и их вес
1. [Король](#король) (♔, ♚)
2. [Ферзь](#ферзь) (♕, ♛) Вес: 5
3. [Слон](#слон) (♗, ♝) Вес: 4
4. [Ладья](#ладья) (♖, ♜) Вес: 3
5. [Конь](#конь) (♘, ♞) Вес: 2
6. [Пешка](#пешка) (♙, ♟) Вес: 1


### Ходы

- Фигуры (кроме [коня](#конь)) передвигаются по прямой линии, при этом все промежуточные поля между начальным и конечным должны быть свободны (на них не должно быть своих или чужих фигур). Исключением является ход [коня](#конь).
- Ход на поле, занятое своей фигурой, невозможен.
- При ходе на поле, занятое чужой фигурой происходит [атака](#атака).
- Ход [пешки](#пешка) на свободное поле противополжного края превращает её в [Ферзя](#ферзь)

#### Король

<img src="images/2.png" title="" alt="" width="450">

#### Ферзь

<img src="images/1.png" title="" alt="" width="450">

#### Слон

<img src="images/5.png" title="" alt="" width="450">

#### Ладья

<img src="images/3.png" title="" alt="" width="450">

#### Конь

<img src="images/4.png" title="" alt="" width="450">

#### Пешка

Ходы пешки:

<img src="images/6.png" title="" alt="" width="450">

Взятие пешкой фигур противника:

<img src="images/7.png" title="" alt="" width="450">

#### Атака

При ходе на поле, занятое чужой фигурой [вес Вашей фигуры](#типы-фигур-и-их-вес) рассчитывается следующим образом:
![equation](http://www.sciweavers.org/upload/Tex2Img_1671655093/render.png)
Где x - вес Вашей фигуры, y - вес фигуры противника, дробь округляется математически.

Следовательно выгоднее бить более слабыми фигурами более сильные фигуры.
Ниже приведены все изменения веса Вашей фигуры при атаке фигур противника:


 | Противник | Вы | Цена вашей фигуры | 
 | - | - | - | 
 | 1 | 1 | 1 | 
 | 1 | 2 | 1 | 
 | 1 | 3 | 2 | 
 | 1 | 4 | 2 | 
 | 1 | 5 | 3 | 
 | * | * | * |
 | 2 | 1 | 2 | 
 | 2 | 2 | 2 |   
 | 2 | 3 | 2 | 
 | 2 | 4 | 3 |   
 | 2 | 5 | 3 | 
 |   |   |   |
 | 3 | 1 | 2 | 
 | 3 | 2 | 3 |   
 | 3 | 3 | 3 |  
 | 3 | 4 | 3 |   
 | 3 | 5 | 4 | 
 |   |   |   |
 | 4 | 1 | 3 |   
 | 4 | 2 | 3 |   
 | 4 | 3 | 4 |   
 | 4 | 4 | 4 |   
 | 4 | 5 | 4 | 
 |   |   |   |
 | 5 | 1 | 3 |   
 | 5 | 2 | 4 |   
 | 5 | 3 | 4 |   
 | 5 | 4 | 5 |   
 | 5 | 5 | 5 | 


Данные правила применимы ко всем фигурам, кроме короля. Если Ваш король находится в зоне хода фигуры противника вам нужно сделать ход в такую клетку, в которой король не находится в зоне атаки фигуры противника. Если Вы не сделаете такой ход - Вы можете проиграть, если Ваш соперник заметит победный ход.

#### Стартовый состав армии

- 1 Король
- 1 Ферзь
- 2 Слона
- 2 Ладьи
- 2 Коня
- 8 Пешек

<img src="images/12.png" title="" alt="" width="450">

## Описание проекта

Проект представляет собой Desktop-приложение (игра по мотивам Шахмат) написанное на языке программирования C++ с использованием фреймворка QT.

Проект подразумевает возможности:

1. Одновременной игры двух пользователей.

   Два пользователя могут вести игру друг с другом сидя за одним компьютером.

3. Оценки позиции игроков в реальном времени.

   Во время партии каждый из игроков может получить оценку своего шанса на победу, которая рассчитывается с учетом позиции фигур на игровом поле.

4. Ведения таблицы лидеров.

   После завершения партии игрокам будет предложено ввести свои имена для таблицы лидеров.

---
## Классы
Все классы представлены в [документации](https://mr-geri.github.io/chess/html/index.html).\
