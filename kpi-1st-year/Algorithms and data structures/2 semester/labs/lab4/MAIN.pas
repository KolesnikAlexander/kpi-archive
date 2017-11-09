Program Main;
Uses M1, M2,MErr,Global;
begin
  writeln('Main started. Invokes:');
  writeln(trace, 'Main started. Invokes:');
  S1;
  S2;
  S3;
  writeln('Main ends.');
  writeln(trace, 'Main ends.');
  close(trace);
end.
