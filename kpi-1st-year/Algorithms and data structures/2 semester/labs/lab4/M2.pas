Unit M2;
Interface
  procedure S2;
  procedure S3;
Implementation
Uses M4,MErr,Global;
  procedure S2;
    begin
      writeln('   Procedure S2 started. Invokes:');
      writeln(trace ,'   Procedure S2 started. Invokes:');
      S6;
      writeln('   S2 ends.');
      writeln(trace ,'   S2 ends.');
    end;
    procedure S3;
    begin
      writeln('   Procedure S3 started. Invokes:');
      writeln(trace, '   Procedure S3 started. Invokes:');
      S6;
      S7;
      S8;
      writeln('   S3 ends.');
      writeln(trace, '   S3 ends.');
    end;
begin
 writeln(trace,'M2 is initialized')
end.

