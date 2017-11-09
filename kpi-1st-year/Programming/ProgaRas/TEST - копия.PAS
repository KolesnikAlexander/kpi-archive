Program pr1;
uses ABCObjects,Common,GraphABC,CellClass,Events,Table;
const n = 4;
var table:array[0..NUM_OF_CELL,0..NUM_OF_CELL] of Cell;
    i,j:integer;
    x,y:integer;
procedure MouseDown(x,y,mb: integer);
var o:Object;
begin
  o:=ObjectUnderPoint(x,y);
  if o is Cell then Cell(o).changeState;
end;
procedure MouseMove(x,y,mb: integer);
var o:Object;
begin
  o:=ObjectUnderPoint(x,y);
  if o is Cell then putCellFrame(Cell(o))
  else removeFrame;
end;

begin
for i:=0 to NUM_OF_CELL-1 do
  begin
  y:=TABLE_SETOFF_Y + i*CELL_HEIGHT + i*CELL_SPACE;
    for j:=0 to NUM_OF_CELL-1 do
    begin
         x:=TABLE_SETOFF_X + j*CELL_WIDTH + j*CELL_SPACE;
         table[i,j]:=Cell.create(x,y,'1.png','2.png','3.png','4.png','5.png');
    end;
  end;
  OnMouseDown:=MouseDown;
  OnMouseMove:=MouseMove;
end.