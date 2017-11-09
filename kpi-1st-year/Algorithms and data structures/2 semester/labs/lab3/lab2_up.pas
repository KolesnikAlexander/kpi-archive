Program rec_up;
uses crt;
var n:integer;
    sum:real;
    k:real;//
function f(i:integer;var sum:real):real;
var val:real;
begin
  if i = 1 then
  begin
    f:=1;
    sum:=1;
    writeln(i,' - 1');
  end
  else
  begin
    val:=sin(f(i-1, sum) + cos(i));
    f:=val;
    sum:=sum+val;
     writeln(i,' - ', val);
  end;
end;
begin 
  write('Enter n: ');
  readln(n);
  k:=f(n, sum); //
  writeln('SUM:');
  writeln('--------');
  writeln(sum);
end.
