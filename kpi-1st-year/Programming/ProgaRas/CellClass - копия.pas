Unit CellClass;
Interface
Uses ABCObjects,ABCSprites;
type
  Cell=class(MultiPictureABC)
  state:integer;
    constructor create(x,y: integer;pic1,pic2,pic3,pic4,pic5: string);
    begin
         inherited create(x,y,pic1);
         add(pic2);
         add(pic3);
         add(pic4);
         add(pic5);
    end;
    procedure changeState;
    begin
         if (state >= 0) and (state <5) then state:=state+1//change
         else state:=0;
         nextPicture;
    end;
  end;
Implementation
begin

end.