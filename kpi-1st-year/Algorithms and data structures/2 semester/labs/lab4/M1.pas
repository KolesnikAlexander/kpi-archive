Unit M1;
Interface
  procedure S1;
Implementation
Uses M3,MErr,Global;
  procedure S1;
    begin
      writeln('   Procedure S1 started. Invokes:');
      S4;
      S5;
      writeln('   S1 ends.');
    end;
begin
  writeln(trace,'M1 is initialized')
end.

