# Задание 5: Создание связанных списков и удаление элементов из них

Необходимо создать связанный список в куче (heap) с использованием структур языка С++, научиться итерироваться по ним и удалять элементы из списка.

## Входные данные:
Текстовый файл содержащий произвольные целые числа, где последнее число - это то число, которое надо удалить из списка.

Пример data.txt
```
1
3
2
4
3
2
3 // данное число надо удалить из списка
```
Рассмотреть все предельные случае: удаляемого числа нет в списке, весь список состоит из одного и того же числа, которое надо удалить.
## Выходные данные:
Вывод в консоль списка поссле удаления.

Для примера из входных данных:
```
1 2 4 2
```
Для предельного случая, когда список состоит из одного и того числа, которое надо удалить, например, для списка {3, 3, 3, 3} полсе удаления всех троек получаем пустой спсисок {}, надо вывести сообщение:
```
Linked list is empty
```

## Запуск программы

```
$ program_name.exe data.txt
```
## Элементы языка С++, которые могут пригодиться
1). Создать структуру, которая будет представлять собой один узел (Node) связанного списка. В ней должно быть два поля: int data, которое хранит значение данных, и Node* pnext, пойнтер к следующему узлу. Опционально в структуре может быть конструктор для более удобной инициализации.

2). Все структуры Node создаются в куче (heap). Пойнтер который указывает на начало связанно списка (на head) хранится в стеке.

3). Пойнтер в самом конце списка указывает в "никуда", поэтому можно использовать nullptr для этих целей. Также nullptr удобен при реализации цикла итерирующего по листу (последний узел в спсике имеет значение nullptr).

4). Организация программы может быть сделана на ваш вкус, но так или иначе должна быть реализована следующая функциональность.
```
addNode() // добавляет узел к концу существующего списка
printLinkedList() // отображает содержимое списка в консоль
deleteElement() // удаляет требуемый элемент из списка
```
