Unit Table;
Interface
Uses CellClass,FrameClass,Common;
procedure putCellFrame(o:Cell);
procedure removeFrame;
procedure createField;
Implementation
var curCell:Cell;
field:array[1..NUM_OF_CELL,1..NUM_OF_CELL] of Cell;
cellFrame:Frame;
 procedure putCellFrame(o:Cell);
    begin
        if curCell <> o then
        begin
             if curCell <> nil then cellFrame.destroy;
             curCell:=o;
             cellFrame:=Frame.create(o.left,o.top,o.width,o.height,CELL_FRAME_THICK,CELL_FRAME_COLOR);
        end;

    end;
     procedure removeFrame;
     begin
          if curCell <> nil then
          begin
          cellFrame.destroy;
          curCell:=nil;
          end;

     end;
procedure createField;
var x,y,i,j:integer;
begin
for i:=1 to NUM_OF_CELL do
  begin
  y:=TABLE_SETOFF_Y + i*CELL_HEIGHT + i*CELL_SPACE;
    for j:=1 to NUM_OF_CELL do
    begin
         x:=TABLE_SETOFF_X + j*CELL_WIDTH + j*CELL_SPACE;
         field[i,j]:=Cell.create(x,y,'1.png','2.png','3.png','4.png','5.png');
    end;
  end;
end;
begin
end.