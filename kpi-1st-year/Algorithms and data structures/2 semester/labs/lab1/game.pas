Program slzfk;
USes ABCObjects, Timers, Events, Colors, PointRect;
Const bottom = 800;
      top=0;
      leftBorder = 0;
      rightBorder = 1500;
      timerInterv = 5;
      widthStick = 40;

Var cir:circleABC;
    t:integer;
    x,y:integer;
    time:integer;
    v,g:real;
    numSticks:integer;
    sticks:array[1..50] of RectangleABC;
    sticksHeight:array[1..50] of integer;
procedure MouseDown(xMouse,yMouse,mb:integer);
begin
numSticks:= numSticks+1;
sticks[numSticks]:= CreateRectangleABC(xMouse,yMouse,widthStick,bottom-yMouse,4);
sticksHeight[numSticks] := yMouse;
end;
procedure changeX;
var i:integer;
begin
     if (x > rightBorder) then
     begin
          x:=rightBorder;
          v:=-v;
     end;
     if x < leftBorder  then
      begin
          x:=leftBorder;
          v:=-v;
     end;
     x:=round(x+v*time);
end;
procedure changeY;
begin
if y>bottom then
     begin
          y:=bottom;
          g:=-g;
     end;
      if y<top then
     begin
          y:=top;
          g:=-g;
          time:=0;
     end;
      y := y + round(g*time*time / 2);
end;
procedure changeCoord;
var i:integer;
begin
     for i:=1 to numSticks do
     begin
          if cir.Intersects(sticks[i].Bounds) then
         begin
               if y < sticksHeight[i] then g:=-g
               else v:=-v;
              break;
          end;
   end;
     changeX;
     changeY;
end;

procedure replaceCircle;
begin
time:= time+timerInterv;
     changeCoord;
     x:=x;
     y:=y;
    cir.moveTo (x,y);
end;

begin
numSticks := 0;
g := 0.003;
v:=0.08;
x:=200;
y:=45;
t:= CreateTimer(timerInterv,replaceCircle);
cir:= CreateCircleABC(x,y,50,4);
OnMouseDown:=MouseDown;


while true do
end.

