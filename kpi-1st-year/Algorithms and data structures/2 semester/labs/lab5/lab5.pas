Program nonLinkedDS;
Uses crt;
Const m1 = 5; n1 = 6;
      m2 = 7; n2 = 4;
      k = 15;
Type
    Matrix1 = array[1..m1,1..n1] of integer;
    Matrix2 = array[1..m2,1..n2] of integer;
    PMatrix1 = ^Matrix1;
    PMatrix2 = ^Matrix2;
Var
    mat1:PMatrix1;
    mat2:PMatrix1;
procedure input(p:pointer;m,n:integer;matNum:byte);
var 
  i,j:integer;
begin
randomize;
case matNum of 
1:
    begin
        for i:= 1 to m do
          for j:= 1 to n do
            begin
                PMatrix1(p)^[i,j]:=random(201)-100;
            end;
    end; 
2:
    begin
        for i:= 1 to m do
          for j:= 1 to n do
            begin
                PMatrix2(p)^[i,j]:=random(201)-100;
            end;
    end;
end;
end;
procedure output(p:pointer;m,n:integer;matNum:byte);
var 
  i,j:integer;
begin
randomize;
case matNum of 
1:
    begin
        for i:= 1 to m do
        begin
          for j:= 1 to n do
            write(PMatrix1(p)^[i,j], ' ');
          writeln; 
         end;   
    end; 
2:
     begin
        for i:= 1 to m do
        begin
          for j:= 1 to n do
            write(PMatrix2(p)^[i,j], ' ');
          writeln; 
         end;   
    end; 
end;
end;
function check(p:pointer;m,n:integer;matNum:byte):integer;
var
  i,j,counter:integer;
begin

case matNum of
1:
    begin
       counter:= 0;
        for i:= 1 to m do
          for j:= 1 to n do
            if odd(i+j) and (PMatrix1(p)^[i,j] > k) then
               counter:=counter+1;
    end;
2:
    begin
       counter:= 0;
        for i:= 1 to m do
          for j:= 1 to n do
            if odd(i+j) and (PMatrix2(p)^[i,j] > k) then
               counter:=counter+1;
    end;
    end;
  check:=counter;
end;
begin
     new(mat1);
     new(mat2);
     input(mat1,m1,n1,1);
     input(mat2,m2,n2,2);
     writeln('K = ',k);
     writeln('Matrix 1 :');
     output(mat1,m1,n1,1);
     writeln('Matrix 2 :');
     output(mat2,m2,n2,2);
     writeln('-----------');
     writeln('Result for matrix 1: ',check(mat1,m1,n1,1));
     
     writeln('Result for matrix 2: ',check(mat2,m2,n2,2));

     
end.    
























