# Состав команды

Камкин Илья - проектировщик

Стебенев Павел - разработчик

Шишкина Алина - разработчик

Дадонов Александр - тестировщик

Беляев Максим - тестировщик

# Шахматы

## Основные правила

Игра происходит на доске, поделённой на равные квадратные клетки, или поля. Размер доски — 8×8 клеток. Вертикальные ряды полей (вертикали) обозначаются латинскими буквами от а до h слева направо, горизонтальные ряды (горизонтали) — цифрами от 1 до 8 снизу вверх; каждое поле обозначается сочетанием соответствующих буквы и цифры. Поля раскрашены в тёмный и светлый цвета (и называются, соответственно, чёрными и белыми) так, что соседние по вертикали и горизонтали поля раскрашены в разные цвета. Доска располагается так, чтобы ближнее угловое поле справа от игрока было белым (для белых это поле h1, для чёрных — поле а8).

У игроков в начале игры имеется по одинаковому набору фигур. Фигуры одного из игроков условно называются «белыми», другого — «чёрными». Белые фигуры окрашены в светлый цвет, чёрные — в тёмный. Сами игроки называются «белые» и «чёрные» по цвету своих фигур.

Игра заключается в том, что игроки поочерёдно делают ходы. Первый ход делают белые. За исключением взятия на [проходе](#проход) и [рокировки](#рокировки). Ход заключается в том, что игрок перемещает одну из своих фигур на другое поле по [правилам](#ходы).

### Типы фигур

1. [Король](#король) (♔, ♚)
2. [Ферзь](#ферзь) (♕, ♛)
3. [Слон](#слон) (♗, ♝)
4. [Ладья](#ладья) (♖, ♜)
5. [Конь](#конь) (♘, ♞)
6. [Пешка](#пешка) (♙, ♟)

### Ходы

- Фигуры (кроме [коня](#конь)) передвигаются по прямой линии, при этом все промежуточные поля между начальным и конечным должны быть свободны (на них не должно быть своих или чужих фигур). Исключением является ход [коня](#конь).
- Ход на поле, занятое своей фигурой, невозможен.
- При ходе на поле, занятое чужой фигурой, она снимается с доски (взятие).

#### Король

<img src="images/2.jpg" title="" alt="" width="538">

#### Ферзь

<img src="images/1.jpg" title="" alt="" width="538">

#### Слон

<img src="images/5.jpg" title="" alt="" width="538">

#### Ладья

<img src="images/3.jpg" title="" alt="" width="538">

#### Конь

<img src="images/4.jpg" title="" alt="" width="538">

#### Пешка

Ходы пешки:

<img src="images/6.jpg" title="" alt="" width="538">

Взятие пешкой фигур противника:

<img src="images/7.jpg" title="" alt="" width="538">

Взятие на проходе:

<img src="images/8.jpg" title="" alt="" width="538">

#### Рокировки

Если король и одна из ладей того же цвета не двигались с начала игры, то король и эта ладья могут в один ход одновременно сменить положение (рокироваться). При рокировке король сдвигается на две клетки по направлению к ладье, а ладья ставится на поле между начальной и конечной позицией короля. Рокировка невозможна, если король или соответствующая ладья уже ходили. Рокировка временно невозможна, если между королём и ладьёй находится какая-либо фигура, а также если поле, на котором стоит король, или поле, которое он должен пересечь, или поле, которое он должен занять, находится под ударом одной из фигур противника.

##### Длинная
Длинная рокировка делается ходом влево. Король становится на С1, а ладья на D1.
<img src="images/9.jpg" title="" alt="" width="538">

##### Короткая
Короткая рокировка делается ходом вправо, король делает шаг на 2 клетки. Король становится на G1, а ладья на F1.
<img src="images/10.jpg" title="" alt="" width="538">
<img src="images/11.jpg" title="" alt="" width="538">

#### Проход

Когда пешка совершает ход на две клетки через поле, находящееся под ударом пешки противника, то ответным ходом она может быть взята этой пешкой противника. При этом пешка противника перемещается на битое поле, а взятая пешка снимается с доски (пример см. на диаграмме). Взятие на проходе возможно только непосредственно в ответ на ход пешки через битое поле, на следующих ходах оно уже не разрешено.

В начальной позиции фигуры обеих сторон размещаются так, как показано на диаграмме. Белые занимают первую и вторую горизонтали, чёрные — седьмую и восьмую. Пешки расположены на второй и седьмой горизонталях соответственно. Фигуры на крайних горизонталях располагаются следующим образом: Слон, Конь, Ладья, Ферзь, Король, Ладья, Конь, Слон.

#### Превращение пешки

Одно из правил шахматной игры: замена пешки, достигшей последней горизонтали (восьмой для белых, первой для чёрных), любой (кроме короля) фигурой того же цвета по выбору игрока, совершающего ход. Производится немедленно (тем же ходом) независимо от наличия на доске фигур того же наименования; таким образом, на доске может оказаться более одного ферзя данного цвета, более двух ладей, слонов или коней.

#### Стартовый состав армии

- 1 Король
- 1 Ферзь
- 2 Слона
- 2 Ладьи
- 2 Коня
- 8 Пешек

<img src="images/12.jpg" title="" alt="" width="538">

## Описание проекта

Проект представляет собой Desktop-приложение (игра Шахматы) написанное на языке программирования C++ с использованием фреймворка QT. 

Проект подразумевает возможности: 

1. Одновременной игры двух пользователей.
   
   Два пользователя могут вести игру друг с другом сидя за одним компьютером.

2. Игры одного пользователя с шахматным ботом с выбором уровня сложности.
   
   В проекте реализуется шахматный движок, просчитывающий ходы и выбирающий лучшие по определенным критериям. Уровень сложности зависит от глубины на которую просчитываются ходы.

3. Оценки позиции игроков в реальном времени.
   
   Во время партии каждый из игроков может получить оценку своего шанса на победу, которая рассчитывается с учетом позиции фигур на игровом поле.

4. Ведения таблицы лидеров.
   
   Перед началом партии игрокам будет предложено ввести свои имена для таблицы лидеров.

---
## Структура классов
1. QMainWindow::Game
2. Bot
3. QGraphicsView::Board
4. QGraphicsItem::Figure
5. QMediaPlayer
   1. Music
   2. Sound
6. QTableView
   1. Junior
   2. Middle
   3. Senior
7. QTimer
   1. FirstPlayer
   2. SecondPlayer

В структуре описаны основные классы и функции, которые не реализованы Qt.

---
## Функции классов

### QMainWindow::Game
#### end_game
Поражение (мат) одного игрока и победа другого.
Выигравшему игроку начисляются победные очки, с занесением в таблицу лидеров.
Если побеждает бот, то уровень его сложности (junior, middle, senior) так же заносится в таблицу лидеров, с начислением очков.

#### start
Начало игры.
Раставляются фигуры по полю, право первого хода за белыми фигурами.
Запуск таймера (30 минут для каждого игрока).

#### reload_lider_board
Обновление таблицы лидеров. Вызывается при добавлении записи в таблицу лидеров.

#### position_evaluation
Оценка текущей позиции и сохранение полученной оценки.

#### saving_move
Сохранение хода игрока.

#### change_active_player
Вызывается после завершения игроком хода.
Переключает текущего игрока и таймеры.

---
### Bot
#### get_move(depth)
Поиск лучшего хода с глубиной поиска depth.

---
### QGraphicsView::Board
#### draw
Отрисовка всех элементов интерфейса и поля на экране.

#### draw_hint
Отрисовывает возможные ходы фигуры.

---
### QGraphicsItem::Figure
#### move
Изменение значений координат фигуры.

#### change_type
Изменение типа фигуры.
Используется для пешек.

---
### QMediaPlayer Music и QMediaPlayer Sound
Объекты класса библиотеки Qt.
Используются для воспроизведения фоновой музыки и звуков игры.

---
### QTableView Junior, QTableView Middle и QTableView Senior
Объекты класса QTableView библиотеки Qt, используемые для отображения таблиц лидеров.

---
### QTimer FirstPlayer и QTimer SecondPlayer
Объекты класса библиотеки Qt, отвечающие за таймеры игроков.
