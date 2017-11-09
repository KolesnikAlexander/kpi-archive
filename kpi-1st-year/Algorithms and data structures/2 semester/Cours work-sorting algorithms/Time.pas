Unit Time;{Модуль для роботи з часом}
Interface
Uses Common;
Type
    {Запис для збереження часу}
  TTime = record
    hours,
    minutes,
    seconds,
    hSeconds:Word
  end;
 {Підрахунок часу роботи алгоритму}
function resTime(const sTime,fTime:TTime):Longint;  
var 
  startTime, {Час початку сортування}
  finishTime:TTime; {Час кінця сортування}
  algoritmTime:LongInt; {Час сортування}
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
  
