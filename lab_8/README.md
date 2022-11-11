# Шаблонный класс полиномов
Используя как отправную точку класс полиномов из предыдущего задания, сделать его шаблонным, чтобы в качеcтве коэффициентов полиномов помимо простых типов int, double, могли выступать комплексные числа (std::complex), и [кватернионы](https://ru.wikipedia.org/wiki/%D0%9A%D0%B2%D0%B0%D1%82%D0%B5%D1%80%D0%BD%D0%B8%D0%BE%D0%BD), которые надо реализовать в  классе Quat. Для данного задания польская нотация не нужна, проверка всех методов классов осуществляется тестами.
## Входные данные:
Входные данные задаются непосредственно в программе в тестирующих функциях.
Коэффициенты полинома хранятся в std::vector по возрастающим степеням полинома начиная со свободного члена, как и в предыдущем задании. 
Пример для простых типов
```
std::vector<double> vd {1., 2., 3.}; // 1 + 2*x + 3*x^2
```
Пример для std::complex
```
std::vector<std::complex<double>> vc {{1., 2.}, {3., 4.}, {5., 6.}}; 
// где {1.,2.} вещественная и мнимая часть
```
Пример для класса Quat, который вы должны реализовать
```
std::vector<Quat> vq {{1., 2., 3., 4.}, {5., 6., 7., 8.}}; 
// где {1., 2., 3., 4.} четыре числа задающие кватернион
```
## Выходные данные:
После проведения операций сложения, вычетания или умножения полиномов с коэффициентами произвольного типа на выход должен возвращаться массив с соответствующими коэффициэнтами полученного полинома, его можно хранить опять же, например, в std::vector

## Тесты
Все входные данные задаются в тестах, там же проверяются выходные данные в соответствии с ожидаемым результатом. Можно использовать как Gtest, так и прстой вывод cout c информацией о результатах тестирования, которое можно делать, например, обычными assert(). 

## Функционал, который должен быть реализован в программе
1). Создать свой класс Quat, котрый также можно сделать шаблонным, но 
это не является обязательным, можно ограничиться только кватернионами типа double. В данном классе надо определить операторы +, -, * (умножение кватернионов, а  также умножение кватерниона на число.) 
Определить оператор вывода в стандартный поток <<, чтобы кватернион можно было выводить в консоль привычным способом cout << quat << endl;
```
(1, [2, 3, 4]) // 1 - "скалярная" часть кватерниона, [2, 3, 4] - "векторная"
```
2). Cоздать шаблонный класс Poly, который может быть как простого типа int, double, так и std::complex, Quat.  Определить операторы +, -, * для полиномов (их можно взять из предыдущего задания). Операторы дифференцирования и интегрирования полиномов можно здесь не реализовывать.

3). Необходимо реализовать специализированный шаблон (см. лекции) вывода в консоль полиномов с коэффициентами из кватернионов, который будет переопределять вывод в стандартный поток (консоль) полиномов в случае вещественных коэффициентов (дожлжен быть уже реализован в предыдущем задании).
Резюмируя, если полиномы с вещественныими коэффициентами - вывод в консоль такого полинома выгдлядит следующим образом.
```
[3, 4, 5, 6] 
```
Если полиномы с кватернионами в качестве коэффициентов, предлагается их 
выводить в следующем виде. 
```
{(1, [2, 3, 4]); (6, [7, 8, 9]); (10, [11, 12, 13])}

```
Заметим, что вывод самого кватерниона в виде (1, [2, 3, 4]) уже определён в классе Quat в пункте 1 выше.

4). Так как шаблонный класс Poly имеет конечное число возможных типов (int, double, float, std::complex, Quat) определения класса можно сделать в .h файле, а реализацию в .сpp файле. Либо шаблонный класс надо полность делать в .h файле (смотрите лекции).