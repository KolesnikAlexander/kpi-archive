Unit ArrInit;{Модуль для роботи з масивами}

Interface
Uses Common, ArrUnit;
procedure createRand3D(var arr:Array3D);{Створення випадкового масиву}
procedure createOrdered3D(var arr:Array3D);{Створення впорядкованого масиву}
procedure createBackOrdered3D(var arr:Array3D);{Створення обернено впорядкованого масиву}
procedure createRandVect(var arr:TVector);{Створення випадкового вектору}
procedure createOrderedVect(var arr:TVector);{Створення впорядкованого вектору}
procedure createBackOrderedVect(var arr:TVector);{Створення обернено випадкового вектору}
procedure copyArray(var src,dst:Array3D);{Копіювання елементів з масиву src до масиву dst}
procedure copyVector(var src,dst:TVector);{Копіювання елементів з ветору src до вектору dst}
procedure printArray3D(var arr:Array3D);{Виведення масиву на екран}
procedure printVector(var vect:TVector);{Виведення вектору на екран}
Implementation
{Створення випадкового масиву}
procedure createRand3D(var arr:Array3D);
var i,j,k:integer; 
begin
randomize;
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do arr[i,j,k]:= random(MAX_RANDOM);
end;
{Створення впорядкованого масиву}
procedure createOrdered3D(var arr:Array3D);
var i,j,k,counter:integer; 
begin
counter:=1;
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do 
        begin
          arr[i,j,k]:= counter;
          counter:=counter+1;
        end;        
end;
{Створення обернено впорядкованого масиву}
procedure createBackOrdered3D(var arr:Array3D);
var i,j,k,counter:integer; 
begin
counter:=P_3D*N_3D*M_3D;
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do 
        begin
          arr[i,j,k]:= counter;
          counter:=counter-1;
        end;        
end;
{Створення випадковго вектору}
procedure createRandVect(var arr:TVector);
var i:integer; 
begin
  randomize;
    for i:=1 to N_VECTOR do arr[i]:= random(MAX_RANDOM);
end;
{Створення впорядкованого ветору}
procedure createOrderedVect(var arr:TVector);
var i:integer; 
begin
  randomize;
    for i:=1 to N_VECTOR do arr[i]:= i;
end;
{Створення обернено впорядкованого вектору}
procedure createBackOrderedVect(var arr:TVector);
var i:integer; 
begin
  randomize;
    for i:=1 to N_VECTOR do arr[i]:= N_VECTOR-i+1;
end;
{Копіювання елементів з масиву src до масиву dst}
procedure copyArray(var src,dst:Array3D);
var i,j,k:integer;   
begin
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do dst[i,j,k]:=src[i,j,k]; {Зчитуємо елемент з файлу у масив}  
      
end;
{Копіювання елементів з вектору src до вектору dst}
procedure copyVector(var src,dst:TVector);
var i:integer;   
begin
      for i:=1 to N_VECTOR do dst[i]:=src[i]; 
end;
{Виведення масиву на екран}
procedure printArray3D(var arr:Array3D);
var i,j,k:integer; 
begin
  randomize;
  for i:=1 to P_3D do 
    begin
      writeln(i, ' pereriz:');
       writeln('---------------');
       for j:=1 to M_3D do
       begin
          for k:=1 to N_3D do write(arr[i,j,k], '  ');
          writeln;
       end;   
      
    end;  
end;
{Виведення вектору на екран}
procedure printVector(var vect:TVector);
var i:integer; 
begin
  randomize;
  for i:=1 to N_VECTOR do write(vect[i]:8);
end;
begin
end.