Unit Time;{������ ��� ������ � �����}
Interface
Uses Common;
Type
    {����� ��� ���������� ����}
  TTime = record
    hours,
    minutes,
    seconds,
    hSeconds:Word
  end;
 {ϳ�������� ���� ������ ���������}
function resTime(const sTime,fTime:TTime):Longint;  
var 
  startTime, {��� ������� ����������}
  finishTime:TTime; {��� ���� ����������}
  algoritmTime:LongInt; {��� ����������}
Implementation
  function resTime(const sTime,fTime:TTime):Longint;
  begin
    resTime:=360000 * Longint(fTime.hours) +
               6000 * Longint(fTime.minutes) +
                100 * Longint(fTime.seconds) +
                      Longint(fTime.hseconds) -
             360000 * Longint(sTime.hours) -
               6000 * Longint(sTime.minutes) -
                100 * Longint(sTime.seconds) -
                      Longint(sTime.hseconds);
    end;
begin
end.
  
