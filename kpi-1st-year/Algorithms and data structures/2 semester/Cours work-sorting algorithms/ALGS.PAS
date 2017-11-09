Unit Algs;{Модуль, що мітить усі алгоитми сортування}
Interface 
Uses Dos, Common, ArrUnit,ArrInit,Time;
  const ALG_QUANTITY = 4;{кількість алгоритмів}
  Type AlgNum = 1..ALG_QUANTITY;{Порядковий номер алгоритма }
  { Сортування тривимірного масиву
    alg: порядковий номер алгоритма
    arr: масив. що сортується
  }
  function sort3D(alg:AlgNum;var arr:array3D):LongInt;
  { Сортування вектору
    alg: порядковий номер алгоритма
  }
  function sortVector(alg:AlgNum):LongInt;
Implementation
Type 
TVector = array[1..N_VECTOR] of integer;
function alg4(n:integer):LongInt;{Швидке сортування}
var
    i:word;
{ Рекурсивна процедура швидкого сортування}
procedure QSort(L,R:word);
  var
    B, Tmp: integer;
    i,j: integer;
    begin
      B:= A[(L+R) div 2];{Збереження елемента що порівнюється} 
      i:=L; 
      j:=R;
      while i <= j do
      begin
        while A[i] < B do i:= i+1;{ Пошук найбліьшого елемента у лівій частині}
        while A[j] > B do j:=j-1;{ Пошук найменшого елемента у правій частині}
        if i <= j then
        begin{Зміна місць елементів}
          Tmp :=A[i];
          A[i]:=A[j];
          A[j]:=Tmp;
          i:=i+1;
          j:=j-1;
        end;
       end;
       if L<j then QSort(L,j);{Сортування лівої чатини}
       if i<R then QSort(i,R); {Сортування правої чатини}
     end;
     begin
      with startTime do {Час початку сортування}
        getTime(hours,minutes,seconds,hSeconds);
     QSort(1,n);
      with finishTime do {Час кінця сортування}
        getTime(hours,minutes,seconds,hSeconds);
     alg4:=resTime(startTime, finishTime);
     end;
{Алгоритм №4 методу обміну (шейкерне сортування) }
function alg3(n:integer):LongInt;
 var
  B: integer;
  i, L, R, k: integer;
  begin
     with startTime do {Час початку сортування}
     getTime(hours,minutes,seconds,hSeconds);
     L:=1; R:=n; k:=1;
     while L < R do
     begin
      for i:=L to R-1 do
       if A[i] > A[i+1] then 
          begin
              B:=A[i];
              A[i]:= A[i+1];
              A[i+1]:=B;
              k:=i;
          end;
      R:=k;
      for i:=R-1 downto L do
        if A[i] > A[i+1] then
            begin
               B:= A[i];
               A[i]:= A[i+1];
               A[i+1]:=B;
               k:=i;
            end;
      L:=k+1;
     end;
     with finishTime do {Час кінця сортування}
     getTime(hours,minutes,seconds,hSeconds);
     alg3:=resTime(startTime, finishTime);
     end;
function alg2(n:integer):LongInt;{Алгоритм №7 методу вибору}
 var
 Min, Max: integer;
 L,R,i,imin,imax:integer;
  begin
   with startTime do {Час початку сортування}
   getTime(hours,minutes,seconds,hSeconds);
    L:=1;R:=n;
    while L<R do
    begin
      Min:=A[L]; Max:=A[L];
      imin:=L; imax:= L;
      for i:= L+1 to R do
        if A[i] < Min then
          begin
            Min:=A[i];
            imin:=i
          end
        else
          if A[i] > Max then
          begin
            Max:=A[i];
            imax:=i;
          end;
      if imin<>L then
      begin
        A[imin]:=A[L];
        A[L]:=Min;
      end;
      if imax <> R then
      begin
        if imax=L then A[imin]:=A[R]
        
        else
          A[imax]:=A[R];
        A[R]:=Max;
      end;
          L:=L+1; R:=R-1;
   end;
    with finishTime do {Час кінця сортування}
     getTime(hours,minutes,seconds,hSeconds);
    alg2:=resTime(startTime, finishTime);
 end;


 {Алгоритм №1 методу прямої вставки}
