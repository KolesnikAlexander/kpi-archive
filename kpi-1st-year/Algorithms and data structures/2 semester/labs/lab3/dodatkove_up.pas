Program rec_up;
uses crt;
var n:integer;
    sum:real;
    k:real;
    res:real;
procedure f(i:integer;var value:real;var sum:real);
begin
  if i = 1 then
  begin
    value:=1;
    sum:=1;
    writeln(i,' - 1');
  end
  else
  begin
    f(i-1, value, sum);
    value:=sin(value + cos(i));
    sum:=sum+value;
    writeln(i,' - ', value);
  end;
end;
begin 
  write('Enter n: ');
  readln(n);
  f(n, res, sum);
  writeln('SUM:');
  writeln('--------');
  writeln(sum);
end.
