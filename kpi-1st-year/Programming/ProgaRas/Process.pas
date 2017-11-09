Unit Common;
Interface
Uses CellClass,Table, Common;
Type
  posIsAllowedResult = record
    lines:array[1..NUM_OF_CELL] of integer;
    cols:array[1..NUM_OF_CELL] of integer;
    gameIsOver:boolean;
    end;
function posIsAllowed(e:Cell):posIsAllowedResult;
procedure resetField;
Implementation

procedure resetField;
var i,j:integer;
begin///
         for i:= 1 to NUM_OF_CELL do
     begin
          for j:=1 to NUM_OF_CELL do
          begin
            field[i,j].state := 0;
            field[i,j].CurrentPicture := 1;
          end;
     end;
end;///
function posIsAllowed(e:Cell):posIsAllowedResult;
var i,j,k:integer;
res:posIsAllowedResult;


begin
res.gameIsOver:=true;
for i:= 1 to NUM_OF_CELL do
begin
     res.lines[i] :=-1;
     res.cols[i]:=-1;
end;
     for i:= 1 to NUM_OF_CELL do
     begin
          for j:=1 to NUM_OF_CELL -1 do
          begin
               for k:=j+1 to NUM_OF_CELL do
               begin
                    if (field[i,j].state <> 0) and
                       (field[i,k].state <> 0) and
                       (field[i,j].state = field[i,k].state) then
                       begin
                        res.lines[i]:=1;
                        res.gameIsOver:=false;
                        break;
                       end
                     else if field[i,j].state = 0 then res.gameIsOver:=false;
               end;
          end;
         if field[i,NUM_OF_CELL].state = 0 then res.gameIsOver:=false;
     end;
      for j:= 1 to NUM_OF_CELL do
     begin
          for i:=1 to NUM_OF_CELL-1 do
          begin
               for k:=i+1 to NUM_OF_CELL do
               begin
                    if (field[i,j].state <> 0) and
                       (field[k,j].state <> 0) and
                       (field[i,j].state = field[k,j].state) then
                       begin
                        res.cols[j]:=1;
                        res.gameIsOver:=false;
                        break;
                       end;
               end;

          end;
     end;
     posIsAllowed:=res;
end;
begin

end.