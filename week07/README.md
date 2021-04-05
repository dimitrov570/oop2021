# Потоци
### Стандартни потоци
- за вход (`stdin`)
- за изход (`stdout`)
- за грешка (`stderr`)

### Функции за проверка за състоянието на потока (връщат `true` ако съответният бит е вдигнат):
- `bool good()`
- `bool eof()`
- `bool fail()`
- `bool bad()`
- `iostate rdstate()`

`clear(iostate state = goodbit)` променя стойността на всички флагове да бъде `state`, което по подрзабиране е `goodbit`, което е 0.

Повече информация [тук](http://www.cplusplus.com/reference/ios/ios/).

### Пренасочване на вход от файл
`./main < input.txt`
### Пренасочване на изход към файл
`./main > output.txt`
### Пренасочване на поток за грешки към файл
`./main 2> err.txt`

# Файлове
- метаданни
- разширения
- file command
- ifstream
- ofstream
- fstream

### Методът `open`
Отваря файл с име `filename`.  
- `void open(const char *filename, ios_base::openmode mode);`  

`mode` може да приема следните стойности:
- app
- binary
- in
- out
- trunc
- ate

### ifstream
Поток за четене от файл.  
`open(const char *filename, ios_base::openmode mode = `**ios_base::in**`);`

### ofstream
Поток за писане върху файл.
`open(const char *filename, ios_base::openmode mode = `**ios_base::out**`);`

### fstream
Поток за четене от и писане върху файл.
`open(const char *filename, ios_base::openmode mode = `**ios_base::in** `|` **ios_base::out**`);`

### Повече информация може да намерите на следните адреси
- [istream](https://en.cppreference.com/w/cpp/io/basic_istream)
- [ostream](https://en.cppreference.com/w/cpp/io/basic_ostream)
- [ifstream](https://en.cppreference.com/w/cpp/io/basic_ifstream)
- [ofstream](https://en.cppreference.com/w/cpp/io/basic_ofstream)
- [fstream](https://en.cppreference.com/w/cpp/io/basic_fstream)

## Задача
Напишете програма, която чете от текстов файл `input.txt` рационални числа, пресмята тяхното произведение и го извежда на стандартния изход. Използвайте класа `Rational` от упражненията. На първия ред във входния файл се намира `N` - броя на рационалните числа и след това `N` реда с едно рационално число на всеки ред. 

### Бонус
- Нека програмата прочетените данни от текстовия файл запише във бинарен файл с име `rationals.bin`.
- Пазете си историята на сметките в един файл с име `calculations.txt` във формат `r1 * r2 * ... * rN = result` на всеки ред, където `r1` до `rN` са `N`-те прочетени числа от файла, а `result` е резултата от изчислението. Обърнете внимание, че всеки път, трябва да се пише в края на файла.