function alg1(n:integer):LongInt;
  var
  B: integer;{буферна змінна}
  i, j, k: integer;
  begin
   with startTime do {Час початку сортування}
     getTime(hours,minutes,seconds,hSeconds);
    for i:=2 to n do
      begin
        B:=A[i];
        j:=1;
        while B>A[j] do j:=j+1;
        for k:= i-1 downto j do
          A[k+1]:= A[k];
         A[j]:=B;
      end;
      with finishTime do {Час кінця сортування}
     getTime(hours,minutes,seconds,hSeconds);
     alg1:=resTime(startTime,finishTime);
    end;
function sortVector(alg:AlgNum):LongInt;
 begin
  case alg of
    1:sortVector:= alg1(N_VECTOR);
    2:sortVector:= alg2(N_VECTOR);
    3:sortVector:= alg3(N_VECTOR);
    4:sortVector:= alg4(N_VECTOR);
  end;
 end; 
 
{Алгоритм №1 методу прямої вставки (3Д)}
function alg1_3D(var A:Array3D;p,m,n:integer):LongInt;
  var
  vect:array[1..M_3D,1..N_3D] of integer;{Масив для збергіання перерізу}
  B: integer;{буферна змінна}
  i, j, k, col, row: integer;
  begin
  with startTime do {Час початку сортування}
    getTime(hours,minutes,seconds,hSeconds);
    for i:=2 to p do
      begin
     
        B:=A[i,1,1]; {зберігаємо ключ сортування}
       for row:= 1 to M_3D do
        for col:= 1 to N_3D do
          vect[row,col]:=A[i,row,col];{Зберігаємо переріз ключа сортування у вектор}
 
        j:=1;{Починаємо пошук з 1 елемента}
        while B>A[j,1,1] do j:=j+1;{Пошук елемента вставки}
        for k:= i-1 downto j do
         for row:=1 to m do
          for col:=1 to n do
             A[k+1, row, col] := A[k, row, col];{Поелементний зсув перерізів}
           
           for row:=1 to m do
          for col:=1 to n do
              A[j,row,col]:=vect[row,col];{Поелементна вставка останнього перерізу}
        
       
      end;
   with finishTime do {Час кінця сортування}
     getTime(hours,minutes,seconds,hSeconds);
    alg1_3D:=resTime(startTime, finishTime);
    end;
function alg2_3D(var A:Array3D;p,m,n:integer):LongInt;{Алгоритм №7 методу вибору}
 var
 minMatr:array[1..M_3D,1..N_3D] of integer;{Масив для збергіання найменшого перерізу}
 maxMatr:array[1..M_3D,1..N_3D] of integer;{Масив для збергіання найбільшого перерізу}
 Min, Max: integer;
 L,R,i,imin,imax,row,col:integer;
  begin
   with startTime do {Час початку сортування}
    getTime(hours,minutes,seconds,hSeconds);
    L:=1;R:=p;
    while L<R do
    begin
      Min:=A[L,1,1]; Max:=A[L,1,1];
      imin:=L; imax:= L;
      for row:= 1 to M_3D do
         for col:= 1 to N_3D do
            minMatr[row,col]:=A[L,row,col];
            
       for row:= 1 to M_3D do
         for col:= 1 to N_3D do
            maxMatr[row,col]:=A[L,row,col];     
            
      for i:= L+1 to R do
      begin
        if A[i,1,1] < Min then
          begin
            Min:=A[i,1,1];
            imin:=i;
            for row:= 1 to M_3D do
              for col:= 1 to N_3D do
                minMatr[row,col]:=A[imin,row,col];
          end
        else
          if A[i,1,1] > Max then
          begin
            Max:=A[i,1,1];
            imax:=i;
             for row:= 1 to M_3D do
              for col:= 1 to N_3D do
                maxMatr[row,col]:=A[imax,row,col];
          end;
        end;  
      if imin<>L then
      begin
        for row:= 1 to M_3D do
          for col:= 1 to N_3D do
            A[imin,row,col]:=A[L,row,col];

        for row:= 1 to M_3D do
          for col:= 1 to N_3D do
            A[L,row,col]:=minMatr[row,col];
      end;
      if imax <> R then
      begin
        if imax=L then
         for row:= 1 to M_3D do
          for col:= 1 to N_3D do
          begin
            A[imin,row,col]:=A[R,row,col];
           end
        
        else

             for row:= 1 to M_3D do
              for col:= 1 to N_3D do
                A[imax,row,col]:=A[R,row,col];

            for row:= 1 to M_3D do
              for col:= 1 to N_3D do
                A[R,row,col]:=maxMatr[row,col];
      end;
          L:=L+1; R:=R-1;
   end;
    with finishTime do {Час кінця сортування}
     getTime(hours,minutes,seconds,hSeconds);
    alg2_3D:=resTime(startTime, finishTime);
