Program lab1;
const m = 3; n = 4;
Type Matrix = array[1..m,1..n] of Real;
Var a:Matrix;
    i:integer;
    res,elem:Real;
function binSearch(a:Matrix;line:integer;x:Real):integer;
var j,l,r:integer;
begin
  l:=1;
  r:=n;
  while l < r do
  begin
    j:=(l+r) div 2;
    if a[line,j]<x then
      l:=j+1
    else
      r:=j;
  end;
  if a[line, r] = x then
   binSearch:=r
  else 
  binSearch:=-1;
  
end;
begin
a[1,1] := -1.3; a[1,2] := 3;   a[1,3] := 3;  a[1,4] := 50;
a[2,1] := 16;  a[2,2] := 16;  a[2,3] := 17;  a[2,4] := 80;
a[3,1] := -10;  a[3,2] := -10; a[3,3] := -10; a[3,4] := 10;

elem:=-10;

for i:= 1 to m do
begin
    res:=binSearch(a,i,elem);
    if res = -1 then
      writeln('No element in line ',i)
    else
       writeln('[',i,' ',res,']');
end;
end.
