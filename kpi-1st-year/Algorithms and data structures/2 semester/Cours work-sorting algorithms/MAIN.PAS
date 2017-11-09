Program CourseWork; {Головна програма}
Uses Crt, Tests, Algs,Common,ArrTemU,ArrInit, ArrUnit, Gr;
var inp:byte;{Змінна для збереження вводу у меню}
    i:integer{del};
    orderedTime,{Час роботи впорядкованого масиву}
    randomTime,{Час роботи невпорядкованого масиву}
    backOrderedTime,{Час роботи обернено впорядкованого масиву}
    sortingTime:LongInt;{Загальний час сортування}
begin
firstScreen;{Запуск заставки}
  while true do
  begin
    clrscr;
    writeln('----------------------');
    writeln('Algorytmy sortuvannya: ');
    writeln('----------------------');
    writeln('1. Vector ');
    writeln('2. 3D masyv ');
    writeln('3. Testy ');
    writeln('4. Vyhid ');
    readln(inp); {Зчитування вводу}
    if inp = 1 then
      begin
        while true do
        begin
          clrscr;
          writeln('----------------------');
          writeln('Vector ',N_VECTOR,' elementiv:');
          writeln('----------------------');
          writeln('1. Vstavka #1 ');
          writeln('2. Vybir #7 ');
          writeln('3. Obmin #4 (sheikerne)'); 
          writeln('4. Shvydke sortuvannya'); 
          writeln('5. Paketnyj zapusk ');
          writeln('6. Nazad ');
            read(inp);{Зчитування вводу}
            case inp of
            1:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A);{Створення впорядкованого вектору}
                 orderedTime:=sortVector(1);{Сортування вектору алгоритмом №1}

                 createRandVect(A); {Створення невпорядкованого вектору}
                 randomTime:=sortVector(1); {Сортування вектору алгоритмом №1}
                 
                 createBackOrderedVect(A);  {Створення обернено впорядкованого вектору}
                 backOrderedTime:=sortVector(1); {Сортування вектору алгоритмом №1}
                 
                 singleTableOutput('Vstavka #1',orderedTime,randomTime,backOrderedTime );{Виведення таблиці результатів}
                 
              end;
            2:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A);{Створення впорядкованого вектору}
                 orderedTime:=sortVector(2);

                 createRandVect(A);{Створення невпорядкованого вектору}
                 randomTime:=sortVector(2);
                 
                 createBackOrderedVect(A);{Створення обернено впорядкованого вектору}
                 backOrderedTime:=sortVector(2);
                 
                 singleTableOutput('Vybir #7',orderedTime,randomTime,backOrderedTime );{Виведення таблиці результатів}
              end;
            3:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A); {Створення впорядкованого вектору}
                 orderedTime:=sortVector(3);

                 createRandVect(A); {Створення невпорядкованого вектору}
                 randomTime:=sortVector(3);
                 
                 createBackOrderedVect(A);{Створення обернено впорядкованого вектору}
                 backOrderedTime:=sortVector(3);
                 {Виведення таблиці результатів}
                 singleTableOutput('Obmin #4(sheikerne)',orderedTime,randomTime,backOrderedTime );

              end; 
            4:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A);{Створення впорядкованого вектору}
                 orderedTime:=sortVector(4);

                 createRandVect(A);{Створення невпорядкованого вектору}
                 randomTime:=sortVector(4);
                 
                 createBackOrderedVect(A);{Створення обернено впорядкованого вектору}
                 backOrderedTime:=sortVector(4);
                 {Виведення таблиці результатів}
                 singleTableOutput('Shvydke sortuvannya',orderedTime,randomTime,backOrderedTime );

              end; 
             5:begin
                 writeln('Sortuvannya, zachekayte ...');
                 with res do
                 begin
                  title:='Paketnyj zapusk vektoriv';
                  name1:='Vstavka #1';
                  name2:='Vybir #7 ';
                  name3:='Obmin #4(sheik)';
                  name4:='Shvydke sort';
                     createOrderedVect(tempVect);{Створення впорядкованого допоміжного вектору вектору}
                     copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     sorted1:=sortVector(1);{Сортування вектору алгоритмом №1}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     sorted2:=sortVector(2); {Сортування вектору алгоритмом №2}
                      copyVector(tempVect,A){Скопіювати значення у масив, що сортується};
                     sorted3:=sortVector(3); {Сортування вектору алгоритмом №3}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     sorted4:=sortVector(4);  {Сортування вектору алгоритмом №4}
                     
                      createRandVect(tempVect);{Створення випадкового допоміжного вектору вектору}
                     copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     rand1:=sortVector(1);{Сортування вектору алгоритмом №1}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     rand2:=sortVector(2); {Сортування вектору алгоритмом №2}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                    rand3:=sortVector(3); {Сортування вектору алгоритмом №3}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     rand4:=sortVector(4); {Сортування вектору алгоритмом №4}
                     
                      createBackOrderedVect(tempVect);{Створення обернено впорядкованого допоміжного вектору вектору}
                     copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     backSorted1:=sortVector(1);{Сортування вектору алгоритмом №1}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     backSorted2:=sortVector(2);{Сортування вектору алгоритмом №2}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     backSorted3:=sortVector(3);{Сортування вектору алгоритмом №3}
                      copyVector(tempVect,A);{Скопіювати значення у масив, що сортується}
                     backSorted4:=sortVector(4);{Сортування вектору алгоритмом №4}
                     packageOutput(res);{Виведення таблиці результатів}
                     
                     
                     
                 end;
              end;   
            6:begin 
                break;{Перехід назад}
              end;
            end;  
        end;
      end;
    if inp = 2 then
      begin
          while true do
        begin
          clrscr;
          writeln('----------------------');
          writeln('3D massiv ',P_3D,'x', M_3D,'x',N_3D,' elementiv:');
          writeln('----------------------');
          writeln('1. Vstavka #1 ');
          writeln('2. Vybir #7 ');
          writeln('3. Obmin #4 (sheikerne)'); 
          writeln('4. Shvydke sortuvannya'); 
          writeln('5. Paketnyj zapusk ');
          writeln('6. Nazad ');
            read(inp);
            case inp of
            1:
              begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrdered3D(arr);{Створення впорядкованого масиву}
                 orderedTime:=sort3D(1,arr);;{Сортування масиву алгоритмом №1}

                 createRand3D(arr);{Створення випадковго масиву}
                 randomTime:=sort3D(1,arr); {Сортування масиву алгоритмом №1}
                 
                 createBackOrdered3D(arr);{Створення обернено впорядкованого масиву}
                 backOrderedTime:=sort3D(1,arr);{Сортування масиву алгоритмом №1}
                 
                 singleTableOutput('Vstavka #1',orderedTime,randomTime,backOrderedTime );{Виведення таблиці результатів}
             
              end;
            2:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrdered3D(arr); {Створення впорядкованого масиву}
                 orderedTime:=sort3D(2,arr);{Сортування масиву алгоритмом №2}

                 createRand3D(arr);{Створення випадковго масиву}
                 randomTime:=sort3D(2,arr);{Сортування масиву алгоритмом №2}
                 
                 createBackOrdered3D(arr);{Створення обернено впорядкованого масиву}
                 backOrderedTime:=sort3D(2,arr);{Сортування масиву алгоритмом №2}
                 
                 singleTableOutput('Vybir #7',orderedTime,randomTime,backOrderedTime );{Виведення таблиці результатів}
              end;
            3:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrdered3D(arr); {Створення впорядкованого масиву}
                 orderedTime:=sort3D(3,arr);{Сортування масиву алгоритмом №3}

                 createRand3D(arr);{Створення випадковго масиву}
                 randomTime:=sort3D(3,arr);{Сортування масиву алгоритмом №3}
                 
                 createBackOrdered3D(arr);{Створення обернено впорядкованого масиву}
                 backOrderedTime:=sort3D(3,arr);{Сортування масиву алгоритмом №3}
                 
                 singleTableOutput('Obmin #4(sheiker)',orderedTime,randomTime,backOrderedTime );{Виведення таблиці результатів}
              end;
            4:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrdered3D(arr);{Створення впорядкованого масиву}
                 orderedTime:=sort3D(4,arr);{Сортування масиву алгоритмом №4}

                 createRand3D(arr); {Створення випадковго масиву}
                 randomTime:=sort3D(4,arr);{Сортування масиву алгоритмом №4}
                 
                 createBackOrdered3D(arr);{Створення обернено впорядкованого масиву}
                 backOrderedTime:=sort3D(4,arr);{Сортування масиву алгоритмом №4}
                 
                 singleTableOutput('Shvydke sort',orderedTime,randomTime,backOrderedTime );{Виведення таблиці результатів}
              end;
            5:begin
                 writeln('Sortuvannya, zachekayte ...');
                 with res do
                 begin
                  title:='Paketnyj zapusk 3D masyviv';
                  name1:='Vstavka #1';
                  name2:='Vybir #7 ';
                  name3:='Obmin #4(sheik)';
                  name4:='Shvydke sort';
                     createOrdered3D(arrTemp);{Створення впорядкованого допоміжного масиву}
                     copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     sorted1:=sort3D(1,arr);{Сортування масиву алгоритмом №1}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     sorted2:=sort3D(2,arr); {Сортування масиву алгоритмом №2}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     sorted3:=sort3D(3,arr); {Сортування масиву алгоритмом №3}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     sorted4:=sort3D(4,arr);{Сортування масиву алгоритмом №4}
                     
                      createRand3D(arrTemp); {Створення випадковго допоміжного масиву}
                     copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     rand1:=sort3D(1,arr);{Сортування масиву алгоритмом №1}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     rand2:=sort3D(2,arr);{Сортування масиву алгоритмом №2}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     rand3:=sort3D(3,arr); {Сортування масиву алгоритмом №3}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     rand4:=sort3D(4,arr);{Сортування масиву алгоритмом №4}
                     
                      createBackOrdered3D(arrTemp);{Створення обернено впорядкованого допоміжного масиву}
                    copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     backSorted1:=sort3D(1,arr);{Сортування масиву алгоритмом №1}
                      copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     backSorted2:=sort3D(2,arr);{Сортування масиву алгоритмом №2}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     backSorted3:=sort3D(3,arr);{Сортування масиву алгоритмом №3}
                       copyArray(arrTemp,arr);{Скопіювати значення у масив, що сортується}
                     backSorted4:=sort3D(4,arr);{Сортування масиву алгоритмом №4}
                      packageOutput(res);{Виведення таблиці результатів}
                     
                     
                 end;
              end;     
            6:begin 
                break;{Перехід назад}
              end;
            end;  
        end;
       
      end;
    if inp = 3 then
       begin
          testAlgs;{Запуск тестування алгоритмів}
       end;  
    if inp = 4 then
       begin
          halt;{Вихід з програми}
       end;
       {inp:=-1;}
  end;     
end.
