Program pr1;
Uses crt,dos;
Const lB = 1;Rb =79;tB = 4;dB=24;
      turnsAmount = 100;
Type
   Turn = record
   x:byte;
   y:byte;
   dirrection:char;
   end;
Var ch,p,tailDirrection,dirrection:char;
  currentTurn,targetX, targetY, tailX,tailY,x,y,turnsInd:byte;
    i,score:integer;
    turns:array[1..turnsAmount] of Turn;
    targetIsFound:Boolean;
Function GetChar(x,y:byte):char;
Var  Reg : Registers;
Begin
  With Reg do
    Begin
      AH:=8;
      BH:=0;
    End;
  Intr($10,Reg);
  GetChar:=chr(reg.AL);
end;
procedure shiftTurnsArr;
var k:integer;
begin
     for k:=1 to turnsInd-2 do
     begin
        turns[i]:=turns[i+1];
     end;
     turnsInd:=turnsInd-1;
end;
procedure changeCoord(var cX,cY:byte;var dir:char);
begin
case dir of
        'u': if cy = tB then cy:=dB
             else cy:=cy-1;
        'd': if cy = dB then cy:=tB
             else cy:=cy+1;
        'l': if cx = lB then cx:=rB
             else  cx:=cx-1;
        'r': if cx = rB then cx:= lB
             else cx:=cx+1;
        end;
end;

function getChValue(val:char):char;
begin
             case val of
             #77:getChValue:='r';
             #75:getChValue:='l';
             #72:getChValue:='u';
             #80:getChValue:='d';
             end;
end;
procedure generateNewTarget;
begin

repeat
   randomize;
   targetX:= random(rb-4)+2;
   targetY:= random(db-4)+6;
   until getChar(targetX,targetY) = ' ';
   gotoxy(targetX,targetY);
   write('*');
   targetIsFound:=false;
end;

procedure addTurn(argX, argY:byte; dir:char);
begin
    turnsInd:=turnsInd+1;
    turns[turnsInd].x:=argX;
    turns[turnsInd].y:=argY;
    turns[turnsInd].dirrection:=dir;
end;
procedure replaceTail;
begin
     if (turnsInd <> 0) or (turnsInd>=currentTurn) then
     begin

          if (tailX = turns[currentTurn].x) and (tailY = turns[currentTurn].y) then
             begin
                   tailDirrection:=turns[currentTurn].dirrection;
                   currentTurn:=currentTurn+1;
                   if turnsInd<currentTurn then
                   begin
                        turnsInd:=0;
                        currentTurn:=1;
                   end;

             end;

           end;
     changeCoord(tailX,tailY,tailDirrection);
     gotoxy(tailX,tailY);
     write(' ');

end;
function opositDirrection(val:char):char;
    begin
    case val of
             #77:opositDirrection:='l';
             #75:opositDirrection:='r';
             #72:opositDirrection:='d';
             #80:opositDirrection:='u';
             end;
    end;
begin
currentTurn:=1;
x:=lB+1;
y:=tB+1;
tailX:=x;
tailY:=y;
tailDirrection:='r';
write('ooo');
dirrection:='r';
ch:=#77;
x:=x+3;
y:=y;
turnsInd:=0;
targetIsFound:=true;
score:=-1;
clrscr;
gotoxy(1,3);
for i:=1 to 80 do write('-');
gotoxy(4,2);write('Rakhunok: ');
while(1<2) do

        begin
        if targetIsFound then
        begin

             score:=score+1;
             generateNewTarget;
             gotoxy(14,2);write(score);

        end;
        while keypressed do ch:=readkey;
             if (getChValue(ch)<>dirrection) and (opositDirrection(ch)<>dirrection) then
             begin
             case ch of
             #77:dirrection:='r';
             #75:dirrection:='l';
             #72:dirrection:='u';
             #80:dirrection:='d';
             #27: halt;
             end;
              addTurn(x,y,dirrection);
           end;

        changeCoord(x,y,dirrection);
gotoxy(x,y);
if getChar(x,y) = 'o' then
                  begin
                  gotoxy(30,10);
                   writeln('Gru Zaversheno');
                   gotoxy(30,11);
                   writeln('Rakhunok: ',score);
                   delay(2000);
                   halt;
                  end
else
 begin
      if getChar(x,y) = '*' then
      begin
           write('o');
           targetIsFound:=true;

      end
      else
      begin
write('o');
replaceTail;
      end;

delay(100);

end;
end;
end.