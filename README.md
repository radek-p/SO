
Repozytorium zawiera pliki, które były wykorzystywane podczas 2. i 3. laboratorium dot. asemblera.

## Debugowanie asemblera

### CLion

`CMakeLists.txt` jest napisany tak, żeby istniała możliwość podglądu instrukcji asemblera w debuggerze programu CLion.
Obsługa debuggera jest raczej standardowa.

### GDB
Inną możliwością jest użycie GDB.
W tym celu kompilujemy program, po czym uruchamiamy GDB:

#### 1. Uruchamianie GDB:

	$ gdb <nazwa pliku wykonywalnego>

Przydatne komendy:
        

 - `layout split` -- włącza widok kodu źródłowego i instrukcji asemblera
 - `layout regs`  -- zamiast kodu źródłowego wyświetla wartości rejestrów

 - `focus next` -- przełącza focus na następne w kolejności okienko (kod źródłowy/asembler/prompt gdb). Dzięki temu można strzałkami w górę/dół przewijać ich zawartość.

 Jest wiele innych wariantów użycia komendy focus, dlatego przyda się:
  - `help <nazwa komendy>` -- wyświetla możliwe warianty polecenia `<nazwa komendy>`, np. `help focus`

#### 2. Dodawanie breakpointów i uruchamianie programu:
 - `break <numer linii w kodzie źródłowym>` -- ustawia breakpoint w danej linii kodu źródłowego
 - `break *main+14` -- ustawia breakpoint na instrukcji asemblera o podanym adresie, np. `main+14`. Adresy podane są po lewej stronie widoku asemblera; przyda się `help break`.
 - `run` -- rozpoczyna wykonywanie programu. Można podać argumenty wywołania (tak jak przy normalnym uruchamianiu z Basha).
 - `step`, `s` -- przejdź o jedną linię w kodzie źródłowym
 - `stepi`, `si` -- przejdź o jedną instrukcję asemblera
 - `<naciśnięcie klawisza enter bez wpisywania polecenia>` -- powtórz ostatnie polecenie, np. `s` lub `si`

#### 3. Śledzenie wartości zmiennych i rejestrów:
 - `watch <dowolne wyrażenie w składni podobnej do C, które może używać rejestrów>` -- oblicza wartość podanego wyrażenia po każdej komendzie `s`/`si` i wypisuje ją, jeśli się zmieniła: np. `watch $rbp`, `watch *($rbp)`.

GDB ma bardzo dużo innych przydatnych komend, dlatego warto spojrzeć na listę najprzydatniejszych (google: "gdb cheatsheet").
Pierwszy z brzegu link: https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf

Warto nauczyć się, jak podglądać zawartość pamięci na stercie oraz na stosie.



