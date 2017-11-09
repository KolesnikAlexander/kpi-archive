Unit MErr;
Interface
  procedure SErr;
Implementation
Uses Global;
  procedure SErr;
    begin
      writeln('Procedure MErr started');
      writeln(trace, 'Procedure MErr started');
    end;
begin
 writeln(trace,'Err is initialized')
end.

