Program rec_down;
uses crt;
var n:integer;
procedure f(i,n:integer;val,sum:real);
begin
  if i >= n then
  begin
  if n <> 1 then 
  begin
    val:=sin(val + cos(i));
    sum:=sum+val;
    writeln(i,' - ', val);
  end; 
    writeln('SUM:');
    writeln('--------');
    writeln(sum);
  end
  else
  begin
    val:=sin(val + cos(i));
    sum:=sum+val;
    writeln(i,' - ', val);
    f(i+1,n,val,sum);
 
  end;
end;
begin 
  write('Enter n: ');
  readln(n);
  writeln('1 - 1');
  f(2,n,1,1);
end.
