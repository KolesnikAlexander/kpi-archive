Program rec_up_down;
uses crt;
var n:integer;
    sum:real;
function f(i,n:integer;val:real):real; //returns sum
begin
  if i >= n then
  begin
          val:=sin(val + cos(i));
          writeln(i,' - ', val);
          f:=val;
  end
  else
  begin
    val:=sin(val + cos(i));
    writeln(i,' - ', val);
    f:=val+f(i+1,n,val);
 
  end;
end;
begin 
  write('Enter n: ');
  readln(n);
  writeln('1 - 1');
  if n <> 1 then
    sum:=f(2,n,1)+1
  else
    sum:=1;
  writeln('SUM:');
  writeln('--------');
  writeln(sum);
end.
