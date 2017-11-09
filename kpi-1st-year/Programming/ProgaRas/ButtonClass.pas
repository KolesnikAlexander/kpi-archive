Unit ButtonClass;
Interface
Uses ABCObjects, Common;
type
  Button=class(MultiPictureABC)
  id:integer;
 constructor create(x,y: integer;pic1,pic2:string;id:integer);
    begin
         inherited create(x,y,pic1);
         add(pic2);
         self.id:=id;
    end;
 procedure action;
  begin
         nextPicture;
  end;
 end;

Implementation
begin
end.