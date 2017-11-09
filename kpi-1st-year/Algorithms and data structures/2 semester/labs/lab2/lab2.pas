Program shake_sort;
Uses crt;
const m = 7;
      n = 8;
Type Matrix=array[1..m,1..n] of Integer;
var A:Matrix;
    i,j:Integer;
    procedure printMatrix(A:Matrix);
      var i,j:Integer;
    begin
        for i:= 1 to m do
        begin
          for j:=1 to n do
          write(A[i,j], '   ');
          writeln;
        end;
    end;
  procedure sortColoumn(j:Integer; var A:Matrix);
  var k,i,l,r,B:Integer;
  begin
     l:=1;
     r:=m;
     k:=1;
     while l < r do
     begin
        for i:= L to R-1 do
          if A[i,j] < A[i+1,j] then
          begin
            B:= A[i,j];
            A[i,j]:=A[i+1,j];
            A[i+1,j]:=B;
            k:=i;
          end;
          R:=k;
          for i:=R-1 downto L do
          if A[i,j] < A[i+1,j] then
          begin
            B:= A[i,j];
            A[i,j]:=A[i+1,j];
            A[i+1,j]:=B;
            k:=i;
          end;
          L:=k+1;
     end;
  end;
begin
a[1,1] := 13; a[1,2] := 99;   a[1,3] := 0;  a[1,4] := 50; a[1,5] := 15; a[1,6] := -3;   a[1,7] := 45;  a[1,8] := 10; 
a[2,1] := 16;  a[2,2] := 70; a[2,3] := 0;  a[2,4] := 80; a[2,5] := 13; a[2,6] := 87;   a[2,7] := 10;  a[2,8] := 18;
a[3,1] := 17;  a[3,2] := 50; a[3,3] := 0; a[3,4] := 10; a[3,5] := 7; a[3,6] := 16;   a[3,7] := 10;  a[3,8] := 30;
a[4,1] := 20; a[4,2] := 30;   a[4,3] := 1;  a[4,4] := 70; a[4,5] := 11; a[4,6] := -3;   a[4,7] := 45;  a[4,8] := 12; 
a[5,1] := 27;  a[5,2] := 24; a[5,3] := 0;  a[5,4] := 0; a[5,5] := 11; a[5,6] := -7;   a[5,7] := 10;  a[5,8] := 11;
a[6,1] := 30;  a[6,2] := 0; a[6,3] := 0; a[6,4] := 10; a[6,5] := 7; a[6,6] := -6;   a[6,7] := 15;  a[6,8] := 36;
a[7,1] := 60;  a[7,2] := -7; a[7,3] := 0; a[7,4] := 10; a[7,5] := 7; a[7,6] := 16;   a[7,7] := 10;  a[7,8] := 30;
writeln('Matrix:');
printMatrix(A);
writeln('-------------');
  for j:=1 to n do
  begin
      sortColoumn(j, A);
  end;
writeln('Sorted matrix:');
printMatrix(A);
writeln('-------------');
end.
