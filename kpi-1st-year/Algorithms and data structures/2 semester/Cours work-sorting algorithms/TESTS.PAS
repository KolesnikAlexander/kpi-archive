Unit Tests;{Модуль для тестування коректності роботи алгоритмів}
Interface
Uses Crt, Common, ArrInit, Algs, ArrUnit;
procedure testAlgs;
Implementation
procedure testAlgs;
var
    res:packOutRec;
    typeOfArray,sortingNum,caseOfSort:integer;
begin
 while true do
  begin
    clrscr;
    writeln('1. Vector ');
    writeln('2. 3D masyv ');
    writeln('3. Nazad ');
    readln(typeOfArray);
    if typeOfArray = 3 then break;
while true do
  begin
    clrscr;
          writeln('1. Vstavka #1 ');
          writeln('2. Vybir #7 ');
          writeln('3. Obmin #4 (sheikerne)'); 
          writeln('4. Shvydke sortuvannya');
          writeln('5. Nazad ');
    readln(sortingNum);
    if sortingNum = 5 then break;
        while true do
        begin
          clrscr;
          writeln('1. Vporiadkovanyj ');
          writeln('2. Nevporiadkovanyj ');
          writeln('3. Oberneno vporiadkovanyj'); 
          writeln('4. Nazad ');
            read(caseOfSort);
             if caseOfSort = 4 then break;
            case caseOfSort of
            1:begin
            if typeofArray = 2 then
            begin
                 createOrdered3D(arr);
                 sort3D(caseOfSort,arr);
                 printArray3D(arr);
                  readln;
                  readln;
             end
             else
             begin
                    createOrderedVect(A);
                    sortVector(sortingNum);
                    printVector(A);
                    readln;
                    readln;
             end;
            end;

            
                 
            2:begin
            if typeofArray = 2 then
            begin
                 createRand3D(arr);
                 sort3D(caseOfSort,arr);
                 printArray3D(arr);
                  readln;
                  readln;
              end
            else
             begin
                    createRandVect(A);
                    sortVector(sortingNum);
                    printVector(A);
                    readln;
                    readln;
             end;
              end;
            3:begin
            if typeofArray = 2 then
            begin
                createBackOrdered3D(arr);
                 sort3D(caseOfSort,arr);
                 printArray3D(arr);
                  readln;
                  readln;
             end
              else
                begin
                    createBackOrderedVect(A);
                    sortVector(sortingNum);
                    printVector(A);
                    readln;
                    readln;
                end;
              end; 
         
           end; 
          
        end;   
end;
end;
end;
begin
end.

  