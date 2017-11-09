Unit M4;
Interface
  procedure S6;
  procedure S7;
  procedure S8;
Implementation
Uses M2,MErr,Global;
  procedure S6;
    begin
      writeln('       Procedure S6 started');
      writeln('       S6 ends.');
      writeln(trace, '       Procedure S6 started');
      writeln(trace, '       S6 ends.');
    end;
     procedure S7;
    begin
      writeln('       Procedure S7 started. Invokes:');
      writeln(trace ,'       Procedure S7 started. Invokes:');
      S2;
      writeln('       S7 ends.');
      writeln(trace, '       S7 ends.');
    end;
     procedure S8;
    begin
      writeln('       Procedure S8 started');
      writeln('       S8 ends.');
      writeln(trace, '       Procedure S8 started');
      writeln(trace, '       S8 ends.');
    end;
    
begin
 writeln(trace,'M4 is initialized')
end.