end; 
{Алгоритм №4 методу обміну (шейкерне сортування) }
function alg3_3D(var A:Array3D;p,m,n:integer):LongInt;
 var
 B:array[1..M_3D,1..N_3D] of integer;{Масив для збергіання перерізу}
  i, L, R, k,row,col: integer;
  begin
   with startTime do {Час початку сортування}
    getTime(hours,minutes,seconds,hSeconds);
     L:=1; R:=p; k:=1;
     while L < R do
     begin
      for i:=L to R-1 do
       if A[i,1,1] > A[i+1,1,1] then 
          begin

             for row:= 1 to M_3D do
              for col:= 1 to N_3D do
                B[row,col]:=A[i,row,col];
              
              for row:= 1 to M_3D do
               for col:= 1 to N_3D do
                 A[i,row,col]:=A[i+1,row,col];
              
              
              for row:= 1 to M_3D do
               for col:= 1 to N_3D do
                 A[i+1,row,col]:=B[row,col];
                 
              k:=i;
          end;
      R:=k;
      for i:=R-1 downto L do
        if A[i,1,1] > A[i+1,1,1] then
                  begin

             for row:= 1 to M_3D do
              for col:= 1 to N_3D do
                B[row,col]:=A[i,row,col];
              
              for row:= 1 to M_3D do
               for col:= 1 to N_3D do
                 A[i,row,col]:=A[i+1,row,col];

              for row:= 1 to M_3D do
               for col:= 1 to N_3D do
                 A[i+1,row,col]:=B[row,col];
                 
              k:=i;
          end;
      L:=k+1;
     end;
 with finishTime do {Час кінця сортування}
     getTime(hours,minutes,seconds,hSeconds);
    alg3_3D:=resTime(startTime, finishTime);
end;
 {Алгоритм №4 методу обміну (шейкерне сортування) }
function alg4_3D(var A:Array3D;p,m,n:integer):LongInt;
procedure QSort(L,R:word);
  var
    B,row,col: integer;
    Tmp:array[1..M_3D,1..N_3D] of integer;
    i,j: word;
    begin
      B:= A[(L+R) div 2,1,1]; i:=L; j:=R;
      while i <= j do
      begin
        while A[i,1,1] < B do i:= i+1;
        while A[j,1,1] > B do j:=j-1;
        if i <= j then
        begin

          for row:= 1 to M_3D do
               for col:= 1 to N_3D do
                 Tmp[row,col]:=A[i,row,col];

          for row:= 1 to M_3D do
               for col:= 1 to N_3D do
                 A[i,row,col]:=A[j,row,col];

         
          for row:= 1 to M_3D do
               for col:= 1 to N_3D do
                 A[j,row,col]:=Tmp[row,col];
          
          i:=i+1;
          j:=j-1;
        end;
       end;
       if L<j then QSort(L,j);
       if i<R then QSort(i,R);
     end;
begin
 with startTime do {Час початку сортування}
    getTime(hours,minutes,seconds,hSeconds);
  QSort(1,p);
   with finishTime do {Час кінця сортування}
     getTime(hours,minutes,seconds,hSeconds);
    alg4_3D:=resTime(startTime, finishTime);
end;     
 function sort3D(alg:AlgNum;var arr:array3D):LongInt;
 var i,e:integer;
 begin
 case alg of
    1:sort3D:= alg1_3D(arr, P_3D,M_3D,N_3D);
    2:sort3D:= alg2_3D(arr, P_3D,M_3D,N_3D);
    3:sort3D:= alg3_3D(arr, P_3D,M_3D,N_3D);
    4:sort3D:= alg4_3D(arr, P_3D,M_3D,N_3D);
  end;
    

 end;
    
 end.{unit}
