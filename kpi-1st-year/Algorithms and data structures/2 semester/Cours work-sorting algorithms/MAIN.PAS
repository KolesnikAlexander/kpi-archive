Program CourseWork; {������� ��������}
Uses Crt, Tests, Algs,Common,ArrTemU,ArrInit, ArrUnit, Gr;
var inp:byte;{����� ��� ���������� ����� � ����}
    i:integer{del};
    orderedTime,{��� ������ �������������� ������}
    randomTime,{��� ������ ���������������� ������}
    backOrderedTime,{��� ������ �������� �������������� ������}
    sortingTime:LongInt;{��������� ��� ����������}
begin
firstScreen;{������ ��������}
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
    readln(inp); {���������� �����}
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
            read(inp);{���������� �����}
            case inp of
            1:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A);{��������� �������������� �������}
                 orderedTime:=sortVector(1);{���������� ������� ���������� �1}

                 createRandVect(A); {��������� ���������������� �������}
                 randomTime:=sortVector(1); {���������� ������� ���������� �1}
                 
                 createBackOrderedVect(A);  {��������� �������� �������������� �������}
                 backOrderedTime:=sortVector(1); {���������� ������� ���������� �1}
                 
                 singleTableOutput('Vstavka #1',orderedTime,randomTime,backOrderedTime );{��������� ������� ����������}
                 
              end;
            2:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A);{��������� �������������� �������}
                 orderedTime:=sortVector(2);

                 createRandVect(A);{��������� ���������������� �������}
                 randomTime:=sortVector(2);
                 
                 createBackOrderedVect(A);{��������� �������� �������������� �������}
                 backOrderedTime:=sortVector(2);
                 
                 singleTableOutput('Vybir #7',orderedTime,randomTime,backOrderedTime );{��������� ������� ����������}
              end;
            3:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A); {��������� �������������� �������}
                 orderedTime:=sortVector(3);

                 createRandVect(A); {��������� ���������������� �������}
                 randomTime:=sortVector(3);
                 
                 createBackOrderedVect(A);{��������� �������� �������������� �������}
                 backOrderedTime:=sortVector(3);
                 {��������� ������� ����������}
                 singleTableOutput('Obmin #4(sheikerne)',orderedTime,randomTime,backOrderedTime );

              end; 
            4:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrderedVect(A);{��������� �������������� �������}
                 orderedTime:=sortVector(4);

                 createRandVect(A);{��������� ���������������� �������}
                 randomTime:=sortVector(4);
                 
                 createBackOrderedVect(A);{��������� �������� �������������� �������}
                 backOrderedTime:=sortVector(4);
                 {��������� ������� ����������}
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
                     createOrderedVect(tempVect);{��������� �������������� ���������� ������� �������}
                     copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     sorted1:=sortVector(1);{���������� ������� ���������� �1}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     sorted2:=sortVector(2); {���������� ������� ���������� �2}
                      copyVector(tempVect,A){��������� �������� � �����, �� ���������};
                     sorted3:=sortVector(3); {���������� ������� ���������� �3}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     sorted4:=sortVector(4);  {���������� ������� ���������� �4}
                     
                      createRandVect(tempVect);{��������� ����������� ���������� ������� �������}
                     copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     rand1:=sortVector(1);{���������� ������� ���������� �1}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     rand2:=sortVector(2); {���������� ������� ���������� �2}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                    rand3:=sortVector(3); {���������� ������� ���������� �3}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     rand4:=sortVector(4); {���������� ������� ���������� �4}
                     
                      createBackOrderedVect(tempVect);{��������� �������� �������������� ���������� ������� �������}
                     copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     backSorted1:=sortVector(1);{���������� ������� ���������� �1}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     backSorted2:=sortVector(2);{���������� ������� ���������� �2}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     backSorted3:=sortVector(3);{���������� ������� ���������� �3}
                      copyVector(tempVect,A);{��������� �������� � �����, �� ���������}
                     backSorted4:=sortVector(4);{���������� ������� ���������� �4}
                     packageOutput(res);{��������� ������� ����������}
                     
                     
                     
                 end;
              end;   
            6:begin 
                break;{������� �����}
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
                 createOrdered3D(arr);{��������� �������������� ������}
                 orderedTime:=sort3D(1,arr);;{���������� ������ ���������� �1}

                 createRand3D(arr);{��������� ���������� ������}
                 randomTime:=sort3D(1,arr); {���������� ������ ���������� �1}
                 
                 createBackOrdered3D(arr);{��������� �������� �������������� ������}
                 backOrderedTime:=sort3D(1,arr);{���������� ������ ���������� �1}
                 
                 singleTableOutput('Vstavka #1',orderedTime,randomTime,backOrderedTime );{��������� ������� ����������}
             
              end;
            2:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrdered3D(arr); {��������� �������������� ������}
                 orderedTime:=sort3D(2,arr);{���������� ������ ���������� �2}

                 createRand3D(arr);{��������� ���������� ������}
                 randomTime:=sort3D(2,arr);{���������� ������ ���������� �2}
                 
                 createBackOrdered3D(arr);{��������� �������� �������������� ������}
                 backOrderedTime:=sort3D(2,arr);{���������� ������ ���������� �2}
                 
                 singleTableOutput('Vybir #7',orderedTime,randomTime,backOrderedTime );{��������� ������� ����������}
              end;
            3:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrdered3D(arr); {��������� �������������� ������}
                 orderedTime:=sort3D(3,arr);{���������� ������ ���������� �3}

                 createRand3D(arr);{��������� ���������� ������}
                 randomTime:=sort3D(3,arr);{���������� ������ ���������� �3}
                 
                 createBackOrdered3D(arr);{��������� �������� �������������� ������}
                 backOrderedTime:=sort3D(3,arr);{���������� ������ ���������� �3}
                 
                 singleTableOutput('Obmin #4(sheiker)',orderedTime,randomTime,backOrderedTime );{��������� ������� ����������}
              end;
            4:begin
                 writeln('Sortuvannya, zachekayte ...');
                 createOrdered3D(arr);{��������� �������������� ������}
                 orderedTime:=sort3D(4,arr);{���������� ������ ���������� �4}

                 createRand3D(arr); {��������� ���������� ������}
                 randomTime:=sort3D(4,arr);{���������� ������ ���������� �4}
                 
                 createBackOrdered3D(arr);{��������� �������� �������������� ������}
                 backOrderedTime:=sort3D(4,arr);{���������� ������ ���������� �4}
                 
                 singleTableOutput('Shvydke sort',orderedTime,randomTime,backOrderedTime );{��������� ������� ����������}
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
                     createOrdered3D(arrTemp);{��������� �������������� ���������� ������}
                     copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     sorted1:=sort3D(1,arr);{���������� ������ ���������� �1}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     sorted2:=sort3D(2,arr); {���������� ������ ���������� �2}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     sorted3:=sort3D(3,arr); {���������� ������ ���������� �3}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     sorted4:=sort3D(4,arr);{���������� ������ ���������� �4}
                     
                      createRand3D(arrTemp); {��������� ���������� ���������� ������}
                     copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     rand1:=sort3D(1,arr);{���������� ������ ���������� �1}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     rand2:=sort3D(2,arr);{���������� ������ ���������� �2}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     rand3:=sort3D(3,arr); {���������� ������ ���������� �3}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     rand4:=sort3D(4,arr);{���������� ������ ���������� �4}
                     
                      createBackOrdered3D(arrTemp);{��������� �������� �������������� ���������� ������}
                    copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     backSorted1:=sort3D(1,arr);{���������� ������ ���������� �1}
                      copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     backSorted2:=sort3D(2,arr);{���������� ������ ���������� �2}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     backSorted3:=sort3D(3,arr);{���������� ������ ���������� �3}
                       copyArray(arrTemp,arr);{��������� �������� � �����, �� ���������}
                     backSorted4:=sort3D(4,arr);{���������� ������ ���������� �4}
                      packageOutput(res);{��������� ������� ����������}
                     
                     
                 end;
              end;     
            6:begin 
                break;{������� �����}
              end;
            end;  
        end;
       
      end;
    if inp = 3 then
       begin
          testAlgs;{������ ���������� ���������}
       end;  
    if inp = 4 then
       begin
          halt;{����� � ��������}
       end;
       {inp:=-1;}
  end;     
end.
