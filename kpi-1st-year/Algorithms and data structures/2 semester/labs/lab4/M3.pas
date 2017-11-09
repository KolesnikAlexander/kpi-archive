Unit M3;
Interface
  procedure S4;
  procedure S5;
Implementation
Uses MErr,Global;
  procedure S4;
    begin
      writeln('       Procedure S4 started.');
      writeln('       S4 ends.');
      writeln(trace, '       Procedure S4 started.');
      writeln(trace, '       S4 ends.');
    end;
    procedure S5;
    begin
      writeln('       Procedure S5 started.');
      writeln('       S5 ends.');
      writeln(trace, '       Procedure S5 started.');
      writeln(trace, '       S5 ends.');
    end;
begin
 writeln(trace,'M3 is initialized')
end.

