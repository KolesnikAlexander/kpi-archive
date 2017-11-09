Unit Global;
Interface
Const Cg1 = 1;
      Cg2 = 2;
      Cg3 = 3;
Type tg1 = array[1..5] of integer;
     tg2 = record
       a1,a2:integer;
       end;
     tg3 = set of real;
     tg4 = set of char;
Var vg1:integer;
    vg2:real;
    vg3:boolean;
    vg4:String;
    vg5:char;
    trace:text;
Implementation
begin
  assign(trace, 'trace.txt');
  rewrite(trace);
  writeln(trace,'Global is initialized');

end.

