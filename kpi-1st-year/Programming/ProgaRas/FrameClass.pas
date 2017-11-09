Unit FrameClass;
Interface
Uses ABCObjects, Common;
type
  Frame=class
  top,bottom,left,right:rectangleABC;
    constructor create(x,y,w,h,thick,color:integer);
    begin
         top:=rectangleABC.create(x,y,w,CELL_FRAME_THICK,color);
         bottom:=rectangleABC.create(x,
                                     y+h-thick,
                                     w,
                                     CELL_FRAME_THICK,
                                     color);
          left:=rectangleABC.create(x,y,thick,h,color);
          right:=rectangleABC.create(x+w-thick,
                                     y,
                                     thick,
                                     h,
                                     color);
    end;
    destructor destroy;
    begin
         top.destroy;
         bottom.destroy;
         left.destroy;
         right.destroy;
    end;
  end;
Implementation
begin
end.