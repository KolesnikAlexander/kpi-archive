Unit ArrInit;{������ ��� ������ � ��������}

Interface
Uses Common, ArrUnit;
procedure createRand3D(var arr:Array3D);{��������� ����������� ������}
procedure createOrdered3D(var arr:Array3D);{��������� �������������� ������}
procedure createBackOrdered3D(var arr:Array3D);{��������� �������� �������������� ������}
procedure createRandVect(var arr:TVector);{��������� ����������� �������}
procedure createOrderedVect(var arr:TVector);{��������� �������������� �������}
procedure createBackOrderedVect(var arr:TVector);{��������� �������� ����������� �������}
procedure copyArray(var src,dst:Array3D);{��������� �������� � ������ src �� ������ dst}
procedure copyVector(var src,dst:TVector);{��������� �������� � ������ src �� ������� dst}
procedure printArray3D(var arr:Array3D);{��������� ������ �� �����}
procedure printVector(var vect:TVector);{��������� ������� �� �����}
Implementation
{��������� ����������� ������}
procedure createRand3D(var arr:Array3D);
var i,j,k:integer; 
begin
randomize;
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do arr[i,j,k]:= random(MAX_RANDOM);
end;
{��������� �������������� ������}
procedure createOrdered3D(var arr:Array3D);
var i,j,k,counter:integer; 
begin
counter:=1;
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do 
        begin
          arr[i,j,k]:= counter;
          counter:=counter+1;
        end;        
end;
{��������� �������� �������������� ������}
procedure createBackOrdered3D(var arr:Array3D);
var i,j,k,counter:integer; 
begin
counter:=P_3D*N_3D*M_3D;
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do 
        begin
          arr[i,j,k]:= counter;
          counter:=counter-1;
        end;        
end;
{��������� ���������� �������}
procedure createRandVect(var arr:TVector);
var i:integer; 
begin
  randomize;
    for i:=1 to N_VECTOR do arr[i]:= random(MAX_RANDOM);
end;
{��������� �������������� ������}
procedure createOrderedVect(var arr:TVector);
var i:integer; 
begin
  randomize;
    for i:=1 to N_VECTOR do arr[i]:= i;
end;
{��������� �������� �������������� �������}
procedure createBackOrderedVect(var arr:TVector);
var i:integer; 
begin
  randomize;
    for i:=1 to N_VECTOR do arr[i]:= N_VECTOR-i+1;
end;
{��������� �������� � ������ src �� ������ dst}
procedure copyArray(var src,dst:Array3D);
var i,j,k:integer;   
begin
for i:=1 to P_3D do
    for j:=1 to M_3D do
      for k:=1 to N_3D do dst[i,j,k]:=src[i,j,k]; {������� ������� � ����� � �����}  
      
end;
{��������� �������� � ������� src �� ������� dst}
procedure copyVector(var src,dst:TVector);
var i:integer;   
begin
      for i:=1 to N_VECTOR do dst[i]:=src[i]; 
end;
{��������� ������ �� �����}
procedure printArray3D(var arr:Array3D);
var i,j,k:integer; 
begin
  randomize;
  for i:=1 to P_3D do 
    begin
      writeln(i, ' pereriz:');
       writeln('---------------');
       for j:=1 to M_3D do
       begin
          for k:=1 to N_3D do write(arr[i,j,k], '  ');
          writeln;
       end;   
      
    end;  
end;
{��������� ������� �� �����}
procedure printVector(var vect:TVector);
var i:integer; 
begin
  randomize;
  for i:=1 to N_VECTOR do write(vect[i]:8);
end;
begin
end.