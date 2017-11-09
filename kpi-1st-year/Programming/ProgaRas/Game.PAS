Unit Game;
Interface
uses ABCObjects,Common,GraphABC,CellClass,Events,Table,FrameClass,Process,ButtonClass;
procedure startGame;
Implementation
var
    x,y:integer;
    frameCounter:integer;
    wrongResFrames:array[1..2*NUM_OF_CELL] of Frame;
    htpButton:Button;
    playAgain:Button;
    exitBut:Button;
    zroz:Button;
    peremoga:TextABC;
    blockPanel:rectangleABC;
    pravyla:PictureABC;
    lastButton:Button;
procedure createName;
begin
   TextABC.create(120,10,40,CELL_COLOR,'×îòèðè â ðÿä');
end;
procedure removeWRFrames;
var i:integer;
begin
       for i:= 1 to 2*NUM_OF_CELL do
      begin
          if wrongResFrames[i] <> nil then wrongResFrames[i].destroy;
      end;
end;
procedure cellClickHandler(o:Object);
var
    res:posIsAllowedResult;
    i:integer;
begin
Cell(o).changeState;
      res:=posIsAllowed(Cell(o));
     { for i:= 1 to 2*NUM_OF_CELL do
      begin
          if wrongResFrames[i] <> nil then wrongResFrames[i].destroy;
      end;    }
      removeWRFrames;
   if not res.gameIsOver then
     begin
      frameCounter:=0;
      for i:=1 to NUM_OF_CELL do
        begin
           if res.lines[i] = 1 then
           begin
              frameCounter:=frameCounter+1;
               wrongResFrames[frameCounter]:=Frame.create(field[i,1].left,
                            field[i,1].top,
                            (NUM_OF_CELL)*(CELL_WIDTH+CELL_SPACE)-CELL_SPACE,
                            (CELL_HEIGHT),
                            WRONG_POS_THICK,
                            WRONG_POS_COLOR);


           end;
        end;

        for i:=1 to NUM_OF_CELL do
        begin
           if res.cols[i] = 1 then
           begin
              frameCounter:=frameCounter+1;
               wrongResFrames[frameCounter]:=Frame.create(field[1,i].left,
                            field[1,i].top,
                            (CELL_WIDTH),
                            (NUM_OF_CELL)*(CELL_HEIGHT+CELL_SPACE)-CELL_SPACE,
                            WRONG_POS_THICK,
                            WRONG_POS_COLOR);


           end;
    end;
        end
        else
    begin
         blockPanel:=rectangleABC.create(field[1,1].left - 15,
                  field[1,1].top - 15,
                  (CELL_WIDTH+CELL_SPACE)*NUM_OF_CELL+27,
                  (CELL_HEIGHT+CELL_SPACE)*NUM_OF_CELL+27,
                  CELL_COLOR
                  );
                  blockPanel.filled:=false;
         peremoga:=TextABC.create(70,200,50,WRONG_POS_COLOR,'ÏÅÐÅÌÎÃÀ!');
    end;
end;
procedure createButtons;
begin
htpButton:=Button.create(field[1,NUM_OF_CELL].left + CELL_WIDTH + CELL_SPACE + 30,
              field[1,NUM_OF_CELL].top - 60,
              'htp.gif','htpFocused.gif',1);

playAgain:=Button.create(field[1,NUM_OF_CELL].left + CELL_WIDTH + CELL_SPACE + 30,
              field[1,NUM_OF_CELL].top + 80,
              'spoch.gif','spochFocused.gif',2);
              
exitBut:=Button.create(field[1,NUM_OF_CELL].left + CELL_WIDTH + CELL_SPACE + 30,
              field[1,NUM_OF_CELL].top + 210,
              'exit.gif','exitFocused.gif',3);
                       

end;
procedure createBackGround;
begin
     ClearWindow(BG_COLOR);
end;
procedure createFieldFrames;
begin
     Frame.create(field[1,1].left - 15,
                  field[1,1].top - 15,
                  (CELL_WIDTH+CELL_SPACE)*NUM_OF_CELL+27,
                  (CELL_HEIGHT+CELL_SPACE)*NUM_OF_CELL+27,
                  3,
                  CELL_COLOR);
                  
      Frame.create(field[1,1].left-6,
                  field[1,1].top-6,
                  (CELL_WIDTH+CELL_SPACE)*NUM_OF_CELL+6,
                  (CELL_HEIGHT+CELL_SPACE)*NUM_OF_CELL+6,
                  3,
                  CELL_COLOR);

end;
procedure MouseDownGame(x,y,mb: integer);
var o:Object;
    res:posIsAllowedResult;
    i:integer;


begin
  o:=ObjectUnderPoint(x,y);
  if o is Cell then
     cellClickHandler(o);
  if o is Button then
     begin
         case Button(o).id of
            1:begin
                 pravyla:=PictureABC.create (field[1,1].left-20,
                                            field[1,1].top-20,
                                            'pravyla.png');
                 zroz:= Button.create(pravyla.left+70,
                                      pravyla.top+270,
                                      'zroz.png',
                                      'zrozFocused.png',
                                      4);
              end;
            2:begin
                 resetField;
                 removeWRFrames;
                 if peremoga <> nil then
                 begin
                      peremoga.destroy;
                      blockPanel.destroy;
                 end;
              end;
            3:begin
                halt;
              end;
            4:begin
                pravyla.destroy;
                zroz.destroy;
              end;
       end;
     end;

end;
procedure MouseMoveGame(x,y,mb: integer);
var o:Object;
begin
  o:=ObjectUnderPoint(x,y);
  if o is Cell then
  begin
       if lastButton <> nil then
          begin
               lastButton.action;
               lastButton:=nil;
          end;
       putCellFrame(Cell(o));
       
  end
  else
      begin
       removeFrame;
       if o is Button then
       begin
        if lastButton <> Button(o) then
           begin
                Button(o).action;
                lastButton:=Button(o);
           end;
       end
       else
       if lastButton <> nil then
          begin
               lastButton.action;
               lastButton:=nil;
          end;
end;
end;


procedure startGame;
begin
  createBackGround;
  createField;
  createFieldFrames;
  createButtons;
  createName;
  OnMouseDown:=MouseDownGame;
  OnMouseMove:=MouseMoveGame;
end;
begin
frameCounter:=0;
end.
