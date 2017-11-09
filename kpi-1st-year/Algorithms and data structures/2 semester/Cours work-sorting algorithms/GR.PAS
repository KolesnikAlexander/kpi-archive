  Unit Gr;{Модуль виведення даних на екран}
Interface
Uses Common, Crt;
{Виведення заставки}
procedure firstScreen;
{Виведення результатів алгоритму}
procedure singleTableOutput(title:String;
                            sorted,
                            rand,
                            backSorted:LongInt);
{Виведення пакетного запуску}
procedure packageOutput(res:packOutRec);


Implementation
{Малює горизонтальну лінію}
procedure hor(x1,x2,y:integer);
var i,j:integer;
begin
  gotoxy(x1,y);
  for i:=x1 to x2 do write(#205);  
end;
{Малює вертикальну лінію}
procedure vert(x,y1,y2:integer);
var i,j:integer;
begin
  gotoxy(x,y1);
   for i:=y1 to y2 do
     begin
          gotoxy(x,i);write(#186);
     end;
end;
{Малює рамку лінію}
procedure frame(x1,y1,x2,y2:integer);
var i,j:integer;
begin
     gotoxy(x1,y1);
     write(#201);

     for i:=x1+1 to x2-1 do write(#205);
     write(#187);
     
        for i:=y1+1 to y2-1 do
     begin
          gotoxy(x1,i);write(#186);
          gotoxy(x2,i);write(#186);
     end;
    
     gotoxy(x1,y2);write(#200);
     for i:=x1+1 to x2-1 do write(#205);
     write(#189);

end;
{Виведення заставки}
procedure firstScreen;
begin
     clrscr;
     Frame(10,5,70,18);
     gotoxy(35,7);
     write('NTUU KPI');
     gotoxy(33,9);write('Kursova robota');
     gotoxy(35,11);write('Variant 5');
     {gotoxy(29,10);write('Naiprostisha grafika');}
     gotoxy(21,14);write('Vykonav Kolesnyk Oleksandr Sergiyovych');
     gotoxy(35,16);write('Kyiv 2016');
     gotoxy(28,20);write('Press any key to continue');
     readln;
     clrscr;

end;
{Виведення результатів алгоритму}
procedure singleTableOutput(title:String;sorted,rand,backSorted:LongInt);
begin
clrscr;
gotoxy(33,3);
write(title);
Frame(10,5,70,13);
hor(11,69,9);
vert(30,5,12);
vert(50,5,12);
gotoxy(12,7);
write('Vporiadkovanyj');
gotoxy(34,7);
write('Ne vporiadkovanyj');
gotoxy(52,7);
write('Oberneno vpor');

gotoxy(12,11);
write(sorted);

gotoxy(34,11);
write(rand);
gotoxy(52,11);
write(backSorted);
readln;
readln;

end;
{Малює рамку таблиці}
procedure packageTable;
begin
clrscr;
Frame(2,5,78,25);

hor(3,77,9);
hor(3,77,13);
hor(3,77,17);
hor(3,77,21);
vert(20,5,24);
vert(39,5,24);
vert(58,5,24);
gotoxy(23,7);
write('Vporiadkovanyj');
gotoxy(43,7);
write('Ne vporiadkovanyj');
gotoxy(60,7);
write('Oberneno vpor');
end;
{Виведення пакетного запуску}
procedure packageOutput(res:packOutRec);
begin
  packageTable;
  with res do
    begin
    gotoxy(35,3);
    write(title);
    
    gotoxy(4,11);
    write(name1);
    gotoxy(25,11);
    write(sorted1);
    gotoxy(43,11);
    write(rand1);
    gotoxy(62,11);
    write(backSorted1);
    
     gotoxy(4,15);
    write(name2);
    gotoxy(25,15);
    write(sorted2);
    gotoxy(43,15);
    write(rand2);
    gotoxy(62,15);
    write(backSorted2);
    
     gotoxy(4,19);
    write(name3);
    gotoxy(25,19);
    write(sorted3);
    gotoxy(43,19);
    write(rand3);
    gotoxy(62,19);
    write(backSorted3);
    
       gotoxy(4,23);
    write(name4);
    gotoxy(25,23);
    write(sorted4);
    gotoxy(43,23);
    write(rand4);
    gotoxy(62,23);
    write(backSorted4);
    readln;
    readln;
    end;
end;
begin
end.
  
